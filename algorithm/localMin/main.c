#include <stdio.h>
#include <stdlib.h>

/*
A[1...n] A[1]>A[2] A[n-1]<A[n] «Û¬˙◊„A[i-1]>A[i]<A[i+1]µƒi
*/

int LocalMin(int arr[],int low,int high,int *c){
    int m;


    while(low<=high){
        m = (low+high)/2;
        ++*c;
        if(arr[m]<arr[m-1] && arr[m]<arr[m+1]){
            return m;
        }
        else if(arr[m]<arr[m-1] && arr[m]>arr[m+1]){
            low = m+1;
        }
        else{
            high = m-1;
        }
    }

    return -1; // ≤È’“ ß∞‹
}

int main()
{
    int arr[] ={10,9,8,7,6,5,4,3,2,1,12};
    int len = 11;
    int count = 0;
    int i = LocalMin(arr,0,len-1,&count);

    printf("%d\n%d\n",i,count);
    return 0;
}
