#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<pair<string, int> > sorting;
    
    for(int i=0;i<numbers.size();i++){
        string tmp = to_string(numbers[i]);
        int size = tmp.size();
        for(int j=size;j<4;j++){
            tmp += to_string(numbers[i]);
        }
        
        sorting.push_back(make_pair(tmp.substr(0, 4), i));
    }
    
    sort(sorting.begin(), sorting.end());
    
    for(int i=sorting.size()-1;i>=0;i--){
        answer += to_string(numbers[sorting[i].second]);
    }
    
    if(answer[0] == '0') return "0";
    
    return answer;
}
