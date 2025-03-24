#include <string>
#include <map>
#include <queue>
#include <numeric>
#include <algorithm>
#include <set>
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int N;
vector<vector<int>> v;
vector<bool> team;
int min_val = INT_MAX;

void backtracking(int index, int count) 
{
    if (count == N / 2)
    {
        int start = 0, link = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (team[i] && team[j])
                {
                    start += v[i][j] + v[j][i];
                }
                if (!team[i] && !team[j])
                {
                    link += v[i][j] + v[j][i];
                }
            }
        }

        min_val = min(min_val, abs(start - link));
        return;
    }

    for (int i = index; i < N; i++)
    {
        if (!team[i])
        {
            team[i] = true;
            backtracking(i + 1, count + 1);
            team[i] = false;
        }
    }
}

int main() 
{
    cin >> N;

    v.assign(N, vector<int>(N));
    team.assign(N, false);
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> v[i][j];
        }
    }

    backtracking(0, 0);

    cout << min_val;
}
