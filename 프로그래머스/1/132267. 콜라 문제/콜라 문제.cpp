#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    while(n >= a) {
        int add = b * (n / a);
        answer +=  add;
        n = add + (n % a);
    }
    
    return answer;
}