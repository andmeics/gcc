package syscall

// Plan 9 Constants

// Open modes
const (
	O_RDONLY  = 0
	O_WRONLY  = 1
	O_RDWR    = 2
	O_TRUNC   = 16
	O_CLOEXEC = 32
	O_EXCL    = 0x1000
)

// Bind flags
const (
	MORDER  = 0x0003 // mask for bits defining order of mounting
	MREPL   = 0x0000 // mount replaces object
	MBEFORE = 0x0001 // mount goes before others in union directory
	MAFTER  = 0x0002 // mount goes after others in union directory
	MCREATE = 0x0004 // permit creation in mounted directory
	MCACHE  = 0x0010 // cache some data
	MMASK   = 0x0017 // all bits on
)

// Rfork flags
const (
	RFNAMEG  = 1 << 0
	RFENVG   = 1 << 1
	RFFDG    = 1 << 2
	RFNOTEG  = 1 << 3
	RFPROC   = 1 << 4
	RFMEM    = 1 << 5
	RFNOWAIT = 1 << 6
	RFCNAMEG = 1 << 10
	RFCENVG  = 1 << 11
	RFCFDG   = 1 << 12
	RFREND   = 1 << 13
	RFNOMNT  = 1 << 14
)

// Qid.Type bits
const (
	QTDIR    = 0x80
	QTAPPEND = 0x40
	QTEXCL   = 0x20
	QTMOUNT  = 0x10
	QTAUTH   = 0x08
	QTTMP    = 0x04
	QTFILE   = 0x00
)

// Dir.Mode bits
const (
	DMDIR    = 0x80000000
	DMAPPEND = 0x40000000
	DMEXCL   = 0x20000000
	DMMOUNT  = 0x10000000
	DMAUTH   = 0x08000000
	DMTMP    = 0x04000000
	DMREAD   = 0x4
	DMWRITE  = 0x2
	DMEXEC   = 0x1
)

const (
	STATMAX    = 65535
	ERRMAX     = 128
	STATFIXLEN = 49
)
