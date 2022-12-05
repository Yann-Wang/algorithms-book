
/*
通过键盘输入一串小写字母（a~z）组成的字符串。
请编写一个字符串过滤程序，若字符串中出现多个相同的字符，将非首次出现的字符过滤掉。
比如字符串abacacde过滤结果为abcde。

*/
#include <stdio.h>
#include <string.h>

void stringFilter(const char * pInputStr, long lInputLen, char * pOutputStr){
	int i,j,k,o=0;
	char ss;
	for(i=0;i<lInputLen;++i){
		j=0;
		k=0;
		ss= pInputStr[i];
		while(pOutputStr[j] != '\0'){
			if(pOutputStr[j] == ss){
				k=1;
				break;
			}
			++j;
		}
		if(k==0){
			pOutputStr[o++] = ss;
		}
	}
}

void main(){
	char *p;
	char pInputStr[1000];
	char pOutputStr[1000];

	gets(pInputStr);

	int i;
	long len = 0;
	for(i=0,p=pInputStr;p[i]!='\0';++i,++p){
        ++len;
	}



	//long lInputLen = (long)len;



	stringFilter(pInputStr, len, pOutputStr);

	puts(pOutputStr);
	//printf("success");
}

