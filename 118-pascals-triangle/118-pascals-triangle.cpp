class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> tri(numRows);
        
        for(int i=0;i<numRows;i++)
        {
            tri[i].resize(i+1); //if you dont want to do this we can avoid by using pushback 
            tri[i][0]=1;
            tri[i][i]=1;
            
            for(int j=1;j<i;j++)
            {
                tri[i][j]=tri[i-1][j] +tri[i-1][j-1];
            }
            
        }
        return tri;
    }
};