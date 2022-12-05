#include <iostream>
#include <vector>
using namespace std;

void Reverse2(vector<int> &vv,int low,int high){
    int i=low,j=high;
    int temp;
    while(i<j){
        temp = vv[i];
        vv[i++] = vv[j];
        vv[j--] = temp;
    }
}

void partical_reverse(vector<int> &vv,int low,int mid,int high){
    Reverse2(vv,low,mid);
    Reverse2(vv,mid+1,high);
    Reverse2(vv,low,high);
}

void Reverse(vector<int> &vv,int low,int mid,int high){
    int leftPosStart=low;
    int rightNegEnd=mid+1;
    while(leftPosStart<=mid){
        if(vv[leftPosStart]>0)
            break;
        else
            ++leftPosStart;
    }

    while(rightNegEnd<=high){
        if(vv[rightNegEnd]>0){
            break;
        }
        else
            ++rightNegEnd;
    }

    if(leftPosStart<=mid && rightNegEnd!=mid+1){
        partical_reverse(vv,leftPosStart,mid,rightNegEnd-1);
    }
}

// time complex : O(nlgn)  space complex: O(lgn)

void posNegSort(vector<int> &vv,int low,int high){
    int i=low,j=high;
    int mid;
    if(low<high){
        mid=(low+high)/2;
        posNegSort(vv,low,mid);
        posNegSort(vv,mid+1,high);
        Reverse(vv,low,mid,high);
    }
}

int main()
{
    vector<int> vv = {-3,3,1,-1,-5,5};
    posNegSort(vv,0,vv.size()-1);
    for(auto m:vv){
        cout << m;
    }

    cout <<  endl;
    return 0;
}
