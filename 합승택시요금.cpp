#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int> > graph[201];

int getDistance(int n, int s, int e){
    vector<int> dis;
    vector<int> visit;
    priority_queue<pair<int, int> > que;
    
    dis.assign(n+1, (n * (n-1) / 2) * 100000);
    dis[s] = 0;
    visit.assign(n+1, 0);
	que.push(make_pair(0, s));
	
	while(!que.empty()){
		pair<int, int> now = que.top();
		que.pop();
		
		if(-now.first > dis[now.second]) continue;
		
		visit[now.second] = 1;
        if(now.second == e) return dis[now.second];
		
		int size = graph[now.second].size();
		for(int i=0;i<size;i++){
			if(graph[now.second][i].first){
				int nextNode = graph[now.second][i].second;
				
				if(dis[nextNode] > -now.first + graph[now.second][i].first){
					dis[nextNode] = -now.first + graph[now.second][i].first;
					que.push(make_pair(-dis[nextNode], nextNode));
				}
			}
		}
	}
    
    return (n * (n-1) / 2) * 100000;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = (n * (n-1) / 2) * 100000;
    
    for(int i=0;i<fares.size();i++){
        graph[fares[i][0]].push_back(make_pair(fares[i][2], fares[i][1]));
        graph[fares[i][1]].push_back(make_pair(fares[i][2], fares[i][0]));
    }
    
    for(int i=1;i<=n;i++){
        int price = getDistance(n, s, i) + getDistance(n, i, a) + getDistance(n, i, b);
        if(price < answer) answer = price;
    }
    
    
    return answer;
}
