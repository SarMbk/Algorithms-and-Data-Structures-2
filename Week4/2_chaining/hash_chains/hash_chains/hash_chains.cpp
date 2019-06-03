#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;


struct Query {
    string type, s;
    size_t ind;
};


class QueryProcessor {
    int bucket_count;
    vector<list<string> > hashTable;


    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }


public:

    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {
        hashTable.resize(bucket_count);
    }


    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }


    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }


    void processQuery(const Query& query){
        // Process "add" queries
        if(query.type == "add"){
            size_t hashIndex = hash_func(query.s);
            list<string>::iterator it;
            it = find(hashTable[hashIndex].begin(), hashTable[hashIndex].end(),query.s);
            if (it == hashTable[hashIndex].end())
                hashTable[hashIndex].push_front(query.s);
        }

        // Process "del" queries
        else if (query.type == "del"){
            size_t hashIndex = hash_func(query.s);
            hashTable[hashIndex].remove(query.s);
        }

        // Process "find" queries
        else if (query.type == "find"){
            size_t hashIndex = hash_func(query.s);
            list<string>::iterator it;
            it = find(hashTable[hashIndex].begin(), hashTable[hashIndex].end(), query.s);
            writeSearchResult(it != hashTable[hashIndex].end());
        }

        // Process "check" queries
        else if(query.type == "check"){
            list<string>::iterator it;
            for (it = hashTable[query.ind].begin(); it != hashTable[query.ind].end(); ++it)
                cout << *it << " ";
            cout << '\n';
        }
    }


    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};



int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
