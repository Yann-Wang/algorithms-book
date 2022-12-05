#include <iostream>

#include<vector>
using namespace std;

int main(){
      int d,i;
      vector<int> vv;


      while(cin >> d){
      	vv.push_back(d);
      }

      int sum=vv[0];
      int max=vv[0];
      int len = vv.size();
      for(i=1;i<len;++i){
            sum += vv[i];
            max = max > sum ? max : sum;
      	if(sum <0){
        	sum = 0;
        }
      }

      cout << max << endl;

	return 0;
}
