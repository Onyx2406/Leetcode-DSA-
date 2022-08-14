class Solution {
public:
    string smallestNumber(string pattern) {
        int n=pattern.size();
        string ans;
        int cnt=0;
        while(cnt<n+1){ // Pushing pattern.size()+1 digits in the ans string
            ans.push_back(char('1'+cnt));
            cnt++;
        }
        for(int i=0;i<n;i++){
            int strt=i; // Calculating the starting and ending position of 'D'
            while(i<n && pattern[i]=='D'){
                i++;
            }
            int k=i; //Reverse from start index of 'D' to (i) where 'D' ends.
            while(strt<k){
                swap(ans[strt],ans[k]);
                strt++;
                k--;
            }
        }
        return ans;
    }
};