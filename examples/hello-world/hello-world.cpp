#include <stdio.h>
#include "uni_library.h"

UNI_DEFINE_LIBRARY (1, NULL);

UNIAPI uni_long UNICALL hello_world (struct uni *uni)
{
    uni_char *data = UNI_PCHAR_PARAM (a1);
    uni_long data_len = UNI_LONG_PARAM (d1);
    snprintf (data, data_len, "Hello World!\nBest regards, %s",
              uni->get_uae_string());
    return 42;
}
