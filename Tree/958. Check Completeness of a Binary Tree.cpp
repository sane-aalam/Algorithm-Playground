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
private:
     // using BFS count all nodes into Binary Tree
     // you can try simple dfs algorithm 1 + call(root->left) + call(root->right);
    int totalNumberNodes(TreeNode * root){
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        while(!q.empty()){
            TreeNode * temp = q.front();
            q.pop();
            count++;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        return count;
   }
   bool dfs(TreeNode * root, int index, int &total){
        if(root == nullptr){
            return true;
        }
        if(index >= total){
            return false;
        }
        bool left =  dfs(root->left,2*index+1, total);
        bool right = dfs(root->right,2*index+2, total);

        return left && right;
   }
public:
    bool isCompleteTree(TreeNode* root) {
        int totalNodes = totalNumberNodes(root); // count all nodes into binary tree 

        int index = 0;
        // think like binary tree as array 
        // root = 1
        // root-left = 2 * 1 + 1
        // root-right = 2 * 1 + 2;
        return dfs(root,index,totalNodes);
    }
};