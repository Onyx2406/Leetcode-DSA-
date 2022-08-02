class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        long long n = nums.size(), sum = 0;
        vector<long long> prefix(n,0);
		
		// Prefix sum array to find the sum of any subarray in O(1)
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            prefix[i] = sum;
        }
        
        vector <int> prev(n,0), next(n,0);
        
		// Finding the previous smaller element
        stack <pair<int,int>> s;
        for(int i = 0; i<n; i++){
            if(s.empty()) s.push({nums[i],i});
            else{
                while(!s.empty() and nums[i]<s.top().first) next[s.top().second] = i, s.pop();
                s.push({nums[i],i});
             }
        }
        while(!s.empty()) next[s.top().second] = n, s.pop();
        
		// Finding the next smaller element
        for(int i = n-1; i>=0; i--){
            if(s.empty()) s.push({nums[i],i});
            else{
                while(!s.empty() and nums[i]<s.top().first) prev[s.top().second] = i, s.pop();
                s.push({nums[i],i});
            }
        }
        while(!s.empty()) prev[s.top().second] = 0, s.pop();
        
		// Calculating the answer from prefix array, previous and next smaller array
        long long ans = 0;
        for(int i = 0; i<n; i++){
			long long prod = prefix[next[i]-1];
			
			// If current element has no previous smaller element.
            if(nums[prev[i]]<nums[i]) prod -= prefix[prev[i]];
            prod *= nums[i];
            ans = max(ans,prod);
        }
        return ans%1000000007;
    }
};