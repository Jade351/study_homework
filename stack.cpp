#include <iostream>
using namespace std;

int N = 0; //N 개 명령어
int result = 0;
string command;
int number;
int stack_a[10001];
int p_index = 0;

void push(int number)
{

	stack_a[p_index] = number;
	cout << stack_a[p_index] << endl;
	p_index++;
	//cout << p_index << endl;
}
void pop()
{
	if (p_index == 0) cout << -1 << endl;
	else
	{
		int pop_result = stack_a[p_index];
		p_index--;
	}
}
void size()
{
	if (p_index == 0) {
		cout << 0 << endl;
	}
	else {
		cout << p_index << endl;
	}
}
void empty()
{
	if (p_index == 0) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}

}

void top()
{
	if (p_index == 0) {
		cout << -1 << endl;
	}
	else {
		//cout << p_index << endl;
		cout << stack_a[p_index - 1] << endl; // 그다음꺼를 현재 가리키고 있어서 하나 빼줌
	}
}

int main(void)
{
	int b[3] = { 1,2,3 };
	cout << b[-1] << endl;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> command;
		//1. push
		if (command == "push") {
			cin >> number;
			push(number);
		}
		//2. pop
		else if (command == "pop") {
			pop();
		}
		//3. size
		else if (command == " size") {
			size();
		}
		//4. empty
		else if (command == "empty") {
			empty();
		}
		//5. top
		else if (command == "top") {
			top();
		}
	}
	return 0;
}