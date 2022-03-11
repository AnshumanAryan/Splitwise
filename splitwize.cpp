#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int N;
void printArray(int amount[],int ar[], int size)
{
	for(int i=0;i<172;i++)
	cout<<"*";
	cout<<"The order of the maximum debtors are\n";
	int i;
	for (i = 0; i<size; i++)
	{
		for(int j=0;j<size;j++)
		if(amount[j]==ar[i])
		{
			cout<<j<<" ";
			amount[j]=-1;
			break;
		}
	}
	cout<<endl;
  for(int i=0;i<172;i++)
	cout<<"*";
cout << "\n\n";
}
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partition (int ar[], int low, int high)
{
	int pivot = ar[high];
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		if (ar[j] < pivot)
		{
			i++; 
			swap(&ar[i], &ar[j]);
		}
	}
	swap(&ar[i + 1], &ar[high]);
	return (i + 1);
}
void quickSort(int ar[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(ar, low, high);
		quickSort(ar, low, pi - 1);
		quickSort(ar, pi + 1, high);
	}
}
int getMin(int arr[])
{
	int minInd = 0;
	for (int i=1; i<N; i++)
		if (arr[i] < arr[minInd])
			minInd = i;
	return minInd;
}
int getMax(int arr[])
{
	int maxInd = 0;
	for (int i=1; i<N; i++)
		if (arr[i] > arr[maxInd])
			maxInd = i;
	return maxInd;
}
int minOf2(int x, int y)
{
	return (x<y)? x: y;
}
void minCashFlowRec(int amount[])
{
	int mxCredit = getMax(amount), mxDebit = getMin(amount);
	if (amount[mxCredit] == 0 && amount[mxDebit] == 0)
		return;
	int min = minOf2(-amount[mxDebit], amount[mxCredit]);
	amount[mxCredit] -= min;
	amount[mxDebit] += min;
	cout << "Person " << mxDebit << " pays " << min
		<< " to " << "Person " << mxCredit << endl;
	minCashFlowRec(amount);
}

void minCashFlow(vector<vector<int>> const& arr)
{
	int amount[N],ar[N],br[N];
  memset(amount, 0, sizeof amount);
	for (int p=0; p<N; p++)
	for (int i=0; i<N; i++)
		amount[p] += (arr[i][p] - arr[p][i]);
	for(int i=0;i<N;i++)
	{
		ar[i]=amount[i];
	}
	for(int i=0;i<N;i++)
	{
		br[i]=amount[i];
	}
	quickSort(ar,0,N-1);
	printArray(br,ar,N);
  minCashFlowRec(amount);
}
int main()
{
  cout<<"Enter the number of person\n";          
  cin>>N;
  int val=0;
  vector< vector<int> > arr(N, vector<int> (N, val));
  cout<<"Enter the number of transactions\n";
  int n,x,y;
  cin>>n;
  for(int i=0;i<n;i++)
  {
	cout<<"\nPerson x has to give money to person y\n";
    cout<<"Enter x ";
    cin>>x;
    cout<<"Enter y ";
    cin>>y;
    cout<<"Enter amount ";
    cin>>arr[x][y];
    cout<<endl;
  }
  for(int i=0;i<172;i++)
	cout<<"*";
  cout<<"\nThe input graph is :-\n";
  for(int i=0;i<n;i++)
  {
	for(int j=0;j<n;j++)
		cout<<arr[i][j]<<"\t";
	cout<<"\n";
  }
	cout<<"\n\n";
	minCashFlow(arr);
	cout<<endl;
	for(int i=0;i<172;i++)
	cout<<"*";
	return 0;
}
