/* 437. Path Sum III
 * Medium
 *
 * Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
 *
 * The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
 *
 *
 *
 * Example 1:
 *
 * Input: root = [10,5,-3,3,2,nullptr,11,3,-2,nullptr,1], targetSum = 8
 * Output: 3
 * Explanation: The paths that sum to 8 are shown.
 *
 * Example 2:
 *
 * Input: root = [5,4,8,11,nullptr,13,4,7,2,nullptr,null,5,1], targetSum = 22
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 * The number of nodes in the tree is in the range [0, 1000].
 * -109 <= Node.val <= 109
 * -1000 <= targetSum <= 1000
*/

#include "Util/TreeNode.hxx"
#include "Util/catch.hpp"

class Solution {
	long long pathSumBase(TreeNode* root, long long targetSum)
	{
		long long result = 0;
		if (root)
		{
			if (root->val == targetSum)
			{
				++result;
			}
			long long new_target = targetSum - root->val;
			result += pathSumBase(root->left, new_target);
			result += pathSumBase(root->right, new_target);

		}
		return result;
	}
public:
	int pathSum(TreeNode* root, int targetSum) {
		long long result = 0;

		if (root)
		{
			result += pathSumBase(root, targetSum);
			result += pathSum(root->left, targetSum);
			result += pathSum(root->right, targetSum);
		}

		return static_cast<int>(result);
	}
};

TEST_CASE("Test Path Sum III","[path_sum_iii][437]")
{
	TreeNodeCreator creator;
	Solution solution;

	SECTION("Example 1")
	{
		TreeNode *head = creator({10,5,-3,3,2,nullptr,11,3,-2,nullptr,1});
		CHECK(solution.pathSum(head, 8) == 3);
	}

	SECTION("Example 2")
	{
		TreeNode *head = creator({5,4,8,11,nullptr,13,4,7,2,nullptr,nullptr,5,1});
		CHECK(solution.pathSum(head, 22) == 3);
	}

	SECTION("My test 1")
	{
		TreeNode *head = creator({});
		CHECK(solution.pathSum(head, 22) == 0);
	}

	SECTION("My test 2")
	{
		TreeNode *head = creator({5,4,8,11,nullptr,13,4,7,2,nullptr,nullptr,5,1});
		CHECK(solution.pathSum(head, 0) == 0);
	}

	SECTION("My test 3")
	{
		TreeNode *head = creator({5,4,0,11,nullptr,13,4,7,2,nullptr,nullptr,5,0});
		CHECK(solution.pathSum(head, 0) == 2);
	}

	SECTION("My test 4")
	{
		TreeNode *head = creator({5,-3,8,-11,nullptr,13,4,7,2,nullptr,nullptr,5,1});
		CHECK(solution.pathSum(head, -14) == 1);
	}

	SECTION("My test 5")
	{
		TreeNode *head = creator({1,-2,-3,1,3,-2,nullptr,-1 });
		CHECK(solution.pathSum(head, -1) == 4);
	}

	SECTION("My test 6")
	{
		TreeNode *head = creator({
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr,
		                         1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000, nullptr, 1000000000
		});
		CHECK(solution.pathSum(head, 1000) == 0);
	}
}
