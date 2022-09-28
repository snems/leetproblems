/* 226. Invert Binary Tree
 * Easy
 *
 * Given the root of a binary tree, invert the tree, and return its root.
 *
 *
 *
 * Example 1:
 *
 * Input: root = [4,2,7,1,3,6,9]
 * Output: [4,7,2,9,6,3,1]
 *
 * Example 2:
 *
 * Input: root = [2,1,3]
 * Output: [2,3,1]
 *
 * Example 3:
 *
 * Input: root = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 */
#include "Util/TreeNode.hxx"
#include "Util/catch.hpp"

namespace
{
	class Solution
	{
	public:
		TreeNode *invertTree(TreeNode *root)
		{
			if (root)
			{
				std::swap(root->left, root->right);
				if (root->left) root->left = invertTree(root->left);
				if (root->right) root->right = invertTree(root->right);
			}
			return root;
		}
	};
}


TEST_CASE("Test Invert Binary Tree","[invert_binary_tree][226]")
{
	TreeNodeCreator creator;
	Solution solution;

	SECTION("Example 1")
	{
		TreeNode *head = creator({4,2,7,1,3,6,9});
		TreeNode *expected = creator({4,7,2,9,6,3,1});
		CHECK(*solution.invertTree(head) == *expected);
	}

	SECTION("Example 2")
	{
		TreeNode *head = creator({2,1,3});
		TreeNode *expected = creator({2,3,1});
		CHECK(*solution.invertTree(head) == *expected);
	}

	SECTION("Example 3")
	{
		TreeNode *head = creator({});
		CHECK(solution.invertTree(head) == nullptr);
	}

}
