#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<string, vector<pair<string, int> > > plane; 
vector<string> answer;
vector<string> route;
int ticket_size;
int finding = 0;

void dfs(int depth, string str){
    if(finding == 1) return;
    route[depth] = str;
    if(depth == ticket_size){
        finding = 1;
        return;
    }
    
    vector<pair<string, int> > list = plane[str];
    for(int i=0;i<plane[str].size();i++){
        if(plane[str][i].second != 0){
            plane[str][i].second = 0;
            dfs(depth + 1, plane[str][i].first);
            plane[str][i].second = 1;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
    ticket_size = tickets.size();
    route.assign(ticket_size + 1, "");
    for(int i=0;i<tickets.size();i++){
        if(plane.find(tickets[i][0]) == plane.end()){
            plane.insert(make_pair(tickets[i][0], vector<pair<string, int> >(1, make_pair(tickets[i][1], 1))));
        }
        else{
            plane[tickets[i][0]].push_back(make_pair(tickets[i][1], 1));
        }
    }
    
    for(map<string, vector<pair<string, int> > >::iterator i = plane.begin();i!=plane.end();i++){
        sort(i->second.begin(), i->second.end());
    }
    
    route[0] = "ICN";
    dfs(0, "ICN");
    return route;
}
