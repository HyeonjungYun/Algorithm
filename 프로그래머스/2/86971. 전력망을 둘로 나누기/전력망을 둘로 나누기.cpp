#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> visited;

vector<vector<int>> makeGraph(vector<vector<int>>&wires, vector<int>& excep, int n)
{
    vector<vector<int>> graph(n + 1, vector<int>());
    
    for (vector<int>& wire : wires)
    {
        if (wire == excep)
        {
            continue;
        }
        graph[wire[0]].push_back(wire[1]);
        graph[wire[1]].push_back(wire[0]);
    }
    
    return graph;
}

int DFS(vector<vector<int>>& graph, int current)
{
    bool check = true;
    for (int i = 0; i < graph[current].size(); i++)
    {
        if (!visited[graph[current][i]])
        {
            check = false;
            break;
        }
    }
    if (check)
    {
        return 1;
    }
    
    visited[current] = true;
    int count = 1;
    
    for (int i = 0; i < graph[current].size(); i++)
    {
        int next = graph[current][i];
        if (!visited[next])
        {
            count += DFS(graph, graph[current][i]);
        }
    }
    
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    vector<int> nodeCount;
    
    for (vector<int>& wire : wires)
    {
        visited.clear();
        visited.assign(wires.size() + 1, false);
        vector<vector<int>> graph = makeGraph(wires, wire, n);
        nodeCount.push_back(DFS(graph, 1));
    }
    
    int min_val = n;
    for (int node : nodeCount)
    {
        min_val = min(min_val, abs(abs(n - node) - node));
    }
    
    return min_val;
}