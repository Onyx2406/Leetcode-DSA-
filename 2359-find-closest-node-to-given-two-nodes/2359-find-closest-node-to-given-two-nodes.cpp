class Solution {
public:
    
    void DFS(int i, int dist, vector<bool> &visited, vector<pair<bool,int>> &path,  vector<vector<int>> &graph){
        visited[i] = true;
        path[i] = {true, dist};
        for(auto adj: graph[i]){
            if(!visited[adj]){
                DFS(adj, dist+1, visited, path, graph);
            }
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
		// Create the adjacency list from the given edges
        vector<vector<int>> graph(edges.size());
        for(int i=0; i<edges.size(); i++){
            if(edges[i] == -1){
                continue;
            }
            graph[i].push_back(edges[i]);
        }
        		
		// Stores the depth of the nodes that can be reached from node1 and node2
        vector<pair<bool,int>> path1(edges.size());
        vector<pair<bool,int>> path2(edges.size());
        
		// Find the path that is possible starting from node1 by traversing through outgoing edges
        vector<bool> visited(edges.size(), false);
        DFS(node1, 0, visited, path1, graph);
		
		// Find the path that is possible starting from node2 by traversing through outgoing edges
        visited.assign(edges.size(), false);
        DFS(node2, 0, visited, path2, graph);

        int ans = INT_MAX, node;
        for(int i=0; i<edges.size(); i++){
			// Node cannot be reached from the node1 or node2
            if(!path1[i].first || !path2[i].first){
                continue;
            }
			// Find the maxium distance to that node
            int dist = max(path1[i].second, path2[i].second);
            if(dist < ans){
                ans = dist;
                node = i;
            }
            
        }
        return ans == INT_MAX ? -1 : node;
    }
};