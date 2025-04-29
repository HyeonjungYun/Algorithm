#include <string>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

vector<int> Collatz(int k)
{
    vector<int> out;
    out.push_back(k);
    
    while(k != 1)
    {
        if (k % 2 == 0)
        {
            k /= 2;
            out.push_back(k);
        }
        else if (k % 2 == 1)
        {
            k = (k * 3) + 1;
            out.push_back(k);
        }
    }
    
    return out;
}

vector<double> calArea(vector<int> values)
{
    vector<double> out;
    out.push_back(0.0f);
    for (int i = 1; i < values.size(); i++)
    {
        double area = (double)(values[i - 1] + values[i]) / 2;
        out.push_back(area);
    }
    return out;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    vector<int> values = Collatz(k);
    vector<double> areas = calArea(values);
    int n = values.size() - 1;
    
    for (vector<int>& range : ranges)
    {
        if (range[1] <= 0)
        {
            range[1] = n + range[1];
        }
        if (range[0] == range[1])
        {
            answer.push_back(0.0f);
            continue;
        }
        if (range[0] > range[1])
        {
            answer.push_back(-1.0f);
            continue;
        }
        
        double sum = 0.0f;
        for (int i = min(range[0], range[1]) + 1; i <= max(range[0], range[1]); i++)
        {
            sum += areas[i];
        }
        
        answer.push_back(sum);
    }
    
    return answer;
}