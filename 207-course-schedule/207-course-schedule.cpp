class Solution {
public:
    vector<int> adj[2002];
    int state[2002];
    bool ok;
    void dfs(int u)
    {
        if(state[u]==1)
        {
            ok=false;
            return;
        }
        state[u]=1;
        for(auto v:adj[u])
        {
            if(state[v]!=2)
            {
                dfs(v);
            }
        }
        state[u]=2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0;i<numCourses;++i)
        {
            state[i]=0;
            adj[i].clear();
        }
        ok=true;
        int m=prerequisites.size();
        for(int i=0;i<m;++i)
        {
            int u=prerequisites[i][0],v=prerequisites[i][1];
            adj[v].push_back(u);
        }
        for(int i=0;i<numCourses;++i)
        {
            if(state[i]==0)
            {
                dfs(i);
            }
        }
        return ok;
    }
};