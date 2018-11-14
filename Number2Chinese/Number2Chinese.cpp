#include "Number2Chinese.h"
#include <sstream>
#include <iomanip>
using namespace std;

string numberChinese[] = { "零","一","二","三","四","五","六","七","八","九" };

string number2Chinese(string number);
string integer2Chinese(const string& number);
string fraction2Chinese(const string& number);

string number2Chinese(string number)
{
	string chinese;
	if (number[0] == '-')
	{
		chinese += "负";
		number.erase(number.begin());
	}
	size_t pos = number.find('.');
	if (pos != string::npos)
	{
		string integer(number.begin(), number.begin() + pos);
		string fraction(number.begin() + pos + 1, number.end());
		chinese += integer2Chinese(integer) + "点" + fraction2Chinese(fraction);
	}
	else
	{
		chinese += integer2Chinese(number);
	}
	return chinese;
}

string integer2Chinese(const string& number)
{
	string chinese;

	auto size = number.length();
	for (size_t i = 0; i < number.length(); ++i)
	{
		const char &n = number[i];
		if (n != '0')
		{
			chinese += numberChinese[n - '0'];
		}
		else
		{
			if (size % 4 == 3 && (number[i + 1] != '0' || number[i + 2] != '0'))
			{
				chinese += "零";
			}
			else if (size % 4 == 2 && number[i - 1] != '0' && number[i + 1] != '0')
			{
				chinese += "零";
			}
			else if (i == 0)
			{
				chinese += "零";
			}
		}
		if (size % 4 == 1)
		{
			if (size / 4 == 1 &&
				(number[i] != '0' || number[i - 1] != '0' || number[i - 2] != '0' || number[i - 3] != '0'))
			{
				chinese += "万";
			}
			if (size / 4 == 2 &&
				(number[i] != '0' || number[i - 1] != '0' || number[i - 2] != '0' || number[i - 3] != '0'))
			{
				chinese += "亿";
			}
			if (size / 4 == 3 &&
				(number[i] != '0' || number[i - 1] != '0' || number[i - 2] != '0' || number[i - 3] != '0'))
			{
				chinese += "兆";
			}
		}
		if (n != '0')
		{
			if (size % 4 == 2)
			{
				chinese += "十";
			}
			else if (size % 4 == 3)
			{
				chinese += "百";
			}
			else if (size % 4 == 0)
			{
				chinese += "千";
			}
		}
		--size;
	}

	return chinese;
}

string fraction2Chinese(const string& number)
{
	string chinese;

	for (size_t i = 0; i < number.size(); ++i)
	{
		chinese += numberChinese[number[i] - '0'];
	}

	return chinese;
}

string number2Chinese(long long number)
{
	stringstream ss;
	ss << number;
	return number2Chinese(ss.str());
}

std::string number2Chinese(int number)
{
	stringstream ss;
	ss << number;
	return number2Chinese(ss.str());
}

std::string number2Chinese(double number, unsigned n)
{
	stringstream ss;
	ss << fixed << setprecision(n) << number;
	return number2Chinese(ss.str());
}

