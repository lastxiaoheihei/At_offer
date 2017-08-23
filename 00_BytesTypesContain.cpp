#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Example1 {

};

class Example2 {
public:
	virtual ~Example2(){}
};

int main(void)
{
	cout << "各类型字节大小:" << endl;
	cout << "int: " << sizeof(int) << endl;
	cout << "float: " << sizeof(float) << endl;
	cout << "long: " << sizeof(long) << endl;
	cout << "double: " << sizeof(double) << endl;
	cout << "long long: " << sizeof(long long) << endl;
	cout << "long long int: " << sizeof(long long int) << endl;
	cout << "string: " << sizeof(string) << endl;
	cout << "vector: " << sizeof(vector<int>) << endl;
	cout << "long long *: " << sizeof(long long *) << endl;
	cout << "int *: " << sizeof(int *) << endl;
	cout << "Example1: " << sizeof(Example1) << endl;
	cout << "Example2: " << sizeof(Example2) << endl;
	if (1)
		throw new exception("hahah");
	system("PAUSE");
	return 0;

}