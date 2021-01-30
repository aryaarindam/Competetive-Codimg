#include<bits/stdc++.h>
using namespace std;
int cheapCan(int Temp[], int Price[],int& N, int& M, int& K, int& L, int& R){
    for (size_t i = 0; i < N; i++){
        if(Temp[i] > K){
            if(Temp[i]-M >= K){
                Temp[i]-= M;
            }else{
                Temp[i] = K;
            }
        }else if(Temp[i] < K){
            if(Temp[i]+M <= K){
                Temp[i]+= M;
            }else{
                Temp[i] = K;
            }
        }
    }
    int minPrice = INT_MAX;
    for (size_t i = 0; i < N; i++){
        if(Temp[i] >= L && Temp[i] <= R){
            if(minPrice > Price[i])
                minPrice = Price[i];
        }
    }
    if(minPrice == INT_MAX)
        return -1;
    return minPrice;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int N,M,K,L,R;
        cin>>N>>M>>K>>L>>R;
        int Temp[N];
        int Price[N];
        for (size_t i = 0; i < N; i++){
            cin>>Temp[i]>>Price[i];
        }
        cout<<cheapCan(Temp,Price,N,M,K,L,R)<<endl;
    }
    return 0;
}