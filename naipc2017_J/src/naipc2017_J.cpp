//============================================================================
// Name        : naipc2017_J.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
char temp;
int w;

int main() {
	while (cin >> temp) {
		if (temp == 'W') {
			w++;
		} else {
			w--;
		}
	}
	cout << (w == 0);
	return 0;
}
