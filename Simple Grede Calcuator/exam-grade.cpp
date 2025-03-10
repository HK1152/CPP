#include<iostream>
using namespace std;
int main(){
	
	int score;
	char grade;
	cout<<"\nEnter your score:";
	cin>>score;

	
	grade = (score >= 90) ? 'A' :
			(score >= 60) ? 'B' :
			(score >= 40) ? 'C' :
			(score >= 35) ? 'D' : 'F';
			cout<<grade<<endl;
			
	switch(grade)
	{
		case 'A' : cout<<"Excellent work!"<<endl; break;
		case 'a' : cout<<"Excellent work!"<<endl; break;
		
		case 'B' : cout<<"Well done"<<endl; break;
		case 'b' : cout<<"Well done"<<endl; break;
		
		case 'C' : cout<<"Good job"<<endl; break;
		case 'c' : cout<<"Good job"<<endl; break;
		
		case 'D' : cout<<"You Passed,but you coukd do better"<<endl; break;
		case 'd' : cout<<"You Passed,but you coukd do better"<<endl; break;
	
		case 'F' : cout<<"Sorry, you faild"<<endl; break;
		case 'f' : cout<<"Sorry, you faild"<<endl; break;
	}
	
	if((grade>= 'a' and grade<='d') or (grade>= 'A' and grade<='D')) cout<<"Congratulation!You are eligible for the next level"<<endl;
	else cout<<"Please try again next time"<<endl;
	
	return 0;
}
