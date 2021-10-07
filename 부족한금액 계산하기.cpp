using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    
    long long need = (long long)count*(count+1) / 2 * price;
    
    answer = need - money;
    if(answer < 0) answer = 0;

    return answer;
}
