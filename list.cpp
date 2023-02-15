#include <iostream>
using namespace std;

int N = 0; //N 개 명령어
int result = 0;
string command;
int number;
int list_a[10001];
int head = 0;
int list_index = 0;
int pop_result = 0;

void push(int number)
{
	
	list_a[list_index] = number;
	cout << list_a[list_index] << endl;
	list_index++;
	//cout << p_index << endl;
}
void pop() 
{
	if (head == list_index) {
		cout << -1 << endl;
	}
	else
	{
		pop_result = list_a[head];
		cout << pop_result << endl;
		head++;

		
	}
}
void size() 
{
	cout << list_index-head << endl;
}
void empty() 
{
	if ( (list_index - head) == 0) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}

}

void front() 
{
	if ((list_index - head) == 0) {
		cout << 1 << endl;
	}
	else {
		cout << list_a[head] << endl;
	}
}

void back()
{
	if ((list_index - head) == 0) {
		cout << 1 << endl;
	}
	else {
		cout << list_a[list_index -1] << endl;
	}
}

int main(void) 
{

	cin >> N ;
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
		else if (command == "size") {
			size();
		}
		//4. empty
		else if (command == "empty") {
			empty();
		}
		//5. front
		else if (command == "front") {
			front();
		}
		//6. back
		else if (command == "back") {
			back();
		}
	}
	return 0;
}