#include<stdio.h>
#include<stdlib.h>

void main(){
    int i = 0,k=0;
    char aa[100] = "a23d";
    int bb[100];
    char cc[2];

    cc[1]='\0';

    for(i=0;aa[i]!='\0';++i){
        printf("%c",aa[i]);
        if(aa[i]<'a' || aa[i]>'z'){
            cc[0] = aa[i];
            bb[k++] = atoi(cc);
            //++k;

        }
    }

    bb[k] = '\0';
    printf("\n");

    for(i=0;bb[i]!='\0';++i){
        printf("%d ",bb[i]);
    }



}
