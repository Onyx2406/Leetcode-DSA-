class Solution {
public:
   bool isPresent(const string &s, const vector<string> &words, unordered_set<string> &st)
{
    int n = s.size();

    for (int i = 1; i <= n; i++)
    {
        if (!st.count(s.substr(0, i)))
            return false;
    }
    return true;
}
string longestWord(vector<string> &words)
{
    unordered_set<string> s;
    for (auto it : words)
        s.insert(it);
    sort(words.begin(), words.end());

    int maxLength = 0;
    string res = "";
    for (auto it : words)
    {
        if (isPresent(it, words, s))
        {
            if (maxLength < it.size())
            {
                maxLength = it.size();
                res = it;
            }
        }
    }
    if (maxLength == 0)
        return "";
    return res;
}
};