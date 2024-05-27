#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<int, vector<string>> pairs;
        vector<string> ans;

        for (int i = 0; i < list1.size(); i++) {
            for (int j = 0; j < list2.size(); j++) {
                if (list1[i] == list2[j]) {
                    pairs[i + j].push_back(list1[i]);
                }
            }
        }

        int minKey = pairs.begin()->first;
        ans = pairs[minKey];

        return ans;
    }
};
