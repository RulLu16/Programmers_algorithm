#include <string>
#include <vector>

using namespace std;

int hole = 0;

bool isOpen(vector<pair<int, int> > keyhole, vector<vector<int> > lock, int n){
    int m = lock.size();
    
    for(int i=-n+1;i<m;i++){
        for(int j=-n+1;j<m;j++){
            int fit = 0;
            int flag = 0;
            for(int k=0;k<keyhole.size();k++){
                int x = keyhole[k].first + i;
                int y = keyhole[k].second + j;
                
                if(x >= m || x<0 || y>=m || y<0) continue;
                
                if(lock[x][y] == 1) {
                    flag = 1;
                    break;
                }
                
                fit++;
            }
            
            if(fit == hole && flag == 0) return true;
        }
    }
    
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    
    for(int i=0;i<lock.size();i++){
        for(int j=0;j<lock.size();j++)
            if(lock[i][j] == 0) hole++;
    }
    
    vector<pair<int, int> > origin;
    vector<pair<int, int> > rotate1;
    vector<pair<int, int> > rotate2;
    vector<pair<int, int> > rotate3;
    
    int n = key.size();
    for(int i=0;i<key.size();i++){
        for(int j=0;j<key.size();j++){            
            if(key[i][j] == 1){
                origin.push_back(make_pair(i, j));
                rotate1.push_back(make_pair(j, n - 1 - i));
                rotate2.push_back(make_pair(n - 1 - i, n - 1 - j));
                rotate3.push_back(make_pair(n - 1 - j, i));
            }
        }
    }
    
    if(isOpen(origin, lock, n)) return true;
    if(isOpen(rotate1, lock, n)) return true;
    if(isOpen(rotate2, lock, n)) return true;
    if(isOpen(rotate3, lock, n)) return true;
    
    return false;
}
