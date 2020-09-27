#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int Inf=999999999;

int n,m;
string f,s;
int repl_c,ins_c,del_c;

//mem[j][i] = the min price to turn the first j charracters of f to the first i characters of s.
vector< vector<int> > mem;

int g_mem(int j,int i){
    if(j==-1 and i==-1){
        return 0;
    }
    if(j<0 or i<0){
        return Inf;
    }
    return mem[j][i];
}

int _min(int a,int b,int c){
    if(a<b and a<c){
        return a;
    }
    if(b<a and b<c){
        return b;
    }
    if(c<a and c<b){
        return c;
    }
    return a;
}

void calc_dyn(){
    mem.resize(n);
    for(int i=0;i<n;i++){
        mem[i].resize(m);
    }
    mem[0][0]=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(f.at(j)==s.at(i)){
                mem[j][i]=g_mem(j-1,i-1);
            }else{
                mem[j][i]=_min(g_mem(j-1,i-1)+repl_c,g_mem(j-1,i)+del_c,g_mem(j,i-1)+ins_c);
            }
        }
    }
    return;
}

int main(){
ios_base::sync_with_stdio(false);
cin>>f>>s;
n=f.length();
m=s.length();
cin>>repl_c>>ins_c>>del_c;
calc_dyn();
//    for(int i=0;i<m;i++){
//        for(int j=0;j<n;j++){
//            cout<<mem[j][i]<<" ";
//        }
//        cout<<endl;
//    }
cout<<"Min price to turn first string into second string is : "<<mem[n-1][m-1];
return 0;
}
