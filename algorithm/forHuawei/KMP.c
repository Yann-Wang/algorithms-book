#include<stdio.h>



typedef struct Str{
    int length;
    char ch[50];
} Str;

int kmp(Str str, Str substr, int next[]){
    int i=0,j=0;
    while(i<str.length && j<substr.length){
        if(str.ch[i]==substr.ch[j]){
            ++i;
            ++j;
        }else{
            j=next[j];
            if(j==-1){
                j=0;
                ++i;
            }
        }
    }
    if(j==substr.length)
        return i-substr.length;
    else
        return -1;
}

void getnext(Str substr, int next[]){
    int i=0,j=-1;
    next[0]=-1;
    while(i<substr.length){
        if(j==-1||substr.ch[i]==substr.ch[j]){
            ++j;
            ++i;
            next[i]=j;
        }
        else{
            j=next[j];
        }
    }
}

void main(){
    Str str={10,"ABABACBABA"};
    Str substr={4,"ACBA"};
    int next[6];
    int res;
    getnext(substr,next);
    res = kmp(str,substr,next);
    printf("%d\n",res);

}
