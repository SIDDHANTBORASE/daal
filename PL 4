#include <iostream>
using namespace std;

int main(){
	long arr[]= {2000,500,100,50,20,10,5,2,1};
	long amount;
	int rem;
	cout<<"Enter the Ammount to Calculate the Notes: ";
	cin>>amount;
	cout<<"Currency Required: "<<endl;
	for(int i = 0; i < 9; i++){
		rem = amount%arr[i];
		if(arr[i]>=10){
			cout<<"Note ";
		}
		else{
			cout<<"Coin ";
		}
		cout<<arr[i]<<" : "<< amount / arr[i]<<endl;
		amount = rem;
	}
}















