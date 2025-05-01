#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    queue<string> c1, c2, g;

    for (int i = 0; i < cards1.size(); i++) {
        c1.push(cards1[i]);
    }

    for (int i = 0; i < cards2.size(); i++) {
        c2.push(cards2[i]);
    }

    for (int i = 0; i < goal.size(); i++) {
        g.push(goal[i]);
    }

    while (!g.empty()) {
        if (c1.front() == g.front()) {
            c1.pop();
        } else if (c2.front() == g.front()) {
            c2.pop();
        } else {
            return "No";
        }
        g.pop();
    }

    return "Yes";
}