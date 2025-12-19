//factorial using recursion:
#include <iostream>
using namespace std;

float returnfact(int n){
	if(n == 0){
		return 1;
	}
	else if (n == 1){
		return 1;	
	}
	else{
		return n*returnfact(n - 1);
	}
}

int main(){
	int num;
	cout<<"Factorial Calculation Using Factorial:"<<endl;
	cout<<"Enter the Number to find Factorial: ";
	cin >>num;
	
	float fact = returnfact(num);
	cout<<"Number Factorial Calculator: " <<fact<<endl;
	return 0;
}
