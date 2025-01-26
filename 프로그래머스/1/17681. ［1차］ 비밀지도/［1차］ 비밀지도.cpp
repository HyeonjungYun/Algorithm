#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int size = arr1.size();
    
    for (int i = 0; i < size; i++)
    {
        int num = arr1[i] | arr2[i];
        string tmp = "";
        
        
        for (int i = 0; i < size; i++)
        {
            int bit = num & 1;
            
            if (bit == 1) tmp += '#';
            else tmp += ' ';
            num = num >> 1;
        }
        
        reverse(tmp.begin(), tmp.end());
        answer.push_back(tmp);
    }
    return answer;
}