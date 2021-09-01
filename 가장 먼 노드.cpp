#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> dis;
vector<int> visit;
vector<vector<int> > graph;

void getDistance(){
    priority_queue<pair<int, int> > que;
    dis[0] = 0; dis[1] = 0;
    que.push(make_pair(0, 1));
    
    while(!que.empty()){
        pair<int, int> now = que.top();
        que.pop();
        
        if(-now.first > dis[now.second]) continue;
        visit[now.second] = 1;
        
        for(int i=0;i<graph[now.second].size();i++){
            int next = graph[now.second][i];
            
            if(dis[next] > -now.first + 1){
                dis[next] = -now.first + 1;
                que.push(make_pair(-dis[next], next));
            }
        }
        
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    graph.assign(n+1, vector<int>());
    dis.assign(n+1, 20000);
    visit.assign(n+1, 0);
    
    for(int i=0;i<edge.size();i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    getDistance();
    
    sort(dis.begin(), dis.end());
    
    int max_v = dis[dis.size()-1];
    for(int i=dis.size()-2;i>0;i--){
        if(dis[i] < max_v) break;
        answer++;
    }
    
    return answer+1;
}
