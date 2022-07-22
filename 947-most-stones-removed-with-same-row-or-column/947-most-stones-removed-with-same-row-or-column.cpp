class Solution {
public:
    set<pair<int, int>> st;  // visited set to keep track of visited points
    unordered_map<int, vector<int>> rows, cols;  // store all columns of points in the same row and row of all points in same column
	
    void dfs(int r, int c){
	// add all points in the same row or column as curr point into the current island and recursively find the points that belong to the current island
        for(int col: rows[r]){
            if(st.find({r, col})==st.end()){
                st.insert({r, col});
                dfs(r, col);
            }
        }
        for(int row: cols[c]){
            if(st.find({row, c})==st.end()){
                st.insert({row, c});
                dfs(row, c);
            }
        }
    }
	
    int removeStones(vector<vector<int>>& stones) {
        for(vector<int> &s: stones){
            rows[s[0]].push_back(s[1]);
            cols[s[1]].push_back(s[0]);
        }
        int islands = 0;
        for(vector<int> &s: stones){
            if(st.find({s[0], s[1]})==st.end()){  // if current point is not yet visited, we have found a new island
                st.insert({s[0], s[1]});
                dfs(s[0], s[1]);  // do dfs and put all connected points in the visited set as they belong to the current island
                islands++;
            }
        }
        return stones.size()-islands;
    }
};
