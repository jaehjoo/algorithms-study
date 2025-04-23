#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    stack<int> deleted;

    vector<int> up;
    vector<int> down;

    for (int i = 0; i < n + 2; i++) {
        up.push_back(i - 1);
        down.push_back(i + 1);
    }
    k++;

    for (int i = 0; i < cmd.size(); i++) {
        if (cmd[i][0] == 'C') {
            deleted.push(k);
            down[up[k]] = down[k];
            up[down[k]] = up[k];

            if (down[k] == n + 1)
                k = up[k];
            else
                k = down[k];
        } else if (cmd[i][0] == 'Z') {
            int r = deleted.top();
            down[up[r]] = r;
            up[down[r]] = r;
            deleted.pop();
        } else {
            int sz = stoi(cmd[i].substr(2));

            if (cmd[i][0] == 'U') {
                for (int j = 0; j < sz; j++) {
                    k = up[k];
                }
            } else if (cmd[i][0] == 'D') {
                for (int j = 0; j < sz; j++) {
                    k = down[k];
                }
            }
        }
    }

    string answer;

    answer.append(n, 'O');
    while (!deleted.empty()) {
        answer[deleted.top() - 1] = 'X';
        deleted.top();
    }

    return answer;
}