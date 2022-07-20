class Solution {
public:
    void dfs(vector<vector<char>>&board, int x, int y, int n, int m){
        board[x][y] = 'V';
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        for(int i=0;i<4;i++){
            int newx = x + dx[i];
            int newy = y + dy[i];
            
            if(newx >=0 && newx<n && newy >=0 && newy < m && board[newx][newy] == 'X'){
                dfs(board, newx, newy, n, m);
            }
        }
    }
    
    int countBattleships(vector<vector<char>>& board) {
        int count=0;
        
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'X'){
                    ++count;
                    dfs(board, i, j, n, m);
                }
            }
        }
        
        return count;
    }
};