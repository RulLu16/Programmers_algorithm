#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int que_size = 0;
    priority_queue<int> max_heap;
    priority_queue<int> min_heap;
    
    for(int i=0;i<operations.size();i++){
        char command = operations[i][0];
        int num = stoi(operations[i].substr(2, operations[i].size() - 2));
        if(que_size == 0) {
            while(!max_heap.empty()) max_heap.pop(); 
            while(!min_heap.empty()) min_heap.pop();
        }
        if(operations[i][0] == 'I'){
            max_heap.push(num);
            min_heap.push(-num);
            que_size++;
        }
        else{
            if(num == 1 && !max_heap.empty()){
                max_heap.pop();
                que_size--;
            }
            else if(num == -1 && !min_heap.empty()){
                min_heap.pop();
                que_size--;
            }
        }
    }
    
    int max_v = 0; int min_v = 0;
    if(!max_heap.empty() && !min_heap.empty()){
        if(max_heap.top() > -min_heap.top()){
            max_v = max_heap.top();
            min_v = -min_heap.top();
        }
        else if(max_heap.top() == -min_heap.top() && que_size == 1){
            max_v = max_heap.top();
            min_v = max_v;
        }
    }
    answer.push_back(max_v);
    answer.push_back(min_v);
    
    return answer;
}
