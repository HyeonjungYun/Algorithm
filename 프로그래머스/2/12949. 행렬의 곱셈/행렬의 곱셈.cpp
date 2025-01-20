#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    int arr2Col = 0;
    for (int row = 0; row < arr1.size(); row++)
    {
        vector<int> temp;
          for (int col = 0; col < arr2[0].size(); col++)  
          {
              int tempNumber = 0;
              for (int i= 0; i< arr1[0].size(); i++)
              {
                  tempNumber += arr1[row][i] * arr2[i][col];
              }
              temp.push_back(tempNumber);
          }
        answer.push_back(temp);
    }
    
    return answer;
}