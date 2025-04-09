#include <iostream>

using namespace std;

int main() 
{
    int N;
    cin >> N;

    while (N--)
    {
        int c[4];
        cin >> c[0] >> c[1] >> c[2] >> c[3];

        int result = -1;

        for (int tmp = c[2]; tmp <= c[0] * c[1]; tmp += c[0])
        {
            int y = tmp % c[1];
            if (y == 0) y = c[1];

            if (y == c[3])
            {
                result = tmp;
                break;
            }
        }

        cout << result << "\n";
    }
}