class Solution {
public:
    void traverse(int x, int y, vector<vector<int>> &heights, vector<vector<bool>> &reach, int n, int m){
        if(reach[x][y]==true) return;
        reach[x][y]=true;
        if(x+1 < n  && heights[x][y]<=heights[x+1][y]) traverse(x+1, y, heights, reach, n, m);
        if(y+1 < m  && heights[x][y]<=heights[x][y+1]) traverse(x, y+1, heights, reach, n, m);
        if(x-1 >= 0 && heights[x][y]<=heights[x-1][y]) traverse(x-1, y, heights, reach, n, m);
        if(y-1 >= 0 && heights[x][y]<=heights[x][y-1]) traverse(x, y-1, heights, reach, n, m);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> reachP(n, vector<bool> (m, false));
        vector<vector<bool>> reachA(n, vector<bool> (m, false));
        //Pacific
        for(int i=0;i<n;i++){
            traverse(i , 0, heights, reachP, n, m);
        }
        for(int i=0;i<m;i++){
            traverse(0 , i, heights, reachP, n, m);
        }
        
        //Atlantic
        for(int i=0;i<n;i++){
            traverse(i , m-1, heights, reachA, n, m);
        }
        for(int i=0;i<m;i++){
            traverse(n-1 , i, heights, reachA, n, m);
        }
        
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout << reachP[i][j] << "," << reachA[i][j] << "  ";
                if(reachP[i][j] && reachA[i][j]) ans.push_back({i,j});
            }
            cout << "\n";
        }
        
        return ans;
    }
};