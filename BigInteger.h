#include <iostream>

class BigInteger
{
public:
	BigInteger() : b_integer("") {};

	BigInteger(const std::string& integer) : b_integer(integer) {};

	BigInteger operator+(const BigInteger& other) const
	{
		return Add(b_integer, other.b_integer);
	}

	void valueof(const std::string& integer)
	{
		b_integer = integer;
	}

	std::string parseString() const
	{
		return b_integer;
	}

private:
	std::string b_integer;

	static std::string Add(const std::string& integer, const std::string& integer2)
	{
		int len = integer.length() - 1;
		int len2 = integer2.length() - 1;
		int carry = 0;
		std::string result = "";

		while (len >= 0 || len2 >= 0 || carry > 0)
		{
			int n = (len >= 0) ? (integer[len--] - '0') : 0;
			int n2 = (len2 >= 0) ? (integer2[len2--] - '0') : 0;
			int sum = n + n2 + carry;
			carry = sum / 10;
			result += (sum % 10) + '0';
		}
		return reverse(result);
	}

	static std::string reverse(const std::string& str)
	{
		std::string result = "";
		for (int i = str.length() - 1;i >= 0;i--)
		{
			result += str[i];
		}
		return result;
	}
};

std::ostream& operator<<(std::ostream& os, const BigInteger& bigInterger)
{
	os << bigInterger.parseString();
	return os;
}
