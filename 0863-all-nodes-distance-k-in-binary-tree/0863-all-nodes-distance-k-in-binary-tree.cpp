/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void markparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& mp){
        if(root == NULL) return;
        if(root->left){
            mp[root->left] = root;
        }
        if(root->right){
            mp[root->right] = root;
        }
        markparent(root->left,mp);
        markparent(root->right,mp);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp; // child -> parent
        markparent(root,mp);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!q.empty()){
            int size = q.size();
            if(curr_level++ == k) break;
            for(int i = 0; i < size; i++){
                TreeNode* current = q.front();
                q.pop();
                if(current->left && visited[current->left] == false){
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && visited[current->right] == false){
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if(mp[current] && visited[mp[current]] == false){
                    q.push(mp[current]);
                    visited[mp[current]] = true;
                }
            }
        }
        vector<int> result;
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            result.push_back(current->val);
        }
        return result;
    }
};