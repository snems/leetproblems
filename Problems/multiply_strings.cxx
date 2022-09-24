/*
 * 43. Multiply Strings
 * Medium
 *
 * Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
 * Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
 *
 *
 *
 * Example 1:
 *
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 *
 * Example 2:
 *
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 *
 *
 *
 * Constraints:
 *
 * 1 <= num1.length, num2.length <= 200
 * num1 and num2 consist of digits only.
 * Both num1 and num2 do not contain any leading zero, except the number 0 itself.
 */

#include "Util/catch.hpp"
#include <string>

namespace{
	class Solution {
		size_t to_number(const std::string &str)
		{
			size_t result = 0;
			size_t multiplier = 1;
			const auto iter = str.crbegin();
			while(iter != str.crend())
			{
				result += (*iter - '0') * multiplier;
				multiplier *= 10;
			}
			return result;
		}
	public:
		std::string multiply(std::string num1, std::string num2) {

		}
	};
}