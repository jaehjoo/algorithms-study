#include <vector>
#include <iostream>

using namespace std;
typedef vector<vector<int>> vi;

bool isFinished(const vi& board, int turn) {
    int win[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };

    for (int i = 0; i < 8; i++) {
        int isSame = 0;
        for (int j = 0; j < 3; j++) {
            if (board[win[i][j] / 3][win[i][j] % 3] == turn)
                isSame++;
        }
        if (isSame == 3)
            return true;
    }
    return false;
}

int canWin(vi& board, int turn) {
    int next = 1 + 2 - turn;

    if (isFinished(board, next))
        return -1;
    int minValue = 2;
    for (int y = 0; y < 3; ++y) {
        for (int x = 0; x < 3; ++x) {
            if (board[y][x] == 0) {
                board[y][x] = turn;
                minValue = min(minValue, canWin(board, next));
                board[y][x] = 0;
            }
        }
    }
    if (minValue == 1)
        return -1;
    if (minValue == 2 || minValue == 0)
        return 0;
    return 1;
}

int main(void) {
    vi board(3, vector<int>(3, 0));
    int e;
    int o = 0;
    int x = 0;
    int turn;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> e;
            board[i][j] = e;
            if (e == 1)
                ++o;
            if (e == 2)
                ++x;
        }
    }

    if (o == x)
        turn = 1;
    else
        turn = 2;

    switch (canWin(board, turn)) {
        case 1:
            cout << 'W' << endl;
            break;
        case 0:
            cout << 'D' << endl;
            break;
        default:
            cout << 'L' << endl;
    }
    return 0;
}