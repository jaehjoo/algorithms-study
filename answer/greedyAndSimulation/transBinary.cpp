#include <string>
#include <vector>

using namespace std;

void makeBinaryStr(int len, string& cur) {
    if (len == 0)
        return ;
    makeBinaryStr(len / 2, cur);
    cur += static_cast<char>(len % 2 + '0');
}

vector<int> solution(string s) {
    vector<int> answer(2, 0);

    while (s != "1") {
        int zero = 0;

        for (char val : s)
            zero += (val == '0' ? 1 : 0);
        answer[1] += zero;
        answer[0]++;
        zero = s.size() - zero;
        s = "";
        makeBinaryStr(zero, s);
    }
    return answer;
}