#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int searchGoal(int s[2], int e[2], vector<string>& maps) {
    // 방문 여부, 방위, bfs 탐색에 필요한 큐 대기열을 작성
    bool visited[maps.size()][maps[0].size()];
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    queue<int*> q;

    // 방문 배열 초기화 및 시작 <위치, 비용> 큐 대기열 기록
    for (int i = 0; i < maps.size(); i++)
        memset(visited[i], false, sizeof(bool) * maps[0].size());
    q.push(new int[3] {s[0], s[1], 0});

    // 대기열이 비거나 아니면 원하는 지점에 도착할 때까지 찾는다
    while (!q.empty()) {
        int* curValue = q.front();
        q.pop();

        if (curValue[0] == e[0] && curValue[1] == e[1])
            return curValue[2];
        for (int i = 0; i < 4; i++) {
            int curY = curValue[0] + dy[i];
            int curX = curValue[1] + dx[i];

            if (curY >= 0 && curY < maps.size() && curX >= 0 && curX < maps[0].size()
                && maps[curY][curX] != 'X' && !visited[curY][curX]) {
                visited[curY][curX] = true;
                q.push(new int[3] {curY, curX, curValue[2] + 1});
            }
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    // 전체 최소 비용을 기록한다.
    int answer = 0;
    // 현재 지점까지 도달하는 데 걸린 시간을 기록한다.
    int curTime = 0;
    // 시작, 개폐장치, 도착 위치를 기록한다.
    int start[2];
    int lever[2];
    int exit[2];

    // 시작, 개폐장치, 도착점을 기록하기 위해 지도를 순회한다.
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (maps[i][j] == 'S') {
                start[0] = i; start[1] = j;
            }
            if (maps[i][j] == 'L') {
                lever[0] = i; lever[1] = j;
            }
            if (maps[i][j] == 'E') {
                exit[0] = i; exit[1] = j;
            }
        }
    }

    // 레버까지 도달하는 데 걸린 시간을 확인한다.
    curTime = searchGoal(start, lever, maps);
    // 최소 경로 시간에 현재까지 걸린 시간을 더한다.
    answer += curTime;
    // 레버에서 도착점까지 걸리는 시간을 확인한다.
    curTime = searchGoal(lever, exit, maps);
    // 만약, 레버나 도착점까지 도달하지 못하는 경우에는 -1을 반환한다.
    if (curTime == -1 || answer == -1)  {
        return -1;
    }
    // 도착점까지 도달한 경우, 걸린 시간을 더해준다.
    answer += curTime;
    
    return answer;
}