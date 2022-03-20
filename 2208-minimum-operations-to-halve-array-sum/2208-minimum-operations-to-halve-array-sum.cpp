class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum=0,ans=0;
        int res=0;
        
        priority_queue<double> pq;
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        ans=sum/2;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        while(sum>ans)
        {
            double curr = pq.top();
            pq.pop();
            curr/=2;
            sum-=curr;
            res++;
            pq.push(curr);
        }
        return res;
        
        
    }
};