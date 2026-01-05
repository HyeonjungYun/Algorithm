#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<int> arr;
    
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            arr.push_back(numbers[i] + numbers[j]);
        }
    }
    
    sort(arr.begin(), arr.end());
    
    auto newEnd = unique(arr.begin(), arr.end());
    for (auto it = arr.begin(); it != newEnd; ++it)
    {
        answer.push_back(*it);
    }
    return answer;
}