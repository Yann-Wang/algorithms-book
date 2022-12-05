#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> slideWindowMaximum(vector<int> & vv, int slideSize){
    deque<int> q;
    int len = vv.size();
    int wlen = len-slideSize+1;
    vector<int> wmax;
    int i;
    if(len>=slideSize && slideSize>=1){
        for(i=0;i<slideSize;++i){
            while(!q.empty() && vv[i] >= vv[q.back()])
                q.pop_back();
            q.push_back(i);
        }

        for(i=slideSize;i<len;++i){
            wmax.push_back(vv[q.front()]);
            while(!q.empty() && vv[i] >= vv[q.back()])
                q.pop_back();
            if(!q.empty() && q.front() <= i-slideSize)
                q.pop_front();
            q.push_back(i);
        }

        wmax.push_back(vv[q.front()]);
    }

    return wmax;
}


int main()
{
    vector<int> vv ={4,3,5,4,3,3,6,7};
    vector<int> wmax = slideWindowMaximum(vv,3);
    for(auto wm:wmax){
        cout << wm << " ";
    }
    cout << endl;
    return 0;
}
