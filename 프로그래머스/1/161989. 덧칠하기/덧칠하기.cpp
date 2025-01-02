#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0, len = section.size();
    
    int i = 0;
    while(i < len) {
        answer++;
        if (section[len - 1] - section[i] < m) break;
        
        for (int j = i; j < len; j++) {
            if (section[j] - section[i] >= m) {
                i = j;
                break;
            }
        }
    }
    
    return answer;
}