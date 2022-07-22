class Solution {
public:
    int dfs(vector<int>adj[],int headID,vector<int>& informTime){
        int mn = 0;
        for(int i:adj[headID]){
            mn = max(mn,dfs(adj,i,informTime));
        }
        return mn + informTime[headID];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int>adj[n];
        for(int i = 0;i<n;i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }
        return dfs(adj,headID,informTime);
    }
};