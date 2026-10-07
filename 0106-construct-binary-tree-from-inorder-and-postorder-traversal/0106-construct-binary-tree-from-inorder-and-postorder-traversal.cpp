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
    TreeNode* helper(vector<int>& inorder, int inStart, int inEnd,vector<int>& postorder, 
                    int postStart, int postEnd, map<int,int>& mp){

            if(inStart > inEnd || postStart > postEnd) return NULL;
            TreeNode* root = new TreeNode(postorder[postEnd]);
            int index = mp[postorder[postEnd]];
            int numsLeft = index - inStart;

            root->left = helper(inorder,inStart,index-1,postorder,postStart,postStart+numsLeft-1,mp);
            root->right = helper(inorder,index+1,inEnd,postorder,postStart+numsLeft,postEnd-1,mp);
            return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return helper(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
        
    }
};