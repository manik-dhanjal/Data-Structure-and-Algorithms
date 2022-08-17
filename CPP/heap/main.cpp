#include <iostream>
#include <vector>
using namespace std;
void displayHeap(vector<int> &heap){
    int count = 1;
    for(int i=0;i<heap.size();i++){
        if(i+1==count){
            cout<<endl;
            count*=2;
        }
        cout<<heap[i]<<" ";
    }
}
void insert(vector<int> &heap, int value){
    heap.push_back(value);
    int curNode = heap.size()-1;
    int curPar = curNode/2;
    while(heap[curPar]<value&&curNode!=0){
        // displayHeap(heap);
        // cout<<heap[curPar];
        heap[curNode] = heap[curPar];
        curNode = curPar;
        curPar = curNode/2;
    }
    heap[curNode] = value;
}
int pop(vector<int> &heap){
    int temp = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    int parNode = 0;
    int childNode = parNode*2+2;
    if(heap[parNode*2+1]>heap[parNode*2+2]){
        childNode = parNode*2+1;
    }
    while(childNode>parNode){
        heap[parNode] = heap[childNode];
        parNode = childNode;
        if(heap[parNode*2+1]>heap[parNode*2+2]){
            childNode = parNode*2+1;
        }else{
            childNode = parNode*2+2;
        }
    }
    return temp;
}
int main(){
    vector<int> heap={20,10};
    // insert(heap,10);
    // insert(heap,20);
    insert(heap,15);
    insert(heap,30);
    insert(heap,40);
    displayHeap(heap);
    for(int i=0;i<heap.size();i++){
        cout<<pop(heap)<<" ";
    }
    return 0;
}