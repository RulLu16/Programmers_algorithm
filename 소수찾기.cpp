#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <iostream>

using namespace std;

vector<int> visit;
map<string, int> strmap;
int answer = 0;

int isPrime(long num){
    if(num == 0 || num == 1) return 0;
    for(int i=2;i<=sqrt(num);i++){
        if(num % i == 0) return 0;
    }
    
    return 1;
}

void brute(int depth, string str){
    if(depth != 0 && strmap.find(str) == strmap.end()){
        strmap.insert(make_pair(str, 1));
        if(isPrime(stoi(str)) == 1) answer++;
    }
    
    for(int i=0;i<10;i++){
        if(visit[i] > 0){
            if(i == 0 && depth == 0) continue;
            visit[i]--;
            brute(depth + 1, str + (char)(i + '0'));
            visit[i]++;
        }
    }
}

int solution(string numbers) {
    visit.assign(10, 0);
    for(int i=0;i<numbers.size();i++){
        visit[numbers[i] - '0']++;
    }
    
    brute(0, "");
    return answer;
}
