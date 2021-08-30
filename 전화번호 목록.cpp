#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string, int> hash;
    
    for(int i=0;i<phone_book.size();i++){
        hash.insert(make_pair(phone_book[i], 1));
    }
    
    for(int i=0;i<phone_book.size();i++){
        for(int j=0;j<phone_book[i].size();j++){
            if(hash.find(phone_book[i].substr(0, j)) != hash.end()){
                return false;
            }
        }
    }
    return answer;
}
