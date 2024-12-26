#include <string>
#include <vector>

using namespace std;

int digit(int num) {
    int sum = 0;
    while(num != 0){
        sum += num % 10;
        num /= 10;
    }
    
    return sum;
}

bool solution(int x) {
    bool answer = true;
    
    if (x % digit(x) != 0) answer = false;
    
    return answer;
}