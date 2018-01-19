#include <iostream>
using namespace std;

int main() {
	struct ListNode {
		int value;
		ListNode *next;
		ListNode *prev;
	};

	ListNode *head = nullptr;
	ListNode *tail = nullptr;
	ListNode *newNode = nullptr;
	ListNode *nodePtr = nullptr;
	ListNode *prevPtr = nullptr;
	ListNode *nextNode = nullptr;

	char menuOption = 'i';
	int val;
	int afterVal = 0;
	bool find = false;

	do {
		cout << "a-add to beginning of list\n";
		cout << "b-Delete beginning of list\n";
		cout << "c-Insert at the end of the list\n";
		cout << "d-Delete at the end of the list\n";
		cout << "e-inserts item after a item in list\n";
		cout << "f-Delete a item\n";
		cout << "g-Print forward\n";
		cout << "h-Print backwards\n";
		cout << "i-Quit\n";
		cout << "j-find integer";

		cin >> menuOption;


		switch (menuOption) {
		case 'a':
			cout << "Inserting at the beginning of list ... \n";
			cout << "please enter an integer: ";
			cin >> val;

			newNode = new ListNode;
			newNode->value = val;
			newNode->next = nullptr;
			newNode->prev = nullptr;

			if (head == nullptr) {
				head = newNode;
				tail = newNode;
			}
			else {
				head->prev = newNode;
				newNode->next = head;
				head = newNode;
			}
			break;
		case 'b':
			if (head != nullptr) {
				cout << "deleting value " << head->value << " ... \n";
				nodePtr = head->next;
				delete head;
				head = nodePtr;
				head->prev = nullptr;
			}
			else {
				cout << "list is empty" << endl;
			}
			break;
		case 'c':
			cout << "Inserting at the end of list ... \n";
			cout << "please enter an integer: ";
			cin >> val;

			newNode = new ListNode;
			newNode->value = val;
			newNode->next = nullptr;
			newNode->prev = nullptr;

			if (head == nullptr) {
				head = newNode;
				tail = newNode;
			}
			else {
				nodePtr = head;
				while (nodePtr->next != nullptr) {
					nodePtr = nodePtr->next;
				}
				newNode->prev = nodePtr; //Points the prev variable to the nodePtr
				nodePtr->next = newNode; //nodePtr.next points to the new node
				tail = newNode;
			}
			break;
		case 'd':
			if (tail != nullptr) {
				cout << "deleting value " << tail->value << " ... \n";
				nodePtr = tail->prev;
				delete tail;
				tail = nodePtr;
				tail->next = nullptr;
			}
			else {
				cout << "list is empty" << endl;
			}
			break;
		case 'e':
			cout << "Inserting after a integer in the list ... \n";
			cout << "please enter an integer: ";
			cin >> val;
			cout << val << " Will be entered after what number?\n";
			cin >> afterVal;

			newNode = new ListNode;
			newNode->value = val;
			newNode->next = nullptr;
			newNode->prev = nullptr;

			nodePtr = head;
			while (nodePtr->next != nullptr && nodePtr->value != afterVal) {
				nodePtr = nodePtr->next;
			}

			if (nodePtr->next == nullptr) {
				tail = newNode;
				newNode->prev = nodePtr;
				nodePtr->next = newNode;
			}
			else {
				newNode->prev = nodePtr;
				nextNode = nodePtr->next;
				nodePtr->next = newNode;
				nextNode->prev = newNode;
				newNode->next = nextNode;
			}
			break;
		case 'f':
			cout << "deleting ... \n";
			cout << "enter a value to delete ";
			cin >> val;
			if (head != nullptr) {
				if (head->value == val) {
					nodePtr = head->next;
					delete head;
					head = nodePtr;
				}
				else if (tail->value == val) {
					nodePtr = tail->prev;
					delete tail;
					tail = nodePtr;
					tail->next = nullptr;
				}
				else {
					nodePtr = head;
					while (nodePtr != nullptr && nodePtr->value != val) {
						prevPtr = nodePtr;
						nodePtr = nodePtr->next;
					}
					if (nodePtr != nullptr) {
						prevPtr->next = nodePtr->next;
						nodePtr->next->prev = prevPtr;
						delete nodePtr;
					}
				}
			}
			else {
				cout << "list is empty" << endl;
			}
			break;
		case 'g':
			cout << "printing forwards ... \n";
			nodePtr = head;
			while (nodePtr != nullptr) {
				cout << "elem: " << nodePtr->value << endl;
				nodePtr = nodePtr->next;
			}
			break;
		case 'h':
			cout << "printing backwards ... \n";
			nodePtr = tail;
			while (nodePtr != nullptr) {
				cout << "elem: " << nodePtr->value << endl;
				nodePtr = nodePtr->prev;
			}
			break;
		case 'i':
			cout << "quitting ... \n";
			nodePtr = head;
			while (nodePtr != nullptr) {
				nextNode = nodePtr->next;
				cout << "deleting ... " << nodePtr->value << endl;
				delete nodePtr;
				nodePtr = nextNode;
			}
			break;
		case 'j':
			find = false;
			cout << "finding ... \n";
			cout << "enter a value to find ";
			cin >> val;
			if (head != nullptr) {
				if (head->value == val) {
					nodePtr = head->next;
					find = true;
					head = nodePtr;
					cout << val << " found" << endl;
				}
				else if (tail->value == val) {
					nodePtr = tail->prev;
					find = true;
					cout << val << " found" << endl;
					tail = nodePtr;
					tail->next = nullptr;
				}
				else {
					nodePtr = head;
					while (nodePtr != nullptr && nodePtr->value != val) {
						prevPtr = nodePtr;
						nodePtr = nodePtr->next;
					}
					if (nodePtr != nullptr) {
						prevPtr->next = nodePtr->next;
						nodePtr->next->prev = prevPtr;
						find = true;
						cout << val << " found" << endl;
					}
				}
			}
			else {
				cout << val << " not found" << endl;
			}
			break;
		}
	} while (menuOption != 'i');

	system("pause");
	return 0;
}
