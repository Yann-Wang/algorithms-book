#include <iostream>
#include <vector>
#include <string>

using namespace std;

void shuffle(vector<string> & v){
    int n = v.size()-1;
    vector<string> v2(v.size());
    int i;
    for(i=1;i<=n;++i){
        v2[(i*2)%(n+1)]= v[i];
    }
    for(i=1;i<=n;++i){
        v[i]=v2[i];
    }
}

int main()
{
    vector<string> vv = {"","a1","a2","a3","a4","b1","b2","b3","b4"};

    shuffle(vv);
    for(int i=1;i<vv.size();++i){
        cout<< vv[i] << " ";
    }
    cout << endl;

    return 0;
}
