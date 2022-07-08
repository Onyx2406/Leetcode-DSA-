class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m  = matrix.size();
        if(m == 0)  return false;
        
        int n = matrix[0].size();
        
        int left=0,right=m*n-1;
        
        int pivotidx,pivotele;
        while(left<=right)
        {
            pivotidx=(left+right)/2;
            pivotele=matrix[pivotidx/n][pivotidx%n];
            if(target==pivotele)
            {
                return true;
            }
            else
            {
                if(target<pivotele)
                {
                    right=pivotidx-1;
                }
                else
                {
                    left=pivotidx+1;
                }
            }
        }
        return false;
    }
};