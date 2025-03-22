use std::vec;

struct DisjointSet {
    parent: Vec<i32>,
}

impl DisjointSet {
    fn init(&mut self, n: i32) {
        for idx in 0..n as usize {
            self.parent[idx] = idx as i32;
        }
    }

    fn findParent(&mut self, idx: i32) -> i32 {
        if self.parent[idx as usize] == idx {
            return idx;
        }

        self.parent[idx as usize] = self.findParent(self.parent[idx as usize]);
        return self.parent[idx as usize];
    }
}

impl Solution {
    pub fn count_complete_components(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        let mut ds = DisjointSet {
            parent: vec![0; n as usize],
        };
        ds.init(n);

        let mut isConnected = vec![vec![false; n as usize]; n as usize];

        for edge in edges {
            let u = edge[0];
            let v = edge[1];

            isConnected[u as usize][v as usize] = true;
            isConnected[v as usize][u as usize] = true;

            let parent1 = ds.findParent(u);
            let parent2 = ds.findParent(v);

            ds.parent[parent1 as usize] = parent2;
        }

        let mut components = vec![vec![0; 0]; n as usize];

        for idx in 0..n {
            components[ds.findParent(idx) as usize].push(idx);
        }

        let mut count = 0;

        for component in components {
            if component.is_empty() {
                continue;
            }

            let mut connected = true;

            for &idx1 in &component {
                if !connected {
                    break;
                }

                for &idx2 in &component {
                    if idx1 == idx2 {
                        continue;
                    }

                    if !isConnected[idx1 as usize][idx2 as usize] {
                        connected = false;
                        break;
                    }
                }
            }

            if connected {
                count += 1;
            }
        }

        return count;
    }
}
