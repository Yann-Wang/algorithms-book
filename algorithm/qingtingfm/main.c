#include <stdio.h>
#include <stdlib.h>



int main()
{
    int d=66576;
    char * b = (char*) &d;
    printf("%d",b[0]-b[1]+b[2]-b[3]);



    int a = 0x12345678;
 char *p = (char *)(&a);
 if (*p == 0x78) {
  printf("xiao duan!\n");
 } else if (*p == 0x12) {
  printf("da duan!\n");
 } else {
  printf("other!\n");
 }
    return 0;
}
