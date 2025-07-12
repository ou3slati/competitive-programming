
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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

const int MXN=1e6+10;
int t[MXN];

int32_t main(){
   boost;

	int N; cin>>N;
	/*int fact[N+1];
	fact[0]=1;
	for(int i=1; i<=N; i++) fact[i]=fact[i-1]*i;

	for(int i=1; i<=N; i++) cin>>t[i];
	int x=getOrder();
	for(int i=1; i<=N; i++) cin>>t[i];
	int y=getOrdet();

	int ord=()*/
	int t[N];
	for(int i=0; i<N; i++) t[i]=i+1;
	int cnt=0;
	do{
      cout << ++cnt << ".   ";
      for(int i=0; i<N; i++) cout << t[i] << ' ';
      cout << endl;
	} while(next_permutation(t,t+N));


   return 0;
}

