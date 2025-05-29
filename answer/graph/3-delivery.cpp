#include <limits>
#include <vector>
#include <queue>

using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    // 주어진 간선(road)을 통해 만들 그래프, 노드 별 최소 비용을 기록할 배열, 노드 방문 여부를 기록할 플래그 배열 선언
    int answer = 0;
    vector<pair<int, int> > graph[N + 1];
    vector<int> distances(N + 1, numeric_limits<int>::max());
    vector<bool> visited(N + 1, false);

    // 출발점을 다시 거쳐갈 일이 없도록 0을 설정한다.
    distances[1] = 0;

    // 간선 가중치를 통한 그래프 작성
    for (vector<int> t : road) {
        graph[t[0]].push_back({t[1], t[2]});
        graph[t[1]].push_back({t[0], t[2]});
    }

    // 다익스트라 알고리즘을 사용하기 위해 우선순위 큐를 선언
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    // 출발점부터 확장할 필요가 있으므로 비용 0, 출발점 1을 큐 대기열에 추가
    q.push({0, 1});

    // 큐 대기열이 끝날 때까지 돌린다.
    while (!q.empty()) {
        int dist = q.top().first;
        int node = q.top().second;
        q.pop();

        if (visited[node])
            continue;
        visited[node] = true;

        // 현재 노드와 연결된 다음 경로까지 가는 최소 비용을 구하고 최소 비용이 갱신되면 그 노드를 대기열에 추가한다.
        for (pair<int, int>& next : graph[node]) {
            int nextNode = next.first;
            int nextDist = next.second;
            int cost = dist + nextDist;

            if (cost < distances[nextNode]) {
                distances[nextNode] = cost;
                q.push({cost, nextNode});
            }
        }
    }

    // 출발점에서 해당 노드까지 가는 데 비용이 K값 이하인 배달 가능 지역 개수를 센다.
    for (int i = 1; i <= N; i++) {
        if (distances[i] <= K)
            answer++;
    }
    
    return answer;
}