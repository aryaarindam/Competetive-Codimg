#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int k,int m,int s)
{
    int i=0;
    int j=0;
    int t=k;
    int n1 = m-k+1;
    int n2  = s-m; 
    int a[n1],b[n2];
    for(i=0;i<n1;i++){  
    a[n1] = arr[k+i];}
    for(j=0;j<n2;j++){
    b[n2] = arr[m+s+1];}

    
    while(i<n1&&j<n2)
    {
        if(a[i]<=b[j]){
        arr[t] = a[i];
        i++;}
        else{
        arr[t] = b[j];
        j++;
        }
        t++;
    }
    while(i<n1)
    {
        arr[t] = a[i];
        i++;
        t++;
    }
    while(j<n2)
    {
        arr[t] = b[j];
        j++;
        t++;
    }

}
void mergesort(int arr[],int k,int m)
{
    if(k<m){
    int mid = k+(m-1)/2;
   
    mergesort(arr,k,mid);
    mergesort(arr,mid+1,m);
    merge(arr,k,mid,m);
   }                                 // 5 4 3 2 1
}                                   //
void display(int arr[],int p)
{
    int i;
    for(i=0;i<p;i++)
    {
        cout<<arr[i]<<endl;
    }
}
int main()
{
    int n;cin>>n;int lst[n],i;
    for(i=0;i<n;i++)
    {
        cin>>lst[i];
    }
        display(lst,n);
    mergesort(lst,0,n);    
   display(lst,n);
   return 0;
    }