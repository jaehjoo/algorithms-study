#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;
int n, m, k;

ll sum(vector<ll>& fenTree, int index) {
    ll ret = 0;
    while (index > 0) {
        ret += fenTree[index];
        index -= (index & -index);
    }
    return ret;
}

void update(vector<ll>& fenTree, int index, ll diff) {
    while (index < n + 1) {
        fenTree[index] += diff;
        index += (index & -index);
    }
}

int main() {
    cin >> n >> m >> k;

    vector<ll> elem(n);
    vector<ll> fenTree(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> elem[i];
        update(fenTree, i + 1, elem[i]);
    }

    for (int i = 0; i < m + k; i++) {
        int flag;
        cin >> flag;

        if (flag == 1) {
            int first;
            ll second;

            cin >> first >> second;

            ll diff = second - elem[first - 1];
            elem[first - 1] = second;
            update(fenTree, first, diff);
        } else {
            int first, second;
            cin >> first >> second;
            ll res = sum(fenTree, second) - sum(fenTree, first - 1);
            cout << res << endl;
        }
    }

    return 0;
}