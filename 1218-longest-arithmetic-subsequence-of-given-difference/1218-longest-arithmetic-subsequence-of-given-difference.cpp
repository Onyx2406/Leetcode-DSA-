	class Solution {
	public:
		int longestSubsequence(vector<int>& v, int d) {

			unordered_map<int,int> m;
			int n = v.size();
			int res = 0;
			for(int i=0; i<n; i++){
				int cnt = 1;
				if(m.find(v[i]-d)!=m.end()){
					cnt += m[v[i]-d];
				}
				m[v[i]] = cnt;
				res = max(res,cnt);
			}
			return res;
		}
	};