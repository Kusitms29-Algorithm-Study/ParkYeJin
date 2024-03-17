#include <string>
#include <vector>
#include <queue>

using namespace std;

/* 
   bridge_length 다리에 올라갈 수 있는 최대 트럭수 
   weight 다리가 버틸 수 있는 무게
   truck_weights 대기 트럭
*/

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue <int> on_bridge; // 다리에 올라간 트럭
    int sum = 0; // 다리에 올라간 트럭 총 무게
    
    int i = 0;
    while(1){
        int now_weight = truck_weights[i];
        
        // 대기 트럭이 없을 경우에 다리의 길이만큼 시간 필요
        if (i == truck_weights.size()) {
            answer += bridge_length;
            break;
        }
        
        // 다리에 올라간 트럭이 다리에 올라갈 수 있는 트럭수와 같을 때
        if (on_bridge.size() == bridge_length) {
            sum -= on_bridge.front();
            on_bridge.pop();
        }
        
        // 다리에 올라간 트럭 총 무게 + 현재 무게 <= 다리가 버틸 수 있는 무게
        if (sum + now_weight <= weight) {
            sum += now_weight;
            on_bridge.push(now_weight);
            i++;
        } else { // 못 올라가면 무게 0 트럭으로 대체
            on_bridge.push(0); 
        }
        
        answer++;
    }
    
    return answer;
}