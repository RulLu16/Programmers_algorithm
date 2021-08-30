#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    priority_queue<pair<int, string> > que;
    map<string, vector<int> > hash; // 장르, 고유번호
    
    for(int i=0;i<genres.size();i++){
        if(hash.find(genres[i]) == hash.end()){
            hash.insert(make_pair(genres[i], vector<int>()));
            hash[genres[i]].push_back(i);
        }
        else{
            hash[genres[i]].push_back(i);
        }
    }
    
    for(map<string, vector<int> >::iterator i = hash.begin();i!=hash.end();i++){
        int sum = 0;
        for(int j=0;j<i->second.size();j++){
            sum += plays[i->second[j]];
        }
        que.push(make_pair(sum, i->first));
    }
    
    while(!que.empty()){
        pair<int, string> g = que.top();
        que.pop();
        
        priority_queue<pair<int, int> > songs;        
        vector<int> list = hash[g.second];
        
        for(int i=0;i<list.size();i++){
            
            songs.push(make_pair(plays[list[i]], -list[i]));
        }
        
        for(int i=0;i<2;i++){
            if(!songs.empty()){
                pair<int, int> s = songs.top();
                songs.pop();
            
                answer.push_back(-s.second);
            }
            else break;
        }
    }
   
    return answer;
}
