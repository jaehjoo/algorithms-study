#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;

    answer.push_back((board[0] - 1) / 2);
    answer.push_back((board[1] - 1) / 2);

    for (string go : keyinput) {
        int curX = answer[0];
        int curY = answer[1];

        if (go == "left") curX += 1;
        if (go == "right") curX -= 1;
        if (go == "up") curY += 1;
        if (go == "down") curY -= 1;

        if (curX < 0 || curX >= board[0] || curY < 0 || curY >= board[1])
            continue;
        
        answer[0] = curX;
        answer[1] = curY;
    }

    answer[0] -= (board[0] - 1) / 2;
    answer[1] -= (board[1] - 1) / 2;
    return answer;
}