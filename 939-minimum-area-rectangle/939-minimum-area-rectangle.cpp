class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int ans = INT_MAX;
        // creating the map for storing all the points
        map<pair<int,int>,bool>mp;
        for(int i=0;i<points.size();i++)
        {
            pair<int,int> current_coordinate = {points[i][0] , points[i][1]};
            mp[current_coordinate] = true;
        }
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                // we got two coordinates here 
                // assuming these are the coordinates of end A and C;
                int x1 = points[i][0];
                int x2 = points[j][0];
                int y1 = points[i][1];
                int y2 = points[j][1];
                
                //checking weather these coordinates are diagonal coordinates
                if((x1 != x2) && (y1 != y2))
                {
                    // finding the next two coordinates
                    
                    // coordinates of B
                    int x3 = x1;
                    int y3 = y2;
                    // coordinates of D
                    int x4 = x2;
                    int y4 = y1;
                    
                    // checking weather these coordinates exist in the given coordinates
                    if((mp.find({x3,y3}) != mp.end())  &&  (mp.find({x4,y4}) != mp.end()))
                    {
                        // calculating area 
                        int current_area = abs(y3 - y4) * abs(x3 - x4);
                        ans = min(ans,current_area);
                    }
                    
                
                }
            }
        }
        if(ans == INT_MAX)
            return 0;
        return ans;
        
    }
};