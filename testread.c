#include "types.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int* a = (int*)4096;//a with the exact same size of the
  //page size, which makes the page aligned
  int* b = (int*)4097;//not aligned address

  //case 1
  //invalid length should cause mprotect fail
  //still readable and writable
  printf(1,"Case1:\n");
  printf(1,"The value of the address a is %d\n", *a);
  int i = mprotect((void *)a,-3);
  printf(1,"Status is %d\n",i);
  printf(1, "About to overwrite a...\n");
  *a=100;
  printf(1, "COMPLETED: a is now %d, expecting 100!\n", *a); 

  //case 2
  //address not aligned will cause mprotect fail
  printf(1,"Case2:\n");
  printf(1,"The value of the address b is %d\n", *b);
  i = mprotect((void *)b,sizeof(int));
  printf(1,"Status is %d\n",i);
  printf(1, "About to overwrite the protected address...\n");
  *b=100;
  printf(1, "COMPLETED: value is %d, expecting 100!\n", *b); 
  
  //case 3
  //aligned address and valid length can make mprotect work,
  //makeing the pte read only
  printf(1,"Case3:\n");
  printf(1,"The value of the address a is %d\n", *a);
  i = mprotect((void *)a,sizeof(int));
  printf(1,"Status is %d\n",i);
  printf(1, "About to overwrite the protected address...\n");
  *a=100;
  printf(1, "COMPLETED: value is %d, expecting 100!\n", *a); 

  // int i = mprotect((void *)a,-3);
  // printf(1,"Status is %d\n",i);
  // int status = mprotect((void *)a, sizeof(int));
  // if(status==0)
  // {
  //   printf(1,"Protect completed.\n");
  //   printf(1,"Still can read, the value is %d\n", *a);
  // }
  // printf(1, "About to overwrite the protected address...\n");
  // *a=100;
  // printf(1, "COMPLETED: value is %d, expecting 100!\n", *a);  
  exit();
}

void
munprotectNotInTheRangeTest(){
    int returnValue = munprotect ((void *)4096, 5);
    int stdout = 1;
    printf (stdout, "The return value of mprotect with nullptr should be -1, actual value is: %d\n\n", returnValue);

}