/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    long totalSum = 0;
    long maxProd = 0;

    void dfs(TreeNode* root){
        if(root == NULL) return ;
        dfs(root->left);
        dfs(root->right);
        totalSum += root->val;
    }

    long subTreeSum(TreeNode* root){
        if(root == NULL) return 0;
        long l = subTreeSum(root->left);
        long r = subTreeSum(root->right);
        long subtreesum = l + r + root -> val;
        maxProd = max(maxProd, (subtreesum) * (totalSum - subtreesum));
        return subtreesum;
    }


    int maxProduct(TreeNode* root) {
        dfs(root);
        subTreeSum(root);
        return (int)(maxProd % (long) (1e9 + 7));
    }
};

// Dry run
// Input: [1,2,3,4,5,6]

// Step 1: Calculate totalSum
// totalSum = 0
// dfs(1):
    // dfs(2):
        // dfs(4):
            // dfs(NULL): return
            // dfs(NULL): return
            // totalSum += 4 -> totalSum = 4
        // dfs(5):
            // dfs(NULL): return
            // dfs(NULL): return
            // totalSum += 5 -> totalSum = 9
        // totalSum += 2 -> totalSum = 11
    // dfs(3):
        // dfs(6):
            // dfs(NULL): return
            // dfs(NULL): return
            // totalSum += 6 -> totalSum = 17
        // dfs(NULL): return
        // totalSum += 3 -> totalSum = 20
// totalSum += 1 -> totalSum = 21

// Step 2: Calculate maxProd
// maxProd = 0
// subTreeSum(1):
    // subTreeSum(2):
        // subTreeSum(4):
            // subTreeSum(NULL): return 0
            // subTreeSum(NULL): return 0
            // subtreesum = 0 + 0 + 4 = 4
            // maxProd = max(0, 4 * (21 - 4)) = 68
            // return 4
        // subTreeSum(5):
            // subTreeSum(NULL): return 0
            // subTreeSum(NULL): return 0
            // subtreesum = 0 + 0 + 5 = 5
            // maxProd = max(68, 5 * (21 - 5)) = 80
            // return 5
        // subtreesum = 4 + 5 + 2 = 11
        // maxProd = max(80, 11 * (21 - 11)) = 110
        // return 11

    // subTreeSum(3):
        // subTreeSum(6):
            // subTreeSum(NULL): return 0
            // subTreeSum(NULL): return 0
            // subtreesum = 0 + 0 + 6 = 6
            // maxProd = max(110, 6 * (21 - 6)) = 110
            // return 6
        // subTreeSum(NULL): return 0
        // subtreesum = 6 + 0 + 3 = 9
        // maxProd = max(110, 9 * (21 - 9)) = 110
        // return 9
    // subtreesum = 11 + 9 + 1 = 21
    // maxProd = max(110, 21 * (21 - 21)) = 110
    // return 21
// Final maxProd = 110

// Return 110 % (1e9 + 7) = 110




