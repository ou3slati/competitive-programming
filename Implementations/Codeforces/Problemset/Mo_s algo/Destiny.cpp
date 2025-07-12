//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
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
const int INF = 1e9;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

const int MX=3e5+10;
int N,Q; int S;
int a[MX];
vector<pair<pi,int>> vec;
int K[MX];

unordered_map<int,set<int>> s;
int cnt[MX];
vi st(4*MX,INF);

bool mo(pair<pi,int> a, pair<pi,int> b){
	if(a.fi.fi/S!=b.fi.fi/S) return a.fi.fi/S<b.fi.fi/S;
	return (a.fi.fi/S)&1 ? a.fi.se<b.fi.se: a.fi.se>b.fi.se;
}

int query(int l, int r, int pos, int tl, int tr){
	if(l>r) return INF;
	if(l==tl && r==tr) return st[pos];
	int tm=(tl+tr)/2;
	return min(query(l,min(r,tm),pos*2,tl,tm),query(max(l,tm+1),r,pos*2+1,tm+1,tr));
}

bool yh;

void update(int i, int v, int pos, int l, int r){
	if(i==0) return;
	if(l==r){
		//if(yh) 
			
		//else 
			//cout << i << ' ' << st[pos] << ' ';
			st[pos]=v; 
			//cout << i << ' ' << st[pos] << endl;
		//cout << i << ' ' << v << endl;
		return;		
	}
	int m=(l+r)/2;
	if(i<=m) update(i,v,pos*2,l,m);
	else update(i,v,pos*2+1,m+1,r);

	st[pos]=min(st[pos*2],st[pos*2+1]);
	//cout << st[pos] << endl;
}

void add(int x){
	s[cnt[x]].erase(x);
	if(s[cnt[x]].empty()) update(cnt[x],INF,1,1,N);
	else{
		auto it=(s[cnt[x]]).begin();
		update(cnt[x],*it,1,1,N);
	}
	cnt[x]++;
	s[cnt[x]].insert(x);
	auto it=(s[cnt[x]]).begin();
	update(cnt[x],*it,1,1,N);

	//for(int i=1; i<=2; i++){for(auto x: s[i]) cout << x << ' '; cout << endl;}
}

void remove(int x){
	s[cnt[x]].erase(x);
	if(s[cnt[x]].empty()) update(cnt[x],INF,1,1,N);
	else{
		auto it=s[cnt[x]].begin();
		update(cnt[x],*it,1,1,N);
	}
	cnt[x]--;
	s[cnt[x]].insert(x);
	auto it=s[cnt[x]].begin();
	update(cnt[x],*it,1,1,N);
	//for(int i=1; i<=2; i++){for(auto x: s[i]) cout << x << ' '; cout << endl;}
}

int main(){
   boost;
   IO();
   for(int i=0; i<MX; i++) cnt[i]=0;
   cin>>N>>Q; S=ceil(sqrt(N));
   for(int i=0; i<N; i++) cin>>a[i],s[0].insert(a[i]);

	for(int i=0; i<Q; i++){
		int l,r,k; cin>>l>>r>>k; l--; r--; K[i]=k;
		vec.pb({{l,r},i});
	}

	sort(all(vec),mo);

	int cl=0,cr=-1;
	int res[Q];
	for(auto x: vec){
		int l=x.fi.fi,r=x.fi.se,idx=x.se;
		while(cr<r){
			cr++;
			add(a[cr]);
		}

		while(cl>l){
			cl--;
			add(a[cl]);
		}
		while(cl<l){
			remove(a[cl]); 
			cl++;
		}
		
		while(cr>r){
			remove(a[cr]);
			cr--;
		}

		//for(int i=1; i<=2; i++){for(auto x: s[i]) cout << x << ' '; cout << endl;}


		int ans=query((r-l+1)/K[idx]+1,N,1,1,N);
		/*yh=true;
		for(int i=1; i<=N; i++) update(i,0,1,1,N);
		yh=false; cout << endl;*/
		if(ans==INF) ans=-1;
		res[idx]=ans;
	}
	for(int i=0; i<Q; i++) cout << res[i] << endl;


   return 0;
}

