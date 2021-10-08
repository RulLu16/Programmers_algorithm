#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int> > visit;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<pair<int, int> > bfs(vector<vector<int> > pan, int mode, int x, int y){
    vector<pair<int, int> > tmp;
    queue<pair<int, int> > que;
    que.push(make_pair(x, y));
    visit[x][y] = 1;
    tmp.push_back(make_pair(x, y));
    
    while(!que.empty()){
        int cx = que.front().first;
        int cy = que.front().second;
        que.pop();
        
        for(int i=0;i<4;i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx < 0 || nx >= pan.size() || ny < 0 || ny >= pan.size())
                continue;
            
            if(visit[nx][ny] == 0 && pan[nx][ny] == mode){
                visit[nx][ny] = 1;
                que.push(make_pair(nx, ny));
                tmp.push_back(make_pair(nx, ny));
            }
        }
    }
    
    return tmp;
}

vector<vector<pair<int, int> > > getShape(vector<vector<int> > pan, int mode){
    vector<vector<pair<int, int> > > tmp;
    visit.assign(pan.size(), vector<int>(pan.size(), 0));
    
    for(int i=0;i<pan.size();i++){
        for(int j=0;j<pan.size();j++){
            if(visit[i][j] == 0 && pan[i][j] == mode){
                tmp.push_back(bfs(pan, mode, i, j));
            }
        }
    }
    
    return tmp;
}

int fullfill(vector<pair<int, int> > board, vector<pair<int, int> > block){
    sort(board.begin(), board.end());
    sort(block.begin(), block.end());
    
    int board_x = board[0].first; int board_y = board[0].second;
    int block_x = block[0].first; int block_y = block[0].second;
    
    for(int i=0;i<board.size();i++){
        if(board[i].first - board_x != block[i].first - block_x || board[i].second - board_y != block[i].second - block_y)
            return 0;
    }
    
    return 1;
}

int isFit(vector<pair<int, int> > board, vector<pair<int, int> > block, int s){
    if(board.size() != block.size()) return 0;
    
    vector<pair<int, int> > rotate1;
    vector<pair<int, int> > rotate2;
    vector<pair<int, int> > rotate3;
    
    for(int i=0;i<block.size();i++){
        int x = block[i].first;
        int y = block[i].second;
        
        rotate1.push_back(make_pair(y, s - 1 - x));
        rotate2.push_back(make_pair(s - 1 - x, s - 1 - y));
        rotate3.push_back(make_pair(s - 1 - y, x));
    }
    
    if(fullfill(board, block)) return 1;
    if(fullfill(board, rotate1)) return 1;
    if(fullfill(board, rotate2)) return 1;
    if(fullfill(board, rotate3)) return 1;
    
    return 0;    
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    vector<vector<pair<int, int> > > board;
    vector<vector<pair<int, int> > > block;
    
    board = getShape(game_board, 0);
    block = getShape(table, 1);
    
    for(int i=0;i<board.size();i++){
        int idx = -1;
        for(int j=0;j<block.size();j++){
            if(isFit(board[i], block[j], table.size())){
                idx = j;
                break;
            }
        }
        
        if(idx >= 0){
            answer += board[i].size();
            block.erase(block.begin() + idx);
        }
    }
    
    return answer;
}
