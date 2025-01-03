#include <string>
#include <vector>
#include <cmath>

using namespace std;

int calAttack (int number, int limit, int power) {
    int count = 0;
    int n = (int)sqrt(number);
    
    for (int i = 1; i <= n; i++)
        if (number % i == 0) {
            count++;
            if (i * i != number) count++;
        }
    
    if (count > limit) return power;
    return count;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for (int i = 1; i <= number; i++) {
        answer += calAttack(i, limit, power);
    }
    
    return answer;
}