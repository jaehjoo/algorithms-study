#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> getBestScoreMan;
    int mathTestGuessingPattern0[5] = {1, 2, 3, 4, 5};
    int mathTestGuessingPattern1[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int mathTestGuessingPattern2[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int> mathScore(3);
    int bestScoreInThey;
    
    for (int i = 0; i < answers.size(); i++) {
        if (mathTestGuessingPattern0[i % 5] == answers[i])
            mathScore[0] += 1;
        if (mathTestGuessingPattern1[i % 8] == answers[i])
            mathScore[1] += 1;
        if (mathTestGuessingPattern2[i % 10] == answers[i])
            mathScore[2] += 1;
    }
    bestScoreInThey = *max_element(mathScore.begin(), mathScore.end());

    for (int i = 0; i < 3; i++) {
        if (mathScore[i] == bestScoreInThey) {
            getBestScoreMan.push_back(i + 1);
        }
    }
    
    return getBestScoreMan;
}