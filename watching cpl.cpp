#include<bits/stdc++.h>
using namespace std;
int dp[4000+1][100000+1];
bool subset(int set[],int n,int s){
        bool sub[n+1][s+1];
        for(auto i=0;i<=n;++i)sub[i][0]=true;
            for(auto i=0;i<=s;++i)sub[0][i]=false;
            for(auto i=1;i<=n;++i){
                for(auto j=1;j<=s;++j){
                    if(j<set[i-1])
                        sub[i][j]=sub[i-1][j];
                    if(j>=set[i-1])
                        sub[i][j]=sub[i-1][j]||sub[i-1][j-set[i-1]];
             }
        }
    return sub[n][s];
}
bool subset1(vector<int> vet,int n,int s){
        bool sub[n+1][s+1];
         for(auto i=0;i<=n;++i)sub[i][0]=true;
            for(auto i=0;i<=s;++i)sub[0][i]=false;
            for(auto i=1;i<=n;++i){
                for(auto j=1;j<=s;++j){
                    if(j<vet[i-1])   sub[i][j]=sub[i-1][j];
                    if(j>=vet[i-1])  sub[i][j]=sub[i-1][j]||sub[i-1][j-vet[i-1]];
                    }
            }
     return sub[n][s];
}
int main(){
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
    int k; 
        cin>>k;
        while (k--)
        {
            int n,m;
            cin>>n>>m;
            vector<int> v1,v2,v3;
            int a[n];  
             int c=0; 
             int s=0;
             int s4=0;
             int s1=0;
            int s2=0;
            int s3=0;
            for(auto i=0;i<n;++i){
                cin>>a[i];
                s1+=a[i];
                }
           // cout<<s1<<endl;
            sort(a,a+n);
            reverse(a,a+n);
            if(n==1||s1<2*m)cout<<-1<<endl;
            else if(a[0]>=m){
                c++;
                for(auto i=1;i<n;++i){
                    s+=a[i];
                    if(s>=m){
                        c++;
                        break; }
                    c++;
                }
                if(s>=m)cout<<c<<endl;
                else cout<<-1<<endl;
            }
            else if(a[0]<m){
                 if(s1==2*m){
                    if(subset(a,n,m))
                        cout<<n<<endl;
                    else 
                        cout<<-1<<endl;
                 }
                
                 else if(s1>2*m){
            //         cout<<s1<<endl;
            
                    int  g=0;
                    int g1=0;
                    for(auto i=0;i<n;i++){
                            s+=a[i];
                            if(s>=2*m)
                                {
                                v3.push_back(a[i]);
                                g=i+1;
                                break;
                                        }
                        v3.push_back(a[i]);
                      }   
                        if(s==2*m){
                            if(subset1(v3,v3.size(),m))
                                 cout<<v3.size()<<endl;
                            else{     
                                 for(auto i=g;i<n;++i){
                                    s3=0; 
                                    s3=v3[0];
                                    s2=0;
                                    v3.push_back(a[i]);
                                 
                                        for(auto i=v3.size()-1;i>0;i--){
                                             s3+=v3[i];
                                                if(s3>=m){                                                
                                                 g1=i-1;
                                                break;
                                             }
                                    }
                            for(auto i=g1;i>0;i--){
                                s2+=v3[i];  
                                if(s2>=m)
                                    break;
                            }
                            if(s2>=m)break;     
                        }                    
                   if(s2>=m)cout<<v3.size()<<endl;
                    else cout<<-1<<endl;
                    }
                
                }
                else if(subset1(v3,v3.size(),m))
                    cout<<v3.size()<<endl;
                else if(subset1(v3,v3.size(),s/2))
                    cout<<v3.size()<<endl;
                else{   
                       // cout<<"heh"    <<endl;
                        int p=0;
                        s3=v3[0];
                        int sm=0;

                            for(auto i=v3.size()-1;i>0;i--){
                                s3+=v3[i];
                                if(s3>=m){
                                    p=i-1;
                                    break;

                                }
                            }
                        for(auto i=p;i>0;i--){
                            sm+=v3[i];
                            if(sm>=m)
                                break;
                        }
                     //   cout<<sm<<endl;
                        if(sm>=m)
                         cout<<v3.size()<<endl;
                        else {
                            int zz=0;
                            for(auto i=g;i<n;i++){
                                sm+=a[i];
                                if(sm>=m){
                                    zz++;
                                    break;
                                }
                                zz++;
                            }
                          //  cout<<zz<<endl;
                            if(sm>=m)cout<<v3.size()+zz<<endl;
                            else cout<<-1<<endl;

                        }

                    }
                }
            }   
        }        
  return 0;
}
// 7 8 19 7 8 7 10 20
// 20 19 10 8 8 7 7 
//
// -1 19 -1 -1 8 7 7 7 =  38-19=19
// k=10              // 19 - 8 = 11
// 18               // 11- 7 = 4
//                  // 4>7= 
  //16              // 100-80
//8 7 6 5 4 2
// 140 90
// 100
// 39
//