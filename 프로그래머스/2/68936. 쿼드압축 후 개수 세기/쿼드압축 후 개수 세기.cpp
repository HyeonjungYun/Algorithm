#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int log2(const int& x)
{
    return (int)(log(x) / log(2));
}

bool checkQuad (int startRow, int startCol, int quadSize, const vector<vector<int>>& arr, vector<vector<bool>>& bArr)
{
    if (bArr[startRow][startCol]) return false;
    
    int checkNum = arr[startRow][startCol];
    
    for (int row = 0; row < quadSize; row++)
        {
            for (int col = 0; col < quadSize; col++)
            {
                if (checkNum != arr[startRow + row][startCol + col])
                    return false;
            }
        }
    
    for (int row = 0; row < quadSize; row++)
        {
            for (int col = 0; col < quadSize; col++)
            {
                bArr[startRow + row][startCol + col] = true;
            }
        }
    
    return true;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    vector<vector<bool>> bArr(arr.size(), vector<bool>(arr.size(), false));
    
    int size = arr.size();
    for (int i = 0; i <= log2(size); i++)
    {
        int quadSize = size / pow(2, i);
        
        for (int j = 0; j < pow(2, i); j++)
        {
            for (int k = 0; k < pow(2, i); k++)
            {
                if(checkQuad (j * quadSize, k * quadSize, quadSize, arr, bArr))
                {
                    answer[arr[j * quadSize][k * quadSize]]++;
                }
            }
        }
        
    }
    
    return answer;
}