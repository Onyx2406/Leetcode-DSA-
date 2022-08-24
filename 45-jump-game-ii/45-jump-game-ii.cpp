class Solution {
public:
    int jump(vector<int>& nums) {
        int jumpIndex=0,maxJump=0,jump=0;
		//jumpIndex & jump is use for jumpCount
		//maxJump is use for calculate max jump till jumpIndex
        for(int i=0;jumpIndex<nums.size()-1;i++){
            maxJump = max(maxJump,i+nums[i]);
            if(i==jumpIndex){
                jumpIndex = maxJump;
                jump++;
            }    
        }
        
        return jump;
    }
};