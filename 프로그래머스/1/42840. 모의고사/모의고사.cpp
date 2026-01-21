#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> n1 = {1,2,3,4,5};
    vector<int> n2 = {2,1,2,3,2,4,2,5};
    vector<int> n3 = {3,3,1,1,2,2,4,4,5,5};
    vector<int> ansNum(3, 0);
    
    for (int i = 0; i < answers.size(); ++i)
    {
        if (answers[i] == n1[i % n1.size()])
        {
            ++ansNum[0];
        }
        if (answers[i] == n2[i % n2.size()])
        {
            ++ansNum[1];
        }
        if (answers[i] == n3[i % n3.size()])
        {
            ++ansNum[2];
        }
    }
    
    int max = *max_element(ansNum.begin(), ansNum.end());
    for (int i = 0; i < 3; ++i)
    {
        if (max == ansNum[i])
        {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}