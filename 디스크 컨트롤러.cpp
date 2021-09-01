#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time, idx;
    priority_queue<pair<int, int> > schedule; // first = ����, second = ����
    
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
        } // �ϵ尡 ����� ��
        
    }
    return answer / jobs.size();
}
