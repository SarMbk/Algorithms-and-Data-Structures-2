#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

using std::vector;
using std::cin;
using std::cout;

class JobQueue {
    // first element is the earliest time that the thread is available, second element is the thread index
    typedef pair<long long, int> threadPair;

    private:
        int numThreads;
        vector<long long> jobs;
        vector<int> assignedThreads;
        vector<long long> startTimes;

        // Minimum priority queue, by default sorts based on first element of pair (i.e. by available time)
        priority_queue<threadPair, vector<threadPair>, greater<threadPair> > threadsPQ;


        void WriteResponse() const {
            for (int i = 0; i < jobs.size(); ++i) {
                cout << assignedThreads[i] << " " << startTimes[i] << "\n";
            }
        }


        void ReadData() {
            int numJobs;
            cin >> numThreads >> numJobs;
            jobs.resize(numJobs);
            startTimes.resize(numJobs);
            assignedThreads.resize(numJobs);
            for(int i = 0; i < numJobs; ++i)
                cin >> jobs[i];
        }


        void AssignJobs() {
            for (int i=0; i<numThreads; i++){
                threadsPQ.push(make_pair(0,i));
            }

            for(int i=0; i<jobs.size(); ++i){
                long long jobStartTime = threadsPQ.top().first;
                long long jobEndTime = jobStartTime + jobs[i];
                int jobThreadNumber = threadsPQ.top().second;
                threadsPQ.pop();
                threadsPQ.push(make_pair(jobEndTime, jobThreadNumber));
                startTimes[i] = jobStartTime;
                assignedThreads[i] = jobThreadNumber;
            }


        }

    public:
        void Solve() {
            ReadData();
            AssignJobs();
            WriteResponse();
        }

};

int main() {
    std::ios_base::sync_with_stdio(false);
    JobQueue job_queue;
    job_queue.Solve();
    return 0;
}
