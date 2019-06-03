#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
    private:
        vector<int> data_;
        vector< pair<int, int> > swaps_;

        int Parent(int i){
            return (i-1)/2;
        }

        int LeftChild(int i){
            return 2*i+1;
        }

        int RightChild(int i){
            return 2*i+2;
        }

        void SiftDown(int i){
            int L = LeftChild(i);
            int R = RightChild(i);
            int smallest;
            if(L<data_.size() && data_[L]<data_[i])
                smallest = L;
            else
                smallest = i;
            if (R<data_.size() && data_[R]<data_[smallest])
                smallest = R;
            if(smallest != i){
                std::swap(data_[i], data_[smallest]);
                swaps_.push_back(make_pair(i, smallest));
                SiftDown(smallest);
            }
        }

        void WriteResponse() const {
            cout << swaps_.size() << "\n";
                for (int i = 0; i < swaps_.size(); ++i) {
                  cout << swaps_[i].first << " " << swaps_[i].second << "\n";
                }
        }

        void ReadData() {
            int n;
            cin >> n;
            data_.resize(n);
            for(int i = 0; i < n; ++i)
                cin >> data_[i];
        }

        void GenerateSwaps() {
            swaps_.clear();
            int n = data_.size();
            for (int i=n/2; i>=0; i--){
                SiftDown(i);
            }
        }

    public:
        void printheap(){
            for(int i=0; i<data_.size(); i++){
                cout << data_[i] << " ";
            }
            cout << "\n";
        }

        void Solve() {
            ReadData();
            GenerateSwaps();
            WriteResponse();
        }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    HeapBuilder heap_builder;
    heap_builder.Solve();
    return 0;
}
