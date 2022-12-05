#include <iostream>
#include <vector>

using namespace std;

class BinarySearch {
    public:
      int getPos(vector<int> A, int n, int val) {
          // write code here
          int x = 0;
          int y = n;
          int m;
          while(x<y){
              m = x + (y-x)/2;
              if(val<=A[m]){
                  y = m;
              }else{
                  x = m+1;
              }
          }

          //return x;

          if(A[x] == val){ // �ж�A[x]�Ƿ����ΪҪ���ҵ�Ԫ��val
              return x;
          }

          return -1;
      }
};

int main()
{
    BinarySearch bs;
    vector<int> A = {1,3,5,7,9};

    cout << bs.getPos(A, 5, 2) << endl;
    return 0;
}
