class Solution {
public:
       int dp[366];
    
    bool travel(vector<int>& days,int d)
    {
        
        //return true if we have the chosen day in our days array
        for(int x:days)
        {
            if(x==d)
                return true;
        }
        //else simply return false
        return false;
    }
    
    int rec(vector<int>& days, vector<int>& costs,int currday)
    {
        // if we come on a day that goes out of the bounds then return 0
        if(currday>days[days.size()-1])
            return 0;
        
        if(dp[currday]!=-1)
            return dp[currday];
        
        int cost=1e9;
        // do we have to actualy travel this day?
        if(travel(days,currday))
        {
            //daily pass
            cost=costs[0]+rec(days,costs,currday+1);
            //weekly pass
            cost=min(cost,costs[1]+rec(days,costs,currday+7));
            //monthly pass
            cost=min(cost,costs[2]+rec(days,costs,currday+30));
        }
        //we don't have to travel on this day to move to next day
        else
            return rec(days,costs,currday+1);
        
        //return whatever the minimum cost came out to be after trying all passes
        return dp[currday]=cost;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof dp);
        return rec(days,costs,0);
    }
};