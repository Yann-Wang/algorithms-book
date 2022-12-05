#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
    int left;
    int right;
} segment;

bool sortByLeft(segment seg1,segment seg2){
    return seg1.left <seg2.left;
}

int getSegmentLen(vector<segment> seg){
    int i,L,R,sumLen;
    sort(seg.begin(),seg.end(),sortByLeft);

    sumLen = seg[0].right - seg[0].left;
    L = seg[0].left;
    R = seg[0].right;

    for(i=1;i<seg.size();++i){
        if(seg[i].left >= R){
            L = seg[i].left;
            R = seg[i].right;
            sumLen = sumLen + R-L;
        }
        else
        {
            if(seg[i].right > R){
                L = R;
                R = seg[i].right;
                sumLen = sumLen + R-L;
            }
        }
    }
    return sumLen;
}

int main()
{
    vector<segment> seg ={{1,3},{3,4},{4,5},{2,6},{7,9}};

    int sumLen = getSegmentLen(seg);

    cout << sumLen << endl;
    return 0;
}
