/*
 * 621. Task Scheduler
 * Medium
 *
 * Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
 *
 * However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.
 *
 * Return the least number of units of times that the CPU will take to finish all the given tasks.
 *
 *
 *
 * Example 1:
 *
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation:
 * A -> B -> idle -> A -> B -> idle -> A -> B
 * There is at least 2 units of time between any two same tasks.
 *
 * Example 2:
 *
 * Input: tasks = ["A","A","A","B","B","B"], n = 0
 * Output: 6
 * Explanation: On this case any permutation of size 6 would work since n = 0.
 * ["A","A","A","B","B","B"]
 * ["A","B","A","B","A","B"]
 * ["B","B","B","A","A","A"]
 * ...
 * And so on.
 *
 * Example 3:
 *
 * Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
 * Output: 16
 * Explanation:
 * One possible solution is
 * A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
 *
 *
 *
 * Constraints:
 *
 * 1 <= task.length <= 104
 * tasks[i] is upper-case English letter.
 * The integer n is in the range [0, 100].
*/
#include <unordered_map>
#include <iostream>
#include "Util/catch.hpp"
namespace
{
	class Solution
	{
	public:
		int leastInterval(std::vector<char> &tasks, int n)
		{
			std::unordered_map<char, int> map;
			int cnt = 0;

			for (auto c: tasks)
			{
				++map[c];
				cnt = std::max(cnt, map[c]);
			}
			int result = (cnt-1) * (n+1);

			for (auto e: map)
			{
				if (e.second == cnt)
				{
					result++;
				}
			}

			return std::max((int)tasks.size(), result);
		}
	};
}

TEST_CASE("Test Task Scheduler", "[task_scheduler][621]")
{
	Solution solution;

	SECTION("Example 1")
	{
		std::vector<char> tasks({'A', 'A', 'A', 'B', 'B', 'B'});
		CHECK(solution.leastInterval(tasks, 2) == 8);
	}

	SECTION("Example 2")
	{
		std::vector<char> tasks({'A', 'A', 'A', 'B', 'B', 'B'});
		CHECK(solution.leastInterval(tasks, 0) == 6);
	}

	SECTION("Example 3")
	{
		std::vector<char> tasks({'A','A','A','A','A','A','B','C','D','E','F','G'});
		CHECK(solution.leastInterval(tasks, 2) == 16);
	}

	SECTION("One")
	{
		std::vector<char> tasks({'A'});
		CHECK(solution.leastInterval(tasks, 2) == 1);
	}

	SECTION("Two")
	{
		std::vector<char> tasks({'A', 'A'});
		CHECK(solution.leastInterval(tasks, 2) == 4);
	}

	SECTION("Three")
	{
		std::vector<char> tasks({'A', 'A', 'A'});
		CHECK(solution.leastInterval(tasks, 2) == 7);
	}

	SECTION("Bug")
	{
		std::vector<char> tasks({'A','A','A','B','B','B', 'C','C','C', 'D', 'D', 'E'});
		CHECK(solution.leastInterval(tasks, 2) == 12);
	}
}


