#include<bits/stdc++.h>
using namespace std;

int main()
{   
    int n ;
    cout<<"Enter Number of element "<<endl;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        int x;
        x=rand()%1000;
        arr[i] = x;
    }
    cout<<endl;
    time_t start,end;
    start = clock();
    for(int i=0; i<n-1; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(arr[j]<arr[i]) swap(arr[i],arr[j]);
        }
    }
    end = clock();
    double d = (difftime(end,start)/CLOCKS_PER_SEC);
    printf("\nTime taken by algorithm for %d element  is %lf",n,d);  
    return 0;
}