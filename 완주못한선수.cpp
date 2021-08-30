#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> hashmap;
    for(int i=0;i<completion.size();i++){
        if(hashmap.find(completion[i]) == hashmap.end())
            hashmap.insert(make_pair(completion[i], 1));
        else hashmap[completion[i]]++;
    }
    
    for(int i=0;i<participant.size();i++){
        if(hashmap.find(participant[i]) == hashmap.end()){
            answer = participant[i];
            return answer;
        }
        else if(hashmap[participant[i]] == 0){
            answer = participant[i];
            return answer;
        }
        else{
            hashmap[participant[i]]--;
        }
    }
    return answer;
}
