#include "pch.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Integers{
private:
public:
	int input;
	Integers(int a) {
		input = a;
	}
	~Integers() {};

int reverse() {
	string output;
	string str = to_string(input);
	for (int  i = str.length() - 1; i >= 0; i--)
	{
		if (str[i] == '0')
			continue;
		output.push_back(str[i]);
	}
	char tmp = output.back();
	if (output.back() == '-')
	{
		output.pop_back();
		output = '-' + output;
	}
	return stoi(output);

}
void swapData(char* a, char* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
int reverseOpt()
{
	string inStr = to_string(input);
	string outStr = inStr;
	int j = inStr.length() - 1;
	int negative = 0;
	for (auto i = 0; i < (inStr.length() -1)/2; i++, j--) {
		if (i == 0 && inStr[i] == '-')
		{
			negative = 1;
			continue;

		}
		/*tmp = outStr[j];
		outStr[j] = inStr[i];
		inStr[i] = tmp; */
		swapData(&outStr[i], &outStr[j+negative]);

	}
	return stoi(outStr);
}

};

int main()
{
	Integers i(95688761);
	cout << "input = "<<i.input<<" output = " << i.reverseOpt();

	return 0;
}