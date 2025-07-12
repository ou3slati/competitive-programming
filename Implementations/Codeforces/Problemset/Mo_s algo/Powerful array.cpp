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

int S;
int cnt[1000001];
int ans=0;

bool mo(pair<pi,int> a, pair<pi,int> b){
	if(a.fi.fi/S!=b.fi.fi/S) return a.fi.fi/S<b.fi.fi/S;
	//return a.fi.se<b.fi.se;
	return ((a.fi.fi/S)&1)? a.fi.se<b.fi.se : a.fi.se>b.fi.se;
}

void add(int x){
	ans-=cnt[x]*cnt[x]*x;
	cnt[x]++;
	ans+=cnt[x]*cnt[x]*x;
}
void remove(int x){
	ans-=cnt[x]*cnt[x]*x;
	cnt[x]--;
	ans+=cnt[x]*cnt[x]*x;
}

int32_t main(){
   boost;
   IO();

   int N,Q; cin>>N>>Q; S=ceil(sqrt(N));
   int a[N];
   for(int i=0; i<N; i++){cin>>a[i]; cnt[a[i]]=0;}

   vector<pair<pi,int>> queries;
   for(int i=0; i<Q; i++){
   	int l,r; cin>>l>>r; l--; r--;
   	queries.pb({{l,r},i});
   }	

   sort(all(queries),mo);

   int res[Q];
   int cl=0,cr=-1;
   for(auto x: queries){
   	int l=x.fi.fi,r=x.fi.se,idx=x.se;
   	while(cl<l){
   		remove(a[cl]);
   		cl++; 
   	}
   	while(cl>l){
   		cl--;
   		add(a[cl]);
   	}
   	while(cr<r){
   		cr++;
   		add(a[cr]);
   	}
   	while(cr>r){
   		remove(a[cr]);
   		cr--;
   	}
   	res[idx]=ans;
   }

   for(int i=0; i<Q; i++) cout << res[i] << endl; 
	
   return 0;
}

