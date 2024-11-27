struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if(root != NULL){
        if(val == root->val){
            return root;
        }
        else{
            if(val<root->val){
                return searchBST(root->left,val);
            }
            else{
                return searchBST(root->right,val);
            }
        }
    }
    return NULL; 
}
