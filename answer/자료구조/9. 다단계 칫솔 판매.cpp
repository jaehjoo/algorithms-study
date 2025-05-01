#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    unordered_map<string, string> parent;

    for (size_t i = 0; i < enroll.size(); i++) {
        parent[enroll[i]] = referral[i];
    }

    unordered_map<string, int> total;

    for (const auto &name: enroll) {
        total[name] = 0;
    }

    for (size_t i = 0; i < seller.size(); i++) {
        int money = amount[i] * 100;
        string cur_name = seller[i];

        while (money > 0 && cur_name != "-") {
            int to_distribute = money / 10;
            total[cur_name] += money - to_distribute;

            if (parent.find(cur_name) != parent.end()) {
                cur_name = parent[cur_name];
            } else {
                break;
            }
            money = to_distribute;
        }
    }

    vector<int> result;

    result.reverse(enroll.size());
    for (const auto &name : enroll) {
        result.push_back(total[name]);
    }

    return result;
}