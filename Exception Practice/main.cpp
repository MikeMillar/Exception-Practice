#include <iostream>
using namespace std;

void thisWillGoWrong() {
	bool err1 = false;
	bool err2 = false;
	bool err3 = true;

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

	try {
		thisWillGoWrong();
	}
	catch (int e) {
		cout << "Error occured: " << e << endl;
	}
	catch (const char* e) {
		cout << "Const char pointer error: " << e << endl;
	}
	catch (string e) {
		cout << "String error: " << e << endl;
	}

	cout << "Still running." << endl;


	return 0;
}