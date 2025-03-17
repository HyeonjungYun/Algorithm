#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    
    sort(data.begin(), data.end(), [&col](vector<int> tmp1, vector<int>tmp2){
        if(tmp1[col - 1] != tmp2[col - 1])
        {
            return tmp1[col - 1] < tmp2[col - 1];
        }
        else
        {
            return tmp1[0] > tmp2[0];
        }
    });
    
    for (int i = row_begin - 1; i <= row_end - 1; i++)
    {
        int sum = 0;
        for (const int& elem : data[i])
        {
            sum += elem % (i + 1);
        }
        
        answer = answer ^ sum;
    }
    
    return answer;
}