#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int idx = 0;
    int answer_idx = -1;
    int days = 0;
    
    for(int idx=0;idx<progresses.size();idx++){
        int remain = 100 - progresses[idx] - speeds[idx]*days;
        if(remain <= 0){
            answer[answer_idx]++;
            continue;
        }
        answer.push_back(1);
        answer_idx++;
        days += ceil((float)remain/speeds[idx]);
    }
    return answer;
}
