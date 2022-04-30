class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int, int> countMap;
        vector<int> res;
        int desiredCount = nums.size();
        for(auto num : nums) {
            for(int i : num) {
                countMap[i]++;
            }
        }
        for(auto num : countMap) {
            if(num.second == desiredCount) {
                res.push_back(num.first);
            }
        }
        return res;
    }
};