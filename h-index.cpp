#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    
    for(int i=0;i<citations[citations.size() - 1];i++){
        int right = citations.size() - 1;
        int left = 0;
        int min_idx = right;
        
        while(left <= right){
            int mid = (right + left) / 2;
            if(citations[mid] >= i){
                right = mid - 1;
                if(min_idx > mid) min_idx = mid;
            }
            else{
                left = mid + 1;
            }
        }
        
        if(citations.size() - min_idx >= i && i > answer){
            answer = i;
        }
    }
    return answer;
}
