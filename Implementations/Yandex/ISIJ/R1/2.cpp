//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//s.order_of_key(), *s.find_by_order()

using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
//#define int ll
typedef double db;
typedef long double ld;

typedef pair<int,int> pi;
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

int N;
char g[50][50];
int res[50][50];
//char ress[50][50];
int nb=0;
int r;

void solve(int x, int y){
   res[x][y]=1;
   if(g[x][y]=='C') {r--;}
   if(r==0){
      r=-1;
      /*for(int i=0; i<N; i++){
         for(int j=0; j<N; j++) ress[i][j]=char('0'+res[i][j]);
      }
      return;*/
      for(int i=0; i<N; i++){
         for(int j=0; j<N; j++) cout << res[i][j];
         cout << endl;
      }
      exit(0);
   }
   for(int m=0; m<4; m++){
      int nwx=x+nx[m],nwy=y+ny[m];
      if(nwx<0||nwy<0||nwx>=N||nwy>=N || res[nwx][nwy]==1) continue;
      solve(nwx,nwy);
   }
}

int main(){
   boost;
   /*ofstream cout ("cities.out");
   ifstream cin ("cities.in");*/

	cin>>N;
	for(int i=0; i<N; i++) for(int j=0; j<N; j++){
      cin>>g[i][j];
      res[i][j]=2;
      if(g[i][j]=='C') nb++;
	}
	r=nb/2;
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) if(g[i][j]=='C'){
      solve(i,j);
      break;
	}
	/*for(int i=0; i<N; i++){
      for(int j=0; j<N; j++) cout << ress[i][j];
      cout << endl;
   }*/

   return 0;
}

