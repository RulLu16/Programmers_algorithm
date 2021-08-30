#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> closet;
    
    for(int i=0;i<clothes.size();i++){
        if(closet.find(clothes[i][1]) == closet.end()){
            closet.insert(make_pair(clothes[i][1], 1));
        }
        else{
            closet[clothes[i][1]]++;
        }
    }
    
    for(map<string, int>::iterator i = closet.begin(); i!=closet.end();i++){
        answer *= i->second + 1;
    }
    
    return answer-1;
}
