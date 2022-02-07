class Solution {
public:
    bool isValid(string s) {
      vector<char> v;
      for(int i=0;i<s.size();i++){
        if(s[i]=='c'){
          int sz = v.size();
          if(sz<2 || v[sz-2]!='a' || v[sz-1]!='b') return false;
          v.pop_back();
          v.pop_back();
        }else{
          v.push_back(s[i]);
        }
      }
      return v.size()==0;
        
    }
};