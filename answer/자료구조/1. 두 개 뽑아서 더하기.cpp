#include <vector>
#include <string>
#include <cstring>

using namespace std;

vector<int> solution(vector<int> numbers) {
    bool resultValue[201];
    vector<int> answer;
    
    memset(resultValue, false, sizeof resultValue);
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            resultValue[numbers[i] + numbers[j]] = true;
        }
    }
    
    for (int i = 0; i < 201; i++) {
        if (resultValue[i])
            answer.push_back(i);
    }
    return answer;
}