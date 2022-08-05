class Solution {
public:
    
    /*
    Since the product should be positive , 0 acts like a blockage
    so we partition the array into subarrays in which 0 is not present
    now for each of the subarray if number of negative in them is even then we can take
    the subarray completely else have to remove the prefix till first negative or
    suffix from last negative, we greedily remove the smaller one
    */
    
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> partitions;
        int prev = 0;
        int i=0;
        while(i<n){
            int x = nums[i];
            if(x == 0){
                while(i<n && nums[i] == x) i++;
                prev = i;
            }
            else{
                while(i<n && nums[i] != 0){
                    i++;
                }
                partitions.push_back({prev,i-1});
            }
        }
        int ans = 0;
        for(auto pr:partitions){
            int start = pr.first;
            int end = pr.second;
            // one pass to find number of negative
            int cnt = 0;
            for(int i=start;i<=end;i++){
                if(nums[i]<0) cnt++;
            }
            if(cnt%2 == 0){
                ans = max(ans,end-start+1);
            }
            else{
                int first; // to store first index of negative
                int last; // to store last index of negative
                for(int i=start;i<=end;i++){
                    if(nums[i]<0){
                        first = i;
                        break;
                    }
                }
                for(int i=start;i<=end;i++){
                    if(nums[i]<0){
                        last = i;
                    }
                }
                int temp = end-start+1;
                temp-=min(first-start+1,end-last+1); // remove the minimum out of prefix and suffix
                ans = max(ans,temp);
            }
        }
        return ans;
    }
};