/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int large(TreeNode<int> *root,int &max){
     if(root!=NULL){
    	int l=large(root->left,max);
    	int r=large(root->right,max);
        int s=root->data;
        root->data=l+r;
        if(s+l+r>max) max=s+l+r;
    	return s+l+r;
    }
    return 0;
}
int largestSubtreeSum(TreeNode<int> *root) {
	// Write your code here.
 	int max=-10000;
    large(root,max);
	if(max==-10000) return -1;
    return max;
}
