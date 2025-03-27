#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

int total_count;

void dfs(int idx, vector<int>& numbers, int sum, int target)
{
    if (idx == numbers.size())
    {
        if (sum == target)
        {
            total_count++;
        }
        return;
    }
    
    dfs(idx + 1, numbers, sum + numbers[idx], target);
    dfs(idx + 1, numbers, sum - numbers[idx], target);
}

int solution(vector<int> numbers, int target) {
    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    if (sum == target || sum == -target)
    {
        return 1;
    }
    
    total_count = 0;
    dfs(0, numbers, 0, target);
    
    return total_count;
}