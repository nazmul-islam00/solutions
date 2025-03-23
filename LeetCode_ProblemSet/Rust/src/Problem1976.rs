use std::{collections::{BinaryHeap, VecDeque}, vec};

const INF: i128 = 1e12 as i128;
const MOD: i32 = 1e9 as i32 + 7;

impl Solution {
    pub fn count_paths(n: i32, roads: Vec<Vec<i32>>) -> i32 {
        let adj = Self::get_adj(n, &roads);
        let dis = Self::dijkstra(0, &adj);
        let (adj, mut parent_count) = Self::get_shortest_path_dag(&roads, &dis);
        let sorted = Self::topological_sorting(&mut parent_count, &adj);
        return Self::number_of_paths(0, n - 1, &adj, &sorted);
    }

    fn get_adj(n: i32, roads: &Vec<Vec<i32>>) -> Vec<Vec<i128>> {
        let mut adj = vec![vec![INF; n as usize]; n as usize];

        for road in roads {
            let u = road[0];
            let v = road[1];
            let wt = road[2];

            adj[u as usize][v as usize] = wt as i128;
            adj[v as usize][u as usize] = wt as i128;
        }

        return adj;
    }

    fn dijkstra(src: i32, adj: &Vec<Vec<i128>>) -> Vec<i128> {
        let mut dis = vec![INF; adj.len()];
        let mut st: BinaryHeap<(i128, i32)> = BinaryHeap::new();

        st.push((0, src));
        dis[src as usize] = 0;

        while !st.is_empty() {
            let p = st.pop();
            let node;
            match p {
                None => break,
                Some(p) => node = p.1,
            };

            for adj_node in 0..adj.len() {
                let wt = adj[node as usize][adj_node];

                if dis[adj_node] > dis[node as usize] + wt {
                    dis[adj_node] = dis[node as usize] + wt;
                    st.push((dis[adj_node], adj_node as i32));
                }
            }
        }

        return dis;
    }

    fn get_shortest_path_dag(roads: &Vec<Vec<i32>>, dis: &Vec<i128>) -> (Vec<Vec<i32>>, Vec<i32>) {
        let mut adj = vec![Vec::new()as Vec<i32>; dis.len() as usize];
        let mut parent_count = vec![0 as i32; dis.len() as usize];

        for road in roads {
            let u = road[0];
            let v = road[1];
            let wt = road[2];

            if dis[u as usize] + wt as i128 == dis[v as usize] {
                parent_count[v as usize] += 1;
                adj[u as usize].push(v);

            } else if dis[v as usize] + wt as i128 == dis[u as usize] {
                parent_count[u as usize] += 1;
                adj[v as usize].push(u);
            }
        }

        return (adj, parent_count);
    }

    fn topological_sorting(parent_count: &mut Vec<i32>, adj: &Vec<Vec<i32>>) -> Vec<i32> {
        let mut sorted: Vec<i32> = Vec::new();
        let mut q: VecDeque<i32> = VecDeque::new();

        for i in 0..parent_count.len() {
            if parent_count[i] == 0 {
                q.push_back(i as i32);
            }
        }

        while !q.is_empty() {
            let p = q.front();
            let node;
            match p {
                None => break,
                Some(p) => node = *p,
            };

            q.pop_front();
            sorted.push(node);

            for &adj_node in &adj[node as usize] {
                parent_count[adj_node as usize] -= 1;

                if (parent_count[adj_node as usize]) == 0 {
                    q.push_back(adj_node);
                }
            }
        }

        return sorted;
    }

    fn number_of_paths(src: i32, dst: i32, adj: &Vec<Vec<i32>>, sorted: &Vec<i32>) -> i32 {
        let mut dp = vec![0; adj.len() as usize];

        dp[dst as usize] = 1;

        for i in (0..sorted.len()).rev() {
            for j in 0..adj[sorted[i] as usize].len() {
                dp[sorted[i] as usize] = (dp[sorted[i] as usize] + dp[adj[sorted[i] as usize][j] as usize]) % MOD;
            }
        }

        return dp[src as usize];
    }
}
