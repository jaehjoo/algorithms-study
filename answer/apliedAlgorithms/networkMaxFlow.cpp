#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#define ALPHABET_LEN 52
#define START 0
#define END 25

using namespace std;
typedef vector<vector<int>> vp;

int charToIndex(char ch) {
    if (ch >= 'A' && ch <= 'Z') return ch - 'A';
    else return ch - 'a' + 26;
}

int findNetworkFlowMax(vp& capacity, vp& flow) {
    int totalAmount = 0;

    while (true) {
        vector<int> parent(ALPHABET_LEN, -1);
        queue<int> q;
        parent[START] = START;
        q.push(START);

        while (!q.empty() && parent[END] == -1) {
            int cur = q.front();
            q.pop();

            for (int there = 0; there < ALPHABET_LEN; there++) {
                if (capacity[cur][there] - flow[cur][there] > 0 && parent[there] == -1) {
                    parent[there] = cur;
                    q.push(there);
                }
            }
        }

        if (parent[END] == -1) break;

        int amount = numeric_limits<int>::max();
        for (int p = END; p != START; p = parent[p]) {
            amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
        }
        for (int p = END; p != START; p = parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totalAmount += amount;
    }
    return totalAmount;
}

int main() {
    int v, cap;
    char s, e;
    vp capacity(ALPHABET_LEN, vector<int>(ALPHABET_LEN, 0));
    vp flow(ALPHABET_LEN, vector<int>(ALPHABET_LEN, 0));

    cin >> v;
    for (int i = 0; i < v; ++i) {
        cin >> s >> e >> cap;
        int si = charToIndex(s);
        int ei = charToIndex(e);
        capacity[si][ei] += cap;
        capacity[ei][si] += cap;
    }

    cout << findNetworkFlowMax(capacity, flow) << endl;
    return 0;
}
