#include <climits>
#include <functional>
#include <queue>
#include <set>
#include <vector>

class Solution {
   private:
    long long INF = 1000000000000;
    int MOD = 1e9 + 7;

   public:
    int countPaths(int n, std::vector<std::vector<int>>& roads) {
        const std::vector<std::vector<long long>> adj = getAdj(n, roads);
        const std::vector<long long> dis = disjkstra(0, adj);
        std::pair<std::vector<std::vector<int>>, std::vector<int>> dag = getShortestPathDAG(roads, dis);
        return numberOfPaths(0, n - 1, dag.first, dag.second);
    }

   private:
    const std::vector<std::vector<long long>> getAdj(const int n, const std::vector<std::vector<int>>& roads) {
        std::vector<std::vector<long long>> adj(n, std::vector<long long>(n, INF));

        for (const auto& road : roads) {
            int u = road[0], v = road[1], wt = road[2];
            adj[u][v] = adj[v][u] = wt;
        }

        return adj;
    }

    const std::vector<long long> disjkstra(const int src, const std::vector<std::vector<long long>>& adj) {
        std::vector<long long> dis(adj.size(), INF);
        std::set<std::pair<long long, int>> st;

        st.insert({0, src});
        dis[src] = 0;

        while (!st.empty()) {
            auto p = *(st.begin());
            st.erase(p);
            int node = p.second;

            for (int adjNode = 0; adjNode < adj.size(); adjNode++) {
                long long wt = adj[node][adjNode];

                if (dis[adjNode] > dis[node] + wt) {
                    if (dis[adjNode] != INF) st.erase({dis[adjNode], adjNode});

                    dis[adjNode] = dis[node] + wt;
                    st.insert({dis[adjNode], adjNode});
                }
            }
        }

        return dis;
    }

    std::pair<std::vector<std::vector<int>>, std::vector<int>> getShortestPathDAG(const std::vector<std::vector<int>>& roads, const std::vector<long long>& dis) {
        std::vector<std::vector<int>> adj(dis.size());
        std::vector<int> parentCount(dis.size(), 0);

        for (const auto& road : roads) {
            int u = road[0], v = road[1], wt = road[2];

            if (dis[u] + wt == dis[v]) {
                parentCount[v]++;
                adj[u].push_back(v);

            } else if (dis[v] + wt == dis[u]) {
                parentCount[u]++;
                adj[v].push_back(u);
            }
        }

        return {adj, parentCount};
    }

    const std::vector<int> topologicalSorting(std::vector<int>& parentCount, const std::vector<std::vector<int>>& adj) {
        std::vector<int> sorted;
        std::queue<int> q;

        sorted.reserve(parentCount.size());

        for (int i = 0; i < parentCount.size(); i++) {
            if (!parentCount[i]) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            sorted.push_back(node);

            for (const int adjNode : adj[node]) {
                parentCount[adjNode]--;

                if (!parentCount[adjNode]) q.push(adjNode);
            }
        }

        return sorted;
    }

    int numberOfPaths(int src, int dst, const std::vector<std::vector<int>>& adj, std::vector<int>& parentCount) {
        std::vector<int> sorted = topologicalSorting(parentCount, adj);
        std::vector<int> dp(parentCount.size(), 0);

        dp[dst] = 1;

        for (int i = sorted.size() - 1; i >= 0; i--) {
            for (int j = 0; j < adj[sorted[i]].size(); j++) {
                dp[sorted[i]] = (dp[sorted[i]] + dp[adj[sorted[i]][j]]) % MOD;
            }
        }

        return dp[src];
    }
};