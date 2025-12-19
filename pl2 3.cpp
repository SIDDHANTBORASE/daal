//Binary Search Using Recursion:
#include <iostream>
using namespace std;

int binarysearch(int arr[],int key, int Nmin, int Nmax){
	int min, mid, max;
	min = Nmin;
	max = Nmax;
	mid = (min+max)/2;
	if(min > max)
	{
		return 0;
	}
	else if(arr[mid] == key){
		return 1;
	}
	else if (key < arr [mid]){
		max=mid-1;
		return binarysearch(arr, key,min , max );
		}	
	
	else if(key > arr [mid]){
		min=mid+1;
		return binarysearch(arr, key,min , max );
	}

}

int main(){
	int arr[5];
	int cnd;
	int key ;
	cout<<"Enter the Elements of the Array: ";
	for(int i =0 ; i< 5; i++){
		cin>>arr[i];
	}
	cout<<"Enter the Key to Search Through Array:";
	cin>>key;
	
	cnd = binarysearch(arr , key , 0, 4);
	if(cnd == 1){
		cout<<"Key Found"<<endl;
	}
	else{
		cout<<"Key not Found"<<endl;
	}
}
