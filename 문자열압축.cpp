#include <string>
#include <vector>

using namespace std;

int getSize(string s, int len){
    int idx = 0;
    int result = 0;
    
    while(1){
        if(idx > s.size()) break;
        
        string match = s.substr(idx, len);
        idx += len;
        if(match.size() < len) {
            result += match.size();
            break;
        }
        
        int num = 1;
        for(;idx<s.size();idx+=len){
            if(s.substr(idx, len) == match) {
                num++;
            }
            else {
                break;
            }
        }
        
        if(num == 1) {
            result += len;
        }
        else result += to_string(num).size() + len;
    }
    
    return result;
}

int solution(string s) {
    int answer = s.size();
    
    for(int i=1;i<=s.size()/2;i++){
        int compress = getSize(s, i);
        if(answer > compress)
            answer = compress;
    }
    return answer;
}
