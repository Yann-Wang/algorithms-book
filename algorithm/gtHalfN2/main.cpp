#include <iostream>
#include <vector>

using namespace std;

int getGTHalfNum(vector<int> & vv){
    int candidate = vv[0];
    int times = 1;

    for(int i=1;i<vv.size();++i){
        if(times == 0){
            candidate = vv[i];
            ++times;
        }
        else if(candidate == vv[i]){
            ++times;
        }
        else{
            --times;
        }
    }
    return candidate;
}

int main()
{
    vector<int> vv={0,1,2,1,1};
    cout << getGTHalfNum(vv) << endl;
    return 0;
}
