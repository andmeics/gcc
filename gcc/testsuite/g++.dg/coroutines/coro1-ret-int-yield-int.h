struct coro1 {
  struct promise_type;
  using handle_type = coro::coroutine_handle<coro1::promise_type>;
  handle_type handle;
  coro1 () : handle(0) {}
  coro1 (handle_type _handle)
    : handle(_handle) {
        PRINT("Created coro1 object from handle");
  }
  coro1 (const coro1 &) = delete; // no copying
  coro1 (coro1 &&s) : handle(s.handle) {
	s.handle = nullptr;
	PRINT("coro1 mv ctor ");
  }
  coro1 &operator = (coro1 &&s) {
	handle = s.handle;
	s.handle = nullptr;
	PRINT("coro1 op=  ");
	return *this;
  }
  ~coro1() {
        PRINT("Destroyed coro1");
        if ( handle )
          handle.destroy();
  }

  struct suspend_never_prt {
  bool await_ready() const noexcept { return true; }
  void await_suspend(handle_type) const noexcept { PRINT ("susp-never-susp");}
  void await_resume() const noexcept { PRINT ("susp-never-resume");}
  };

  struct  suspend_always_prt {
  bool await_ready() const noexcept { return false; }
  void await_suspend(handle_type) const noexcept { PRINT ("susp-always-susp");}
  void await_resume() const noexcept { PRINT ("susp-always-resume");}
  ~suspend_always_prt() { PRINT ("susp-always-dtor"); }
  };

  struct suspend_always_intprt {
    int x;
    suspend_always_intprt() : x(5) {}
    suspend_always_intprt(int __x) : x(__x) {}
    ~suspend_always_intprt() {}
    bool await_ready() const noexcept { return false; }
    void await_suspend(coro::coroutine_handle<>) const noexcept { PRINT ("susp-always-susp-intprt");}
    int await_resume() const noexcept { PRINT ("susp-always-resume-intprt"); return x;}
  };

  struct promise_type {

  promise_type() : vv(-1) {  PRINT ("Created Promise"); }
  ~promise_type() { PRINT ("Destroyed Promise"); }

  auto get_return_object () {
    PRINT ("get_return_object: handle from promise");
    return handle_type::from_promise (*this);
  }

  auto initial_suspend () {
    PRINT ("get initial_suspend (always)");
    return suspend_always_prt{};
  }
  auto final_suspend () {
    PRINT ("get final_suspend (always)");
    return suspend_always_prt{};
  }

#ifdef USE_AWAIT_TRANSFORM
  auto await_transform (int v) {
    PRINTF ("await_transform an int () %d\n",v);
    return suspend_always_intprt (v);
  }
#endif

  auto yield_value (int v) {
    PRINTF ("yield_value (%d)\n", v);
    vv = v;
    return suspend_always_prt{};
  }

  void return_value (int v) {
    PRINTF ("return_value (%d)\n", v);
    vv = v;
  }

  void unhandled_exception() { PRINT ("** unhandled exception"); }

  int get_value () { return vv; }
  private:
    int vv;
  };

};
