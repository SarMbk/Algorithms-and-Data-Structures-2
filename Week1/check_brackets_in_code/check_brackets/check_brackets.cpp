#include <iostream>
#include <stack>
#include <string>
#include <stack>

using namespace std;

// Define a data structure for a bracket that will contain index and type
struct Bracket{
    Bracket(char type, int index):
        type(type),
        index(index)
    {}
    char type;
    int index;
};


void isBalanced(string &s){
    stack<Bracket> stk;

    // pass through all characters in a string
    for (size_t i=0; i<s.size(); i++){
        // push all opening brackets in a stack
        if (s[i]=='{' || s[i]=='[' || s[i]=='('){
            Bracket br(s[i], i+1);
            stk.push(br);
        }

        // if you see a closing bracket
        else if (s[i]=='}' || s[i]==']' || s[i]==')') {
            // if the stack is empty, then up to this point string was balanced
            // and the wrong bracket is the one you're currently at
            if (stk.empty()){
                cout << i+1 << endl;
                return;
            }

            // otherwise compare the current bracket with the one on top of the stack
            // if the current one doesn't match, then the current one is wrong
            Bracket br = stk.top();
            stk.pop();
            if ( (br.type=='(' && s[i] !=')' ) || (br.type=='{' && s[i] !='}' ) ||(br.type=='[' && s[i] !=']' ) ){
                cout << i+1 << endl;
                return;
            }
        }
    }

    // In the end if the stack is empty then the string is balanced
    if (stk.empty())
        cout << "Success"<< endl;

    // Otherwise the bracket on top of the stack is the wrong one
    else
        cout << stk.top().index << endl;
    return;
}


int main() {
    stack<char> s;
    std::string text;
    getline(std::cin, text);
    isBalanced(text);
    return 0;
}

