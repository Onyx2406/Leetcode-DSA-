class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-2;i++)
    {
    if(i==0 || (i>0 && nums[i]!=nums[i-1]))
    {
    int l=i+1,h=nums.size()-1,sum =0 - nums[i];

                while(l<h)
                {
                    if(sum == nums[l]+nums[h])
                    {
                        vector<int> temp(3);
                        temp[0]=nums[i];
                        temp[1]=nums[l];
                        temp[2]=nums[h];
                        res.push_back(temp);
                        while(l<h && nums[l]==nums[l+1]) 
                            l++;
                        while(l<h && nums[h]==nums[h-1])
                            h--;
                        l++;
                        h--;
                    }
                    else if(nums[l]+nums[h] <sum)
                        l++;
                    else
                        h--;
                }
            }
        }
        return res;
    }
};