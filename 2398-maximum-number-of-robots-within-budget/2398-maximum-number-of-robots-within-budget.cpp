class Solution {
public:
    int maximumRobots(vector<int>& charge, vector<int>& run, long long budget) {
        int ans = 0;
        
        //we will use two pointer 
        //we will find the cost and also the 
        //let us have prefix array of sum of cost of subarray in range in O(1)
        
        int n = run.size();
        vector<long long>pref(n);
        long long tot = 0;
        
        for(int i=0;i<n;++i){
            tot+=run[i];
            pref[i] = tot;
        }
        
        set<int>P;
        map<int,int>count;
        //so we will use set to find the max element in O(log n)
        //we will use count to remove the elements
        
        tot = 0;
        int c = 0,start = 0;
        long long z;
        for(int i=0;i<n;++i){
           //I choose the current value 
            //add in set and increment frequency of it
            P.insert(charge[i]);
            count[charge[i]]++;
            c++;
            
            //now find the current score
            tot = pref[i];
            if(start)tot-=pref[start-1];
            z = c;
            tot*=z;
            auto it = P.rbegin();
            long long val = *it;
            
            tot += val;
           
            
            //now if this score is within the budget then we store the max size of subarray in answer
            if(tot<=budget){
                ans = max(ans,c);
            }
            else{
                //now I need to move my left poitner until
                //the score is less than budget
                
                while(start<=i){
                    
                    if(count[charge[start]] == 1){
                        P.erase(charge[start]);
                    }
                    count[charge[start]]--;
                    start++;
                    c--;
                    
                    //this means our subarray is empty
                    if(start>i)break;
                    
                    auto it2 = P.rbegin();
                    val = *it2;
                    long long cur_score = 0;
                    cur_score += pref[i];
                    cur_score -= pref[start-1];
                    z = c;
                    cur_score*=c;
                    cur_score+=val;
                    
                    if(cur_score<=budget)break;
                }
            }
        }
        
        return ans;
    }
};