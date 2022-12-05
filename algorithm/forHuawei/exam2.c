#include<stdio.h>
#include<stdlib.h>

void main(){
    int i,j=0,k=0;
    int m,n;
    char *str[4097];
    char input[4097];

    scanf("%s",input);
    //puts(input);

    for(i=0;i<4096;++i){
        if(input[i]!= '/'){
            *(str[j]+k) = input[i];
            k++;
        }else{
            *(str[j]+k) = '\0';
            ++j;
            k=0;
            *(str[j]+0)= '/';
            *(str[j]+1)= '\0';
            ++j;
            k=0;
        }
    }

    for(m=j;m>=0;m--){
        for(n=0;*(str[m]+n)!='\0';++n){
            printf("%c",*(str[m]+n));
        }
    }


}
