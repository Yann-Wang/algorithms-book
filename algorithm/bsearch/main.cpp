#include <iostream>
#include <vector>

using namespace std;

int bsearch(vector<int>& A,int x,int y, int v){
    int m;
    while(x<y){
        m = x + (y-x)/2;
        if(v == A[m]){
            return m;
        }
        else if(v < A[m]){
            y = m;
        }
        else{
            x = m+1;
        }
    }

    return -1;
}


int main()
{
    vector<int> vv={0,1,2,3,4,5,5,5,6,7,8};
    int len = vv.size();
    cout << bsearch(vv,0,len,5) << endl;
    return 0;
}
