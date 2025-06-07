#include <iostream>
#include <string>
using namespace std;

class Stack
{
    string *arr;
    int top,max;

public:
    Stack(int size)
    {
        max = size;
        arr = new string[max];
        top = -1;
    }

    void push()
    {
        if (!isFull()) // first step ye hai ki stack full to nahi hai. jo nahi hoga to ye run hoga
        {
            string value;
            cout << "Enter a value to push onto the stack: ";
            cin >> value;
            arr[++top] = value;
        }
        else
        {
            cout << "Stack is full." << endl;
        }
    }

    void pop()
    {
        if (!isEmpty()) // agar stack empty nahi hua to "top" aek step pichhe chala jae ga
        {
            top--;
        }
        else
        {
            cout << "Stack is empty. " << endl;
        }
    }

    void displayTop()
    {
        if (!isEmpty())
        {
            cout << "Top element: " << arr[top] << endl;
        }
        else
        {
            cout << "Stack is empty." << endl;
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == max - 1;
    }
};

int main()
{
	 Stack stack(5);
	int ch;
	while(1){
		cout<<"\n1.push \n2.pop\n3.Is stack empty? \n4.Is stack full? \n5.exit";
		cout<<"Enter a choice:";
		cin>>ch;
		switch(ch){
			case 1:     
				stack.push();
    			stack.displayTop();
				break;
			case 2:
				stack.pop();
   				stack.displayTop();
				break;
			case 3 : cout << "-" << (stack.isEmpty() ? "stack is empty" : "stack is not empty") << endl; break;
			case 4 : cout << "- " << (stack.isFull() ? "stack is FULL" : "stack is not FULL") << endl; break;
			case 5 : exit(0);
		}
	}

    return 0;
}
