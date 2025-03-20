#include <iostream>
using namespace std;

int add(int a, int b),sub(int a, int b), mult(int a, int b),div(int a, int b),mod(int a, int b);

int main() {
    int ch, x, y;
    
    do {
        cout<<"\n*************************************************************************\n";
        cout << "\nPress 1 for +";
        cout << "\nPress 2 for -";
        cout << "\nPress 3 for *";
        cout << "\nPress 4 for /";
        cout << "\nPress 5 for %";
        cout << "\nPress 0 for exit\n";
        cout<<"\n*************************************************************************\n";
        cout << "Enter your choice: ";
        cin >> ch;

        if(ch == 0) break;
        else if(ch>0 and ch<6)continue;
        else cout<<"wrong choice..................!";
	     cout<<"\n\n*************************************************************************\n";
        cout << "Enter the first number: ";
        cin >> x;
        cout << "Enter the second number: ";
        cin >> y;
        cout<<"\n*************************************************************************\n";


        switch(ch) {
            case 1:
                cout << "Addition of " << x << " and " << y << " is " << add(x, y) << endl;
                cout<<"\n*************************************************************************\n";
                break;
            case 2:
                cout << "Subtraction of " << x << " and " << y << " is " << sub(x, y) << endl;
      			cout<<"\n*************************************************************************\n";               
				break;
            case 3:
                cout << "Multiplication of " << x << " and " << y << " is " << mult(x, y) << endl;
       			cout<<"\n*************************************************************************\n";
                break;
            case 4:
                if(y != 0) {
                	cout << "Division of " << x << " and " << y << " is " << div(x, y) << endl;
                	cout<<"\n*************************************************************************\n";
                   
                } else {
                     cout << "infinite\n";
                }
                break;
            case 5:
                if(y != 0) {
                    cout << "Modulus of " << x << " and " << y<< " is " << mod(x, y) << endl;
                    cout<<"\n*************************************************************************\n";
                } else {
                    cout << " Modulus by zero!\n";
                }
                break;
           
        }
    } while(1);

    cout << "\nGood by...................................\n";
    cout<<"\n*************************************************************************\n";
    return 0;
}

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mult(int a, int b) {
    return a * b;
}

int div(int a, int b) {
    return a / b;
}

int mod(int a, int b) {
    return a % b;
}


//debug
/*
	cin :- x=5 y=10
	if(ch==0) than break.........else if(ch>0 and ch<6) condition continue........else print : wrong choice.....
1. ch=0 than break do-while condition
2. ch=1 true, than case 1 condition true, than call add function. this function is WAWR.and return condition is (a+b)
3. ch=2 true, than case 2 condition true, than call sub function. this function is WAWR.and return condition is (a-b)
3. ch=3 true, than case 3 condition true, than call mult function. this function is WAWR.and return condition is (a*b)
4. ch=4 true, than case 4 condition true, than if(y!=0)that mean if(10!=0) than true.call add function. this function is WAWR.and return condition is (a/b)
5. ch=5 true, than case 5 condition true, than if(y!=0)that mean if(10!=0) than true.call add function. this function is WAWR.and return condition is (a%b)
6. ch=6 or more true, than print : wrong choice.....
*/
