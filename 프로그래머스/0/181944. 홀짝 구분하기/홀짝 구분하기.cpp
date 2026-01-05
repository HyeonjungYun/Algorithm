#include <iostream>

using namespace std;

bool isEven(const int& n)
{
    if (n % 2 == 0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int main(void) {
    int n;
    cin >> n;
    
    if (isEven(n))
    {
        cout << n << " is even";
    }
    else
    {
        cout << n << " is odd";
    }
}