#include <iostream>
using namespace std;

int main()
{
	int t = 1;
	//1-7ÐÐ
	for (int i = 1; i <= 7; i++) {
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}
	//7ÐÐÒÔÏÂ
	for (int i = 6; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}
}