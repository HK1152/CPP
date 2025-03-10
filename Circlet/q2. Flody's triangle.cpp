#include <iostream>
using namespace std;

int main() {
    int i,j,hk=11;

    for(i=1;i<=4;i++) {
        for(j=1;j<=i;j++) {
            cout<<hk<<" ";
            hk++;
        }
        cout<<endl;
    }

    return 0;
}
