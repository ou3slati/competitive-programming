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

const int MX=1e5+10;
int N,K; 
unordered_map<int,int> cnt;
int pref[MX];
int ans=0; 	

bool mo(pair<pi,int> a,pair<pi,int>b){
   const int S=ceil(sqrt(N));
	if(a.fi.fi/S!=b.fi.fi/S) return a.fi.fi/S<b.fi.fi/S;
	return a.fi.fi/S&1 ? a.fi.se<b.fi.se : a.fi.se>b.fi.se;
}

void remove(int alpha){
   cnt[alpha]--;
   ans-=cnt[alpha-K];
	
	
}
void add(int alpha){
   ans+=cnt[alpha-K];
   cnt[alpha]++;
}
void remove2(int alpha){
   cnt[alpha]--;
   ans-=cnt[alpha+K];
   
   
}
void add2(int alpha){
   ans+=cnt[alpha+K];
   cnt[alpha]++;
}

int32_t main(){
   boost;
   IO();

   cin>>N>>K; //S=ceil(sqrt(N));

   pref[0]=0;
   int type[N+1];

   for(int i=1; i<=N; i++) cin>>type[i];

   for(int i=1; i<=N; i++){
   	int t,x; cin>>x; t=type[i];
   	
   	if(t==1) pref[i]=x;
      else pref[i]=-x;
   	pref[i]+=pref[i-1];
   }

   int Q; cin>>Q;
   vector<pair<pi,int>> q;
   for(int i=0; i<Q; i++){
   	int l,r; cin>>l>>r;
   	l--;
   	q.pb({{l,r},i});
   }
   sort(all(q),mo);

   int res[Q];
   int cl=1,cr=0;

   for(auto x: q){
   	int l=x.fi.fi,r=x.fi.se,idx=x.se;

   	while(cl<l){
   		remove2(pref[cl]);
   		cl++;
   	}
   	while(cl>l){
   		cl--;
   		add2(pref[cl]);
   	}
   	while(cr<r){
   		cr++;
   		add(pref[cr]);
   	}
   	while(cr>r){
   		remove(pref[cr]);
   		cr--;
   	}

   	res[idx]=ans;
   }

   for(int i=0; i<Q; i++) cout << res[i] << endl;

	

   return 0;
}

// pref[j]-pref[i-1]=K
// pref[i-1]=pref[j]-K
// pref[j]=K+pref[i-1];