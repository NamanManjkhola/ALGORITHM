#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//huffman tree node
struct MinHeapNode{
    char data;
    int freq;
    MinHeapNode *left, *right;
    
    MinHeapNode(char d, int f){
        data = d;
        freq = f;
        left = right = NULL;
    }
};

struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};

void printCodes(struct MinHeapNode*root, string str){
    if(!root){
        return;
    }
    if(root->data != '$'){
        cout << root->data << " - " << str << endl;
    }
    printCodes(root->left, str+"0");
    printCodes(root->right, str+"1");
    
}

void huffman_coding(char data[], int freq[], int s){
    struct MinHeapNode *l, *r, *t;
    
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    
    //insert data into minHeap
    for(int i=0; i<s; i++){
        minHeap.push(new MinHeapNode(data[i],freq[i]));
    }
    
    while(minHeap.size() != 1){
        l = minHeap.top();
        minHeap.pop();
        
        r = minHeap.top();
        minHeap.pop();
        
        t = new MinHeapNode('$', l->freq+r->freq);
        t->left = l;
        t->right = r;
        
        minHeap.push(t);
    }
    printCodes(minHeap.top(), "");
}

int main()
{
    char data[] = {'a','b','c','d','e'};
    int freq[] = {3,5,6,4,2};
    
    int size = sizeof(freq)/sizeof(freq[0]);
    
    huffman_coding(data, freq, size);
    
    return 0;
}
