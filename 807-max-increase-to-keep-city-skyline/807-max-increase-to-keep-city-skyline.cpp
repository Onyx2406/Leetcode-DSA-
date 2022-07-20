class Solution {
public:
   int maxIncreaseKeepingSkyline(vector<vector<int>>& grid){
        
        int row = grid.size();
        int col = grid[0].size();
        vector<int> east(row, 0);
        vector<int> north(col, 0);
        
        //Find east face and north face (max items in row and columns)
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                east[i] = max(east[i], grid[i][j]);
                north[j] = max(north[j], grid[i][j]);
            }
        }
        
        //Finding the answer
        int ans = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int height = min(east[i], north[j]);
                if(grid[i][j] < height){
                    ans += height - grid[i][j];
                }
            }
        }
        return ans;
    }
};