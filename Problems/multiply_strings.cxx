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
#include <iostream>

namespace{
	int char_to_int(char c)
	{
		return c - '0';
	}
	class Number
	{
	public:
		Number() = default;
		explicit Number(const std::string &str)
		{
			for (int i = 0; i < str.size(); ++i)
			{
				number.push_back(char_to_int(*(str.crbegin() + i)));
			}
		}
		Number(const Number &) = delete;
		Number(Number &&) = default;
		Number &operator=(const Number &) = delete;
		Number &operator=(Number &&) = default;

		Number operator*(int mul)
		{
			Number result;
			result.number = number;
			int carry = 0;

			for (int i = 0; i < result.size(); ++i)
			{
				result.number[i] *= mul;
				result.number[i] += carry%10;
				carry /= 10;
				carry += result.number[i]/10;
				result.number[i] %=10;
			}
			if (carry) result.number.push_back(carry%10);
			return std::move(result);
		}
		bool is_zero() const
		{
			for (const auto n: number)
			{
				if (n > 0)
				{
					return false;
				}
			}
			return true;
		}
		void operator*=(const Number &other)
		{
			int shift = 0;
			Number sum;
			Number tmp;
			if (other.is_zero())
			{
				tmp.number.push_back(0);
				std::swap(number, tmp.number);
				return;
			}
			for (int i = 0; i < other.number.size(); ++i)
			{
				tmp = this->operator*(other.number[i]);
				tmp.dump();
				sum.add_shift(tmp, shift);
				++shift;
			}
			if (sum.is_zero())
			{
				Number zero("0");
				std::swap(number, zero.number);
			}
			else
			{
				std::swap(number, sum.number);
			}
		}

		void add_shift(Number &other, size_t shift)
		{
			int carry = 0;
			while(shift >= number.size())
			{
				number.push_back(0);
			}
			for (int i = 0; i < other.size(); ++i, ++shift)
			{
				if (shift == number.size()) number.push_back(0);
				number[shift] += other.number[i];
				number[shift] += carry%10;
				carry /= 10;
				carry += number[shift] / 10;
				number[shift] %= 10;
			}
			if (carry) number.push_back(carry%10);
		}
		size_t size() { return number.size(); }
		std::string dump() const
		{
			std::string result;
			for (int i = 0; i < number.size(); ++i)
			{
				result +=  static_cast<char>(*(number.crbegin() + i)) + '0';
			}
			return result;
		}
	private:
		std::vector<int> number;
	};
	class Solution {
	public:
		std::string multiply(std::string num1, std::string num2) {
			Number n1(num1);
			Number n2(num2);
			n1 *= n2;
			return n1.dump();
		}
	};
}


TEST_CASE("Test multiply strings", "[multiply-strings][43]")
{
	Solution s;
	SECTION("Number")
	{
		Number num("99999");
		Number mul("11111");

		num *= mul;
		std::string result = num.dump();
		CHECK(result == "1111088889");
	}

	SECTION("Example 1")
	{
		CHECK(s.multiply("2", "3") == "6");
	}

	SECTION("Example 2")
	{
		CHECK(s.multiply("123", "456") == "56088");
	}

	SECTION("Zero")
	{
		CHECK(s.multiply("123", "0") == "0");
	}

	SECTION("One")
	{
		CHECK(s.multiply("123", "1") == "123");
	}

	SECTION("#1")
	{
		CHECK(s.multiply("345", "9") == "3105");
	}

	SECTION("#2")
	{
		CHECK(s.multiply("9", "345") == "3105");
	}
}

