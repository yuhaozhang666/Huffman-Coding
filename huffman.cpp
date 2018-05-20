//
//  huffman.cpp
//  PA1
//
//  Created by Yuhao Zhang on 4/16/18.
//  Copyright © 2018 Yuhao Zhang. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int bits = 0;

class node {
public:
    int value;
    int freq;
    node *left;
    node *right;
    
    node() {
        left = NULL;
        right = NULL;
    }
    
    node(int v, int f, node *l, node *r) {
        value = v;
        freq = f;
        left = l;
        right = r;
    }
};

class comparison {
public:
    bool operator() (const node *a, const node *b){
        return a->freq > b->freq;
    }
};

class huffman {
private:
    priority_queue<node*, vector<node*>, comparison> que;
    node *root;
    // static int bits;
    
public:
    void readInput(int ASC, int freq) {
        node *n = new node(ASC, freq, NULL, NULL);
        que.push(n);
    }
    
    void generateHuffmanTree() {
        if (que.size() == 1) {
            root = que.top();
            que.pop();
        }
        while (que.size() > 1) {
            node *fst = que.top();
            que.pop();
            node *snd = que.top();
            que.pop();
            node *parent = new node(-1, fst->freq + snd->freq, fst, snd);
            que.push(parent);
            root = parent;
        }
    }
    
    void saveCode(const char *filename) {
        ofstream os(filename);
        generateHuffmanCode(root, "", os);
    }
    
    void generateHuffmanCode(node *treeRoot, string str, ostream &os) {
        if (!treeRoot)
            return;
        if (treeRoot->value != -1) {
            bits = bits + treeRoot->freq * (int) str.length();
            os << treeRoot->value << "    " << str << endl;
        }
        generateHuffmanCode(treeRoot->left, str + "0", os);
        generateHuffmanCode(treeRoot->right, str + "1", os);
    }
};

int main(int argc, const char * argv[]) {
    huffman h;
    int ASC;
    int freq;
    while (cin >> ASC) {
        cin >> freq;
        h.readInput(ASC, freq);
    }
    h.generateHuffmanTree();
    h.saveCode("codewords.txt");
    cout << bits << endl;
    return 0;
}
