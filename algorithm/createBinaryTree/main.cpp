#include <iostream>
#include <stack>

#include "createbt.h"

//using namespace std;


int btDeepth(BTNode *bt){
    if(bt == NULL)
        return 0;
    int LD = btDeepth(bt->left);
    int RD = btDeepth(bt->right);

    return LD>RD ? LD+1 : RD+1;
}



int main()
{
    //BTNode * btnode = new BTNode();
    // the data of binary tree in pre order
    vector<int> vpre = {1,2,4,5,7,3,6};
    vector<int> vin  = {4,2,7,5,1,3,6};
    int l1 =0, l2 = 0;
    int r1 = vpre.size()-1;
    int r2 = vin.size()-1;
    BTNode * btroot = createBinaryTree(vpre,vin,l1,r1,l2,r2);


    cout << btDeepth(btroot) << endl;
    return 0;
}
