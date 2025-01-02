#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void sort(vector<int>& score) {
    for (int s : score) 
        for (int i = 0; i < score.size() - 1; i++)
            if (score[i] > score[i + 1]) {
                int tmp = score[i];
                score[i] = score[i + 1];
                score[i + 1] = tmp;
            }
}

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end());
    
    int len = score.size();
    
    for (int i = 1; i <= len / m; i++) {
        answer += score[len - i * m] * m;
    }
    
    return answer;
}