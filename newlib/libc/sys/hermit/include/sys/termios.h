#ifndef _SYS_TERMIOS_H
#define _SYS_TERMIOS_H

#include <sys/cdefs.h>
#include <sys/types.h>

__BEGIN_DECLS

typedef uint8_t cc_t;
typedef uint32_t speed_t;
typedef uint32_t tcflag_t;

#define NCCS 32

struct termios {
    tcflag_t c_iflag;
    tcflag_t c_oflag;
    tcflag_t c_cflag;
    tcflag_t c_lflag;
    cc_t     c_cc[NCCS];
    speed_t  c_ispeed;
    speed_t  c_ospeed;
};

#define VEOF    0
#define VEOL    1
#define VERASE  2
#define VINTR   3
#define VKILL   4
#define VMIN    5
#define VQUIT   6
#define VSTART  7
#define VSTOP   8
#define VSUSP   9
#define VTIME  10

#define BRKINT 0x0001
#define ICRNL  0x0002
#define IGNBRK 0x0004
#define IGNCR  0x0008
#define IGNPAR 0x0010
#define INLCR  0x0020
#define INPCK  0x0040
#define ISTRIP 0x0080
#define IXANY  0x0100
#define IXOFF  0x0200
#define IXON   0x0400
#define PARMRK 0x0800

#define OPOST  0x00000001
#define ONLCR  0x00000002
#define OCRNL  0x00000004
#define ONOCR  0x00000008
#define ONLRET 0x00000010
#define OFDEL  0x00000020
#define OFILL  0x00000040
#define NLDLY  0x00000180
#define NL0    0x00000080
#define NL1    0x00000100
#define CRDLY  0x00001e00
#define CR0    0x00000200
#define CR1    0x00000400
#define CR2    0x00000800
#define CR3    0x00001000
#define TABDLY 0x0001e000
#define TAB0   0x00002000
#define TAB1   0x00004000
#define TAB2   0x00008000
#define TAB3   0x00010000
#define BSDLY  0x00060000
#define BS0    0x00020000
#define BS1    0x00040000
#define VTDLY  0x00180000
#define VT0    0x00080000
#define VT1    0x00100000
#define FFDLY  0x00600000
#define FF0    0x00200000
#define FF1    0x00400000

#define B0         0
#define B50       50
#define B75       75
#define B110     110
#define B134     134
#define B150     150
#define B200     200
#define B300     300
#define B600     600
#define B1200   1200
#define B1800   1800
#define B2400   2400
#define B4800   4800
#define B9600   9600
#define B19200 19200
#define B38400 38400

#define CSIZE  0x000f
#define CS5    0x0001
#define CS6    0x0002
#define CS7    0x0004
#define CS8    0x0008
#define CSTOPB 0x0010
#define CREAD  0x0020
#define PARENB 0x0040
#define PARODD 0x0080
#define HUPCL  0x0100
#define CLOCAL 0x0200

#define ECHO   0x0001
#define ECHOE  0x0002
#define ECHOK  0x0004
#define ECHONL 0x0008
#define ICANON 0x0010
#define IEXTEN 0x0020
#define ISIG   0x0040
#define NOFLSH 0x0080
#define TOSTOP 0x0100

struct winsize {
    unsigned short ws_row;
    unsigned short ws_col;
};

#define TCSANOW   0
#define TCSADRAIN 1
#define TCSAFLUSH 2

#define TCIFLUSH  0
#define TCIOFLUSH 1
#define TCOFLUSH  2

#define TCIOFF 0
#define TCION  1
#define TCOOFF 2
#define TCOON  3

speed_t cfgetispeed(const struct termios *termios_p);
speed_t cfgetospeed(const struct termios *termios_p);
int cfsetispeed(struct termios *termios_p, speed_t speed);
int cfsetospeed(struct termios *termios_p, speed_t speed);
int tcdrain(int fildes);
int tcflow(int fildes, int action);
int tcflush(int fildes, int queue_selector);
int tcgetattr(int fildes, struct termios *termios_p);
pid_t tcgetsid(int fildes);
int tcgetwinsize(int fildes, struct winsize *winsize_p);
int tcsendbreak(int fildes, int duration);
int tcsetattr(int fildes, int optional_actions, const struct termios *termios_p);
int tcsetwinsize(int fildes, const struct winsize *winsize_p);

__END_DECLS

#endif /* _SYS_TERMIOS_H */
