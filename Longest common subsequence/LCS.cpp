#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int n,m;
string A,B;

vector< vector<int> > memo_table;

vector< vector<int> > backtrack;
vector<char> resulting_sub;

int get_from_m(int j,int i){
    if(j<0 or i<0){
        return 0;
    }
    return memo_table[j][i];
}

void calc_dyn(){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(A.at(j)==B.at(i)){
                memo_table[j][i]=get_from_m(j-1,i-1)+1;
                backtrack[j][i]=0;
            }else{
                memo_table[j][i]=max(get_from_m(j-1,i),get_from_m(j,i-1));
                if(get_from_m(j-1,i)>get_from_m(j,i-1)){
                    backtrack[j][i]=1;
                }else{
                    backtrack[j][i]=2;
                }
            }

        }
    }
    return;
}

void calc_res_subs(){
    int curr_x=n-1,curr_y=m-1;
    while(true){
        //cout<<"Loop: "<<curr_x<<" "<<curr_y<<endl;
        if(backtrack[curr_x][curr_y]==0){
            resulting_sub.push_back(A.at(curr_x));
            curr_x--;
            curr_y--;
        }else{
            if(backtrack[curr_x][curr_y]==1){
                curr_x--;
            }else{
                curr_y--;
            }
        }
        if(curr_x==0 and curr_y==0){
            if(backtrack[curr_x][curr_y]==0){
                resulting_sub.push_back(A.at(curr_x));
            }
            return;
        }
    }
    return;
}

int main(){
ios_base::sync_with_stdio(false);
cin>>A>>B;
n=A.length();//!!!
m=B.length();//!!!
memo_table.resize(n);
backtrack.resize(n);
for(int i=0;i<n;i++){
    memo_table[i].resize(m);
    backtrack[i].resize(m);
}
calc_dyn();
//cout<<endl;
//for(int i=0;i<m;i++){
//    for(int j=0;j<n;j++){
//        cout<<memo_table[j][i]<<" ";
//    }
//    cout<<endl;
//}
cout<<"Longest common subsequence : "<<get_from_m(n-1,m-1)<<endl;
calc_res_subs();
cout<<"Subsequence is : ";
for(int i=resulting_sub.size()-1;i>-1;i--){
    cout<<resulting_sub[i];
}
return 0;
}
