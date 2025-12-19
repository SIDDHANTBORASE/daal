//factorial using iterators
#include <iostream>
using namespace std;

int main (){
	int fact =0, num ;
	cout<<"Enter the Number to Do Factorial: ";
	cin >>num;
	fact = num;
	int i = 1;
	for ( i =1 ; i<num ; i++){
		fact = fact * i;
	}
	cout <<"Factorial of the Number is : "<<fact<<endl;
}
