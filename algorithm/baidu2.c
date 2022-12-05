#include <stdio.h>
//#define maxSize 100
typedef struct Str{
    char *str;
    int length;
} Str;

void getNext(Str ms,int next[]){
    int i=0,j=-1;
    next[0] = -1;
    if(ms.length<1){
        return;
    }
    next[1] = 0;
    int pos = 2, cn = 0;

    while(pos<ms.length){
        if(ms.str[pos-1] == ms.str[cn]){
            ++pos;
            ++cn;
        }
        else if(cn>0){
            cn = next[cn];
        }
        else{
            next[pos++] = 0;
        }
    }

}

int getIndexOf(Str ss, Str ms){
    if(ss.length<1 || ms.length<1 || ss.length<ms.length){
        return -1;
    }

    int *next = (int *)malloc(sizeof(int)*ms.length);
    getNext(ms,next);

    int si=0,mi=0;
    while(si<ss.length && mi<ms.length){
        if(ss.str[si]==ms.str[mi]){
            ++si;
            ++mi;
        }
        else if(next[mi]==-1){
            ++si;
        }
        else{
            mi = next[mi];
        }
    }

    free(next);

    return mi==ms.length ? si-mi : -1;
}

int getStringLen(char *p){
    int len=0;

    while(*p){
        ++len;
    }
    return len;
}

void main(){

    char *str0 = "the great wall";

    Str filterString[2] = {{"gre",3},{"eat",3}};
    Str ss;
    ss.str = str0;
    ss.length = getStringLen(str0);

    int i,j,index;

    int *arr = (int *)malloc(sizeof(int)*ss.length);
    for(i=0;i<ss.length;++i){
        arr[i]=0;
    }

    for(j=0;j<2;++j){
        index = getIndexOf(ss,filterString[j]);
        if(index != -1){
            for(i=0;i<filterString[j].length;++i){
                arr[index++] = 1;
            }
        }

    }

    for(i=0;i<ss.length;++i){
        if(arr[i]==1){
            ss.str[i] = '*';
        }
    }

    printf("%s",ss.str);

    free(arr);


}









