class Solution {
public:
    int solve(TreeNode* root, char track){
        if(root==nullptr) return 0;

        if(root->left==NULL && root->right==NULL){
            if(track=='l') return root->val;
            else if(track=='root') return 0;
        }
     
        return solve(root->left, 'l') + solve(root->right, 'r');
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root, 'root');
    }
};
//tc=>O(N) 
//space=>O(logN)