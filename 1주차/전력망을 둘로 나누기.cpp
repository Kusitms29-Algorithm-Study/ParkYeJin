#include <string>
#include <vector>
#include <iostream>

using namespace std;

int parent[101];


int getParent(int x){
    if(x == parent[x]) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    
    if(a > b) parent[a] = b;
    else parent[b] = a;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 1e9;
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
    int cnt = 0;
    for(int j = 0; j < wires.size(); j++){
        for(int i = 0; i < wires.size(); i++){
            if(i == cnt) continue;
            unionParent(wires[i][0], wires[i][1]);
        }
        int res[101] = {0};
        for(int i = 1; i <= n; i++){
            res[getParent(i)]++;
        }
        for(int i = 1; i <= n; i++){
            cout << res[i] << " ";
        }
        cout << "\n";
        
        vector <int> v;
        for(int i = 1; i <= n; i++){
            if(res[i] != 0) v.push_back(res[i]);
        }
        answer = min(answer, abs(v[0] - v[1]));
        cnt++;
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
    }
    return answer;
}