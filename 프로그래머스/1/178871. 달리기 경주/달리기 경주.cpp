#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void overtakings(unordered_map<string, int> &rank, vector<string> &callings, vector<string>& players) {
    for (const string& call : callings) {
        string called = call;
        string uncalled = players[rank[call] - 1];
        
        string temp = players[rank[called]];
        players[rank[called]] = players[rank[called] - 1];
        players[rank[call] - 1] = temp;
        
        rank[uncalled]++;
        rank[called]--;
    }
}

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> rank;
    
    int ranking = 0;
    for (const string& player : players){
        rank[player] = ranking;
        ranking++;
    }
    
    overtakings(rank, callings, players);
    
    return players;
}