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

   int N; cin>>N;
   int t[N];
   for(int i=0; i<N; i++) cin>>t[i];

   int ans=0;
   int cnt[N+1];
   
   for(int x=1; x*x<=N; x++){
   	//cout << x << endl;
   	for(int i=0; i<=N; i++) cnt[i]=0;
   	int nb=0;
   	for(int i=0; i<N; i++){
   		if(cnt[t[i]]==x) nb--;
   		cnt[t[i]]++;
   		if(cnt[t[i]]==x) nb++;
   		//if(x==3) cout << cnt[t[i]] << ' ' << nb << endl;

   		if(i+1<x*x) continue;
   		if(nb==x) ans++; //cout << x << endl;
   		//cout << x << ' ' <<nb << endl;

   		int j=i-x*x+1;
   		if(cnt[t[j]]==x) nb--;
   		cnt[t[j]]--;
   		if(cnt[t[j]]==x) nb++;

   	}
   }
   cout << ans << endl;
	

   return 0;
}

