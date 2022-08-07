class Solution {
public:
     int minSwaps(string s) {
        int n=s.size();
        int c1=0,c0=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') c1++;
            else c0++;
        }
        if(n%2==0&&c1!=c0) return -1;    //if n is even but count of 1 and 0 is different
        if(n%2!=0&&c1>c0&&c1-1!=c0) return -1; //if n is odd and count of 1 is greater than it has to be bigger by differenc of 1 only 
        if(n%2!=0&&c1<c0&&c1+1!=c0) return -1;
        int ans1=0,ans2=0;
        
        //if count of 1 is greater than count 0 than at first place we have to put 1 only
        if(c1>c0){
            for(int i=0;i<n;i+=2){
            if(s[i]=='0') ans2++;
        }
            return ans2;
        }
        //if count of 0 is greater than count 0 than at first place we have to put 0 only
        if(c0>c1){
            for(int i=0;i<n;i+=2){
            if(s[i]=='1') ans2++;
        }
            return ans2;
        }
        
        //if count is same than 2 possible answer choose minimum
        for(int i=0;i<n;i+=2){
            if(s[i]=='0') ans2++;
            else ans1++;
        }
        cout<<ans1<<ans2;
        return min(ans1,ans2);
    }
};