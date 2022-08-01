class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        long long int MOD = pow(10,9) + 7;
        
        stack<pair<int,int>>s;
        
        //storing next smaller element index on left and right.
        vector<pair<int,int>>sm(n,{-1,-1});
        
        s.push({arr[0],0});
        
        //next smaller element index on left.
        for(int i=1;i<n;i++)
        {
            while(!s.empty() && s.top().first >= arr[i])
            {
                s.pop();
            }
            
            if(!s.empty())
            {
                sm[i].first = s.top().second;
            }
            s.push({arr[i],i});
        }
        
        while(!s.empty()) s.pop();
        
        s.push({arr[n-1],n-1});
        
        //next smaller element on right.
        for(int i=n-2;i>=0;i--)
        {                       
                                //if we pop equal element when counting left smaller element
                                //then we have to consider it when count right smaller element
            while(!s.empty() && s.top().first > arr[i])
            {
                s.pop();
            }
            
            if(!s.empty())
            {
                sm[i].second = s.top().second;
            }
            s.push({arr[i],i});   
        }
        
        long long int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            long long int left = i , right = n-i-1;
            
            if(sm[i].first != -1)
            {
                left = i - sm[i].first - 1;
            }
            if(sm[i].second != -1)
            {
                right = sm[i].second - i - 1;
            }
            
            //from left index to right index -> minimum element is arr[i]
            //so total possible subarray from left index to right index including ith index
            //in every subarray is (left+1)*(right+1).
            
                        //cout << arr[i] << " " << left <<" " << right << endl;
            ans = (ans + ((left+1)*(right+1))*arr[i])%MOD;
        }
        return ans;
        
    }
};