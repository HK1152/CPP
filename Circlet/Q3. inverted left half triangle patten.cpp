#include<iostream>
using namespace std;

int main() {
    int hk = 5,j,i; 

    for (i = hk; i >= 1; i--) {
    	for (j = hk; j > i; j--) {
            cout << " ";
        }
        for (j = 1; j <= i; j++) {
            if (j % 2 == 0) {
                cout<<0; //t
            } else {
                cout<<1; //f
            }
        }
        cout<<"\n"; 
    }

    return 0;
}
