#include <iostream>
using namespace std;

int main() {
    int hk,l,f;
    cout<<"Enter any number:";
    cin>>hk;
    l=hk%10;
	f=hk;
    if(hk>0){
	
    while (f>=10 and f>=0) {
        f/=10;
    }
     
    int sum=f+l;
    cout<<"The sum of the first and the last digit:"<<sum<<endl;
}
else
cout<<"Your digit negative........!";
    return 0;
}
