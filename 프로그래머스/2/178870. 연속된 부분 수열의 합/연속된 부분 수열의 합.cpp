#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<int> pSum(sequence.size() + 1);
    pSum.push_back(0);
    int start = 0, end = 1, len = 9999999, ansStart, ansEnd;
    
    partial_sum(sequence.begin(), sequence.end(), pSum.begin() + 1);
    
    while(end < sequence.size() + 1)
    {
        int sum = pSum[end] - pSum[start];
        
        if (sum == k)
        {
            if (len > (end - start - 1))
            {
                len = (end - start - 1);
                ansStart = start;
                ansEnd = end - 1;
            }
            end++;
        }
        if (sum < k)
        {
            end++;
        }
        if (sum > k)
        {
            start++;
        }
    }
    
    answer.push_back(ansStart);
    answer.push_back(ansEnd);
    
    return answer;
}