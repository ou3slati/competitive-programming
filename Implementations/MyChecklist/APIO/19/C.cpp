//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
const int MX = 3e5 + 10;
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


int N,Q; str s;
V<pair<int,pi>> q;


bool sub2(){
	for(auto x: q) if(x.fi==1){
		if(x.se.se-x.se.fi!=1) return false;
	}
	return true;
}

bool sub3(){
	str ss=s;
	for(auto x: q) if(x.fi==0){
		int idx=x.se.fi;
		if(ss[idx]=='0') ss[idx]=1;
		else return false;
	}
	return true;
}

bool check(str ss, int l, int r){
	FOR(i,l,r) if(ss[i]=='0') return 0;
	return 1;
}

V<ll> t(4*MX,INF);

void update(int i, int x, int pos=1, int l=0, int r=N-1){
	if(l==r){
		t[pos]=x;
		return;
	}

	int m=(l+r)/2;
	if(i<=m) update(i,x,pos*2,l,m);
	else update(i,x,pos*2+1,m+1,r);
	t[pos]=max(t[pos*2],t[pos*2+1]);
}

ll get(int l, int r, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return -1;
	if(l==tl && r==tr) return t[pos];
	int tm=(tl+tr)/2;
	return max(get(l,min(tm,r),pos*2,tl,tm),get(max(tm+1,l),r,pos*2+1,tm+1,tr));
}


bool cmp(pair<pi,pi> a, pair<pi,pi> b){
	if(a.fi.fi!=b.fi.fi) return a.fi.fi < b.fi.fi;
	return a.se.se < b.se.se;
}

vi bit(MX,0);
void add(int i, int v){
	i++;
	for(;i<MX;i+=i&-i) bit[i]+=v;
}
int getSum(int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=bit[i];
	return ans;
}
int getSumRange(int l, int r){
	l++; r++;
	return getSum(r)-getSum(l-1);
}

vi number(MX,0);
void updateNumber(int i,int v){
	i++;
	for(;i<MX;i+=i&-i) number[i]+=v;
}
int getNum(int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=number[i];
	return ans;
}
int getNumber(int l, int r){
	r++; l++;
	return getNum(r)-getNum(l-1);
}


vi rmv(MX,0);
void updateToRemove(int i,int v){
	i++;
	for(;i<MX;i+=i&-i) rmv[i]+=v;
}
int getRmv(int i){
	int ans=0;
	
	for(;i;i-=i&-i) ans+=rmv[i];
	return ans;
}
int getToRemove(int l, int r){
	r++; l++;
	return getRmv(r)-getRmv(l-1);
}


vi closed(MX,0);
void updateClosed(int i,int v){
	i++;
	for(;i<MX;i+=i&-i) closed[i]+=v;
}
int getCl(int i){	
	int ans=0;
	for(;i;i-=i&-i) ans+=closed[i];
	return ans;
}
int getClosed(int l, int r){
	r++; l++;
	return getCl(r)-getCl(l-1);
}

