#ifndef LEETPROBLEMS_TREENODE_HXX
#define LEETPROBLEMS_TREENODE_HXX

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

#include <initializer_list>
#include <memory>
#include <vector>
#include <queue>
#include <variant>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	friend std::ostream& operator<<(std::ostream& os, const TreeNode& node);
	bool operator!=(const TreeNode &other) const
	{
		return !(*this == other);
	}
	bool operator==(const TreeNode &other) const
	{
		if (this->val != other.val) return false;
		if (this->left && !other.left) return false;
		if (!this->left && other.left) return false;
		if (this->right && !other.right) return false;
		if (!this->right && other.right) return false;
		if (this->left)
		{
			if (*this->left != *other.left)
			{
				return false;
			}
		}
		if (this->right)
		{
			if (*this->right != *other.right)
			{
				return false;
			}
		}

		return true;
	}
};


class TreeNodeCreator
{
private:
	std::vector<std::unique_ptr<TreeNode>> nodes;
	TreeNode *create_node()
	{
		nodes.emplace_back(std::make_unique<TreeNode>());
		return nodes.back().get();
	}
public:
	TreeNode *operator()(std::initializer_list<std::variant<int, nullptr_t>> list)
	{
		TreeNode *result = nullptr;
		std::queue<TreeNode**> queue;
		if (list.size() == 0)
		{
			return result;
		}

		result = create_node();

		queue.push(&result->left);
		queue.push(&result->right);
		result->val = std::get<int>(*list.begin());

		size_t i = 1;
		while(!queue.empty() && i < list.size())
		{
			if (queue.front() && std::holds_alternative<int>(*(list.begin() + i)))
			{
				*queue.front() = create_node();
				(*queue.front())->val = std::get<int>(*(list.begin() + i));
				queue.push(&(*queue.front())->left);
				queue.push(&(*queue.front())->right);
			}
			else
			{
				queue.push(nullptr);
				queue.push(nullptr);
			}
			queue.pop();
			++i;
		}
		return result;
	}
};


#endif //LEETPROBLEMS_TREENODE_HXX
