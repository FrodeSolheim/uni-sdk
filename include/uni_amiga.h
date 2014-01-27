#ifndef _UNI_AMIGA_H_
#define _UNI_AMIGA_H_

typedef char uni_char;
typedef unsigned char uni_uchar;
typedef short uni_short;
typedef unsigned short uni_ushort;
typedef long uni_long;
typedef unsigned long uni_ulong;

typedef unsigned long uni_handle;

#define UNI_VALID_HANDLE(x) (((x) & 0xff000000) == 0x80000000)

#define UNI_ERROR_NOT_ENABLED            0x70000001
#define UNI_ERROR_INVALID_LIBRARY        0x70000002
#define UNI_ERROR_INVALID_FUNCTION       0x70000002
#define UNI_ERROR_FUNCTION_NOT_FOUND     0x70000003
#define UNI_ERROR_LIBRARY_NOT_FOUND      0x70000004
#define UNI_ERROR_INVALID_FLAGS          0x70000005
#define UNI_ERROR_COULD_NOT_OPEN_LIBRARY 0x70000006
#define UNI_ERROR_ILLEGAL_LIBRARY_NAME   0x70000007
#define UNI_ERROR_LIBRARY_TOO_OLD        0x70000008
#define UNI_ERROR_INIT_FAILED            0x70000009
#define UNI_ERROR_INTERFACE_TOO_OLD      0x7000000a

#define NATIVE_BASE_NAME NativeBase

extern struct Library * NATIVE_BASE_NAME;

struct NativeLibrary {
    int dummy;
};

struct NativeFunction {
    int dummy;
};

#define OpenNativeLibrary(___libName, ___version) \
        LP2(0x1e, struct NativeLibrary *, OpenNativeLibrary, const char *, ___libName, a1, unsigned long, ___version, d0,\
        , NATIVE_BASE_NAME)

#define CloseNativeLibrary(___library) \
        LP1NR(0x24, CloseNativeLibrary, struct NativeLibrary *, ___library, a1,\
        , NATIVE_BASE_NAME)

#define FindNativeFunction(___library, ___name) \
        LP2(0x2a, struct NativeFunction *, FindNativeFunction, struct NativeLibrary *, ___library, a0, const char *, ___name, a1,\
        , NATIVE_BASE_NAME)

#define CallNativeFunction2(___function, ___arg0, ___arg1) \
        LP3(0x36, long, CallNativeFunction2, struct NativeFunction *, ___function, a0, long, ___arg0, a1, long, ___arg1, d1,\
        , NATIVE_BASE_NAME)

#endif /* _UNI_AMIGA_H_ */

