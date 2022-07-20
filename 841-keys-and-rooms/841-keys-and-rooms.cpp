class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       stack<int> s;
        int n = rooms.size();
        if( n <= 1) return true;
        vector<int> vis(rooms.size(), 0);
        s.push(0);
        
        while(!s.empty()){
            int i = s.top();
            s.pop();
            if(vis[i] == 0){
                vis[i] = 1;
                n--;
                for(auto j: rooms[i]) s.push(j);
            }  
        }
        if(n == 0){ return true; }
        return false;
    }
};