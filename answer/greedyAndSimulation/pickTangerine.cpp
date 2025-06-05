#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int maxSize = *max_element(tangerine.begin(), tangerine.end());
    vector<int> tangerineSize(maxSize, 0);

    for (int size : tangerine) {
        tangerineSize[size - 1]++;
    }
    stable_sort(tangerineSize.begin(), tangerineSize.end());

    for (int num : tangerineSize) {
        if (k <= 0) break;
        answer++;
        k -= num;
    }
    return answer;
}