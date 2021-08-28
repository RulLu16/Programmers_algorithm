#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string temp = "";
    
    for(int i=0;i<new_id.length();i++){        
        if(new_id[i] >= 'A' && new_id[i] <= 'Z'){
            temp += new_id[i] - ('A' - 'a');
        }
        else if(new_id[i] >= 'a' && new_id[i] <= 'z'){
            temp += new_id[i];
        }
        else if(new_id[i] >= '0' && new_id[i] <= '9'){
            temp += new_id[i];
        }
        else if(new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.'){
            temp += new_id[i];
        }
    } // 기본 필요없는 문자들 제거
    
    int flag = 0;
    for(int i=0;i<temp.length();i++){
        if(temp[i] == '.'){
            if(flag > 0) continue;
            else flag++;
        }
        else flag = 0;
        
        answer += temp[i];
    } // 연속 마침표 제거
    
    if(answer[0] == '.') answer.erase(0, 1);
    if(answer[answer.length()-1] == '.') answer.erase(answer.length()-1, 1);
    
    if(answer.empty()) answer = "a";
    
    if(answer.length() >= 16) answer = answer.substr(0, 15);
    if(answer[answer.length()-1] == '.') answer.erase(answer.length()-1, 1);
    
    if(answer.length() <= 2){
        int idx = answer.length() - 1;
        for(int i=answer.length();i<3;i++){
            answer += answer[idx];
        }
    }
    
    return answer;
}
