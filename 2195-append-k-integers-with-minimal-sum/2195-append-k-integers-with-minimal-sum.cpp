class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
       
        // Sort the nums array
        sort(nums.begin(),nums.end());
        
        // get the sum of 1 to K 
        long long sum = ((long long)k * (long long)(k+1)) /2;
        
        // current unique number
        int curr = k + 1;
        
        // loop through array and deduce the numbers which occurs only once
        // and add the next unique number curr and increment curr
        for(int i=0;i<nums.size();i++)
        {
            // break when current unique number is less or equal nums[i]
            // cause in this case all unique numbers have been taken in to sum
            if(curr<=nums[i])break;
            
            // check if current number occurs only once
            if(i>0 && nums[i-1]==nums[i])continue;
            
            sum -= nums[i];
            sum += curr;
            curr++;
        }
        
        return sum;
    }
};