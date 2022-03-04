class Solution {
public:
    int longestWPI(vector<int>& hours) {
        vector<int>vc;
        int n = hours.size();
        for(int i=0;i<hours.size();i++)
        {
            if(hours[i] > 8)
                vc.push_back(1);
            else
                vc.push_back(0);
        }
        int sum = 0;
        int maxlen = 0;
        int currlen;
        map<int,int>prevSum;
         for (int i = 0; i < n; i++) {
 
        
        if (vc[i] == 1)
            sum++;
        else
            sum--;
 
        
        if (sum > 0) {
            maxlen = i + 1;
        }
 
       
        else if (sum <= 0) {
            if (prevSum.find(sum - 1) != prevSum.end()) {
                currlen = i - prevSum[sum - 1];
                maxlen = max(maxlen, currlen);
            }
        }
 
        if (prevSum.find(sum) == prevSum.end())
            prevSum[sum] = i;
    }
 
    return maxlen;
        
    }
};