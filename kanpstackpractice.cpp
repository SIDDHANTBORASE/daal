#include<iostream>
using namespace std;

int max(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int main(){
    int n;
    cout<<"Enter the Number of Items: ";
    cin>>n;

    int w[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the Weight of "<<i+1<<" Element: ";
        cin>>w[i];
    }

    int p[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the Profit of "<<i+1<<" Element: ";
        cin>>p[i];
    }

    int W;
    cout<<"Enter Knapsack Capacity: ";
    cin>>W;

    int dp[n+1][W+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(w[i-1] <= j){
                dp[i][j] = max(dp[i-1][j-w[i-1]] + p[i-1], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<endl;
    int row;
    cout<<" |";
    for(int i=0;i<=W;i++){
    	cout<<i<<"|";
	}
	cout<<endl;
    for (int i = 0; i<=n;i++){
    		cout<<row<<"|";
    		row++;
    	for(int j =0; j <=W;j++){
    		cout<<dp[i][j]<<"|";
		}
		cout<<endl;
	}

    cout<<"\nMaximum Profit with Maximum Capacity is: "<<dp[n][W];
}
