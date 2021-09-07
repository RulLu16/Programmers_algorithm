#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<map<string, int> > list;
    
    list.assign(10001, map<string, int>());
    
    for(int i=0;i<words.size();i++){
        int word_s = words[i].size();
        
        string start = words[i];
        string end = words[i];
        for(int j=0;j<word_s;j++){
            
            start[j] = '?';
            end[word_s - 1 - j] = '?';
            
            if(list[word_s].find(start) == list[word_s].end()){
                list[word_s].insert(make_pair(start, 1));
            }
            else list[word_s][start]++;
            if(j != word_s - 1){
                if(list[word_s].find(end) == list[word_s].end()){
                    list[word_s].insert(make_pair(end, 1));
                }
                else list[word_s][end]++;
            }
        }
        
        list[word_s].insert(make_pair(words[i], 1));
    }
    
    for(int i=0;i<queries.size();i++){
        int query_len = queries[i].size();
        
        if(list[query_len].find(queries[i]) == list[query_len].end()){
            answer.push_back(0);
            continue;
        }
        
        answer.push_back(list[query_len][queries[i]]);
    }
    
    return answer;
}
