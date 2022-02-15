class Solution {  
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> records(1001, 0);
        for (const auto& trip : trips) {
            records[trip[1]] += trip[0];
            records[trip[2]] -= trip[0];
        }
        int total = 0;
        for (const int& incr : records) {
            total += incr;
            if (total > capacity) return false;
        }
        return true;
    }
};