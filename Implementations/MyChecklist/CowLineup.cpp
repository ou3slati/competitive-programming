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
    freopen("lineup.in", "r", stdin); 
    freopen("lineup.out", "w", stdout); 
#endif 
}

int32_t main(){
   boost;
   IO();

   int N,K; cin>>N>>K;

   unordered_map <int,int> mp;

   int t[N];
   int cnt=0;
   for(int i=0; i<N; i++){
   	int x; cin>>x;
   	if(!mp.count(x)) mp[x]=cnt++;
   	t[i]=mp[x];
   }

   int c[cnt];
   for(int i=0; i<cnt; i++) c[i]=0;

   int j=-1,nb=0;
   int res=0;

   for(int i=0; i<N; i++){
   	while(j<N-1 && nb<=K+1){
   		j++;
   		if(c[t[j]]==0) nb++;
   		if(nb>K+1){
   			nb--;
   			j--; break;
   		}
   		c[t[j]]++;
   	}
   	//cout << i << ' ' << j << endl;
   	res=max(res,c[t[i]]);
   	c[t[i]]--;
   	if(c[t[i]]==0) nb--;
   }

   cout << res << endl;
	

   return 0;
}

