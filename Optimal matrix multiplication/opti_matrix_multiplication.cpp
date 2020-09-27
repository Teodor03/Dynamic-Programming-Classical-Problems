#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

const int Inf=99999999;
const int Max_N=100000;

// the n-th (1 to n) matrix y=n-1, x=n

int n;
//pair<int,int> sizes [Max_N];

//sizes compressed
//int s_comp[Max_N];
//
//void get_i_x(int i){
//    return s_comp[i+1];
//}
//
//void get_i_y(){}

pair<int,int> sizes[Max_N];

vector< vector<int> > memo_table;

void calc_dyn(){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            memo_table[j][i]=Inf;
        }
    }

    for(int i=0;i<n;i++){
        memo_table[i][i]=0;
    }

    for(int i=n-2;i>-1;i--){
        for(int j=i+1;j<n;j++){
            for(int k=i;k<j ;k++){
                memo_table[i][j]=min(memo_table[i][j],memo_table[i][k]+memo_table[k+1][j]+sizes[i].second*sizes[k].first*sizes[j].first);
                memo_table[j][i]=k;
            }
        }
    }



    return;
}

int main(){
cin>>n;
for(int i=0;i<n;i++){
    cin>>sizes[i].first>>sizes[i].second;
}
memo_table.resize(n);
for(int i=0;i<n;i++){
    memo_table[i].resize(n);
}
calc_dyn();
//for(int i=0;i<n;i++){
//    for(int j=0;j<n;j++){
//        cout<<memo_table[j][i]<<" ";
//    }
//    cout<<endl;
//}
cout<<"Minimum number of multiplies to solve: M1*M2*M3...*MN is : "<<memo_table[0][n-1];
return 0;
}
