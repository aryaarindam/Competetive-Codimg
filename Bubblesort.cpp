#include<bits/stdc++.h>
using namespace std;
template<class Bubble>
void Add(Bubble arr[],int n){
    Bubble temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j])
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;           
        }
    }
}
int main(){
    int m;cin>>m;int am[m];char as[m];
    for(int i=0;i<m;i++)cin>>am[i];
    Add(am,m);
    for(int i=0;i<m;i++)cout<<am[i]<<" "<<endl;
    for(int i=0;i<m;i++)
    cin>>as[i];
    Add(as,m);
    for(int i=0;i<m;i++)cout<<as[i]<<" "<<endl;
    return 0;
}