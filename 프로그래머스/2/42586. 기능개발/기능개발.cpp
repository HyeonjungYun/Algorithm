#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int day = 1, index = 0;
    queue<int> proQueue;
    
    for (int progress : progresses)
        proQueue.push(progress);
    
    while(1)
    {
        int tempAnswer = 0;
        while (proQueue.front() + (speeds[index] * day) >= 100 && !proQueue.empty())
        {
            proQueue.pop();
            index++;
            tempAnswer++;
        }
        if (tempAnswer > 0) answer.push_back(tempAnswer);
        
        day++;
        
        if (proQueue.empty()) break;
    }
    
    return answer;
}