#include <stdio.h>

void main(){
    char c[80];
    int i;
    scanf("%s",c);



    for(i=0;c[i]!='\0';++i)
        printf("%c",c[i]);
}
