class Solution {
public:
    string alphabetBoardPath(string target) {
        
        vector<vector<int>> dp = {
            {0,1,2,3,4},
            {5,6,7,8,9},
            {10,11,12,13,14},
            {15,16,17,18,19},
            {20,21,22,23,24},
            {25}
        };
        
        string res;
        
        int i = 0,j = 0;
        
        for(int k = 0;k<target.size();k++){
            int x = target[k] - 'a';
            while(dp[i][j] != x){
                if(x == 25 && dp[i][j]>20){         //special case: y --> z
                    res += 'L';
                    j--;
                }
                else if(x<dp[i][j]){               // go up or left
                    if(x<dp[i][0]){
                        res += 'U';
                        i--;
                    }else{
                        res += 'L';
                        j--;
                    }
                }else{                            // go down or right
                    if(x>dp[i][4]){  
                        res+= 'D';
                        i++;
                    }else{
                        res += 'R';
                        j++;
                    }
                }
            }
            res += '!';                            //pushing '!'
        }
        return res;
    }
};