struct UnionFind {
    parent: Vec<usize>,
    pub count: usize,
}

impl UnionFind {
    pub fn new(n: usize) -> Self {
        let mut parent = vec![0; n];
        for i in 0..n {
            parent[i] = i;
        }
        UnionFind {
            parent,
            count: n,
        }
    }
    pub fn find(&mut self, x: usize) -> usize {
        if self.parent[x] != x {
            self.parent[x] = self.find(self.parent[x]);
        }
        self.parent[x]
    }
    pub fn union(&mut self, x: usize, y: usize) {
        let root_x = self.find(x);
        let root_y = self.find(y);
        if root_x == root_y {
            return;
        }
        self.parent[root_x] = root_y;
        self.count -= 1;
    }

}

fn find_circle_num(is_connected: Vec<Vec<i32>>) -> i32 {
        let n = is_connected.len();
        let mut union_find = UnionFind::new(n);
        for i in 0..n {
            for j in 0..n {
                if is_connected[i][j] == 1 {
                    union_find.union(i, j);
                }
            }
        }
        union_find.count as i32
}

#[cfg(test)]
mod tests {
    use crate::find_circle_num;

    #[test]
    fn it_works() {
        assert_eq!(find_circle_num(vec![vec![1,1,0],vec![1,1,0],vec![0,0,1]]), 2);
        assert_eq!(find_circle_num(vec![vec![1,0,0],vec![0,1,0],vec![0,0,1]]), 3);
    }
}