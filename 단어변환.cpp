#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int min_v = 51;

void dfs(string cur, string target, map<string, int> hash, int depth){
    if(cur == target){
        if(depth < min_v) min_v = depth;
        return;
    }
    
    for(int i=0;i<cur.size();i++){
        for(int j=0;j<26;j++){
            string tmp = cur.substr(0, i) + (char)(j + 'a') + cur.substr(i+1, cur.size()- 1 - i);
            
            if(hash.find(tmp) != hash.end() && hash[tmp] != 0){
                hash[tmp]--;
                dfs(tmp, target, hash, depth+1);
                hash[tmp]++;
            }
        }
    }
    
    return;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    map<string, int> hash;
    
    for(int i=0;i<words.size();i++){
        hash.insert(make_pair(words[i], 1));
    }
    
    if(hash.find(target) == hash.end()){
        return 0;
    }
    
    dfs(begin, target, hash, 0);
    return min_v;
}
