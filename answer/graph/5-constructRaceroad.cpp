#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board) {
    // 방위 : E, W, N, S
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    // 최소 비용을 저장하는 배열
    vector<vector<vector<int>>> leastCost(board.size(), vector<vector<int>>(board.size(), vector<int>(4, numeric_limits<int>::max())));
    // 비용이 적은 노드부터 따지기 위한 우선순위 큐. 들어가는 내용은 <최소 비용, 행, 열, 방위>
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;

    // 원점으로 다시 들어가는 경우를 차단한다
    for (int i = 0; i < 4; i++) {
        leastCost[0][0][i] = 0;
    }

    // 계산 편하게 하려고 지정하는 초기값
    if (!board[0][1])
        q.push({100, 0, 1, 0});
    if (!board[1][0])
        q.push({100, 1, 0, 3});
    leastCost[0][1][0] = 100; leastCost[1][0][3] = 100;
    
    // 큐에 들어간 노드들을 탐색한다
    while (!q.empty()) {
        // 현 노드의 정보를 저장한다.
        int cost = q.top()[0];
        int y = q.top()[1];
        int x = q.top()[2];
        int bearing = q.top()[3];

        q.pop();

        // 현 노드에서 접근할 수 있는 방위를 돌아다니며 최소 비용을 따진다.
        for (int i = 0; i < 4; i++) {
            int curY = y + dy[i];
            int curX = x + dx[i];
            int curCost = cost + (i == bearing ? 100 : 600);

            // 경주장을 벗어나지 않고, 현재 가려는 곳이 벽으로 막혀 있지 않으며, 비용이 덜 들면 그쪽 경로로 가본다.
            if (curY >= 0 && curY < board.size() && curX >= 0 && curX < board.size()
                && !board[curY][curX] && curCost < leastCost[curY][curX][i]) {
                leastCost[curY][curX][i] = curCost;
                q.push({curCost, curY, curX, i});
            }
        }
    }
    
    // 도착점에서 방위별로 기록된 최소 비용 중, 가장 비용이 적은 경로를 선택한다.
    return *min_element(leastCost[board.size() - 1][board.size() - 1].begin(), leastCost[board.size() - 1][board.size() - 1].end());
}