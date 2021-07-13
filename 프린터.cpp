#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pro;
    queue<int> que;

    for(int i=0;i<priorities.size();i++){
        pro.push(priorities[i]);
        que.push(priorities[i]);
    }

    while(1){

        if(que.front() == pro.top()){
            answer++;
            if(location == 0){
                break;
            }
            else{
                location--;
                que.pop();
                pro.pop();
            }
        }
        else{
            if(location == 0){
                location = que.size()-1;
            }
            else{
                location--;
            }
            que.push(que.front());
            que.pop();
        }
    }
    return answer;
}
