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
    vector<int>A;
    int sum(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        else if(root->left==NULL && root->right==NULL)
        {
            return root->val;
        }
        else if(root->left==NULL || root->right==NULL)
        {
            if(root->left==NULL)
            {
                A.push_back(root->val);
                int z=sum(root->right);
                A.push_back(z);
                A.push_back(z+root->val);
                return max(root->val,z+root->val);
            }
            if(root->right==NULL)
            {
                 A.push_back(root->val);
                int z=sum(root->left);
                A.push_back(z);
                A.push_back(z+root->val);
                return max(root->val,z+root->val);
            }
        }
        else
        {
            A.push_back(root->val);
            int left=sum(root->left);
            int right=sum(root->right);
              A.push_back(left+right+root->val);
            A.push_back(left);
            A.push_back(right);
            A.push_back(root->val+left);
            A.push_back(root->val+right);
            return max(root->val,max(root->val+left,root->val+right));
        }
        return -1001;
    }
    int maxPathSum(TreeNode* root) {
        A.push_back(sum(root));
        return *max_element(A.begin(),A.end());
    }
};
