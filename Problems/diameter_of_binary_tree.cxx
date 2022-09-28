/*
 * 543. Diameter of Binary Tree
 * Easy
 *
 * Given the root of a binary tree, return the length of the diameter of the tree.
 *
 * The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
 *
 * The length of a path between two nodes is represented by the number of edges between them.
 *
 *
 *
 * Example 1:
 *
 * Input: root = [1,2,3,4,5]
 * Output: 3
 * Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
 *
 * Example 2:
 *
 * Input: root = [1,2]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 * The number of nodes in the tree is in the range [1, 104].
 * -100 <= Node.val <= 100
*/
#include <iostream>
#include "Util/TreeNode.hxx"
#include "Util/catch.hpp"

namespace
{
	class Solution
	{
		int dim(TreeNode *root, int &max)
		{
			if (!root) return 0;
			int a;
			int b;

			a = dim(root->left, max);
			b = dim(root->right, max);

			max = std::max(max,a+b);
			return std::max(a,b) + 1;
		}
	public:
		int diameterOfBinaryTree(TreeNode *root)
		{
			int max{0};

			dim(root, max);

			return max;
		}
	};
}


TEST_CASE("Diameter of Binary Tree","[Diameter of Binary Tree][543]")
{
	TreeNodeCreator creator;
	Solution solution;

	SECTION("Example 1")
	{
		TreeNode *head = creator({1,2,3,4,5});
		CHECK(solution.diameterOfBinaryTree(head) == 3);
	}

	SECTION("Example 2")
	{
		TreeNode *head = creator({1,2});
		CHECK(solution.diameterOfBinaryTree(head) == 1);
	}

	SECTION("My test 1")
	{
		TreeNode *head = creator({1,2,3});
		CHECK(solution.diameterOfBinaryTree(head) == 2);
	}

	SECTION("My test 2")
	{
		TreeNode *head = creator({1});
		CHECK(solution.diameterOfBinaryTree(head) == 0);
	}

	SECTION("My test 3")
	{
		TreeNode *head = creator({
			1,
			1,nullptr,
			1,nullptr,nullptr,1,
			1,nullptr,nullptr,1,
			1,nullptr,nullptr,1,
			nullptr,nullptr,nullptr,1 });

		CHECK(solution.diameterOfBinaryTree(head) == 7);
	}

	SECTION("My test 4")
	{
		TreeNode *head = creator({
			4,
			-7,-3,
			nullptr,nullptr,-9,-3,
			9,-7,-4,nullptr,
			6,nullptr,-6,-6, nullptr,nullptr,
			0,6,5,nullptr,9,nullptr,
			nullptr,-1, -4,nullptr,nullptr,nullptr,-2
		});
		CHECK(solution.diameterOfBinaryTree(head) == 8);

	}

}