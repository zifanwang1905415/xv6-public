#include "types.h"
#include "user.h"

void
mprotectNotInTheRangeTest(){
    int returnValue = mprotect ((void *)4096, 5);
    int stdout = 1;
    printf (stdout, "The return value of mprotect should be -1, actual value is: %d\n\n", returnValue);
}

void
munprotectNotInTheRangeTest(){
    int returnValue = munprotect ((void *)4096, 5);
    int stdout = 1;
    printf (stdout, "The return value of munprotect with nullptr should be -1, actual value is: %d\n\n", returnValue);
}