class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) {
            return 0;
        }

        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; i++) {
            graph[arr[i]].push_back(i);
        }

        vector<int> curs; // store current layer
        curs.push_back(0);
        unordered_set<int> visited;
        int step = 0;

        // when current layer exists
        while (!curs.empty()) {
            vector<int> nex;

            // iterate the layer
            for (int node : curs) {
                // check if reached end
                if (node == n - 1) {
                    return step;
                }

                // check same value
                for (int child : graph[arr[node]]) {
                    if (!visited.count(child)) {
                        visited.insert(child);
                        nex.push_back(child);
                    }
                }

                // clear the vector to prevent redundant search
                graph[arr[node]].clear();

                // check neighbors
                if (node + 1 < n && !visited.count(node + 1)) {
                    visited.insert(node + 1);
                    nex.push_back(node + 1);
                }
                if (node - 1 >= 0 && !visited.count(node - 1)) {
                    visited.insert(node - 1);
                    nex.push_back(node - 1);
                }
            }

            curs = nex;
            step++;
        }

        return -1;
    }
};
