/*#include "garden.h"
#include "gardenlib.h"*/
//#include "grader.h"
#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
//#define int ll
typedef double db;
typedef long double ld;

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

const int MXN=150000+1;

int ans;
int V,E,D;
vpi g[MXN];
int num;
vi p;

void dfs(int u, int c){
   if(c==num && u==D){ans++; return;}
   if(c==num) return;
   int mx=0,v=-1;
   for (auto x: g[u]){
      if(g[u].size()==1){ v=x.fi; break;}
      if(x.se>mx && p[u]!=x.fi){mx=x.se; v=x.fi;}
   }
   p[v]=u;
   dfs(v,c+1);
   return;
}

void count_routes(int N, int M, int P, int R[][2], int Q, int G[]){
   V=N; E=M; D=P;
   int w=E;
   for (int i=0; i<E; i++){
      int a=R[i][0],b=R[i][1];
      g[a].pb({b,w});
      g[b].pb({a,w});
      w--;
   }
   for (int q=0; q<Q; q++){
      ans=0; num=G[q];
      for (int i=0; i<V; i++){p.assign(V,-1); dfs(i,0);}
      answer(ans);
   }
}

/*int main(){
   return 0;
}*/


/*
6 6 0

1 2
0 1
0 3
3 4
4 5
1 5

1
3

*/

/*

5 5 2

1 0
1 2
3 2
1 3
4 2

2
3
1
*/
