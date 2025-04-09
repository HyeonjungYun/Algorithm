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

    vector<int> life(N);
    vector<int> pain(N);

    for (int i = 0; i < N; i++)
    {
        cin >> life[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> pain[i];
    }

    int maxJoy = 0;
    int total = 1 << N;

    for (int mask = 0; mask < total; mask++)
    {
        int sumL = 0, sumJ = 0;

        for (int i = 0; i < N; i++)
        {
            if (mask & (1 << i))
            {
                sumL += life[i];
                sumJ += pain[i];
            }
        }

        if (sumL < 100)
        {
            maxJoy = max(maxJoy, sumJ);
        }
    }

    cout << maxJoy;
}