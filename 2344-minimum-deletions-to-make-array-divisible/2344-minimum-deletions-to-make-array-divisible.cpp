class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gc = numsDivide[0], n = nums.size(), del = 0;
        for (int &a: numsDivide) gc = __gcd(gc, a);
        sort(nums.begin(), nums.end());
        vector<int> data;
        
        for (int i = 1; i * i <= gc; i++)
            if (gc % i == 0)
                data.push_back(i), data.push_back(gc / i);
        
        sort(data.begin(), data.end());
        
        for (int &a: data) {
            while (del < n && nums[del] < a)
                del++;
            
            if (del < n && nums[del] == a)
                return del;
        }
        
        return -1;
    }
};