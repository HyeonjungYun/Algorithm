#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class AdjList 
{
private:
    map<string, vector<string>> _adjList;
    int _nodeNumbers;

public:
    AdjList(int nodeNumbers)
    {
        _nodeNumbers = nodeNumbers;
    }

    ~AdjList()
    {
        delete this;
    }

    void AddVertex(string from, string to)
    {
        if (_adjList.find(from) == _adjList.end())
        {
            _adjList.insert({ from, vector<string>() });
            _adjList[from].push_back(to);
            return;
        }
        _adjList[from].push_back(to);
    }

    void sortVertexElements()
    {
        for (auto& elements : _adjList)
        {
            sort(elements.second.begin(), elements.second.end());
        }
    }

    bool hasEdge(string tmp)
    {
        return _adjList.find(tmp) != _adjList.end();
    }

    auto getCurrent(string current)
    {
        return _adjList.find(current);
    }
    
    void printGraph()
    {
        for (auto& elem : _adjList)
        {
            cout << elem.first << ": ";

            cout << "( ";
            for (string v : elem.second)
            {
                cout << v << " ";
            }
            cout << ")\n";
        }
    }
};

AdjList* adjList;

bool dfs(string current, vector<string>& answer, int ticketCount)
{    
    if (answer.size() == ticketCount + 1) return true;

    if (!adjList->hasEdge(current))
    {
        return false;
    }

    auto it = adjList->getCurrent(current);

    for (int i = 0; i < it->second.size(); i++)
    {
        string next = it->second[i];

        it->second.erase(it->second.begin() + i);
        answer.push_back(next);

        if (dfs(next, answer, ticketCount))
        {
            return true;
        }

        answer.pop_back();
        it->second.insert(it->second.begin() + i, next);
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets)
{
    adjList = new AdjList(tickets.size());
    vector<string> answer;

    for (vector<string> ticket : tickets)
    {
        adjList->AddVertex(ticket[0], ticket[1]);
    }
    adjList->sortVertexElements();

    answer.push_back("ICN");

    dfs("ICN", answer, tickets.size());
    adjList->printGraph();

    return answer;
}