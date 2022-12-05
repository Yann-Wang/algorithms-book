#include <string>
#include <vector>
using namespace std;
vector<int> getNext(string& ms){
    int len = ms.size();
    vector<int> next(len);
    next[0]=-1;
    if(ms.size()==1)
        return next;
    next[1]=0;
    int pos=2;
    int cn=0;

    while(pos<len){
        if(ms[pos-1]==ms[cn]){
            next[pos++]=++cn;
        }
        else if(cn>0){
            cn= next[cn];
        }
        else{
            next[pos++] = 0;
        }
    }
    return next;

}


int getIndex(string &ss,string & ms){
    if(ms.size()<1 || ss.size()<ms.size()){
        return -1;
    }
    int si=0,mi=0;
    vector<int> next = getNext(ms);

    while(si<ss.size() && mi<ms.size()){
        if(ss[si]==ms[mi]){
            ++si;
            ++mi;
        }
        else if(next[mi]==-1){
            ++si;
        }
        else{
            mi=next[mi];
        }
    }

    return mi==ms.size() ? si-mi : -1;


}
