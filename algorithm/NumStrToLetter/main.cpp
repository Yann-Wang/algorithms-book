#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool withNextToLetter(string &ss, int i){
    if( (ss[i] == '1' && ss[i+1]>='0' && ss[i+1]<='9') || (ss[i] == '2' && ss[i+1]>='0' && ss[i+1]<='6') ){
        return true;
    }
}

int NumStrToLetter(string & ss){
    int i=0;
    int len = ss.size();
    vector<int> vv(len);
    vv[len-1]= 1;
    if(withNextToLetter(ss,len-2)){
        vv[len-2] = 2;
    }

    for(i=len-3;i>=0;--i){
        if(withNextToLetter(ss,i)){
            vv[i] = vv[i+1] +vv[i+2];
        }
        else
            vv[i] = vv[i+1];

    }

    return vv[0];

}

int main()
{
    string str = "1111";
    //cout << str.size() << endl;
    cout << NumStrToLetter(str) << endl;
    return 0;
}
