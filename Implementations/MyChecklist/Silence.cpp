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
   //IO();

   int N,M,C; cin>>N>>M>>C;
   int a[N];
   for(int i=0; i<N; i++) cin>>a[i];

   vi vec;
   multiset<int> s;
	for(int i=0; i<N; i++){
		s.insert(a[i]);
		if(i<M-1) continue;

		auto it=s.end(); it--;
		int x=*it;
		it=s.begin();
		x-=*it;

		if(x<=C) vec.pb(i-M+1);
		s.erase(s.find(a[i-M+1]));
	}
	if(vec.empty()) cout << "NONE" << endl;
	else for(auto x: vec) cout << x+1 << endl;
	

   return 0;
}

