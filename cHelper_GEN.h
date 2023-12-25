#ifndef __CHELPER_GEN_H__
#define __CHELPER_GEN_H__

#include <main.h>
#include <stdio.h>
#include <string.h>

//in this concept "null" has not "0" value so get place of "-128",
//so according to that, a signed byte min value is "-127",
//to be symmetrical by max value of "+127" for 8-bit length
#ifdef SYMMETRIC_NULL
#undef  NULL
#define NULL (-128)
#undef  null
#define null (-128)
#else
#ifndef NULL
#define NULL (0)
#endif
#ifndef null
#define null (0)
#endif
#endif

#define PACK_BIG        __attribute__((packed, scalar_storage_order("big-endian")))     //facilitate attributes for struct
#define PACK_LIT        __attribute__((packed, scalar_storage_order("little-endian")))  //facilitate attributes for struct
#define TIMEOUT(t, x)   { size_t __$_o_$__ = 1000*(t); do { x } while(__$_o_$__--); }   //facilitate timeouting process job

#define ABSO(x)         ( ((x) < 0) ? (-(x)) : (x) )    //absolute value of x
#define FULL(x)         ((1 << (sizeof(x) * 8)) - 1)    //most value that x can store (-1 in signed)
#define HALF(x)         (((FULL(x) + 1) / 2) - 1)       //middle value that x can sore (+max in signed)
#define PROLEN(s, i)    ( sizeof( ((s){0}).i ) )        //sizing a struct item (byte)

    typedef enum {Rx = -1, Nx = 0, Tx = +1} xfer_dir_t;
    typedef enum {NONE, UART} io_port_t;
    typedef enum {SUCCED, FAILED, BORTED, TIMEED} result_t;
    typedef enum {OFF, ON} state_t;
    typedef enum {FALSE, TRUE} bool_t;
    typedef enum {YES, NO} ask_t;
    typedef enum {NA, OK} is_t;
    typedef enum {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE} n_t;

    typedef void void_t;
    typedef struct { void_t* pointer; size_t length; } data_t;

    char* getVersion(void);
    void setVersion(char point, char major, char minor, char patch, char batch[10], char build[10]);

#ifdef __GNUC__
    int __io_putchar(int ch);
#else
    int fputc(int ch, FILE *f);
#endif
    void io_init(io_port_t type, void* handle);
    unsigned crc32_gen(void* data, unsigned size);

#endif
