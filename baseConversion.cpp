#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

const int WRONG_INPUT = -1;

string to_result(unsigned long long num, int base_output) {
	string output; int r; char ascii;
	for (; num != 0; num /= base_output) {
		r = num % base_output;
		(r >= 10) ? ascii = r + 55 : ascii = r + 48;
		output += ascii;
	}
	reverse(output.begin(), output.end());
	return output;
}

unsigned long long to_decimal(string num_str, int base_input) {
	unsigned long long result = 0; int ascii;
	for (int i = 0; i < num_str.size(); i++) {
		ascii = num_str[i];
		(ascii >= 65) ? ascii -= 55 : ascii -= 48;
		if (ascii >= base_input) return WRONG_INPUT;
		result += (ascii * pow(base_input, (num_str.size() - i - 1)));
	}
	return result;
}

int main() {
	unsigned long long num;
	int base_input, base_output;
	string num_str;
	cout << "base input: ";
	cin >> base_input;
	cout << "INPUT: ";
	cin >> num_str;
	for_each(num_str.begin(), num_str.end(), [](char& c) {
		c = ::toupper(c);
		});
	num = to_decimal(num_str, base_input);
	if (num == WRONG_INPUT) { cout << "\nInvalid input!\n"; return EXIT_FAILURE; }
	cout << endl << "base output: ";
	cin >> base_output;
	num_str = to_result(num, base_output);
	cout << "OUTPUT: " << num_str << endl;
	return EXIT_SUCCESS;
}
