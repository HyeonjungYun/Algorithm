#include <string>
#include <vector>

using namespace std;

int rotation(vector<int*>& tmp)
{
    int size = tmp.size();
    int tmpLastNumber = *tmp[size - 1];
    int min = tmpLastNumber;
    
    for (int i = size - 2; i >= 0; i--)
    {
        if (*tmp[i] < min)
        {
            min = *tmp[i];
        }
        
        *tmp[i + 1] = *tmp[i];
    }
    
    *tmp[0] = tmpLastNumber;
    
    return min;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> numbers(rows, vector<int>(columns));
    
    int number = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            numbers[i][j] = number;
            number++;
        }
    }
    
    for (vector<int>& query : queries)
    {
        vector<int*> tmp;
        for (int i = query[1] - 1; i <= query[3] - 1; i++)
        {
            tmp.push_back(&numbers[query[0] - 1][i]);
        }
        for (int i = query[0]; i <= query[2] - 1; i++)
        {
            tmp.push_back(&numbers[i][query[3] - 1]);
        }
        for (int i = query[3] - 2; i >= query[1] - 1; i--)
        {
            tmp.push_back(&numbers[query[2] - 1][i]);
        }
        for (int i = query[2] - 2; i > query[0] - 1; i--)
        {
            tmp.push_back(&numbers[i][query[1] - 1]);
        }
        
        answer.push_back(rotation(tmp));
    }
    return answer;
}