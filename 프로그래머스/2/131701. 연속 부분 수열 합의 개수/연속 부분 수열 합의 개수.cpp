#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

const int calSum(vector<int>& elements, int sumSize, int start)
{
    int sum = 0;
    int size = elements.size();
    
    for (int j = 0; j < sumSize; j++)
    {
        if (start + j >= size)
            sum += elements[start + j - size];
        else
            sum += elements[start + j];
    }
    
    return sum;
}

int solution(vector<int> elements) {
    int answer = 0;
    unordered_map<int, bool> totalSum;    
    
    int size = elements.size();
    for (int i = 0; i < size; i++)
    {        
        for (int sumSize = 1; sumSize < size; sumSize++)
        {
            totalSum[calSum(elements, sumSize, i)] = true;
        }
    }
    int sum = 0;
                
    for (int element : elements)
        sum += element;
                
    totalSum[sum] = true;
    
    answer = totalSum.size();
    
    return answer;
}