#include <stdio.h>
#include <proto/exec.h>
#include <inline/dos.h>
#include <inline/macros.h>
#include "uni_amiga.h"

struct ExecBase *SysBase;
struct DosLibrary *DOSBase;
struct Library *NativeBase;
struct NativeLibrary *HelloWorldBase;

int main(int argc, char *argv[])
{
    char data[128];
    struct NativeFunction *HelloWorldFunc;
    long result;

    SysBase = *((struct ExecBase **) 0x00000004);
    if (!(DOSBase = (struct DosLibrary *) OpenLibrary ("dos.library", 33))) {
        return 1;
    }

    if (!(NativeBase = OpenLibrary ("uaenative.library", 1))) {
        PutStr ("Could not open uaenative.library");
        return 1;
    }

    if (!(HelloWorldBase = OpenNativeLibrary ("hello-world", 1))) {
        PutStr ("Could not open native library hello-world");
    }

    HelloWorldFunc = FindNativeFunction (HelloWorldBase, "hello_world");
    result = CallNativeFunction2 (HelloWorldFunc, data, 128);
    if (result != 42) {
        Printf ("Got return value: %ld, expected 42\n", result);
        return 1;
    }
    PutStr (data);
    PutStr ("\n");

    CloseNativeLibrary (HelloWorldBase);
    return 0;
}
