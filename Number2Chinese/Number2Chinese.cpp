#include "Number2Chinese.h"
#include <sstream>
#include <iomanip>
using namespace std;

string numberChinese[] = { "��","һ","��","��","��","��","��","��","��","��" };

string number2Chinese(string number);
string integer2Chinese(const string& number);
string fraction2Chinese(const string& number);

string number2Chinese(string number)
{
	string chinese;
	if (number[0] == '-')
	{
		chinese += "��";
		number.erase(number.begin());
	}
	size_t pos = number.find('.');
	if (pos != string::npos)
	{
		string integer(number.begin(), number.begin() + pos);
		string fraction(number.begin() + pos + 1, number.end());
		chinese += integer2Chinese(integer) + "��" + fraction2Chinese(fraction);
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
				chinese += "��";
			}
			else if (size % 4 == 2 && number[i - 1] != '0' && number[i + 1] != '0')
			{
				chinese += "��";
			}
			else if (i == 0)
			{
				chinese += "��";
			}
		}
		if (size % 4 == 1)
		{
			if (size / 4 == 1 &&
				(number[i] != '0' || number[i - 1] != '0' || number[i - 2] != '0' || number[i - 3] != '0'))
			{
				chinese += "��";
			}
			if (size / 4 == 2 &&
				(number[i] != '0' || number[i - 1] != '0' || number[i - 2] != '0' || number[i - 3] != '0'))
			{
				chinese += "��";
			}
			if (size / 4 == 3 &&
				(number[i] != '0' || number[i - 1] != '0' || number[i - 2] != '0' || number[i - 3] != '0'))
			{
				chinese += "��";
			}
		}
		if (n != '0')
		{
			if (size % 4 == 2)
			{
				chinese += "ʮ";
			}
			else if (size % 4 == 3)
			{
				chinese += "��";
			}
			else if (size % 4 == 0)
			{
				chinese += "ǧ";
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

