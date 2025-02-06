#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int tmpWeight = 0;
    int truckIndex = 0;
    int arrivedTruck = 0;
    
    int size = truck_weights.size();
    queue<int> tmpBridge;
    
    while(1)
    {
        answer++;
        
        if (tmpBridge.size() >= bridge_length)
        {
            const int value = tmpBridge.front();
            tmpBridge.pop();
            
            if (value > 0)
            {
                arrivedTruck++;
            }
            
            tmpWeight -= value;
        }
        
        if (arrivedTruck >= size) 
        {
            break;
        }
        
        if (truckIndex + 1 > size)
        {
            tmpBridge.push(0);
            continue;
        }
        
        if (tmpWeight + truck_weights[truckIndex] <= weight)
        {
            tmpBridge.push(truck_weights[truckIndex]);
            tmpWeight += truck_weights[truckIndex];
            truckIndex++;
        }
        else
        {
            tmpBridge.push(0);
        }
    
    }
    
    return answer;
}