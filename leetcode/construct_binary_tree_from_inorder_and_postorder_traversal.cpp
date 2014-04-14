/*

 Construct Binary Tree from Inorder and Postorder Traversal

 Given inorder and postorder traversal of a tree, construct the binary tree.

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
	TreeNode *createTree(vector<int> &postorder, int postStart, int postEnd,
			vector<int> &inorder, int inStart, int inEnd) {
		if (inStart > inEnd)
			return nullptr; // stop recursion

		// in postorder, the last node is root, create it
		TreeNode *root = new TreeNode(postorder[postEnd]);

		int i = 0;
		// i is valid here as postorder and inorder both are valid and they have no duplicates
		// find the root node in inorder and thus split it into left node set and right node set
		for (i = inStart; i <= inEnd; i++) {
			if (postorder[postEnd] == inorder[i])
				break;
		}

		// create left child tree recursively
		root->left = createTree(postorder, postStart,
				i + postStart - inStart - 1, inorder, inStart, i - 1);
		// create right child tree recursively
		root->right = createTree(postorder, postEnd - inEnd + i, postEnd - 1,
				inorder, i + 1, inEnd);

		return root;
	}

	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		int inLen = inorder.size(), postLen = postorder.size();
		if (inLen != postLen || inLen == 0)
			return nullptr;
		return createTree(postorder, 0, postLen - 1, inorder, 0, inLen - 1);
	}
};

void print_tree_postorder(TreeNode *root) {
	if (root) {
		print_tree_postorder(root->left);
		print_tree_postorder(root->right);
		cout << root->val << ends;
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
	vector<int> postorder = { 4, 2, 5, 3, 1 };
	vector<int> inorder = { 4, 2, 1, 5, 3 };

	TreeNode *root = sol.buildTree(inorder, postorder);
	print_tree_postorder(root);
	cout << endl;
	print_tree_inorder(root);

	return 0;
}
