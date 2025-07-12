//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
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

const int MOD = 998244353; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

int N,E,K;
int t[50][50];
int memo[50][101][2][2][10];

int solve(int u, int i, int st, int st2, int k){
	if(i==E && u==N-1 && st==1 && st2==1 && k==K) return 1;
	if(i==E) return 0;
	if(memo[u][i][st][st2][k]!=-1) return memo[u][i][st][st2][k];
	int ans=0;
	for(int v=0; v<N; v++) if(t[u][v]==1) ans=(ans+solve(v,i+1,(st)|(v==1),(st2)|(v==2),min(K+1,k+(v==3))))%MOD;
	return memo[u][i][st][st2][k]=ans;
}

int32_t main(){
   boost;
   IO();

   memset(memo,-1,sizeof(memo));
   cin>>N>>E>>K;
   for(int i=0; i<N; i++) for(int j=0; j<N; j++){
   	char c; cin>>c;
   	t[i][j]=c-'0';
   }

   cout << solve(0,1,0,0,0) << endl;

   return 0;
}

