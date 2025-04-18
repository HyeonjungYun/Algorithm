#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

bool checkManhatan(vector<string>& place, int row, int cell)
{
    queue<pair<pair<int, int>, int>> q;
    
    q.push({{row, cell}, 0});
    place[row][cell] = 'O';
    
    while(!q.empty())
    {
        auto [current, count] = q.front();
        q.pop();
        
        if (place[current.first][current.second] == 'P')
        {
            cout << current.first << " " << current.second << "\n";
            place[row][cell] = 'P';
            return true;
        }
        
        if ((current.first - 1 >= 0 && place[current.first - 1][current.second] != 'X') && count <=1)
        {
            q.push({{current.first - 1, current.second}, count + 1}); 
        }
        if ((current.first + 1 <= 4 && place[current.first + 1][current.second] != 'X') && count <=1)
        {
            q.push({{current.first + 1, current.second}, count + 1}); 
        }
        if ((current.second - 1 >= 0 && place[current.first][current.second - 1] != 'X')&& count <=1)
        {
            q.push({{current.first, current.second - 1}, count + 1}); 
        }
        if ((current.second + 1 < 4 && place[current.first][current.second + 1] != 'X')&& count <=1)
        {
            q.push({{current.first, current.second + 1}, count + 1}); 
        }
    }
    place[row][cell] = 'P';
    return false;
}

bool checkDistancing(vector<string>& place)
{
    for (int row = 0; row < 5; row++)
    {
        for (int cell = 0; cell < 5; cell++)
        {
            if (place[row][cell] == 'P')
            {
                if (checkManhatan(place, row, cell))
                {
                    return false;
                }
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (vector<string> place : places)
    {
        if (checkDistancing(place))
        {
            answer.push_back(1);
        }
        else
        {
            answer.push_back(0);
        }
    }
    
    return answer;
}