int main() {
	boost; IO();

	cin>>N>>Q;
	cin>>s;
	
	FOR(i,0,Q){
		str t; cin>>t;
		if(t=="toggle"){
			int i; cin>>i; i--;
			q.pb({0,{i,-1}});
		}
		else{
			int i,j; cin>>i>>j; i--; j--;
			q.pb({1,{i,j}});
		}
	}

	vi ans;
	if(N<=100 && Q<=100){
		FOR(i,0,Q)if(q[i].fi==1){
			str ss=s;
			int x=0;
			int l=q[i].se.fi,r=q[i].se.se;
			if(check(ss,l,r)) x++;

			FOR(j,0,i){
				if(q[j].fi==0){
					int idx=q[j].se.fi;
					if(ss[idx]=='0') ss[idx]='1';
					else ss[idx]='0';
				}
				if(check(ss,l,r)) x++;
			}
			ans.pb(x);
		}
	}
	else if(sub2()){
		vi v(N,0),state(N,-1); 
		FOR(j,0,N) if(s[j]=='1') state[j]=0;

		FOR(i,0,Q){
			if(q[i].fi==0){
				int idx=q[i].se.fi;
				if(state[idx]==-1) state[idx]=i+1;
				else{
					v[idx]+=i+1-state[idx];
					state[idx]=-1;
				}
			}
			else{
				int idx=q[i].se.fi;
				ans.pb(v[idx]+(state[idx]!=-1)*(i+1-state[idx]));
			}
		}
	}
	else if(sub3()){
		FOR(i,0,N)if(s[i]=='1') update(i,0);
		FOR(i,0,Q){
			if(q[i].fi==0) update(q[i].se.fi,i+1);
			else{
				int l=q[i].se.fi,r=q[i].se.se;
				ll x=get(l,r-1);
				ans.pb(max(0ll,i+1-x));
			}
		}
	}
	else{
		str ss=s;
		FOR(i,0,N) if(s[i]=='1') add(i,1);

		pi a[N]; //{right of the interval, moment it opened}
		FOR(i,0,N) a[i]={-1,-1}; 

		int cnt=0;
		FOR(i,0,sz(ss)){
			if(s[i]=='1') cnt++;
			if(s[i]=='0' || i==N-1){
				if(cnt>0){
					int x=(i==N-1 && s[i]=='1');
					int l=i-cnt+x,r=i-1+x;
					a[l]={r,0};
				}
				cnt=0;
			}
		}

		//FOR(i,0,N) cout << a[i].fi << ' ' << a[i].se << endl;

		V<pair<pi,int>> vec; //closed intervals and their duration
		int i=0; 

		for(;i<Q;i++){
			if(q[i].fi==1) break;
			int idx=q[i].se.fi;

			int l=idx,r=idx;
			int ll=0,rr=idx-1;
			while(ll<=rr){
				int m=(ll+rr)/2;
				if(getSumRange(m,idx-1)==idx-m){
					l=m; rr=m-1;
				}
				else ll=m+1;
			}

			ll=idx+1,rr=N-1;
			while(ll<=rr){
				int m=(ll+rr)/2;
				if(getSumRange(idx+1,m)==m-idx){
					r=m; ll=m+1;
				}
				else rr=m-1;
			}

			//cout << l << ' ' << r << endl;

			if(ss[idx]=='1'){ //111 1 111 --> 111 0 111
				vec.pb({{l,r},i+1-a[l].se});
				a[l]={-1,-1};
				if(l!=idx){
					a[l]={idx-1,i+1};
				}
				if(r!=idx){
					a[idx+1]={r,i+1};
				}

				add(idx,-1);
				ss[idx]='0';
			}
			else{ //111 0 111 --> 1111111
				if(l!=idx){
					vec.pb({{l,idx-1},i+1-a[l].se});
					a[l]={-1,-1};
				}
				if(r!=idx){
					vec.pb({{idx+1,r},i+1-a[idx+1].se});
					a[idx+1]={-1,-1};
				}
				a[l]={r,i+1};

				add(idx,1);
				ss[idx]='1';
			}
		}
		//for(auto x: vec) cout << x.fi.fi << ' ' << x.fi.se << ' ' << x.se << endl;
		//FOR(i,0,N) cout << a[i].fi << ' ' << a[i].se << endl;

		V<pair<pi,pi>> v; //closed intervals + opened intervals 
		                  //+ queries

		for(auto x: vec){
			v.pb({x.fi,{x.se,0}});
		}
		FOR(i,0,N) if(a[i].fi!=-1){
			v.pb({{i,a[i].fi},{a[i].se,1}});
		}
		for(;i<Q; i++){
			v.pb({{q[i].se.fi,q[i].se.se},{i,2}});
		}

		sort(all(v),cmp);

		/*for(auto x: v){
			cout << x.fi.fi << ' ' << x.fi.se << ' '
			<< x.se.fi << ' ' << x.se.se << endl;
		}*/

		vpi res; //{idx,ans};
		for(auto x: v){
			if(x.se.se==2){
				int idx=x.se.fi;
				int l=x.fi.fi,r=x.fi.se-1;
				//still open
				int val=(idx+1)*(getNumber(r,N-1)) - getToRemove(r,N-1); 
				//closed
				val+=getClosed(r,N-1);
				res.pb({idx,val});
			}
			else if(x.se.se==0){
				int r=x.fi.se; int val=x.se.fi;
				updateClosed(r,val);
			}
			else{
				int r=x.fi.se; int idx=x.se.fi;
				updateNumber(r,1);
				updateToRemove(r,idx);
			}
		}

		sort(all(res));
		for(auto x: res) ans.pb(x.se);
		
	}

	for(auto x: ans) cout << x << endl;


	return 0;
}

//35

/* Careful!!!
	.Array bounds
	.Infinite loops
	.Uninitialized variables / empty containers
	.Order of input

   Some insights:
	.Binary search
	.Graph representation
	.Write brute force code
	.Change your approach
*/
