/* 110. Balanced Binary Tree
 * Easy
 *
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as:
 *
 * a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
 *
 *
 *
 * Example 1:
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: true
 *
 * Example 2:
 *
 * Input: root = [1,2,2,3,3,null,null,4,4]
 * Output: false
 *
 * Example 3:
 *
 * Input: root = []
 * Output: true
 *
 *
 *
 * Constraints:
 *
 * The number of nodes in the tree is in the range [0, 5000].
 * -104 <= Node.val <= 104
*/
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
#include "Util/TreeNode.hxx"
#include "Util/catch.hpp"

namespace {
class Solution
{
	size_t depth_max(TreeNode *root, size_t levels, size_t &max)
	{
		if (root)
		{
			++levels;
			max = std::max(max, levels+1);
			depth_max(root->left,levels, max);
			depth_max(root->right,levels, max);
		}
		return levels;
	}
public:
	bool isBalanced(TreeNode *root)
	{
		if (!root) return true;
		size_t max_left = 1;
		size_t max_right = 1;

		if (root->left)
		{
			depth_max(root->left,0, max_left);
		}
		if (root->right)
		{
			depth_max(root->right,0, max_right);
		}
		if (max_left > max_right)
		{
			std::swap(max_left, max_right);
		}
		if ((max_right - max_left) > 1) return false;

		if (root->left)
		{
			if (!isBalanced(root->left)) return false;
		}
		if (root->right)
		{
			if (!isBalanced(root->right)) return false;
		}

		return true;
	}
};

}


TEST_CASE("Test Balanced Binary Tree","[balanced_binary_tree][110]")
{
	TreeNodeCreator creator;
	Solution solution;

	SECTION("Example 1")
	{
		TreeNode *head = creator({3,9,20,nullptr,nullptr,15,7});
		CHECK(solution.isBalanced(head) == true);
	}

	SECTION("Example 2")
	{
		TreeNode *head = creator({1,2,2,3,3,nullptr,nullptr,4,4});
		CHECK(solution.isBalanced(head) == false);
	}

	SECTION("Example 3")
	{
		TreeNode *head = creator({});
		CHECK(solution.isBalanced(head) == true);
	}

	SECTION("My test 1")
	{
		TreeNode *head = creator({1, 2,2, 3,3,nullptr,nullptr, 4,nullptr,nullptr,nullptr, 4,nullptr,nullptr,nullptr});
		CHECK(solution.isBalanced(head) == false);
	}

	SECTION("My test 2")
	{
		TreeNode *head = creator({1, 2,2, 3,3,nullptr,3, 4,nullptr,nullptr,nullptr, 4,4,4,4});
		CHECK(solution.isBalanced(head) == false);
	}

	SECTION("My test 3")
	{
		TreeNode *head = creator({1, 2,2, 3,3,3,nullptr, 4,4,4,4, 4,nullptr,nullptr,nullptr});
		CHECK(solution.isBalanced(head) == false);
	}

	SECTION("My test 4")
	{
		TreeNode *head = creator({1, 2,2, 3,3,3,3, 4,4,4,4, 4,4,4,4});
		CHECK(solution.isBalanced(head) == true);
	}

	SECTION("My test 5")
	{
		TreeNode *head = creator({1, 2});
		CHECK(solution.isBalanced(head) == true);
	}
}