#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while(storey > 0)
    {
        int tmp = storey % 10;
        int next = (storey / 10) % 10;
        
        if (tmp > 5 || (tmp == 5 && next >= 5))
        {
            storey += 10 - tmp;
        }
        
        storey /= 10;
        
        answer += min (tmp, 10 - tmp);
    }
    
    return answer;
}