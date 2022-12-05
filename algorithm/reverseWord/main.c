#include <stdio.h>
#include <stdlib.h>

void Reverse(char *pStart, char * pEnd){
    char tmp;
    while(pStart<pEnd){
        tmp = *pStart;
        *pStart = *pEnd;
        *pEnd = tmp;
        ++pStart;
        --pEnd;
    }
}

void reverseWord(char *str){
    char *pS;
    char *pE;

    pS = pE = str;

    while(*pE != '\0'){
        ++pE;
    }
    --pE;

    Reverse(pS, pE);

    pS = pE = str;

    while(*pS != '\0'){
        if(*pE == ' ' && *pS == ' '){
            ++pS;
            ++pE;
        }else if((*pE == ' ' || *pE == '\0') && *pS != ' '){
            Reverse(pS, pE-1);
            pS = pE;
        }else{
            ++pE;
        }
    }
}

int main()
{
    char str[] = "I am a student.";
    char *s = str;
    reverseWord(str);

    while(*s != '\0'){
        printf("%c", *s);
        ++s;
    }

    //printf("Hello world!\n");
    return 0;
}
