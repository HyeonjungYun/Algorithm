#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    
    int size = citations.size();
    for (int i = 0; i < size; i++)
    {
        cout << citations[i] << " ";
        if (size - i <= citations[i])
        {
            answer = size - i;
            break;
        }
    }  
    
    return answer;
}