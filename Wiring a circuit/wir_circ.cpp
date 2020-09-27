#include<iostream>
#include<vector>
using namespace std;

const int Max_N=100000;

int n;
// Wiring task looks like this :
// 1 2 3 ... n
// outp[0] outp[1] ... outp[n-1]
//
//(outp is basically a random permutation of the original array)

int outp [Max_N];
int perm [Max_N];

//vector<int> sol;
int sm_mem [Max_N];
//vector< vector<int> > mem;

//int acc_mem(int j,int i){
//    if(j<0 or i<0){
//        return 0;
//    }
//    return mem[j][i];
//}

int acc_sm_mem(int j){
    if(j<0){
        return 0;
    }
    return sm_mem[j];
}

void calc_dyn(){
//    mem.resize(n);
//    for(int i=0;i<n;i++){
//        mem[i].resize(n);
//    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(perm[i]<=j){
                if((1+acc_sm_mem(perm[i]-1))>sm_mem[j]){
                    //sol.push_back(i);
                    sm_mem[j]=(1+acc_sm_mem(perm[i]-1));
                }
                //sm_mem[j]=max((1+acc_sm_mem(perm[i]-1)),acc_sm_mem(j));
//                mem[j][i]=max((1+acc_mem(perm[i]-1,i-1)),acc_mem(j,i-1));
            }else{
//                mem[j][i]=acc_mem(j,i-1);
            }

//            cout<<endl;
//            cout<<"Curr calculated : "<<j<<" "<<i<<endl;
//            for(int i=0;i<n;i++){
//                for(int j=0;j<n;j++){
//                    cout<<mem[j][i]<<" ";
//                }
//                cout<<endl;
//            }
//            cout<<endl;
        }
    }
    return;
}

/*

9
2 5 3 8 7 4 6 9 1

*/

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cin>>n;
//for(int i=0;i<n;i++){
//    cout<<i+1<<" ";
//}
//cout<<endl;
for(int i=0;i<n;i++){
    cin>>outp[i];
    perm[(outp[i]-1)]=i;
}
//cout<<endl;
//for(int i=0;i<n;i++){
//    cout<<perm[i]<<" ";
//}
//cout<<endl<<endl;
calc_dyn();
//for(int i=0;i<n;i++){
//    for(int j=0;j<n;j++){
//        cout<<mem[j][i]<<" ";
//    }
//    cout<<endl;
//}
cout<<"Maximum number of cables that you can connect is : "<<sm_mem[n-1]<<endl;
return 0;
}
