#include <iostream>
#include <vector>

using namespace std;

//when key exists, return the position after the last position

int Upper_bound(vector<int> &A,int x,int y,int v){
    int m;
    while(x<y){
        m = x + (y-x)/2;
        if(v >= A[m])
            x=m+1;
        else
            y=m;
    }
    return x;
}

int main()
{
    vector<int> A={0,1,2,3,4,5,5,5,6,7,8};
    int len = A.size();
    cout << Upper_bound(A,0,len,5) << endl;
    return 0;
}
