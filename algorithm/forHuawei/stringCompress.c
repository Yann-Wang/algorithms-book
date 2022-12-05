#include<stdio.h>
#include<stdlib.h>

void stringZip(const char * pInputStr, long lInputLen, char * pOutputStr){
    char *p = pInputStr,*po=pOutputStr;
    int i,k=0,count=1;

    po[0] = p[0];

    for(i=1;i<lInputLen;++i){
        if(p[i]==po[k]){
            count++;

        }else{
            if(count!=1){
                ++k;
                itoa(count,(po+k),10);
            }

            count = 1;
            po[++k] = p[i];
        }
    }


    if(count != 1){
        ++k;
        itoa(count,(po+k),10);
    }

    po[++k] = '\0';


}

void main(){
    char pInputStr[1000];
    char pOutputStr[1000];

    gets(pInputStr);
    int i;
    long len=0;

    for(i=0;pInputStr[i]!='\0';++i){
        ++len;
    }

    stringZip(pInputStr, len, pOutputStr);

    puts(pOutputStr);

}

