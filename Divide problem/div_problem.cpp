#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int Inf=999999999;
const int Max_N=99999999;

//original values
int n,k;
int s [Max_N];

int pref_s [Max_N];

void calc_pref_s(){
    pref_s[0]=s[0];
    for(int i=1;i<n;i++){
        pref_s[i]=pref_s[i-1]+s[i];
    }
}

int get_sum(int j,int i){
    if(j>i){
        swap(j,i);
    }
    return (pref_s[i]-pref_s[j]+s[j]);
}

vector< vector<int> > mem;

int acc_mem(int j,int i){
    if(j<0){
        return 0;
    }
    return mem[j][i];
}

//int calc_rec_dyn(int i,int k){
//    if(k==0 or i<0){
//        return 0;
//    }
//    int res=Inf;
//    for(int j=0;j<=i;j++){
//        res=min(res, max( calc_rec_dyn(j-1,k-1),get_sum(j,i) ) );
//    }
//    return res;
//}

void calc_dyn(){
    mem.resize(n);
    for(int i=0;i<n;i++){
        mem[i].resize(k+1);
        mem[i][0]=Inf;
    }
    mem[0][0]=0;
    int curr;
    for(int curr_k=1;curr_k<=k;curr_k++){
        for(int i=0;i<n;i++){
            curr=Inf;
            for(int j=0;j<=i;j++){
                curr=min(curr, max( acc_mem(j-1,curr_k-1),get_sum(j,i) ));
            }
            mem[i][curr_k]=curr;
            cout<<endl;
            for(int ii=0;ii<=k;ii++){
                for(int jj=0;jj<n;jj++){
                    cout<<mem[jj][ii]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return;
}

int main(){
cin>>n>>k;
if(k>n){
    cout<<"Impossible";
    return 0;
}
for(int i=0;i<n;i++){
    cin>>s[i];
}
calc_pref_s();
calc_dyn();
cout<<mem[n-1][k];
return 0;
}
