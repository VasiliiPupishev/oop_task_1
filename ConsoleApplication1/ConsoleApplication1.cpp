#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int foo1(int a[]);
int foo2(int a[]);
int foo3(int a[]);
void print_menu(int a[]);
void fill_array(int *a);

void foo_1();
void foo_2();
void foo_3();
void fill_array_1();
void print_menu_1();

int A[12];
int MAX = INT_MIN;
int MIN = INT_MAX;
int S1;
int S2;


int main()
{
	int a[12];
	cout << "select v.1 or v.2 of programm" << endl;
	string req;
	cin >> req;
	if (req == "1") {
		fill_array(a);
		while (req != "exit") {
			print_menu(a);
			cin >> req;
			if (req == "1") { fill_array(a); }
			if (req == "2") { cout << "sum 1 is " << foo1(a) << endl; }
			if (req == "3") { cout << foo2(a) << endl; }
			if (req == "4") { cout << "sum of negative numbers is " << foo3(a) << endl; }
			if (req == "exit") { break; }
		}
	}
	else if (req == "2") {
		fill_array_1();
		while (req != "exit") {
			print_menu_1();
			cin >> req;
			if (req == "1") { fill_array_1(); }
			if (req == "2") {
				foo_1();
				cout << "sum 1 is " << S1 << endl; 

			}
			if (req == "3") {
				foo_2();
				if(MAX == INT_MIN)
					cout << "min " << MIN << endl;
				else
					cout << "max " << MAX << endl;
			}
			if (req == "4") {
				foo_3();
				cout << "sum of negative numbers is " << S2 << endl; 
			}
			if (req == "exit") { break; }
		}
	}
	return 0;

}
void print_menu(int *a) {
	cout << "you array is ";
	for (int i = 0; i < 12; i++) {
		cout << a[i] << " ";
	}
	cout << endl << "1 - rewrite array" << endl << "2 - sum of the values on not even indexes" << endl << "3 - max or min"<<endl<<"4 - sum of negative numbers"<< endl << "exit" << endl;
}

void print_menu_1() {
	cout << "you array is ";
	for (int i = 0; i < 12; i++) {
		cout << A[i] << " ";
	}
	cout << endl << "1 - rewrite array" << endl << "2 - sum of the values on not even indexes" << endl << "3 - max or min" << endl << "4 - sum of negative numbers" << endl << "exit" << endl;
}

void reinit() {
	MAX = INT_MIN;
	MIN = INT_MAX;
	S1 = 0;
	S2 = 0;
}

void fill_array(int *a) {
	cout << "input 12 numbers, one in new line" << endl;
	for (int i = 0; i < 12; i++) {
		cin >> a[i];
	}
}

void fill_array_1() {
	reinit();
	cout << "input 12 numbers, one in new line" << endl;
	for (int i = 0; i < 12; i++) {
		cin >> A[i];
	}
}

int foo1(int a[])
{
	int res = 0;
	for (int i = 0; i < 12; i++) {
		if (i%2 == 1) {
			res += a[i];
		}
	}
	return res;
}

void foo_1() {
	reinit();
	for (int i = 0; i < 12; i++) {
		if (i % 2 == 1) {
			S1 += A[i];
		}
	}
}

int foo2(int a[])
{
	string req = "";
	cout << "max or min" << endl;
	cin >> req;
	if (req == "max") {
		int max = INT_MIN;
		for (int i = 0; i < 12; i++) {
			if (a[i] > max) {
				max = a[i];
			}
		}
		return max;
	}
	else if (req == "min") {
		int min = INT_MAX;
		for (int i = 0; i < 12; i++) {
			if (a[i] < min) {
				min = a[i];
			}
		}
		return min;
	}
	else {
		cout << "Wrong request" << endl;
	}
}

void foo_2(){
	reinit();
	string req = "";
	cout << "max or min" << endl;
	cin >> req;
	if (req == "max") {
		for (int i = 0; i < 12; i++) {
			if (A[i] > MAX) {
				MAX = A[i];
			}
		}
	}
	else if (req == "min") {
		for (int i = 0; i < 12; i++) {
			if (A[i] < MIN) {
				MIN = A[i];
			}
		}
	}
	else {
		cout << "Wrong request" << endl;
		throw exception();
	}
}

int foo3(int a[]) {
	int res = 0;
	for (int i = 0; i < 12; i++) {
		if (a[i] < 0) {
			res += a[i];
		}
	}
	return res;
}

void foo_3() {
	reinit();
	for (int i = 0; i < 12; i++) {
		if (A[i] < 0) {
			S2 += A[i];
		}
	}
}