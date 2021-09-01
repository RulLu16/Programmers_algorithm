#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<long long> que;
    for(int i=0;i<scoville.size();i++){
        que.push(-scoville[i]);
    }
    
    while(1){
        if(-que.top() >= K) break;
        if(que.size() == 1) return -1;
        
        long long first = -que.top(); que.pop();
        long long second = -que.top(); que.pop();
        
        answer++;
        que.push(-(first + second*2));
    }
    
    return answer;
}
