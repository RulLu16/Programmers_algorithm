#include <string>
#include <vector>

using namespace std;

int splitString(string s){
    int start = 0;
    int end = 0;
    
    if(s[0] == '(') start++;
    else end++;
    
    for(int i=1;i<s.size();i++){
        if(s[i] == '(') start++;
        else end++;
        
        if(start == end) return i;
    }
    
    return s.size();
}

int testString(string s){
    int stack = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == '(') stack++;
        else stack--;
        
        if(stack<0) return 0;
    }
    
    if(stack>0) return 0;
    
    return 1;
}

string getString(string u, string v){
    if(testString(u)){
        if(v.size() == 0) return u;
        
        int idx = splitString(v);
        string nextu = v.substr(0, idx + 1);
        string nextv = v.substr(idx+1, v.size());
        
        return u + getString(nextu, nextv);
    }
    
    string tmp = "(";
    if(v.size() == 0) tmp += ")";
    else {
        int idx = splitString(v);
        string nextu = v.substr(0, idx + 1);
        string nextv = v.substr(idx+1, v.size());
    
        tmp += getString(nextu, nextv);
        tmp += ")";
    }
    
    for(int i=1;i<u.size()-1;i++){
        if(u[i] == '(') tmp += ")";
        else tmp += "(";
    }
    
    return tmp;
}

string solution(string p) {
    string answer = "";
    
    if(p.size() == 0) return answer;
    if(testString(p)) return p;
    
    int idx = splitString(p);
    string u = p.substr(0, idx + 1);
    string v = p.substr(idx+1, p.size());
    
    answer = getString(u, v);
    return answer;
}
