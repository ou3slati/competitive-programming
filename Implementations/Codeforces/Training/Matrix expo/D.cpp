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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

int32_t main(){
   boost;
   IO();

   int N,M,K; cin>>N>>M>>K; 

   int ma[N][N];
   int res[N][N];
   for(int i=0; i<N; i++) for(int j=0; j<N; j++) res[i][j]=0,ma[i][j]=0;
   for(int i=0; i<N; i++) res[i][i]=1;

   for(int i=0; i<M; i++){
   	int u,v; cin>>u>>v;
   	u--; v--;
   	ma[u][v]++;
   	//res[u][v]=1;
   }

   while(K){
   	if(K%2==1){
   		int pro[N][N]; for(int i=0; i<N; i++) for(int j=0; j<N; j++) pro[i][j]=0;
   		for(int i=0; i<N; i++) for(int j=0; j<N; j++) for(int k=0; k<N; k++) pro[i][j]+=res[i][k]*ma[k][j],pro[i][j]%=MOD;
   		for(int i=0; i<N; i++) for(int j=0; j<N; j++) res[i][j]=pro[i][j];
   	}
   	int pro[N][N]; for(int i=0; i<N; i++) for(int j=0; j<N; j++) pro[i][j]=0;
		for(int i=0; i<N; i++) for(int j=0; j<N; j++) for(int k=0; k<N; k++) pro[i][j]+=ma[i][k]*ma[k][j],pro[i][j]%=MOD;
		for(int i=0; i<N; i++) for(int j=0; j<N; j++) ma[i][j]=pro[i][j];
   	K/=2;
   }

   int ans=0;
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) ans+=res[i][j],ans%=MOD;
	cout << ans << endl;

   return 0;
}

