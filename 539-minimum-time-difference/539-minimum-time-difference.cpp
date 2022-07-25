class Solution {
public:
    int findMinDifference(vector<string> &timePoints){
	int n=timePoints.size();
	vector<int> res(n);
	for(int i=0;i<n;i++){
		res[i]=stoi(timePoints[i].substr(0,2))*60+stoi(timePoints[i].substr(3,2));
	}
	sort(res.begin(),res.end());
	int ans=INT_MAX;
	for(int i=1;i<n;i++){
		ans=min(ans,res[i]-res[i-1]);
	}
	ans=min(ans,res[0]-res[n-1]+24*60);
	return ans;
}
};