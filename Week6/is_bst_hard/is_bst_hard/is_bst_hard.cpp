#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

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


void isBST(const vector<Node> &tree, int i, long min, long max, bool &flag){
    if(i==-1) return;
    if(tree[i].key < min || tree[i].key >= max){
        flag = false;
        return;
    }
    isBST(tree, tree[i].left, min, tree[i].key, flag);
    isBST(tree, tree[i].right, tree[i].key, max, flag);
}


bool IsBinarySearchTree(const vector<Node>& tree){
    long min = LONG_MIN, max = LONG_MAX;
    bool flag = true;
    if (tree.empty() || tree.size()==1)
        return flag;
    isBST(tree, 0, min, max, flag);
    return flag;
}


int main() {
    int nodes;
    cin >> nodes;
    vector<Node> tree;
    for (int i = 0; i < nodes; ++i) {
        long key;
        int left, right;
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
