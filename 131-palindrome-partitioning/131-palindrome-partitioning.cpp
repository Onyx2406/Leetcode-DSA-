class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> pars;
        vector<string> par;
        partition(s,0,par,pars);
        return pars;
    }
private :
    void partition(string& s,int start,vector<string> &par,vector<vector<string>> &pars)
    {
        int n = s.size();
        if(start == n)
        {
            pars.push_back(par);
        }
        else
        {
            for (int i = start; i<n; i++)
            {
                if(isPalindrome(s,start,i))
                {
                    par.push_back(s.substr(start,i-start+1));
                    partition(s,i+1,par,pars);
                    par.pop_back();
                }
            }
        }
    }
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
    //The problem has a nice structure that backtracking naturally fits in. The structure is, given a starting position start, we search from start till the end of the string. Once we reach a position i such that the sub-string from start to i (s.substr(start, i - start + 1)) is a palindrome, we add it to a temporary par. Then we recursively call the same function to process the remaining sub-string. Once we reach the end of the string, we add par into the result pars of all the possible partitioning.

//Then, backtracking happens. Remember that at position i, we find s.substr(start, i - start + 1) to be a palindrome and we immediately add it to par. It is obvious that there may be some other position j such that j > i and s.substr(start, j - start + 1) is also a palindrome. So we need to recover to the state before adding s.substr(start, i - start + 1) to par and continue to find the next palindrome position after i. And we simply need to pop s.substr(start, i - start + 1) out of par to make things work.

};