#include<stdio.h>
#define len 5

typedef struct {
    int left;
    int right;
} segment;

void sortSeg(segment seg[]){
    int i,j;
    for(i=1;i<len;++i){
        segment temp = seg[i];
        j = i;
        while(j>0 && seg[j].left<seg[j-1].left){
            seg[j] = seg[j-1];
            --j;
        }
        seg[j] = temp;
    }
}

int getCoverLength(segment seg[]){
    int i,sumLen,L,R;
    sortSeg(seg);
    L = seg[0].left;
    R = seg[0].right;

    sumLen = R-L;
    for(i=1;i<len;++i){
        if(seg[i].left >= R){
            L = seg[i].left;
            R = seg[i].right;
            sumLen = sumLen + R-L;
        }
        else if(seg[i].left < R){
            if(seg[i].right > R){
                L = R;
                R = seg[i].right;
                sumLen= sumLen + R-L;
            }

        }
    }

    return sumLen;
}

void main(){
    int res;
    segment seg[len] = {{1,3},{3,4},{4,5},{2,6},{7,9}};

    res = getCoverLength(seg);

    printf("%d\n",res);
}
