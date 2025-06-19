#include <vector>
#include <queue>
#include <limits>
#include <iostream>

using namespace std;
typedef vector<vector<int>> vp;

int findNetworkflowMax(vp& capacity, vp& flow, int source, int sink) {
    int totalAmount = 0;

    while (true) {
        vector<int> parent(capacity.size(), -1);
        queue<int> q;

        parent[source] = source;
        q.push(source);

        while (!q.empty() && parent[sink] == -1) {
            int cur = q.front();
            q.pop();
            for (int there = 0; there < static_cast<int>(capacity.size()); there++) {
                if (capacity[cur][there] - flow[cur][there] > 0 && parent[there] == -1) {
                    parent[there] = cur;
                    q.push(there);
                }
            }
        }

        if (parent[sink] == -1) break;

        int amount = numeric_limits<int>::max();
        for (int p = sink; p != source; p = parent[p]) {
            amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
        }
        for (int p = sink; p != source; p = parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }

        totalAmount += amount;
    }

    return totalAmount;
}

int main(void) {
    int n, m;
    cin >> n >> m;

    const int SOURCE = 0;
    const int SINK = n + m + 1;
    const int SIZE = n + m + 2;

    vp capacity(SIZE, vector<int>(SIZE, 0));
    vp flow(SIZE, vector<int>(SIZE, 0));

    for (int i = 1; i <= n; i++) {
        int desired;
        cin >> desired;
        for (int j = 0; j < desired; j++) {
            int stable;
            cin >> stable;
            int cowNode = i;
            int stableNode = n + stable;
            capacity[cowNode][stableNode] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        capacity[SOURCE][i] = 1;
    }

    for (int i = n + 1; i <= n + m; i++) {
        capacity[i][SINK] = 1;
    }

    cout << findNetworkflowMax(capacity, flow, SOURCE, SINK) << endl;

    return 0;
}