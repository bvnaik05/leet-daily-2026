class Solution
{
public:
    TreeNode *subtreeWithAllDeepest(TreeNode *root) { return dfs(root).second; }
    pair<int, TreeNode *> dfs(TreeNode *node)
    {
        if (!node)
            return {0, nullptr}; 
            // Check for height of left and right subtree 
            pair<int, TreeNode*> left = dfs(node->left); 
            pair<int, TreeNode*> right = dfs(node->right); // If left and right's height are same, it means deepest nodes are split among both sides. 
            if(left.first == right.first){ 
                return {left.first + 1, node}; 
            } // If left's height is more, we have our answer on the left side. 
            else if(left.first > right.first){ 
                return {left.first + 1, left.second}; 
            } // If right's height is more, we have our answer on the right side. 
            else{ 
                return {right.first + 1, right.second}; 
            } 
    }
};

// Dry run

// Input: root = [3,5,1,6,2,0,8,null,null,7,4]
// The tree structure is as follows:
//         3
//        / \
//       5   1
//      / \ / \
//     6  2 0  8
//       / \
//      7   4
// The deepest nodes are 6, 7, 4, 0, and 8 at depth 3.
// The smallest subtree containing all deepest nodes is the subtree rooted at node 2, which includes

// nodes 7 and 4.
// The function will return the node with value 2.
// The output will be the subtree:
//         2
//        / \
//       7   4

