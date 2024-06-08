#include <iostream>
#include <queue>
using namespace std;
 
class TreeNode {
public:    
    int val;
    TreeNode *left, *right;
    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};
 
TreeNode* buildTree(int *nums, int size) {
    if (nums == NULL) return NULL;
    
    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < size) {
        TreeNode* curr = q.front();
        q.pop();
        if (i < size) {
            curr->left = new TreeNode(nums[i++]);
            q.push(curr->left);
        }
        if (i < size) {          
            curr->right = new TreeNode(nums[i++]);
            q.push(curr->right);
        }
    }
    return root;
}
 
void printPreOrderTree(TreeNode* root) {
    if (!root) return;
    if(root->val != 0)
        cout << root->val << " ";
    printPreOrderTree(root->left);
    printPreOrderTree(root->right);
}

void printPostOrderTree(TreeNode* root) {
    if (!root) return;
    printPostOrderTree(root->left);
    printPostOrderTree(root->right);
    if(root->val != 0)
        cout << root->val << " ";
}
 
int main() {
    int* nums;
    int size, order;
    cin >> size;
    nums = new int(size);
    cin >> order;
    for(int i = 0; i<size; i++){
        cin >> nums[i];
    }
    TreeNode* root = buildTree(nums,size);
    if(order == 1){
        cout << "preorder traversal: ";
        printPreOrderTree(root);
    }
    else if(order == 2){
        cout << "postorder traversal: ";
        printPostOrderTree(root);
    }
    return 0;
}