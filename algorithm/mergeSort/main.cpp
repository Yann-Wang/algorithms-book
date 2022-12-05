#include <iostream>
#include <vector>

using namespace std;

void Merge(vector<int> &vv,int low,int mid,int high){
    int i=low,j=mid+1,k=0;
    vector<int> v2(high-low+1);
    while(i<=mid && j<=high){
        if(vv[i]<=vv[j])
            v2[k++] = vv[i++];
        else
            v2[k++] = vv[j++];
    }
    while(i<=mid)
        v2[k++] = vv[i++];
    while(j<=high)
        v2[k++] = vv[j++];
    for(i=low,k=0;i<=high;++i,++k)
        vv[i] = v2[k];
}

void MergeSort(vector<int> &vv){
    int itv=1,low,mid,high;
    int len = vv.size();
    while(itv<=len-1){
        low=0;
        while(low+itv<=len-1){
            mid = low+itv-1;
            high = mid+itv;
            if(high>len-1)
                high = len-1;
            Merge(vv,low,mid,high);
            low = high+1;
        }
        itv *= 2;
    }
}

int main()
{
    vector<int> vv = {4,-5,0,3,-1,12,9,-7,8,-4,11};
    MergeSort(vv);
    for(auto v:vv)
        cout << v << " ";
    cout<< endl;
    return 0;
}
