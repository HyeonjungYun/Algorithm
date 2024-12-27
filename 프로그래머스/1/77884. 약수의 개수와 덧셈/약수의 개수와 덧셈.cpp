#include <string>
#include <vector>

using namespace std;

int find(int num) {
    int out = 0;
    
    for (int i = 1; i <= num; i++) 
        if (num % i == 0) out++;
    
    return out;
}

int solution(int left, int right) {
    int answer = 0;
    
    for (int i = left; i <= right; i++){
        int num = find(i);
        if (num % 2 == 0) answer += i;
        if (num % 2 == 1) answer -= i;
    }
    
    return answer;
}