#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

int calFee(vector<string>& records, vector<int> fees)
{
    int fee = fees[1];
    if(records[records.size() - 1].substr(11) == "IN")
    {
        string tmp = "23:59 ";
        tmp += records[0].substr(6,4);
        tmp += " OUT";
        
        records.push_back(tmp);
        
    }
    
    int totalMin = 0;
    for (int i = 0; i < records.size(); i += 2)
    {
        string firstTime = records[i].substr(0, 5);
        string secondTime = records[i + 1].substr(0, 5);
        
        totalMin += (stoi(secondTime.substr(0,2)) - stoi(firstTime.substr(0,2))) * 60;
        totalMin += stoi(secondTime.substr(3,2)) - stoi(firstTime.substr(3,2));
        
    }
    
    totalMin -= fees[0];
        
    if (totalMin > 0)
    {
        if (totalMin % fees[2] != 0)
            fee += (totalMin / fees[2] + 1) * fees[3];
        else
            fee += (totalMin / fees[2]) * fees[3];
    }
    
    return fee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<string, vector<string>> recordPerCar;
    map<string, int> feePerCar;
    
    for (string record : records)
    {
        string carNumber = record.substr(6, 4);
        
        recordPerCar[carNumber].push_back(record);
    }
    
    for (auto& [key, value] : recordPerCar)
    {
        feePerCar[key] = calFee(value, fees);
    }
    
    for (const auto& [key, value] : feePerCar)
        answer.push_back(value);
    
    return answer;
}