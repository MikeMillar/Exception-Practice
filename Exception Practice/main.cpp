#include <iostream>
#include <exception>
using namespace std;

class CanGoWrong {
public:
	CanGoWrong() {
		char* pMemory = new char[999];
		delete[] pMemory;
	};
};

class MyException : public exception {
public:
	virtual const char* what() const throw() {
		return "Something bad happened!";
	}
};

class Test {
public:
	void goesWrong() {
		throw MyException();
	}
};

void thisWillGoWrong() {
	bool err1 = false;
	bool err2 = false;
	bool err3 = false;

	if (err1) {
		throw 1;
	}
	if (err2) {
		throw "Something is wrong.";
	}
	if (err3) {
		throw string("Something definetely went wrong");
	}
}

void useThisWillGoWrong() {
	thisWillGoWrong();
}

int main() {
	Test test;

	try {
		test.goesWrong();
	}
	catch (int e) {
		cout << "Error occured: " << e << endl;
	}
	catch (const char* e) {
		cout << "Const char pointer error: " << e << endl;
	}
	catch (string& e) {
		cout << "String error: " << e << endl;
	}
	catch (bad_alloc& e) {
		cout << "Caught exception: " << e.what() << endl;
	}
	catch (MyException& e) {
		cout << e.what() << endl;
	}
	
	cout << "Still running." << endl;


	return 0;
}