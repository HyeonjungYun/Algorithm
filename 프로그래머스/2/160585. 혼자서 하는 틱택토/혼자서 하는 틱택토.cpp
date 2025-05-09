#include <string>
#include <vector>

using namespace std;

bool isWinO(vector<string>& board)
{
    if (board[0] == "OOO" || board[1] == "OOO" || board[2] == "OOO")
    {
        return true;
    }
    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
    {
        return true;
    }
    if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
    {
        return true;
    }
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
            return true;
    }
        
    return false;
}

bool isWinX(vector<string>& board)
{
    if (board[0] == "XXX" || board[1] == "XXX" || board[2] == "XXX")
    {
        return true;
    }
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
    {
        return true;
    }
    if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
    {
        return true;
    }
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
            return true;
    }
        
    return false;
}

pair<int, int> countOX(vector<string>& board)
{
    int O = 0, X = 0;
    for (const string& row : board)
    {
        for (const char& c : row)
        {
            if (c == 'O')
            {
                O++;
            }
            if (c == 'X')
            {
                X++;
            }
        }
    }
    
    return make_pair(O,X);
}

int solution(vector<string> board) {
    
    auto[O, X] = countOX(board);
    
    bool bWinO = isWinO(board);
    bool bWinX = isWinX(board);
    
    if (O == X)
    {
        if (!bWinO)
        {
            return 1;
        }
    }
    if (O == X + 1)
    {
        if (!bWinX)
        {
            return 1;
        }
    }
    return 0;
}