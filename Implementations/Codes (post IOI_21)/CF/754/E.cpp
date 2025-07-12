//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
typedef string str;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
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
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////


int32_t main() {
    boost; IO();

    int N; cin>>N; 

    vi a(N+1),b(N+1); 
    FOR(i,1,N+1) cin>>a[i];
    FOR(i,1,N+1) cin>>b[i];

    vi alpha(N+1,0),c(N+1);
    FOR(i,1,N+1) c[i]=a[i];

    vi v1,v2;
    FOR(i,1,N+1){
    	//cout << alpha[i] << ' ' << c[i] << endl;
    	if(i==1){
    		for(int j=2; j<=N; j++) alpha[j]=1,c[j]-=c[i];

    		v1.pb(-c[i]);
    		v2.pb(1);
    	}
    	else{
    		for(int j=i*2; j<=N; j+=i) c[j]+=b[i]-c[i],alpha[j]-=alpha[i]; 
			v1.pb(b[i]-c[i]);
    		v2.pb(-alpha[i]);
    	}
    }

    /*for(int x: v1) cout << x << ' '; cout << endl;
	for(int x: v2) cout << x << ' '; cout << endl;
	return 0;*/

    FOR(i,0,N) if(v1[i]<0 && v2[i]<0) v1[i]*=-1,v2[i]*=-1;

    int ALPHA1=0,C1=0;
    FOR(i,0,N) if(v1[i]>=0 && v2[i]>=0) ALPHA1+=v2[i],C1+=v1[i];

    vector<pair<int,pi>>vec,vecc; 
    
    FOR(i,0,N){
    	if(v1[i]<=0){
    		vec.pb({-v1[i]/v2[i],{v2[i],v1[i]}});
   	 	}
   	 	else if(v2[i]<=0){
   	 		vecc.pb({-v1[i]/v2[i],{v2[i],v1[i]}});
   	 	}
	}
   	sort(all(vec)); sort(all(vecc));
   	 
   	vpi pref1,suf1;
    FOR(i,0,sz(vec)){
   		pref1.pb(vec[i].se);
   		suf1.pb(vec[i].se);
   	}
   	FOR(i,1,sz(vec)){
   		pref1[i].fi+=pref1[i-1].fi;
   		pref1[i].se+=pref1[i-1].se;
   	}
   	ROF(i,0,sz(vec)-1){
   		suf1[i].fi+=suf1[i+1].fi;
   		suf1[i].se+=suf1[i+1].se;
   	}

   	vpi pref2,suf2;
    FOR(i,0,sz(vecc)){
   		pref2.pb(vecc[i].se);
   		suf2.pb(vecc[i].se);
   	}
   	FOR(i,1,sz(vecc)){
   		pref2[i].fi+=pref2[i-1].fi;
   		pref2[i].se+=pref2[i-1].se;
   	}
   	ROF(i,0,sz(vecc)-1){
   		suf2[i].fi+=suf2[i+1].fi;
   		suf2[i].se+=suf2[i+1].se;
   	}


    int q; cin>>q;
    while(q--){
    	int x; cin>>x;
    	int ans=0;
    	ans+=ALPHA1*x+C1; 


    	int l=0,r=sz(vec)-1,idx=N;
    	while(l<=r){
    		int m=(l+r)/2;
    		if(x<=vec[m].fi){
    			idx=m; 
    			r=m-1;
    		}
    		else l=m+1;
    	}
    	
		int alp=0,cst=0;
		if(idx!=N){alp+=-suf1[idx].fi; cst+=-suf1[idx].se;} 
		if(idx-1>=0 && idx-1<sz(pref1)){
			alp+=pref1[idx-1].fi; cst+=pref1[idx-1].se;
		} 

		ans+=alp*x+cst;

    	

    	l=0,r=sz(vecc)-1,idx=-1;
    	while(l<=r){
    		int m=(l+r)/2;
    		if(x>=vecc[m].fi){
    			idx=m; 
    			l=m+1;
    		}
    		else r=m-1;
    	}
    	
		alp=0,cst=0;
		if(idx!=-1){alp+=-pref2[idx].fi; cst+=-pref2[idx].se;}
		if(idx+1>=0 && idx+1<sz(pref2)){
			alp+=suf2[idx+1].fi; cst+=suf2[idx+1].se;
		}

		ans+=alp*x+cst;

    	

    	cout << ans << endl;
    }
    

    return 0;
}
//Change your approach 