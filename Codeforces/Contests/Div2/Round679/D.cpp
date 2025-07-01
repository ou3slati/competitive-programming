/*
CF 679D - TBD
https://codeforces.com/contest/1435/problem/D

Key insights:
1. TBD
2. TBD
3. TBD
*/

#include <bits/stdc++.h>
using namespace std;

#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;	
typedef double db;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<str> vs;
typedef vector<ld> vd;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 2e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

#define dbg(x) cerr << " - " << #x << " : " << x << endl;
#define dbgs(x,y) cerr << " - " << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << " - " << #v << " : " << endl << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;

void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int N; 
vi v(MX); //the value added
vi a(MX,0); //size
set<int> s[MX];

void no(){
	cout << "NO" << endl;
	exit(0);
}

vi t(MX*4,0);

void update(int i, int val, int pos=1, int l=0, int r=N-1){
	if(l==r){
		t[pos]=val;
		return;
	}
	int m=(l+r)/2;
	if(i<=m) update(i,val,pos*2,l,m);
	else update(i,val,pos*2+1,m+1,r);
	t[pos]=max(t[pos*2],t[pos*2+1]);
}

int get(int l, int r, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return 0;
	if(l==tl && r==tr) return t[pos];
	int tm=(tl+tr)/2;
	return max(get(l,min(r,tm),pos*2,tl,tm),get(max(l,tm+1),r,pos*2+1,tm+1,tr));

}


int main() {
	boost; IO();

	cin>>N;
	//divide to ++ . ++ . ++ .
	int idx=0,last=-1;
	FOR(i,0,N*2){
		char c; cin>>c;
		if(c=='-'){
			int x; cin>>x;
			v[idx]=x; a[idx]=i-last-1;
			idx++; last=i; 
		}
	}

	FOR(i,0,N) update(i,v[i]);

	V<pi> vec; //{value to put, before which add}
	FOR(i,0,N){
		//min idx sth max(v[idx]-->v[i])<=v[i]
		int l=0,r=i;
		int idx=-1;
		while(l<=r){
			int m=(l+r)/2;
			if(get(m,i)<=v[i]){
				idx=m; r=m-1;
			}
			else l=m+1;
		}
		vec.pb({idx,i});
	}

	for(auto x: vec) s[x.fi].insert(x.se);

	deque<int> d;
	set<int> ss;
	FOR(i,0,N){
		while(!s[i].empty()){
			ss.insert(*(s[i].begin()));
			s[i].erase(s[i].begin());
		}
		while(!ss.empty() && a[i]>0){
			d.pb(*(ss.begin()));
			ss.erase(ss.begin());
			a[i]--;
		}
		if(!ss.empty() && *(ss.begin())<=i) no();
		//for(auto x: s[i]) s[i+1].insert(x);
	}
		
	cout << "YES" << endl;
	for(auto x: d) cout << v[x] << ' '; cout << endl;



	return 0;
}

