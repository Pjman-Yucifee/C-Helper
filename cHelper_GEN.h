#ifndef __CHELPER_GEN_H__
#define __CHELPER_GEN_H__

#include <main.h>
#include <stdio.h>
#include <string.h>

#undef NULL
#define PACK_BIG      __attribute__((packed, scalar_storage_order("big-endian")))
#define PACK_LIT      __attribute__((packed, scalar_storage_order("little-endian")))

#define ABSO(x)         ( ((x) < 0) ? (-(x)) : (x) )
#define FULL(x)         ((1 << (sizeof(x) * 8)) - 1)
#define HALF(x)         (((FULL(x) + 1) / 2) - 1)
#define PROLEN(s, i)    ( sizeof( ((s){0}).i ) )
#define TIMEOUT(t, x)   { size_t __$_o_$__ = 1000*(t); do { x } while(__$_o_$__--); }

    typedef enum {Rx = -1, Nx = 0, Tx = +1} xfer_dir_t;
    typedef enum {NONE, UART} io_port_t;
    typedef enum {SUCCED, FAILED} result_t;
    typedef enum {OFF, ON} state_t;
    typedef enum {FALSE, TRUE} bool_t;
    typedef enum {YES, NO} ask_t;
    typedef enum {NA, OK} is_t;
    typedef enum {ZERO,ONE,TWO,THREE,FOUR,
                  FIVE,SIX,SEVEN,EIGHT,NINE,
                  NULL = -128} n_t;

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
