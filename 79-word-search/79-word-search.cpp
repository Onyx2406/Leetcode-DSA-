class Solution {
public:
   bool dfs(vector<vector<char>>& board, string word, vector<vector<bool>>& isVisited, int idx, int i, int j, int m, int n){
        if(idx==word.size()){ // Base Case
            return true; 
        }
        if(i<0 || i>m-1 || j<0 || j>n-1 || isVisited[i][j]==true ||board[i][j]!=word[idx]){ // Edge Case
            return false;
        }
        
        isVisited[i][j]=true;
        
        bool a= dfs(board, word, isVisited, idx+1, i+1, j, m, n);
        bool b= dfs(board, word, isVisited, idx+1, i, j+1, m, n);
        bool c= dfs(board, word, isVisited, idx+1, i-1, j, m, n);
        bool d= dfs(board, word, isVisited, idx+1, i, j-1, m, n);
        
        if(a||b||c||d){ // If any of the path returns true. ----> True
            return true;
        }
        isVisited[i][j]=false; // backtrack. We have not succeded in this path but this grid might get used by some other path
        return false; // none of the above 4 path returns true. So --> False
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();  int n=board[0].size();
        
        vector<vector<bool>> isVisited(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isVisited[i][j]==false && board[i][j]==word[0]){
                    bool a= dfs(board, word, isVisited, 0, i, j, m, n);
                    if(a==true){
                        return true; 
                    }
                }
            }
        }
        return false;
    }
};