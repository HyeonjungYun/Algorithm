#include <string>
#include <vector>

using namespace std;
int currentAlp(char tmp)
{
    if (tmp == 'A') return 1;
    if (tmp == 'E') return 2;
    if (tmp == 'I') return 3;
    if (tmp == 'O') return 4;
    if (tmp == 'U') return 5;
}

int calNumber(char tmp, int index)
{
    if (index == 0) return 1 + (currentAlp(tmp) - 1) * 781;
    if (index == 1) return 1 + (currentAlp(tmp) - 1) * 156;
    if (index == 2) return 1 + (currentAlp(tmp) - 1) * 31;
    if (index == 3) return 1 + (currentAlp(tmp) - 1) * 6;
    if (index == 4) return currentAlp(tmp);
    
}
int solution(string word) {
    int answer = 0;
    
    for (int i = 0; i < word.size(); i++)
        answer += calNumber(word[i], i);
    
    return answer;
}