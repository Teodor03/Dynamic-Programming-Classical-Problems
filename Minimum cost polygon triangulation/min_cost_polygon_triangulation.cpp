#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
#include<algorithm>
using namespace std;

const int Inf=999999999;

int n;
//n points forming a
vector< pair<float,float> > p_loc;

vector< vector<float> > dist;

float calc_dist_betw_pair(pair<float,float> p_o,pair<float,float> p_t){
    return sqrt( (p_o.first-p_t.first)*(p_o.first-p_t.first)+(p_o.second-p_t.second)*(p_o.second-p_t.second) );
}

void calc_dist(){
    dist.resize(n);
    for(int i=0;i<n;i++){
        dist[i].resize(n);
    }
    for(int i=0;i<n;i++){
        dist[i][i]=0;
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            dist[i][j]=calc_dist_betw_pair(p_loc[i],p_loc[j]);
            dist[j][i]=dist[i][j];
        }
    }
    return;
}

vector< vector<float> > memo_table;

void calc_dyn(){
    memo_table.resize(n);
    for(int i=0;i<n;i++){
        memo_table[i].resize(n);
    }
    //memo
    for(int i=0;i<n;i++){
        memo_table[i][i]=0;
    }
    for(int i=0;i<n-1;i++){
        memo_table[i][i+1]=0;
    }

    for(int i=n-1;i>-1;i--){
        for(int j=i+2;j<n;j++){
            memo_table[i][j]=Inf;
            for(int k=i+1;k<j;k++){
                if( (memo_table[i][k]+memo_table[k][j]+dist[i][j]+dist[i][k]+dist[k][j])<memo_table[i][j]){
                    memo_table[i][j]=(memo_table[i][k]+memo_table[k][j]+dist[i][j]+dist[i][k]+dist[k][j]);
                }
                //memo_table[i][j]=min (memo_table[i][j], (memo_table[i][k]+memo_table[k+1][j]+dist[i][j]+dist[i][k]+dist[k][j]) );
            }
        }
    }
    return;
}

float get_min_cut(){
    float P=dist[0][n-1];
    for(int i=0;i<n-1;i++){
        P+=dist[i][i+1];
    }
    //cout<<"P : "<<P<<endl;
    return (memo_table[0][n-1]-P)/2;
}

/*

6
1 1
5 1
7 4
4 6
-1 5
-3 1



*/

int main(){
ios_base::sync_with_stdio(false);
cin>>n;
float a,b;
for(int i=0;i<n;i++){
    cin>>a>>b;
    p_loc.push_back({a,b});
}
calc_dist();
//for(int i=0;i<n;i++){
//    for(int j=0;j<n;j++){
//        cout<<dist[j][i]<<" ";
//    }
//    cout<<endl;
//}
calc_dyn();
//for(int i=0;i<n;i++){
//    for(int j=0;j<n;j++){
//        cout<<memo_table[j][i]<<" ";
//    }
//    cout<<endl;
//}
cout<<"Min sum of diag. length to cut the polygon in triangles : "<<get_min_cut()<<endl;
return 0;
}
