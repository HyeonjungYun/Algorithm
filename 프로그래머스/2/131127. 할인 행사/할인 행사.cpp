#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

const bool check(unordered_map<string, int> wantList, const vector<string>& discount)
{
    for (string element : discount)
        wantList[element]--;
    
    for (auto pair : wantList)
        if (pair.second > 0) return false;
    
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> wantList;
    
    for (int i = 0; i < want.size(); i++)
        wantList[want[i]] = number[i];
    
    for (int i = 0; i <= discount.size() - 10; i++)
    {
        vector<string> tmp;
        for (int j = 0; j < 10; j++)
            tmp.push_back(discount[i + j]);
        
        if (check(wantList, tmp))
            answer++;
    }
    
    return answer;
}