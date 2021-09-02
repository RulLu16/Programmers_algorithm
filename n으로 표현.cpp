#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int getNN(int N, int idx) { 
    int result = N; 
    for (int i = 1; i <= idx; i++) { 
        result = result * 10 + N; 
    } 
    
    return result; 
}


int solution(int N, int number) {
    int answer = 0;
    vector<unordered_set<int> > dp(8);
    
    if(N == number) return 1;
    
    dp[0].insert(N);
    for(int k=1;k<8;k++){
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){ // k개 이전 숫자들을 순회하면서 조합
                if (i + j + 1 != k) continue;
                for(int a : dp[i]){
                    for(int b : dp[j]){
                        dp[k].insert(a + b);
                        if(a - b > 0)
                            dp[k].insert(a-b);
                        dp[k].insert(a*b);
                        if(a/b > 0)
                            dp[k].insert(a/b);
                    }
                }
            }
        }
        dp[k].insert(getNN(N, k));
        
        if(dp[k].count(number)) return k+1;
    }
    
    return -1;
}
