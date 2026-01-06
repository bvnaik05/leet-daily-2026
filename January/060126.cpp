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
    int maxLevelSum(TreeNode* root) {
        if (root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        int maxlevel;
        int maxsum = INT_MIN;
        while(!q.empty()){
            level++;
            int size = q.size();
            int sum = 0;
            for(int i = 0; i < size; i++){
                TreeNode *ptr = q.front();
                q.pop();
                sum += ptr->val;
                if(ptr->left != NULL) q.push(ptr->left);
                if(ptr->right != NULL) q.push(ptr->right);
                
            }
            if(sum > maxsum){
                maxsum = sum;
                maxlevel = level;
            }
        }
        return maxlevel;
    }
};

// Dry run of BFS approach
// Input: root = [1,7,0,7,-8,null,null]
// level = 0, maxlevel = ?, maxsum = INT_MIN

// While loop iteration 1:
    // level = 1
    // size = 1
    // sum = 0
    // For loop iteration:
        // ptr = 1
        // sum = 1
        // Push 7 and 0 to queue
    // sum (1) > maxsum (INT_MIN), so maxsum = 1, maxlevel = 1

// While loop iteration 2:
    // level = 2
    // size = 2
    // sum = 0
    // For loop iteration 1:
        // ptr = 7
        // sum = 7
        // Push 7 and -8 to queue
    // For loop iteration 2:
        // ptr = 0
        // sum = 7
    // sum (7) > maxsum (1), so maxsum = 7, maxlevel = 2

// While loop iteration 3:
    // level = 3
    // size = 2
    // sum = 0
    // For loop iteration 1:
        // ptr = 7
        // sum = 7
    // For loop iteration 2:
        // ptr = -8
        // sum = -1
    // sum (-1) > maxsum (7)? No change

// Return maxlevel = 2
