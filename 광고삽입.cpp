#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    vector<long> viewer;
    
    long play_second = stol(play_time.substr(0, 2)) * 3600 + stol(play_time.substr(3, 2)) * 60 + stol(play_time.substr(6, 2));
    viewer.assign(play_second + 1, 0);
    
    for(long i=0;i<logs.size();i++){
        long start = stol(logs[i].substr(0, 2)) * 3600 + stol(logs[i].substr(3, 2)) * 60 + stol(logs[i].substr(6, 2));
        long end = stol(logs[i].substr(9, 2)) * 3600 + stol(logs[i].substr(12, 2)) * 60 + stol(logs[i].substr(15, 2));
        
        for(long j=start;j<end;j++){
            viewer[j]++;
        }
    }
    
    long ad = stol(adv_time.substr(0, 2)) * 3600 + stol(adv_time.substr(3, 2)) * 60 + stol(adv_time.substr(6, 2));
    long sum = 0;
    long idx = 0;
    for(long i=0;i<ad;i++){
        sum += viewer[i];
    }
    
    long max_sum = sum;
    for(long i=ad;i<play_second;i++){
        sum = sum - viewer[i - ad] + viewer[i];
        if(sum > max_sum){
            max_sum = sum;
            idx = i - ad + 1;
        }
    }
    
    string hour = to_string(idx / 3600);
    string min = to_string((idx % 3600) / 60);
    string sec = to_string(idx % 60);
    
    if(hour.size() == 1) hour = "0" + hour;
    if(min.size() == 1) min = "0" + min;
    if(sec.size() == 1) sec = "0" + sec;
    
    answer = hour + ":" + min + ":" + sec;
    return answer;
}
