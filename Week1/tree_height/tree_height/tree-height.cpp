#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;


class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};


int get_height(Node *n){
    if (n == NULL) return 0;
    else{
        int d = 0;
        for (int i=0; i<n->children.size(); i++){
            d= max(d, get_height(n->children[i]));
        }
        return 1+d;
    }
}


int main_with_large_stack_space() {
    // Code for inputting the nodes of the tree
    std::ios_base::sync_with_stdio(0);
    int n;
    std::cin >> n;

    std::vector<Node> nodes;
    nodes.resize(n);
    for (int child_index = 0; child_index < n; child_index++) {
        int parent_index;
        std::cin >> parent_index;
        if (parent_index >= 0)
            nodes[child_index].setParent(&nodes[parent_index]);
        nodes[child_index].key = child_index;
    }


    // first find the root of the tree
    int maxHeight = 0;
    int i = 0;
    for (i=0; i<n; i++){
        if (nodes[i].parent==NULL)
            break;
    }

    // Then implement the function
    maxHeight = get_height(&nodes[i]);
    std::cout << maxHeight << std::endl;
    return 0;
}



// I don't understand what this means
int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }

#endif
  return main_with_large_stack_space();
}
