use std::cell::RefCell;
use std::cmp::max;
use std::rc::Rc;

impl Solution {
    pub fn lca_deepest_leaves(
        root: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        let mut depths: Vec<i32> = vec![0; 1001];
        let mut answer = None;

        fn get_max_depth<F>(
            root: &Option<Rc<RefCell<TreeNode>>>,
            cur_depth: i32,
            set_depth: &mut F,
        ) -> i32
        where
            F: FnMut(i32, i32),
        {
            match root {
                None => cur_depth,
                Some(root) => {
                    set_depth(root.borrow().val, cur_depth + 1);
                    max(
                        get_max_depth(&root.borrow().left, cur_depth + 1, set_depth),
                        get_max_depth(&root.borrow().right, cur_depth + 1, set_depth),
                    )
                }
            }
        }

        let max_depth = get_max_depth(&root, -1, &mut |val, depth| {
            depths[val as usize] = depth;
        });

        fn get_lca<F>(
            root: &Option<Rc<RefCell<TreeNode>>>,
            depths: &Vec<i32>,
            max_depth: i32,
            set_answer: &mut F,
        ) -> bool
        where
            F: FnMut(Option<Rc<RefCell<TreeNode>>>),
        {
            if let None = root {
                return false;
            }

            let left = get_lca(
                &root.as_ref().unwrap().borrow().left,
                depths,
                max_depth,
                set_answer,
            );
            let right = get_lca(
                &root.as_ref().unwrap().borrow().right,
                depths,
                max_depth,
                set_answer,
            );

            if depths[root.as_ref().unwrap().borrow().val as usize] == max_depth {
                set_answer(root.clone());
                return true;
            }
            if left && right {
                set_answer(root.clone());
                return true;
            }

            if left || right {
                return true;
            }
            false
        }

        get_lca(&root, &depths, max_depth, &mut |node| {
            answer = node;
        });

        return answer;
    }
}
