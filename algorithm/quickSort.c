#include<stdio.h>

void quickSort(int arr[],int m,int n){

    int temp = arr[m];
    int i=m,j=n;
    while(i<j){
        while(j>i && arr[j]>temp){
            --j;
        }
        if(j>i){
            arr[i] = arr[j];
        }
        while(i<j && arr[i]<temp){
            ++i;
        }
        if(i<j){
            arr[j] = arr[i];
        }
    }
    arr[i] = temp;
    quickSort(arr,m,i-1);
    quickSort(arr,i+1,n);
}

void main(){
    int arr[8] = {2,5,3,4,1,7,8,6};
    int i;
    quickSort(arr,0,7);

    for(i=0;i<8;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
