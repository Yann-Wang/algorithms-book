#include <iostream>

using namespace std;

unsigned int FindFirstBitIs1(int num){
    int indexBit  = 0;
    while(((num & 1)==0)&& (indexBit<8*sizeof(int))){
        num = num>>1;
        ++indexBit;
    }
    return indexBit;
}

bool IsBit1(int num,unsigned int indexBit){
    num = num >> indexBit;
    return (num & 1);
}

void FindNumsAppearOnce(int data[],int len,int * num1,int * num2){
    if(data == NULL || len < 2)
        return;
    int resultExclusiveOR = 0;
    for(int i=0;i<len;++i){
        resultExclusiveOR ^= data[i];
    }

    unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);
    *num1 = *num2 = 0;
    for(int j=0;j<len;++j){
        if(IsBit1(data[j],indexOf1))
            *num1 ^= data[j];
        else
            *num2 ^= data[j];
    }
}



int main()
{
    int arr[] = {2,4,3,6,3,2,5,5};
    int num1,num2;
    int len = 8;
    FindNumsAppearOnce(arr,len,&num1,&num2);
    cout << num1 << " "<< num2 << endl;
    return 0;
}
