#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time, idx;
    priority_queue<pair<int, int> > schedule; // first = 길이, second = 시점
    
    sort(jobs.begin(), jobs.end());
    schedule.push(make_pair(-jobs[0][1], -jobs[0][0]));
    time = jobs[0][0];
    idx = 1;
    while(1){
        if(!schedule.empty()){
            time -= schedule.top().first;
            answer += time + schedule.top().second;
            schedule.pop();
            
            for(;idx<jobs.size();idx++){
                if(jobs[idx][0] > time){
                    break;
                }
                schedule.push(make_pair(-jobs[idx][1], -jobs[idx][0]));
            }
        }
        else{
            if(idx == jobs.size()) break;
            
            time = jobs[idx][0];
            schedule.push(make_pair(-jobs[idx][1], -jobs[idx][0]));
            idx++;
        } // 하드가 비었을 때
        
    }
    return answer / jobs.size();
}
