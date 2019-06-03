#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using std::string;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& ans) {
    for (size_t i = 0; i < ans.size(); ++i)
        std::cout << ans[i] << " ";
    std::cout << "\n";
}

std::vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    std::vector<int> ans;
    for (size_t i = 0; i + s.size() <= t.size(); ++i)
        if (t.substr(i, s.size()) == s)
            ans.push_back(i);
    return ans;
}

std::vector<int> get_occurrences_RabinKarp(const Data& input){
    std::vector<int> ans;
    const string& pat = input.pattern, txt = input.text;
    const int q = 101; // prime number
    const int d = 52; // 2*num of latin letters (2 because of upper and lower case)
    const int m = pat.length();
    const int n = txt.length();
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1;

    for (int i=0; i<m-1; i++)
        h = (h*d)%q;

    // Calculate the hash value of pattern and first text window
    for (int i = 0; i<m; i++){
        p = (d*p + pat[i])%q;
        t = (d*t + txt[i])%q;
    }

    // Slide the pattern and compare hash values
    for (int i=0; i<=n-m; i++){
        if (p==t){
            int j;
            for (j=0; j<m; j++){
                if (txt[i+j] != pat[j])
                    break;
            }

            if (j==m)
                ans.push_back(i);
        }

        if(i < n-m){
            t = ( d*(t-txt[i]*h) + txt[i+m] )%q;
            if (t<0)
                t=(t+q);
        }
    }

    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences_RabinKarp(read_input()));
    return 0;
}
