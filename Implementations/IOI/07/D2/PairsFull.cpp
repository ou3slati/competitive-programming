//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef string str;
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
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e9;
const int MX = 2e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
//constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

ll random(ll a, ll b){
    return a + rng() % (b - a + 1);
}

#ifndef LOCAL  
#define cerr if(false) cerr
#endif
#define dbg(x) cerr << #x << " : " << x << endl; 
#define dbgs(x,y) cerr << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << #v << " : " << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;
#define here() cerr << "here" << endl;

void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int B,N,D,M; 

vi bit;
void upd(int i, int v){
	for(;i<MX;i+=i&-i) bit[i]+=v;
}
int sum(int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=bit[i];
	return ans;
}
int get(int l, int r){return sum(r)-sum(l-1); }
	

vi v={-INF,INF},v2={-INF,INF},v3={-INF,INF};
V<V<vi>> ft;
void update(int ii, int jj, int kk, int val){
	for(int i=ii; i<sz(v)+10; i+=i&-i) 
		for(int j=jj ;j<sz(v2)+10; j+=j&-j) 
			for(int k=kk ;k<sz(v3)+10; k+=k&-k){
				ft[i][j][k]+=val;
			}
}
int sum2(int ii, int jj, int kk){	
	int ans=0;
	for(int i=ii;i;i-=i&-i)
		for(int j=jj;j;j-=j&-j)
			for(int k=kk;k;k-=k&-k){
				ans+=ft[i][j][k];
			}
	return ans;
}
int get2(int x, int xx, int y, int yy, int z, int zz){
	int ans=0;
	ans+=sum2(xx,yy,zz);
	ans-=sum2(x-1,yy,zz);
	ans-=sum2(xx,y-1,zz);
	ans+=sum2(x-1,y-1,zz);

	ans-=sum2(xx,yy,z-1);
	ans+=sum2(x-1,yy,z-1);
	ans+=sum2(xx,y-1,z-1);
	ans-=sum2(x-1,y-1,z-1);
	return ans;
}

int main() {
    boost; IO();

    cin>>B>>N>>D>>M;
    if(B==1){
    	vi x(N);
    	FOR(i,0,N){
    		cin>>x[i];
    	}
    	sort(all(x));
    	int j=0;
    	ll ans=0;
    	FOR(i,0,N){
    		while(x[i]-x[j]>D) j++;
    		ans+=i-j;
    	}
    	cout << ans << endl;
    }
    else if(B==2){
        bit.assign(MX,0);
    	vpi vec;
    	FOR(i,0,N){
    		int x,y; cin>>x>>y;
    		vec.pb({x-y,x+y});
    	}
    	sort(all(vec));
    		
    	int j=0;
    	ll ans=0;
    	FOR(i,0,N){
    		while(vec[i].fi-vec[j].fi>D){
    			upd(vec[j].se,-1);
    			j++;
			}
			ans+=get(max(vec[i].se-D,1),vec[i].se+D);
    		upd(vec[i].se,1);
    	}
    	cout << ans << endl;
    }
    else{
    	V<pair<pi,pi>> vec;
        
    	FOR(i,0,N){
    		int x,y,z; cin>>x>>y>>z;
    		vec.pb({{x+y+z,x+y-z},{x-y+z,x-y-z}});
    		v.pb(x+y-z);
    		v2.pb(x-y+z); 
    		v3.pb(x-y-z); 
    	} 
        sort(all(vec));
    	sort(all(v)); sort(all(v2)); sort(all(v3));
        v.erase(unique(all(v)),v.end());
        v2.erase(unique(all(v2)),v2.end());
        v3.erase(unique(all(v3)),v3.end());

        ft.resize(sz(v)+10);
        FOR(i,0,sz(v)+10){ 
            ft[i].resize(sz(v2)+10);
            FOR(j,0,sz(v2)+10) ft[i][j].assign(sz(v3)+10,0);
        }
    	
    	int j=0;
    	ll ans=0;
    	FOR(i,0,N){
    		pair<pi,pi> &x=vec[i];
    		int a=x.fi.se,b=x.se.fi,c=x.se.se;

            int amd=lower_bound(all(v),a-D)-v.begin(); amd++; 
            int bmd=lower_bound(all(v2),b-D)-v2.begin(); bmd++;
            int cmd=lower_bound(all(v3),c-D)-v3.begin(); cmd++;
            int apd=upper_bound(all(v),a+D)-v.begin(); 
            int bpd=upper_bound(all(v2),b+D)-v2.begin(); 
            int cpd=upper_bound(all(v3),c+D)-v3.begin();
            a=lower_bound(all(v),a)-v.begin(); a++;
            b=lower_bound(all(v2),b)-v2.begin(); b++;
            c=lower_bound(all(v3),c)-v3.begin(); c++;
    	
    		while(x.fi.fi-vec[j].fi.fi>D){
    			update(vec[j].fi.se,vec[j].se.fi,vec[j].se.se,-1);
				j++;
	    	}
    		ans+=get2(amd,apd, bmd,bpd, cmd,cpd);
            
    		update(a,b,c,1);
            x.fi.se=a; x.se.fi=b; x.se.se=c;
    	}
    	cout << ans << endl;
    }

    return 0;
}

/* Careful!!!
    .Array bounds
    .Infinite loops
    .Uninitialized variables / empty containers
    .Multisets are shit

   Some insights:
    .Binary search
    .Graph representation
    .Write brute force code
    .Change your approach
*/