class Solution {
public:
    int jump(vector<int>& nums) {
        int current=0,farthest=0,jumps=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            farthest=max(farthest,nums[i]+i);
            if(current==i){
                current=farthest;
                jumps++;
            }
        }
        return jumps;
    }
};