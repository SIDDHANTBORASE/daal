	#include <iostream>
	using namespace std;
	
	class student{
		public:
		string name;
		char grade;
	};
	
	int main(){
		student s1, s2;
		char a , b;
		cout<<"Enter the Name of the Student 1 and Student 2: "<<endl;
		cout<<"Enter the Name of the Student 1:";
		cin>>s1.name;
		cout<<"Enter the Grade of Student 1: ";
		cin>>a;
		cout<<"Enter the Name of the Student 2:";
		cin>>s2.name;
		cout<<"Enter the Grade of Student 2: ";
		cin>>b;
		
		s1.grade =a;
		s2.grade = b;
		
		cout<<"Correcting the Mismatch: "<<endl;
		char swap;
		swap = s1.grade;
		s1.grade =s2.grade;
		s2.grade = swap;
		
		cout<<"Name of the Student 1:" <<s1.name<<"\n Grade of Student 1: "<<s1.grade<<endl;
		cout<<"Name of the Student 2:" <<s2.name<<"\n Grade of Student 2: "<<s2.grade<<endl;
		
		int c , d;
		c= a;
		d = b;
		cout<<"Swapping again without : "<<endl;
		c = c + d;
		d = c - d;
		c = c - d;
		
		s1.grade =c;
		s2.grade = d;
		
		cout<<"Name of the Student 1:" <<s1.name<<"\n Grade of Student 1: "<<s1.grade<<endl;
		cout<<"Name of the Student 2:" <<s2.name<<"\n Grade of Student 2: "<<s2.grade<<endl;
		return 0;
			
	}
		
		
