#include <iostream>
using namespace std;

struct Employee {
    int id;
    string name;
    double salary;
};

void merge(Employee arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    Employee L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (L[i].salary <= R[j].salary)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(Employee arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);       
        mergeSort(arr, mid + 1, high);  
        merge(arr, low, mid, high);     
    }
}

int main() {
    int n;
    cout<<"Enter the Total Number of Employee:";
    cin>>n;
    Employee emp[n];
    for(int i = 0; i <n; i++){
    	
    	cout<<"Enter the ID of the Employee: ";
    	cin>>emp[i].id;
		cout<<"\nEnter the Name of the Employee: ";
    	cin>>emp[i].name;
    	cout<<"Enter the Salary of the Employee: ";
    	cin>>emp[i].salary;
	}

    mergeSort(emp, 0, n - 1);

    cout << "Employees sorted by Salary:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nName:"<<emp[i].name<<endl<<"ID: " << emp[i].id<<endl
             << "Salary: " << emp[i].salary << endl;
    }

    return 0;
}
