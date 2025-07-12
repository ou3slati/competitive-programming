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
int N,Q,K;

int a[100001];
int cnt[2000001];
int res[100001];
vector<pair<pi,int>> queries;
int ans=0;

bool mo(pair<pi,int> a,pair<pi,int>b){
	if(a.fi.fi/S!=b.fi.fi/S) return a.fi.fi/S<b.fi.fi/S;
	return a.fi.fi/S&1 ? a.fi.se<b.fi.se : a.fi.se>b.fi.se;
}

void add(int x){
	ans+=cnt[((x)^(K))];
	cnt[x]++;
}

void remove(int x){
	cnt[x]--;
	ans-=cnt[((x)^(K))];
}

int32_t main(){
   boost;
   IO();

   cin>>N>>Q>>K; S=ceil(sqrt(N));
   for(int i=1; i<=N; i++) cin>>a[i];
   a[0]=0; cnt[0]=0;
   for(int i=1; i<=N; i++) a[i]^=a[i-1],cnt[a[i]]=0;

   //for(int i=1; i<=N; i++) cout << a[i] << ' '; cout << endl;
   //cout << (int)((a[6])^(a[5])) << endl;
   
	for(int i=0; i<Q; i++){
		int l,r; cin>>l>>r; l--;
		queries.pb({{l,r},i});
	}

	sort(all(queries),mo);
		
	int cl=1,cr=0;
	
	for(auto x: queries){
		int l=x.fi.fi,r=x.fi.se,idx=x.se;
		while(cl>l){
			cl--;
			add(a[cl]);
			//cout << ans << endl;
		}
		while(cr<r){
			cr++;
			add(a[cr]);
			//cout << ans << endl;
		}
		while(cl<l){
			remove(a[cl]);
			cl++;
			//cout << ans << endl;
		}		
		while(cr>r){
			remove(a[cr]);
			cr--;
			//cout << ans << endl;
		}

		res[idx]=ans;
	}
	for(int i=0; i<Q; i++) cout << res[i] << endl;

   return 0;
}


//the number of pairs (i,j) st pref[j]^pref[i-1]=k (in the interval [l-1,r])
//when adding x add cnt[x^k]
//x^y=K --> y=x^k

