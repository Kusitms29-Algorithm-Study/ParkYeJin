#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair <int, int>> q; // idx, 중요도
    priority_queue <int> pq; // 우선순위 큐
    
    for(int i = 0; i < priorities.size(); i++){
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    while(!q.empty()){
        int idx = q.front().first; // idx
        int num = q.front().second; // 중요도
        q.pop();
        
        if(pq.top() == num){
            pq.pop();
            answer++;
            if(location == idx) break;
        } else {
            q.push({idx, num});
        }
    }
    
    
    return answer;
}