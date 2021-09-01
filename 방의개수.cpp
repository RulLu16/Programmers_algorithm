#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int xmove[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int ymove[8] = {0, 1, 1, 1, 0, -1, -1, -1};
map<string, vector<int> > visit;

int checkCross(int dir, int x, int y){
    if(dir != 1 && dir != 5 && dir != 7 && dir != 3) return 0;
            
    int crossx; int check1;
                
    if(dir == 1){
        crossx = 1; check1 = 7;
    }
    else if(dir == 3){
        crossx = -1; check1 = 5; 
    }
    else if(dir == 5){
        crossx = -1; check1 = 3;
    }
    else if(dir == 7){
        crossx = 1; check1 = 1; 
    }
                
    string tmp1 = to_string(x + crossx) + "," + to_string(y);
    if(visit.find(tmp1) != visit.end() && visit[tmp1][check1])
        return 1;
    
    return 0;
} 

int solution(vector<int> arrows) {
    int answer = 0;
    int x = 0; int y = 0;
    
    visit.insert(make_pair("0,0", vector<int>(8, 0)));
    for(int i=0;i<arrows.size();i++){
        string str = "";
        visit[to_string(x) + "," + to_string(y)][arrows[i]] = 1;
        
        x += xmove[arrows[i]];
        y += ymove[arrows[i]];
        str = to_string(x) + "," + to_string(y);
        int dir = (arrows[i] + 4) % 8;
        
        if(visit.find(str) == visit.end()){
            visit.insert(make_pair(str, vector<int>(8, 0)));
            visit[str][dir] = 1;
            
            answer += checkCross(arrows[i], x, y);
        }
        else {
            if(visit[str][dir] == 0){
                visit[str][dir] = 1;
                answer++;
                
                answer += checkCross(arrows[i], x, y);
            }
        }
    }
    return answer;
}
