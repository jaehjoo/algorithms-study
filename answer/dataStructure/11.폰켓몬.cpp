#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    set<int> number(nums.begin(), nums.end());

    return min(number.size(), nums.size() / 2);
}