class Solution {
public:
    int romanToInt(string s) {
        // creating a map to store the character and its value
        unordered_map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;)
        {
            // if the value of the next element is greater than previous one 
            // for example if we encounter IX , then basically we need to subtract the value of 'I' from value of 'X' and then add to answer and then also increment the iterator i by 2 , as we have already considered i+1 element
            // 'IX'= 10-1=9
            // 'XL'= 50-10=40
            // 'IV'= 5-1=4
            if(i+1<n && m[s[i]]<m[s[i+1]])
            {
                ans=ans+m[s[i+1]]-m[s[i]];
                i=i+2;
            }
            // else we can simply add the value of s[i] to answer and increment i by 1
            // example- 'VIII' = 5+1+1+1 = 8
            //          'LX' = 50+10=60    
            else
            {
                ans=ans+m[s[i]];
                i++;
            }
        }
        return ans;
        
    }
};