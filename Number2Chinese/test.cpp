#include <iostream>
#include "Number2Chinese.h"
using namespace std;
int main() {
	int a;
	double b;
	while(true)
	{
		cin >> a;
		cout << number2Chinese(a) << endl;
		cin >> b;
		cout << number2Chinese(b) << endl;
	}
}