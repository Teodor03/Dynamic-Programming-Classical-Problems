#include<iostream>
#include<vector>
using namespace std;

const int Max_N=100000;
const int Inf=99999999;

int n,n_val,max_sum=0;
int co [Max_N];

vector<int> res_seq;

//mem[j][i] minimal coins to make j value, by using the first i coins
//
//mem[j][i]=min(mem[j][i-1],1+mem[j-co[i]][i-1]);
//
vector< vector<int> > mem;

// back_tr[j][i] true for using i coin, false for not using i coin
vector< vector<bool> > back_tr;

int access_mem(int j,int i){
    if(j<0 or i<0){
        return Inf;
    }
    if(j==0){
        return 0;
    }
    return mem[j][i];
}

void calc_dyn(){
    mem.resize(n_val+1);
    back_tr.resize(n_val+1);
    for(int i=0;i<=n_val;i++){
        mem[i].resize(n);
        back_tr[i].resize(n);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=n_val;j++){
            int arg_1=access_mem(j,i-1);
            int arg_2=access_mem(j-co[i],i-1)+1;
            if(arg_1<arg_2){
                mem[j][i]=arg_1;
                back_tr[j][i]=false;
            }else{
                mem[j][i]=arg_2;
                back_tr[j][i]=true;
            }
            //mem[j][i]=min(access_mem(j,i-1),access_mem(j-co[i],i-1)+1);
        }
    }

    return;
}

void find_cont(){
    int curr_x=n_val;
    int curr_y=n-1;
    while(curr_x>0 or curr_y>0){
        //cout<<"Now : "<<curr_x<<" "<<curr_y<<endl;
        if(back_tr[curr_x][curr_y]){
            res_seq.push_back(co[curr_y]);
            curr_x-=co[curr_y];
            curr_y--;
        }else{
            curr_y--;
        }
    }
    return;
}

/*

Examples:

7 6
1 2 2 3 3 4 6

14 31
0 5 2 2 3 2 2 2 4 3 5 8 6 7 9

*/

int main(){
ios_base::sync_with_stdio(false);
cin>>n>>n_val;
for(int i=0;i<n;i++){
    cin>>co[i];
    max_sum+=co[i];
}
calc_dyn();
//for(int i=0;i<n;i++){
//    for(int j=0;j<=n_val;j++){
//        cout<<back_tr[j][i]<<" ";
//    }
//    cout<<endl;
//}
cout<<"Minimal amount of coins to make "<<n_val<<" is : "<<mem[n_val][n-1]<<endl;
cout<<"Values of selected coins are : ";
find_cont();
for(int i=0;i<res_seq.size();i++){
    cout<<res_seq[i]<<" ";
}
return 0;
}
