/*

 Construct Binary Tree from Preorder and Inorder Traversal

 Given preorder and inorder traversal of a tree, construct the binary tree.

 Note:
 You may assume that duplicates do not exist in the tree.

 */

#include <iostream>
#include <vector>

using namespace std;

//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	TreeNode *createTree(vector<int> &preorder, int preStart, int preEnd,
			vector<int> &inorder, int inStart, int inEnd) {
		if (inStart > inEnd)
			return nullptr; // stop recursion

		// in preorder, the first node is root, create it
		TreeNode *root = new TreeNode(preorder[preStart]);

		int i = 0;
		// i is valid here as preorder and inorder both are valid and they have no duplicates
		// find the root node in inorder and thus split it into left node set and right node set
		for (i = inStart; i <= inEnd; i++) {
			if (preorder[preStart] == inorder[i])
				break;
		}

		// create left child tree recursively
		root->left = createTree(preorder, preStart + 1, i + preStart - inStart,
				inorder, inStart, i - 1);
		// create right child tree recursively
		root->right = createTree(preorder, preEnd + i + 1 - inEnd, preEnd,
				inorder, i + 1, inEnd);

		return root;
	}

	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		int preLen = preorder.size(), inLen = inorder.size();
		if (preLen != inLen || preLen == 0)
			return nullptr;
		return createTree(preorder, 0, preLen - 1, inorder, 0, inLen - 1);
	}
};

void print_tree_preorder(TreeNode *root) {
	if (root) {
		cout << root->val << ends;
		print_tree_preorder(root->left);
		print_tree_preorder(root->right);
	}
}

void print_tree_inorder(TreeNode *root) {
	if (root) {
		print_tree_inorder(root->left);
		cout << root->val << ends;
		print_tree_inorder(root->right);
	}
}

int main(int argc, char *argv[]) {
	Solution sol;
	vector<int> preorder = { 1, 2, 4, 3, 5 };
	vector<int> inorder = { 4, 2, 1, 5, 3 };

	TreeNode *root = sol.buildTree(preorder, inorder);
	print_tree_preorder(root);
	cout << endl;
	print_tree_inorder(root);

	return 0;
}
