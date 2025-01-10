#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

bool checkReportLog(const string aReport, unordered_map<string, vector<string>> &checkDuplicatedUser, vector<string> user)
{
    for (string log : checkDuplicatedUser[user[0]])
        if (log == user[1])
            return true;
    
    checkDuplicatedUser[user[0]].push_back(user[1]);
    return false;
}

const vector<string> seekReportedUser (string aReport) 
{
    vector<string> userName;
    
    stringstream ss(aReport);
    string aReportUser, aReportedUser;
        
    ss >> aReportUser >> aReportedUser;
    
    userName.push_back(aReportUser);
    userName.push_back(aReportedUser);
    
    return userName;
}

const vector<int> reportedUser(const vector<string> &id_list, const vector<string> &report, int k)
{
    unordered_map<string, int> reportedUser;
    unordered_map<string, int> mailedUser;
    unordered_map<string, vector<string>> reportUser;
    unordered_map<string, vector<string>> checkDuplicatedUser;
    vector<int> answer;
    
    for (const string &id : id_list)
        reportedUser[id] = 0;
    
    for (const string &id : id_list)
        mailedUser[id] = 0;
    
    for (const string &aReport : report) {
        vector<string> usersName = seekReportedUser(aReport);
        
        if (checkReportLog(aReport, checkDuplicatedUser, usersName)) continue;
        
        reportedUser[usersName[1]]++;
        
        reportUser[usersName[1]].push_back(usersName[0]);
    }
    
    for(pair<string, int> user : reportedUser) 
    {
        if (user.second >= k) 
            for (string user : reportUser[user.first])
                mailedUser[user]++;
    }
    
    for(const string& id : id_list)
        answer.push_back(mailedUser[id]);
    
    return answer;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer = reportedUser(id_list, report, k);
    return answer;
}