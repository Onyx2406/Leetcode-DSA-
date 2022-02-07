// class Solution {
// public:
//     int maximumGain(string s, int x, int y) {
//       stack<char> st;
//       int sum=0;

//       if(x>y)
//       {
//         for(auto i:s)
//         {
//           if(st.empty())  {st.push(i);}
//           else if(st.top() == 'a' && s[i] == 'b') {st.pop(); sum+=x;}
//           else  {st.push(i);}
//         }
//       }
//       if(y>x)
//       {
//         for(auto i:s)
//         {
//           if(st.empty())  {st.push(i);}
//           else if(st.top() == 'b' && s[i] == 'a') {st.pop(); sum+=y;}
//           else  {st.push(i);}
//         }
//       }
//       return sum;
//     }
// };
class Solution {
public:
    
    int helper(string&str, char a, char b){
        int count =0;
        stack<char> st;
        for(int i=0;i<str.length();i++) {
            if(!st.empty() && str[i]==b && st.top()==a) {
                st.pop();
                count++;
            }
            else {
                st.push(str[i]);
            }
        }
        str="";
        while(!st.empty()) {
            str += st.top();
              st.pop();
            }
        reverse(str.begin(),str.end());
        return count;
    }
    
    int maximumGain(string s, int x, int y) {
        int ca=0,cb=0;
        if(x>y) {
            ca = helper(s,'a','b');
            cb = helper(s,'b','a');
        }
        else {
            cb = helper(s,'b','a');
            ca = helper(s,'a','b');
        }
        return ca*x + cb*y;
    }
};