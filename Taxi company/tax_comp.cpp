#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int Max_N=1000000;

const int Max_K=1000000;

const int Inf=99999999;

int c [Max_K];
int memo [Max_N];
int backtr [Max_N];

int n,k;

void calc_dyn(){
    memo[0]=0;
    for(int i=1;i<=n;i++){
        memo[i]=Inf;
        for(int j=1;j<=min(i,k);j++){
            if((memo[i-j]+c[j])<memo[i]){
                memo[i]=memo[i-j]+c[j];
                backtr[i]=i-j;
            }
        }
    }
    return;
}

vector<int> path;

void calc_path(){
    int curr=n;
    while(curr!=0){
        path.push_back(curr);
        curr=backtr[curr];
    }
    path.push_back(curr);
    return;
}

/*

15 10
0 12 21 31 40 49 58 69 79 90 101

*/

int main(){
ios_base::sync_with_stdio(false);
cin>>n>>k;
for(int i=0;i<=k;i++){
    cin>>c[i];
}
calc_dyn();
//for(int i=0;i<=n;i++){
//    cout<<memo[i]<<" ";
//}
cout<<"Min price to get to "<<n<<" is : "<<memo[n]<<endl;
calc_path();
cout<<"Path is : ";
for(int i=path.size()-1;i>-1;i--){
    cout<<path[i]<<" ";
}
cout<<endl;
return 0;
}
