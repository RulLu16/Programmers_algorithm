#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int> > floyd;
    
    floyd.assign(n+1, vector<int>(n+1, 0));
    
    for(int i=0;i<results.size();i++){
        floyd[results[i][1]][results[i][0]] = 1;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(floyd[j][k] == 0 && floyd[j][i] + floyd[i][k] == 2){
                    floyd[j][k] = 1;
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        int win=0; int lose=0;
        for(int j=1;j<=n;j++){
            if(floyd[i][j] > 0) lose++;
            if(floyd[j][i] > 0) win++;
        }
        
        if(lose + win == n-1) answer++;
    }
    return answer;
}
