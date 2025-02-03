#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) 
{
    int answer = 0, size = topping.size();
    vector<int> front(size, 0);
    vector<int> back(size, 0);
    unordered_map<int, int> kind;
    
    
    for(int i = 0; i < size; i++)
    {
        kind[topping[i]] = 1;
        front[i] = kind.size();
    }
    
    kind.clear();
    
    for(int i = size - 1; i >= 0; i--)
    {
        kind[topping[i]] = 1;
        back[i] = kind.size();
    }
    
    for (int i = 0; i < size - 1; i++)
        if (front[i] == back[i + 1])
            answer++;
    
    return answer;
}