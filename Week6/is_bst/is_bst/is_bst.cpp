#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};


const int MAXINT = 2147483647;
const int MININT =-2147483648;


bool isBST(const vector<Node> &tree, int i, int min, int max){
    if(i==-1) return true;
    if(tree[i].key < min || tree[i].key > max)
        return false;
    return
        isBST(tree, tree[i].left, min, tree[i].key-1) &&
        isBST(tree, tree[i].right, tree[i].key+1, max);
}


bool IsBinarySearchTree(const vector<Node>& tree){
    if (tree.empty() || tree.size()==1) return true;
    return isBST(tree, 0, MININT, MAXINT);
}


int main() {
    int nodes;
    cin >> nodes;
    vector<Node> tree;
    for (int i = 0; i < nodes; ++i) {
        int key, left, right;
        cin >> key >> left >> right;
        tree.push_back(Node(key, left, right));
    }
    if (IsBinarySearchTree(tree)) {
        cout << "CORRECT" << endl;
    } else {
        cout << "INCORRECT" << endl;
    }
    return 0;
}
