#include<stdio.h>
#include<stdlib.h>

int getMinKthByBFPRT(int arr[],int length,int k);

int * getMinKNumsByBFPRT(int arr[],int length,int k){
    if(k<1 || k>length){
        return;
    }
    int minKth = getMinKthByBFPRT(arr,length,k);
    int *result = (int *)malloc(sizeof(int)*k);
    int index = 0;
    int i;
    for(i=0;i<length;++i){
        if(arr[i]<minKth){
            result[index++] = arr[i];
        }
    }

    while(index!=length){
        result[index++]= minKth;
    }

    return result;
}

int * copyArray(int arr[],int length);

int getMinKthByBFPRT(int arr[],int length,int k){
    int *copyArr = copyArray(arr,length);
    int res = select(copyArr,0,length-1,k-1);
    free(copyArr);
    return res;
}

int * copyArray(int arr[],int length){
    int *res = (int *)malloc(sizeof(int)*length);
    int i;
    for(i=0;i<length;++i){
        res[i] = arr[i];
    }
    return res;
}

int* partition(int arr[],int begin, int end, int pivotValue);

int select(int arr[],int begin, int end, int i){
    if(begin == end){
        return arr[begin];
    }
    int pivot = medianOfMedians(arr,begin,end);
    int *pivotRange = partition(arr,begin,end,pivot);
    if(i>=pivotRange[0] && i<=pivotRange[1]){
        return arr[i];
    }
    else if(i<pivotRange[0]){
        return select(arr,begin,pivotRange[0]-1,i);
    }
    else{
        return select(arr,pivotRange[1]+1,end,i);
    }
}

int medianOfMedians(int arr[],int begin,int end){
    int num = end - begin + 1;
    int offset = num % 5 == 0 ? 0 : 1;
    int mArr_len = num/5+offset;
    int *mArr = (int *)malloc(sizeof(int)*mArr_len);
    int i;
    int mm;
    for(i=0;i<mArr_len;++i){
        int beginI = begin + i*5;
        int endI = beginI + 4;
        mArr[i] = getMedian(arr,beginI,endI<end?endI:end);
    }

    mm = select(mArr,0,mArr_len-1,mArr_len/2);
    free(mArr);
    return mm;
}

void swap(int arr[],int a,int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int* partition(int arr[],int begin, int end, int pivotValue){
    int small = begin -1;
    int cur = begin;
    int big = end +1;
    while(cur != big){
        if(arr[cur]<pivotValue){
            swap(arr,++small,cur++);
        }
        else if(arr[cur]>pivotValue){
            swap(arr,cur,--big);
        }
        else{
            cur++;
        }
    }
    int range[2];
    range[0] = small + 1;
    range[1] = big - 1;
    return range;
}

void insertionSort(int arr[],int begin, int end);

int getMedian(int arr[],int begin, int end){
    insertionSort(arr,begin,end);
    int mid = (end+1)/2;
    return arr[mid];
}

void insertionSort(int arr[],int begin, int end){
    int i,j;
    for(i=begin+1;i<end+1;++i){
        for(j=i;j!=begin;--j){
            if(arr[j-1]>arr[j]){
                swap(arr,j-1,j);
            }
            else{
                break;
            }
        }
    }
}

void main(){
    int arr[8] = {2,5,3,4,1,7,8,6};
    int i;

    int len = 8;
    int k = 4;
    int *res = getMinKNumsByBFPRT(arr,len,k);

    for(i=0;i<k;++i){
        printf("%d ",res[i]);
    }
    printf("\n");

    free(res);
}
