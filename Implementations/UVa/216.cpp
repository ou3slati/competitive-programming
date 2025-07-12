#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ldb;

typedef pair<int,int> pi;
#define mp make_pair
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)


const int MOD = 1e9+7;
const ldb INF = 999999;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};


int N;
int x[9];
int y[9];
db dist[9][9];
db memo[9][1<<8];
int p[9][1<<8];

void initialize(){
   for (int i=0; i<8; i++) for (int j=0; j<8; j++) dist[i][j]=-1;
   for (int i=0; i<8; i++) for (int j=0; j<(1<<8); j++){p[i][j]=-1; memo[i][j]=-1;}
   return;
}

db tsp(int i, int m){
   if(m==(1<<N)-1) return 0;
   db &ind=memo[i][m];
   if(ind>=0) return ind;
   db pt=INF;
   for (int c=0; c<N; c++) if(!(m&(1<<c))&&c!=i){
      db x=tsp(c, m|(1<<c) )+dist[i][c];
      if(x<pt){
         pt=x;
         p[i][m]=c;
      }
   }
   return ind=pt;
}

int32_t main(){
   cin>>N;
   int nb=0;
   while(N){
      initialize();
      nb++;
      printf("**********************************************************\nNetwork #%d\n",nb);
      for (int i=0; i<N; i++)cin>>x[i]>>y[i];
      for (int i=0; i<N; i++) for (int j=0; j<N; j++){
         int absc=abs(x[i]-x[j]), ord=abs(y[i]-y[j]);
         db w=sqrt(absc*absc+ord*ord);
         dist[i][j]=w+16; dist[j][i]=w+16;
      }

      db l=INF;
      int idx=-1;
      for (int i=0; i<N; i++){
         db x=tsp(i,(1<<i));
         if(x<l){
            idx=i;
            l=x;
         }
      }
      int m=1<<idx;
      while(p[idx][m]!=-1){
         int c=p[idx][m];
         cout << "Cable requirement to connect ("<<x[idx]<<','<<y[idx]<<')'<<" to "<<'('<<x[c]<<','<<y[c]<<')'<<" is "<<fixed<<setprecision(2)<<dist[idx][c]<<" feet."<<endl;
         idx=c;
         m|=(1<<idx);
      }

      printf("Number of feet of cable required is %.2lf.\n",l);

      cin>>N;
   }

}
/*
6
5 19
55 28
38 101
28 62
111 84
43 116
5
11 27
84 99
142 81
88 30
95 38
3
132 73
49 86
72 111
*/
