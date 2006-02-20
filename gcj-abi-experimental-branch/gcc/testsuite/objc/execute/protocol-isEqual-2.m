/* Contributed by Nicola Pero - Fri Jun  4 03:16:17 BST 2004 */
/* Test that protocols with different names are different.  */
#include <objc/Protocol.h>

@protocol Foo1
- (void)foo1;
@end

@protocol Foo2
- (void)foo2;
@end

int main (void)
{
  if ([@protocol(Foo1) isEqual: @protocol(Foo2)])
    {
      abort ();
    }
  
  return 0;
}

