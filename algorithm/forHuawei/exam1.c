#include<stdio.h>
#include<stdlib.h>

void stringCount(char * pInputStr, int lInputLen, char * pOutputStr){
    char *p = pInputStr,*po=pOutputStr;
    int i,k=0,count=1;
    int start=0;



    for(i=0;i<lInputLen;++i){
        if((p[i]>='A' && p[i]<='Z')|| (p[i]>='a' && p[i]<='z')){
            po[0]=p[i];
            start  = i;
            break;
        }
    }

    for(i=start+1;i<lInputLen;++i){
        if(p[i]<'A'|| (p[i]>'Z' && p[i]<'a') || p[i]>'z'){
            continue;
        }

        if(p[i]==po[k]){
            count++;

        }else{
            ++k;
            itoa(count,(po+k),10);

            count = 1;
            po[++k] = p[i];
        }
    }


    ++k;
    itoa(count,(po+k),10);

    po[++k] = '\0';
}

void main(){
    char *p;
	char pInputStr[1025];
	char pOutputStr[1025];
	int j2;

    scanf("%s",pInputStr);
	int i;
	int len = 0;

	for(i=0,p=pInputStr;p[i]!='\0';++i){
        ++len;


	}

	stringCount(pInputStr, len, pOutputStr);


	for(j2=0;pOutputStr[j2]!='\0';j2++){
        printf("%c",pOutputStr[j2]);
	}
}

