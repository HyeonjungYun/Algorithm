#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int N;
vector<int> nums;
int op[4];

int max_val = INT_MIN;
int min_val = INT_MAX;

void backtracking(int index, int current) 
{
    if (index == N) 
    {
        if (current > max_val)
        {
            max_val = current;
        }

        if (current < min_val)
        {
            min_val = current;
        }

        return;
    }

    for (int i = 0; i < 4; i++) 
    {
        if (op[i] > 0) 
        {
            op[i]--;

            int next_value = current;
            if (i == 0)
            {
                next_value += nums[index];
            }
            else if (i == 1)
            {
                next_value -= nums[index];
            }
            else if (i == 2)
            {
                next_value *= nums[index];
            }
            else if (i == 3) 
            {
                if (next_value < 0)
                {
                    next_value = -(abs(next_value) / nums[index]);
                }
                else
                {
                    next_value /= nums[index];
                }
            }

            backtracking(index + 1, next_value);
            op[i]++;
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }

    for (int i = 0; i < 4; i++)
    {
        cin >> op[i];
    }

    backtracking(1, nums[0]);

    cout << max_val << endl << min_val;
}
