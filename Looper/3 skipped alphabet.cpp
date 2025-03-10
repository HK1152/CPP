#include<iostream>
using namespace std;
int main()
{
	char hk;
	cout<<"Enter a alphabet:";
	cin>>hk;
	
	do{
		cout<<"Alphabet:"<<hk<<endl;
		hk += 4;
	}while(hk<='z' or hk<='Z');
	return 0;
}
