#include <string>
#include <vector>
#include <iostream>

using namespace std;

void sort(vector<int> &tempArray) {
    for (int i = 0; i < tempArray.size(); i++) 
        for (int j = 0; j < tempArray.size() - 1; j++)
            if(tempArray[j] > tempArray[j+1]){
                int tmp = tempArray[j];
                tempArray[j] = tempArray[j+1];
                tempArray[j+1] = tmp;
            }
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (auto command : commands) {
        vector<int> tempArray;
        
        for (int i = command[0] - 1; i <= command[1] - 1; i++)
            tempArray.push_back(array[i]);
        
        sort(tempArray);
        
        answer.push_back(tempArray[command[2] - 1]);
    }
    
    return answer;
}