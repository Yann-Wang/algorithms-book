#include <iostream>
#include <vector>
using namespace std;

int minPathSumInMatrix(vector<vector<int>> & vv){
    int i,j;
    int row = vv.size();
    int col = vv[0].size();
    vector<vector<int>> pathSum(row,vector<int>(col,0));

    int k;

    pathSum[0][0] = vv[0][0];

    for(i=1;i<col;++i){
        pathSum[0][i] = pathSum[0][i-1] + vv[0][i];
    }
    for(j=1;j<row;++j){
        pathSum[j][0] = pathSum[j-1][0] + vv[j][0];
    }

    for(i=1;i<col;++i){
        for(j=1;j<row;++j){
            k = pathSum[i][j-1]>pathSum[i-1][j] ? pathSum[i-1][j] : pathSum[i][j-1];
            pathSum[i][j] = k + vv[i][j];
        }
    }

    return pathSum[row-1][col-1];
}


int main()
{
    vector<vector<int>> vv = { {1,3,5,9},{8,1,3,4},{5,0,6,1},{8,8,4,0}};
    cout << minPathSumInMatrix(vv) << endl;
    return 0;
}
