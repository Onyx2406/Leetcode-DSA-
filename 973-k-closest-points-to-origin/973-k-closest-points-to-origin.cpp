class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
		//min priority queue syntax
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        vector<vector<int>> answer;
        
        for (int i = 0; i < points.size(); i++) {
            pq.push({points[i][0]*points[i][0] + points[i][1]*points[i][1], i});
        }
        
        while (K--) {
            answer.push_back(points[pq.top().second]);
            pq.pop();
        }
        
        return answer;
    }
};