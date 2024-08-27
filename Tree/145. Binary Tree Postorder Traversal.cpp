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

// using recursion [trust on yourself,you are good!]

class Solution {
private:
  
   void solve(TreeNode* root, vector<int> & postorderResult){
       if(root == nullptr){
          return;
       }

       // LRN = left -> right -> node (print)
       solve(root->left,postorderResult);
       solve(root->right,postorderResult);
       postorderResult.push_back(root->val);
   }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorderResult;
        solve(root, postorderResult);
        return postorderResult;
    }
};


// using stack [iterative way]

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
         
        vector<int> postorder;
        if(root == NULL) {
            return postorder;
        }

        // create stack and push the root into the stack 1 
        stack<TreeNode*> st1,st2;
        st1.push(root);

        while(!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop();
            st2.push(node);
            if(node->left) st1.push(node->left);

            if(node->right) st1.push(node->right);
        }

        // push all the node stack 2 to array(vector)
        while(!st2.empty()) {
            TreeNode* temp = st2.top();
            postorder.push_back(temp->val);
            st2.pop();
        }
        return postorder;
    }
};














