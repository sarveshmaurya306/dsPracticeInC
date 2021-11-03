
class Solution {
public:
    int sumNumbers(TreeNode* root, int sum=0, int mul=1) {
       
        sum= sum * mul + ( root->val );
        int left = -1, right=-1;
        if(root->left!=NULL)
            left = sumNumbers(root->left, sum, 10);
        if(root->right!=NULL)
            right = sumNumbers(root->right, sum, 10);
        
        if(left==-1 && right==-1)
            return sum;
        if(left!=-1 && right!=-1)   return left+right;
        else if(left!=-1) return left;
        return right;
    }
};
//logic
/*
	iterate top to bottom with multiple value of 10;
*/

// have to iterate each node at least once
// so time complexity will be O(N)
//space = O(logN)

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