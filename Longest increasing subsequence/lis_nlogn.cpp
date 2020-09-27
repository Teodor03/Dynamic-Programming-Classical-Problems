#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;

const int Max_N=1000000;

struct segment_tree_node{

int _max;

};

struct segment_tree{

segment_tree_node * a;

segment_tree(int n){
    a = new segment_tree_node [4*n+1];
    for(int i=0;i<4*n;i++){
        a[i]._max=0;
    }
    return;
}

void update(int or_i,int new_val,int i,int l,int r){
    //cout<<"update : "<<or_i<<" "<<new_val<<" "<<i<<" "<<l<<" "<<r<<endl;
    if(l==r){
        a[i]._max=new_val;
        return;
    }
    int m=(r+l)/2;
    if(or_i<m+1){
        update(or_i,new_val,2*i+1,l,m);
    }else{
        update(or_i,new_val,2*i+2,m+1,r);
    }
    a[i]._max=max(a[2*i+1]._max,a[2*i+2]._max);
    return;
}

int find_max(int n_l,int n_r,int i,int l,int r){
    if(n_l>n_r){
        return 0;
    }
    if(n_l==l and n_l==r){
        return a[i]._max;
    }
    int m=(r+l)/2;
    if(n_r<m+1){
        return find_max(n_l,n_r,2*i+1,l,m);
    }
    if(n_l>m){
        return find_max(n_l,n_r,2*i+2,m+1,r);
    }
    return max(find_max(n_l,m,2*i+1,l,m),find_max(m+1,n_r,2*i+2,m+1,r));
}

};

int n;

int or_array [Max_N];
int comp_arr [Max_N];

void calc_compr(){
    vector< pair<int,int> > temp;
    for(int i=0;i<n;i++){
        temp.push_back({or_array[i],i});
    }
    std::sort(temp.begin(),temp.end());
    int curr_ind=0;
    for(int i=0;i<n;i++){
        //cout<<temp.at(i).first<<" "<<temp.at(i).second<<endl;
        comp_arr[temp.at(i).second]=curr_ind;
        if(i!=(n-1)){
            if(temp.at(i).first<temp.at(i+1).first){
                curr_ind++;
            }
        }
    }
    return;
}

//int memo_table [Max_N];


int calc_dyn(){
    segment_tree memo_table(n);
    int res=0,curr_max;
    for(int i=0;i<n;i++){
        curr_max=memo_table.find_max(0,comp_arr[i]-1,0,0,n-1);
        memo_table.update(comp_arr[i],curr_max+1,0,0,n-1);
        if((curr_max+1)>res){
            res=(curr_max+1);
        }
    }
    return res;
}

int main(){
ios_base::sync_with_stdio(false);
cin>>n;
for(int i=0;i<n;i++){
    cin>>or_array[i];
}

calc_compr();
//for(int i=0;i<n;i++){
//    cout<<comp_arr[i]<<" ";
//}
cout<<"Resulting length : "<<calc_dyn()<<endl;
return 0;
}
