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
    int ans=0; // storing number of palindrom
    unordered_map<int,int> mp; // storing freq 0f each number
    void helper(TreeNode*root)
    {
        if(root==NULL) return;
        mp[root->val]++; // increasing freq of number
        
        if(root->left==NULL&&root->right==NULL) //leaf node
        {
            int temp=0;
            for(int i=0;i<10;i++)
            {
                if(mp[i]%2!=0)
                {
                    temp++;
                }
            }
            if(temp<=1) 
                ans++;
        }
        helper(root->left);
        helper(root->right);
        mp[root->val]--; // decreasing the number of freq when we are going back from leaf node to another node
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        helper(root);
        return ans;
    }
};


















