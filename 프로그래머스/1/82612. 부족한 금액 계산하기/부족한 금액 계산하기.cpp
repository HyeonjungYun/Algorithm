using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    
    long long bill = 0;
    
    for (int i = 0 ; i < count; i++) {
        bill += price * (i + 1);
    }
    
    if (money - bill < 0) answer = bill - money;

    return answer;
}