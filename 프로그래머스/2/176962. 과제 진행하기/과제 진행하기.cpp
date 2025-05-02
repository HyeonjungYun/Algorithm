#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

int convertTime(string time)
{
    int Time = 0;
    Time += (time[0] - '0') * 600;
    Time += (time[1] - '0') * 60;
    Time += (time[3] - '0') * 10;
    Time += time[4] - '0';
    
    return Time;
}

void sortPlans(vector<vector<string>>& plans)
{
    sort(plans.begin(), plans.end(), [](vector<string>& a, vector<string>& b)
         {
             int aTime = convertTime(a[1]); 
             int bTime = convertTime(b[1]);
             return aTime < bTime;
         });
    
    return;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    int plansIndex = 0;
    queue<string> sequence;
    stack<string> unfinished;
    unordered_map<string, pair<int, int>> task;
    
    sortPlans(plans);
    
    for (vector<string>& plan : plans)
    {
        task.insert({plan[0], make_pair(convertTime(plan[1]), stoi(plan[2]))});
    }
    sequence.push(plans[0][0]);
    
    while(!sequence.empty())
    {
        string tmpTask = sequence.front();
        sequence.pop();
        int endTime = task[tmpTask].first + task[tmpTask].second;
        
        if (plans.size() <= plansIndex + 1)
        {
            answer.push_back(tmpTask);
        }
        else if ((plans.size() > plansIndex + 1) && (endTime > task[plans[plansIndex + 1][0]].first))
        {
            task[tmpTask].second = endTime - task[plans[plansIndex + 1][0]].first;
            unfinished.push(tmpTask);
            sequence.push(plans[plansIndex + 1][0]);
            plansIndex++;
        }
        else if (plans.size() > plansIndex + 1 && endTime < task[plans[plansIndex + 1][0]].first)
        {
            answer.push_back(tmpTask);
            
            if (!unfinished.empty())
            {
                string nextTask = unfinished.top();
                task[nextTask].first = endTime;
                sequence.push(nextTask);
                unfinished.pop();
            }
            else
            {
                sequence.push(plans[plansIndex + 1][0]);
                plansIndex++;
            }
        }
        else if (plans.size() > plansIndex + 1 && endTime == task[plans[plansIndex + 1][0]].first)
        {
            answer.push_back(tmpTask);
            sequence.push(plans[plansIndex + 1][0]);
            plansIndex++;
        }
    }
    
    while(!unfinished.empty())
    {
        string tmpTask = unfinished.top();
        unfinished.pop();
        
        answer.push_back(tmpTask);
    }
    
    return answer;
}