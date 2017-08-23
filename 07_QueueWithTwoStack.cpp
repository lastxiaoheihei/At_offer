#include <iostream>
#include <stack>
using namespace std;
template <typename T>
class mQueue {
public:
	mQueue() {};
	~mQueue() {};
	void push(const T &node);
	T pop();
private:
	stack<T> stack1;
	stack<T> stack2;
};
template <typename T>
void mQueue<T>::push(const T &node)
{
	stack1.push(node);
}
template <typename T>
T mQueue<T>::pop()
{
	if (stack1.empty() && stack2.empty())
		throw new exception("队列为空！");
	if (stack2.empty())
	{
		while (!stack1.empty())
		{
			T data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}
	T head = stack2.top();
	stack2.pop();
	return head;
}
void test1();
int main()
{
	test1();
	system("PAUSE");
	return 0;
}
void test1()
{
	cout << "测试用例1: " << endl;
	mQueue<int> queue1;
	//queue1.pop();
	queue1.push(1);
	queue1.push(2);
	cout << queue1.pop() << " " << queue1.pop() << endl;
}