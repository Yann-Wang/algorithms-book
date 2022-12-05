#ifndef CREATEBT_H_INCLUDED
#define CREATEBT_H_INCLUDED

#include <vector>
using namespace std;

class BTNode{
public:
    int data;
    BTNode * left;
    BTNode * right;
    BTNode():data(0),left(NULL),right(NULL){}
    ~BTNode(){
        delete left;
        delete right;
    }
};

BTNode * createBinaryTree(vector<int> & pre,vector<int> & in, int l1,int r1,int l2,int r2){
    BTNode *s;
    int i;
    if(l1>r1)
        return NULL;
    s = new BTNode();
    //s->left = s->right = NULL;
    s->data = pre[l1];

    for(i=l2;i<=r2;++i){
        if(in[i] == pre[l1]){
            break;
        }
    }

    s->left = createBinaryTree(pre,in,l1+1,l1+i-l2,l2,i-1);
    s->right= createBinaryTree(pre,in,l1+i-l2+1,r1,i+1,r2);

    return s;

}

#endif // CREATEBT_H_INCLUDED
