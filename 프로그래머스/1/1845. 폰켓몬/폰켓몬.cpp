#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> s;
    int numsSize = nums.size();
    
    for(int i : nums)
    {
        s.insert(i);
    }
    if (s.size() > numsSize/2)
    {
        answer = numsSize/2;
    }
    else
    {
        answer = s.size();
    }
    return answer;
}