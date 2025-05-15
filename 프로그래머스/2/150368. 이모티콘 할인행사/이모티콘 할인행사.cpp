#include <string>
#include <vector>

using namespace std;

vector<int> rates = {10, 20, 30, 40};
vector<int> sel;
int max_member = 0;
int max_sales = 0;

void simulate(vector<vector<int>>& users, vector<int>& emoticons)
{
    int member = 0, sales = 0;
    vector<int> purchase(users.size(), 0);
    for (int i = 0; i < users.size(); i++)
    {
        for (int j = 0; j < emoticons.size(); j++)
        {
            if (users[i][0] <= sel[j])
            {
                purchase[i] += emoticons[j] * ((100.0f - sel[j]) / 100.0f);
            }
        }
    }
    
    for (int i = 0; i < users.size(); i++)
    {
        if (purchase[i] >= users[i][1])
        {
            member++;
        }
        else
        {
            sales += purchase[i];
        }
    }

    if (max_member < member)
    {
        max_member = member;
        max_sales = sales;
    }
    else if (max_member == member && sales > max_sales)
    {
        max_sales = sales;
    }
}

void dfs(int idx, vector<vector<int>>& users, vector<int> emoticons)
{
    if (idx == emoticons.size())
    {
        simulate(users, emoticons);
        return;
    }
    
    for (const int& rate : rates)
    {
        sel[idx] = rate;
        dfs(idx + 1, users, emoticons);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    sel = vector<int>(emoticons.size());
    dfs(0, users, emoticons);
    
    answer.push_back(max_member);
    answer.push_back(max_sales);
    return answer;
}