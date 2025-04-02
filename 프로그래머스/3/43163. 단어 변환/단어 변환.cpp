#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    if (find(words.begin(), words.end(), target) == words.end())
    {
        return 0;
    }
    
    queue<pair<string, int>> q;
    vector<bool> visited(words.size(), false);
    q.push({begin, 0});
    
    while(!q.empty())
    {
        auto [current, count] = q.front();
        q.pop();
        
        if (current == target)
        {
            return count;
        }
        
        for (string word : words)
        {
            int wrongCount = 0;
            for (int i = 0; i < current.length(); i++)
            {
                if (current[i] != word[i])
                {
                    wrongCount++;
                }
            }
            
            if (wrongCount == 1)
            {
                q.push({word, count + 1});
            }
        }
    }
    
    return 0;
}