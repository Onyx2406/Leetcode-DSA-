class Solution {
public:
   string largestPalindromic(string num) {
        unordered_map<char,int> m;
        for(auto x: num){
            m[x]++;
        }
        vector<char> one,other;
        for(auto x: m){
            if(x.second == 1){
                one.push_back(x.first);
            }else{
                if(x.second % 2==1){
                    one.push_back(x.first);
                    m[x.first]--;
                }
                other.push_back(x.first);
            }
        }
        
        sort(one.begin(), one.end(), greater<char>());
        sort(other.begin(), other.end());
        
        deque<char> dq;
        string s = "";
        if(one.size()>0){
            // s.push_back(one[0]);
            dq.push_back(one[0]);
        }
        if(other.size()==1 && other[0]=='0'){
            if(dq.empty()==true)
            {
                // s += '0';
                dq.push_back('0');
            }
            // return s;
        }else{
        for(auto x: other){
            int val = m[x]/2;
            while(val>0){
                // s += x;
                // s = x+s;
                dq.push_back(x);
                dq.push_front(x);
                val--;
            }
        }
        }
        while(dq.empty()==false){
            s += dq.front();
            dq.pop_front();
        }
        return s;
    }
};