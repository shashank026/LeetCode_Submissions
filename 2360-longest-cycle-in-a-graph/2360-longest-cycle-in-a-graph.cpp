class Solution {
public:
    int longestCycle(vector<int>& edges) {
        vector<int> in(edges.size(),0);
        for(int i=0;i<in.size();++i){
            if(edges[i] != -1){
                in[edges[i]]++;
            }
        }
        vector<int> visited(edges.size());
        queue<int> q;
        for(int i=0;i<in.size();++i){
            if(in[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int rv = q.front();
            visited[rv] = true;
            q.pop();
            int nbrs = edges[rv];
            if(nbrs != -1){
                in[nbrs]--;
                if(in[nbrs] == 0){
                    q.push(nbrs);
                }
            }
        }
        // Couting Wala Part -> Khan's Algo.
        int ans = -1;
        for(int i=0;i<visited.size();++i){
            if(!visited[i]){
                int count = 1;
                int nbrs = edges[i];
                visited[i] = true;
                while(nbrs != i){
                    visited[nbrs] = true;
                    count++;
                    nbrs = edges[nbrs];
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};