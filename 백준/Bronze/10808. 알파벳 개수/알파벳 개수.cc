#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    vector<int> alp(26, 0);

    string in;
    cin >> in;

    for (char& a : in)
    {
        alp[a - 'a']++;
    }

    for (int& elem : alp)
    {
        cout << elem << " ";
    }
}