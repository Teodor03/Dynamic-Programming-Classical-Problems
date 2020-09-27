#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int Max_N=1000000;

int n;
int or_v [Max_N];

int mem_t [Max_N];
int _prev [Max_N];

int res_length=1;
int res_ind;
vector<int> res_sub;


void calc_dyn(){

    fill(mem_t,mem_t+n,1);
    fill(_prev,_prev+n,-1);

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(or_v[j]<=or_v[i]){
                if(mem_t[j]+1>mem_t[i]){
                    mem_t[i]=mem_t[j]+1;
                    _prev[i]=j;
                }
            }
        }
        if(mem_t[i]>res_length){
            res_length=mem_t[i];
            res_ind=i;
        }
    }

    return;
}

void find_res_subseq(){
    int curr=res_ind;
    while(curr!=-1){
        res_sub.push_back(or_v[curr]);
        curr=_prev[curr];
    }
    return;
}

int main(){
ios_base::sync_with_stdio(false);
cin>>n;
for(int i=0;i<n;i++){
    cin>>or_v[i];
}
calc_dyn();
find_res_subseq();
cout<<"Resulting length : "<<res_length<<endl;
cout<<"Resulting subsequence : ";
for(int i=res_sub.size()-1;i>-1;i--){
    cout<<res_sub[i]<<" ";
}
return 0;
}
