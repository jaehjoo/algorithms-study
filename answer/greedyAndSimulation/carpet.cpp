#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = yellow + brown;
    int width;
    int height;
    
    for (int i = 1; i <= yellow; i++) {
        width = yellow / i + 2;
        height = total / width;
        if (total % width == 0 && total / width == i + 2) {
            if (width * 2 + height * 2 - 4 == brown) {
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }
    }
    return answer;
}