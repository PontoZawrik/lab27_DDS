#include <iostream>
using namespace std;

struct stack {
	int* arr = new int[0];
	int head = 0;

	int* change_size_array(int* old_arr, int size, int change_size) {
		int* change_arr = new int[change_size];

		for (int i = 0; i < ((size < change_size) ? size : change_size); i++) {
			change_arr[i] = old_arr[i];
		}

		delete[] old_arr;
		return change_arr;
	}

	void push(int x) {
		arr = change_size_array(arr, head, head + 1);
		arr[head] = x;
		head++;
	}

	int pop() {
		if (head - 1 != -1) {
			int tmp = arr[head - 1];
			arr = change_size_array(arr, head, head - 1);
			head--;
			return tmp;
		}
		else {
			cout << "";
			return -1;
		}
	}

	bool is_empty() {
		return head - 1 == -1;
	}
};

void function_stack() {
	stack mystack;
	int element_stack;
	int menu = 0;
	bool exit_menu = true;

	while (exit_menu) {
		cout << "";
		cin >> menu;

		switch (menu) {
			case 1: {
				cout << "";
				cin >> element_stack;
				mystack.push(element_stack);
				break;
			}
			case 2: {
				element_stack = mystack.pop();
				cout << "" << element_stack << endl;
				break;
			}
			case 3: {
				cout << "" << ((mystack.is_empty() == true) ? "true" : "false") << endl;
				break;
			}
			default: {
				exit_menu = false;
				break;
			}
		}
	}
}

struct queue {
	int* arr = new int[NULL];
	int head = 0;
	int tail = 0;

	int* change_size_array(int* old_arr, int size, int change_size) {
		int* change_arr = new int[change_size];

		for (int i = 0; i < ((size < change_size) ? size : change_size); i++) {
			change_arr[i] = old_arr[i];
		}

		delete[] old_arr;
		return change_arr;
	}

	void push(int x) {
		arr = change_size_array(arr, tail, tail + 1);
		arr[tail] = x;
		tail++;
	}

	int pop() {
		if (head != tail) {
			int tmp = arr[head];
			for (int i = 0; i < tail; i++) {
				arr[i] = arr[i + 1];
			}
			arr = change_size_array(arr, tail, tail - 1);

			tail--;
			return tmp;
		}
		else {
			cout << "";
			return -1;
		}
	}

	bool is_empty() {
		return head == tail;
	}
};

void function_queue() {
	queue my_queue;
	int element_queue;
	int menu = 0;
	bool exit_menu = true;

	while (exit_menu) {
		cout << "";
		cin >> menu;

		switch (menu) {
			case 1: {
				cout << "";
				cin >> element_queue;
				my_queue.push(element_queue);
				break;
			}
			case 2: {
				element_queue = my_queue.pop();
				cout << "" << element_queue << endl;
				break;
			}
			case 3: {
				cout << "" << ((my_queue.is_empty() == true) ? "true" : "false") << endl;
				break;
			}
			default: {
				exit_menu = false;
				break;
			}
		}
	}
}