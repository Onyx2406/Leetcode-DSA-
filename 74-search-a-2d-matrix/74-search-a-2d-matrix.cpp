class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0) return false;
        int col = matrix[0].size();

        int row_bottom = row -1;
        int col_left = 0;
        while(row_bottom >=0 && col_left<col){
            if(matrix[row_bottom][col_left] == target)
                return true;
            else if(matrix[row_bottom][col_left] > target)
                row_bottom--;
            else {
                col_left++;
                if(col_left <= col-1 && matrix[row_bottom][col_left] > target)
                    break;
            }

        }
        return false;
    }
};