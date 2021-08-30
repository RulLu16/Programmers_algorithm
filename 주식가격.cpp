#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<pair<int, int> > jusik;
    answer.assign(prices.size(), 0);
    prices.push_back(0);
    
    for(int i=0;i<prices.size();i++){
        if(jusik.empty()){
            jusik.push(make_pair(prices[i], i));
            continue;
        }
        pair<int, int> cur = jusik.top();
        
        if(cur.first > prices[i]){
            while(!jusik.empty() && cur.first > prices[i]){
                answer[cur.second] = i - cur.second;
                if(i == prices.size() - 1) answer[cur.second]--;
                jusik.pop();
                cur = jusik.top();
            }   
            
        }
        jusik.push(make_pair(prices[i], i));
    }
    return answer;
}
