#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<bool> v(n + 1);
    v[1] = true;
    
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (v[i]) continue;
        
        for (int j = i + i; j <= n; j += i)
            v[j] = true;
    }
    
    for(int i = 2; i <= n; i++)
        if (!v[i]) answer++;
    
    return answer;
}