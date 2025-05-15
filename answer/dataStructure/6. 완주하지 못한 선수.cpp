#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    int isElementNum = 0;
    string answer = "";
    participant.insert(participant.end(), completion.begin(), completion.end());
    sort(participant.begin(), participant.end());
    for (vector<string>::iterator iter = participant.begin(); iter < participant.end(); iter++) {
        isElementNum++;
        if (isElementNum % 2 && *iter != *(iter + 1)) {
            answer = *iter;
            break ;
        }
        if (!(isElementNum % 2) && *iter != *(iter + 1)) {
            isElementNum = 0;
        }
    }
    return answer;
}