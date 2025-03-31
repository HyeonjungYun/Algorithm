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

int main() 
{
    int N;
    cin >> N;
    int n;
    cin >> n;

    vector<vector<int>> computers(N + 1, vector<int>());
    queue<int> q;
    vector<bool> visited(N + 1, false);
    int count = 0;
    visited[1] = true;
    q.push(1);
    
    for (int i = 0; i < n; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        computers[tmp1].push_back(tmp2);
        computers[tmp2].push_back(tmp1);
    }

    for (int i = 1; i <= N; i++) {
        sort(computers[i].begin(), computers[i].end());
    }

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int next : computers[current])
        {
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
                count++;
            }
        }
    }

    cout << count;
}