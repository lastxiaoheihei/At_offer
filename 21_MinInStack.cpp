#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;
template <typename T>
class StackWithMin {
public:
	StackWithMin() {};
	~StackWithMin() {};
	void push(const T data);
	void pop();
	T min()const;
private:
	stack<T> mStack1;
	stack<T> mStack2;
};
template <typename T>
void StackWithMin<T>::push(const T data)
{
	mStack1.push(data);
	if (mStack2.empty() || data < mStack2.top())
		mStack2.push(data);
	else
		mStack2.push(mStack2.top());
}
template <typename T>
void StackWithMin<T>::pop()
{
	assert(mStack1.size() > 0 && mStack2.size() > 0);
	mStack1.pop();
	mStack2.pop();
}
template <typename T>
T StackWithMin<T>::min() const
{
	assert(mStack1.size() > 0 && mStack2.size() > 0);
	return mStack2.top();
}
void test();
int main()
{
	test();
	system("PAUSE");
	return 0;
}
void test()
{
	cout << "Test: " << endl;
	StackWithMin<int> stack1;
	//for (int i = 0; i < 8; i++)
	//	stack1.push(i);
	//cout << "Min: " << stack1.min() << endl;
	//stack1.pop();
	cout << "Min: " << stack1.min() << endl;
}