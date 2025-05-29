#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int searchShortestPath(vector<vector<int>>& maps) {
    // 방문 여부, 현 노드에서 갈 수 있는 4방위, 큐 대기열
    bool checkStep[maps.size()][maps[0].size()];
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    queue<pair<int, int>> q;
    
    int answer = -1;
    
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++)
            checkStep[i][j] = false;
    }

    // 출발점 기록 및 방문 여부 확인
    q.push(make_pair(0, 0));
    checkStep[0][0] = true;

    // 대기열이 끝나거나 도착점에 도달할 때까지
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        
        // 도착점에 도달하면 탈출
        if (cur.first == maps.size() - 1 && cur.second == maps[0].size() - 1)
            return maps[cur.first][cur.second];
        
        // 현 노드에서 갈 수 있는 4방위를 확인하고 방문한 적 없으면 큐 대기열에 추가한다. 
        for (int i = 0; i < 4; i++) {
            int y = cur.first + dy[i];
            int x = cur.second + dx[i];
            
            if (0 <= y && y < maps.size() && 0 <= x && x < maps[0].size() &&
               maps[y][x] != 0 && !checkStep[y][x]) {
                q.push(make_pair(y, x));
                maps[y][x] += maps[cur.first][cur.second];
                checkStep[y][x] = true;
            }
        }
    }
    
    return answer;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    answer = searchShortestPath(maps);
    return answer;
}