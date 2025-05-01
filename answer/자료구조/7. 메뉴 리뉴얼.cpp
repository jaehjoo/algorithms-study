#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> combi;

void combination(string src, string dst, int depth) {
    if (dst.size() == depth)
        combi[dst]++;
    else
        for (int i = 0; i < src.size(); i++)
            combination(src.substr(i + 1), dst + src[i], depth);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (string& order : orders)
        sort(order.begin(), order.end());

    for (int len : course) {
            for (string order : orders)
                combination(order, "", len);

            int max_order = 0;
            
            for (auto it : combi)
                max_order = max(max_order, it.second);

            for (auto it : combi)
                if (max_order >= 2 && it.second == max_order)
                    answer.push_back(it.first);
            
            combi.clear();
        }

    sort(answer.begin(), answer.end());

    return answer;
}