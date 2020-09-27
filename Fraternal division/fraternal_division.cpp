#include<iostream>
#include<vector>
using namespace std;

const int Max_N=10000;

int n;
int obj [Max_N];

vector<bool> is_pos;

int _max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

void calculate(){

    int s=0,curr_max_s=0;
    for(int i=0;i<n;i++){
        s+=obj[i];
    }

    is_pos.resize(s+1);
    is_pos[0]=true;

    for(int i=0;i<n;i++){
        for(int j=curr_max_s;j>-1;j--){
            if(is_pos.at(j)){
                is_pos.at(j+obj[i])=true;
                curr_max_s=_max(curr_max_s,j+obj[i]);
            }
        }
    }

    for(int i=s/2;i>-1;i--){
        if(is_pos[i]){
            cout<<"Guy 1 takes : "<<i<<endl<<"Guy 2 takes : "<<(s-i)<<endl;
            return;
        }
    }

    return;
}

/*

10
3 2 3 2 2 77 89 23 90 11
cout<<"aetgryhtrgrtgrtg";

*/

int main(){
ios_base::sync_with_stdio(false);
cin>>n;

for(int i=0;i<n;i++){
    cin>>obj[i];
}

calculate();
return 0;
}
