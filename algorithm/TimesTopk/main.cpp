#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Node {
public:
    string str;
    int times;
    Node():str(""),times(0){}
    Node(const Node & node):str(node.str),times(node.times){}
    Node(string s,int t){
        str = s;
        times = t;
    }
};

void swap(vector<Node>& heap,int parent,int index){
    Node node(heap[parent]);
    heap[parent] = heap[index];
    heap[index] = node;
}

void adjust(vector<Node> & heap ,int low,int high){
    int i=low,j=2*i+1;
    Node node = heap[i];
    while(j<=high){
        if(j<high && heap[j].times>heap[j+1].times){
            ++j;
        }
        if(heap[i].times>heap[j].times){
            heap[i] = heap[j];
            i=j;
            j= 2*i+1;
        }
        else
            break;
    }

    heap[i] = node;
}

void heapInsert(vector<Node> & heap,int index){
    while(index !=0){
        int parent = (index-1)/2;
        if(heap[index].times < heap[parent].times){
            swap(heap,parent,index);
            index = parent;
        }
        else{
            break;
        }

    }
}

void printTopKAndRank(vector<string> & ss,int topk){
    if(ss.size()<1 || topk<1)
        return;

    unordered_map<string, int> mapp;
    for(int i=0;i!=ss.size();++i){
        string cur = ss[i];
        if(mapp.find(cur) == mapp.end()){
            mapp[cur] = 1;
        }
        else{
            ++mapp[cur];
        }
    }

    vector<Node> heap(topk);
    int index =0;
    for(auto &m : mapp){
        Node node(m.first,m.second);
        if(index != topk){
            heap[index] = node;
            heapInsert(heap,index++);
        }
        else{
            if(heap[0].times<node.times){
                heap[0] = node;
                adjust(heap,0,topk);
            }
        }
    }
    //this time heap has already been incremental.


    for(int i=heap.size()-1;i>=0;--i){
        cout << "No."<< i+1 << " : " << heap[i].str << ", times: " << heap[i].times << endl;
    }

}

int main()
{
    vector<string> vv{"1","2","3","1"};
    printTopKAndRank(vv,2);
    //cout << "Hello world!" << endl;
    return 0;
}
