#include <string>
#include <stack>
#include <iostream>

using namespace std;

int solution(string s) {
    stack<int> notPairAlphabetString;
    int isDeleteAllAlphabet;

    for (char curAlphabet : s) {
        if (!notPairAlphabetString.size()) {
            notPairAlphabetString.push(curAlphabet);
            continue;
        }
        if (curAlphabet == notPairAlphabetString.top())
            notPairAlphabetString.pop();
        else
            notPairAlphabetString.push(curAlphabet);
    }

    if (notPairAlphabetString.size())
        isDeleteAllAlphabet = 0;
    else
        isDeleteAllAlphabet = 1;
    return isDeleteAllAlphabet;
}

int main(void) {
    string s = "baabaa";

    cout << solution(s) << endl;

    return 0;
}