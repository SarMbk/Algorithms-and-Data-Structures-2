#include <iostream>
#include <queue>
#include <vector>
using namespace std;


// Request structure definition
struct Request {
    Request(int arrival_time, int process_time):
        arrival_time(arrival_time),
        process_time(process_time)
    {}

    int arrival_time;
    int process_time;
};


// Response structure definition
struct Response {
    Response(bool dropped, int start_time):
        dropped(dropped),
        start_time(start_time)
    {}

    bool dropped;
    int start_time;
};


// Buffer class definition
class Buffer {

public:
    // Constructor
    Buffer(int size):
        size_(size),
        finish_time_()
    {}

    // Process method definition
    Response Process(const Request &request) {      
        // Create a blank response
        Response response(false, 0);

        // Condition for dequeueing the requests
        if (request.arrival_time >= finish_time_.front() && !finish_time_.empty())
            finish_time_.pop();

        // If the queue is full, then drop the request
        if (finish_time_.size()==size_ && request.arrival_time < finish_time_.back()){
            //cout << "true 2" << endl;
            response.dropped==true;
            response.start_time=-1;
        }

        // If the queue is empty take the request
        else if ( finish_time_.empty()){
            int request_fin_time = request.arrival_time + request.process_time;
            finish_time_.push(request_fin_time);
            response.start_time = request.arrival_time;
            response.dropped = false;
        }

        // If the queue is not empty but also not full, take the request
        else if ( finish_time_.size() < size_ ){
            response.start_time = finish_time_.back();
            response.dropped = false;
            int request_fin_time = finish_time_.back() + request.process_time;
            finish_time_.push(request_fin_time);
        }
        return response;
    }

private:
    int size_;
    std::queue <int> finish_time_;
};



std::vector <Request> ReadRequests() {
    std::vector <Request> requests;
    int count;
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        int arrival_time, process_time;
        std::cin >> arrival_time >> process_time;
        requests.push_back(Request(arrival_time, process_time));
    }
    return requests;
}



std::vector <Response> ProcessRequests(const std::vector <Request> &requests, Buffer *buffer) {
    std::vector <Response> responses;
    for (int i = 0; i < requests.size(); ++i)
        responses.push_back(buffer->Process(requests[i]));
    return responses;
}



void PrintResponses(const std::vector <Response> &responses) {
    for (int i = 0; i < responses.size(); ++i)
        std::cout << (responses[i].dropped ? -1 : responses[i].start_time) << std::endl;
}



int main() {
    int size;
    std::cin >> size;
    std::vector <Request> requests = ReadRequests();

    Buffer buffer(size);
    std::vector <Response> responses = ProcessRequests(requests, &buffer);

    PrintResponses(responses);
    return 0;
}
