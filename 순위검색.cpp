#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<string, vector<int> > submit;

vector<string> split(string input, char delimiter) {
    vector<string> result;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        result.push_back(temp);
    }
 
    return result;
}

void setMap(){
    string language[4] = {"cpp","java","python","-"};
    string position[3] = {"backend", "frontend","-"};
    string career[3] = {"junior","senior","-"};
    string soulfood[3] = {"chicken","pizza","-"};
    
    for(int a=0; a<4; a++) {
        for(int b=0; b<3; b++) {
            for(int c=0; c<3; c++) {
                for(int d=0; d<3; d++) {
                    submit.insert(make_pair(language[a]+position[b]+career[c]+soulfood[d], vector<int>()));
                }
            }
        }
    }
}

int findNum(vector<int> v, int target){
    int right = v.size() - 1;
    int left = 0;
    int idx = right;
    
    if(target > v[v.size() - 1]) return 0;
    
    while(left <= right){
        int mid = (right + left) / 2;
        
        if(v[mid] >= target){
            right = mid - 1;
            if(mid < idx) idx = mid;
        }
        else{
            left = mid + 1;
        }
    }
    
    return v.size() - idx;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for(int i=0;i<info.size();i++){
        vector<string> person = split(info[i], ' ');
        
        submit[person[0] + person[1] + person[2] + person[3]].push_back(stoi(person[4]));
        submit["-" + person[1] + person[2] + person[3]].push_back(stoi(person[4]));
        submit[person[0] + "-" + person[2] + person[3]].push_back(stoi(person[4]));
        submit[person[0] + person[1] + "-" + person[3]].push_back(stoi(person[4]));
        submit[person[0] + person[1] + person[2] + "-"].push_back(stoi(person[4]));
        submit["--" + person[2] + person[3]].push_back(stoi(person[4]));
        submit["-" + person[1] + "-" + person[3]].push_back(stoi(person[4]));
        submit["-" + person[1] + person[2] + "-"].push_back(stoi(person[4]));
        submit[person[0] + "--" + person[3]].push_back(stoi(person[4]));
        submit[person[0] + "-" + person[2] + "-"].push_back(stoi(person[4]));
        submit[person[0] + person[1] + "--"].push_back(stoi(person[4]));
        submit["---" + person[3]].push_back(stoi(person[4]));
        submit["-" + person[1] + "--"].push_back(stoi(person[4]));
        submit["--" + person[2] + "-"].push_back(stoi(person[4]));
        submit[person[0] + "---"].push_back(stoi(person[4]));
        submit["----"].push_back(stoi(person[4]));
    }
    
    for(map<string, vector<int>>::iterator i = submit.begin(); i != submit.end();i++){
        sort(i->second.begin(), i->second.end());
    }
    
    for(int i=0;i<query.size();i++){
        vector<string> options = split(query[i], ' ');
        
        vector<int> scores = submit[options[0] + options[2] + options[4] + options[6]];
        if(scores.size() == 0) answer.push_back(0);
        else {
            answer.push_back(findNum(scores, stoi(options[7])));
        }
    }
    
    return answer;
}
