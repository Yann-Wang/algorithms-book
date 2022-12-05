#include<stdio.h>

void adjust(int arr[],int low,int high){
    int i=low,j=2*i+1;
    int temp =arr[i];
    while(j<=high){
        if(j<high && arr[j]<arr[j+1]){
            ++j;
        }
        if(arr[i]<arr[j]){
            arr[i] = arr[j];
            i=j;
            j=2*i+1;
        }
        else{
            break;
        }
    }
    arr[i] = temp;
}

void heapSort(int arr[],int n){
    int i,temp;
    for(i=n/2;i>=0;--i){
        adjust(arr,i,n);
    }

    for(i=n;i>=0;--i){
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        adjust(arr,0,i-1);
    }
}

void main(){
    int arr[8] = {2,5,3,4,1,7,8,6};
    int i;

    heapSort(arr,7);

    for(i=0;i<8;++i){
        printf("%d ",arr[i]);
    }
}
