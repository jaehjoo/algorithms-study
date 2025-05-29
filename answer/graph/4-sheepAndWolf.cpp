#include <string>
#include <vector>

using namespace std;

// 노드의 개수와 최대한 데려갈 수 있는 양 마리 수
int n, answer = 0;
// 노드값과 간선을 참조하여 만든 트리, 노드 방문 여부, 각 노드값
vector<vector<int>> tree;
vector<bool> visited;
vector<int> comp;

// 모든 경우의 수를 따진다
void dfs(vector<int> cur) {
    int sheep = 0;
    int wolf = 0;

    // 현재까지 선택한 노드에서 양과 늑대의 수를 계산
    for (int c : cur) {
        if (comp[c] == 1)
            wolf++;
        else
            sheep++;
    }
    
    // 늑대가 양과 수가 같거나 많으면 양이 다 잡아 먹히므로 탈출한다
    if (sheep <= wolf)
        return ;
    
    // 현재 양이 늑대보다 많아 살 수 있으면 살아 있는 양 수를 현재 기록값과 비교하여 더 큰 수를 기록한다.
    answer = max(answer, sheep);

    // 현재 노드에서 갈 수 있는 곳을 다 가본다.
    for (int i = 0; i < cur.size(); i++) {
        int node = cur[i];

        for (int g : tree[node]) {
            if (visited[g])
                continue ;
            visited[g] = true;
            cur.push_back(g);
            dfs(cur);
            cur.pop_back();
            visited[g] = false;
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    n = info.size();
    tree.resize(n);
    visited.resize(n, false);
    comp = info;

    for (vector<int> edge : edges) {
        tree[edge[0]].push_back(edge[1]);
    }

    visited[0] = true;
    dfs({0});
    return answer;
}