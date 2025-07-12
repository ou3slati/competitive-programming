//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef string str;
typedef long double ld;
typedef pair<int, int> pi;
#define x first
#define lazy second
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
const int MX = 3e5 + 10;
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

const int mxx=2e5+30; 

int N,Q; 
vi a(MX), vec(MX,0); 


vpi t(mxx*4+20); 


void push_down(int pos, int tl, int tm, int tr){
	int &x=t[pos].lazy;
	if(x==-1) return; 

	t[pos*2].x=x*(tm-tl+1); 
	t[pos*2+1].x=x*(tr-tm); 
 
	t[pos*2].lazy=x; 
	t[pos*2+1].lazy=x; 
 
	t[pos].lazy=-1; 
}
 
void upd(int l, int r, int x, int tl=1, int tr=mxx, int pos=1){
	if(l>r) return; 
	if(l==tl && r==tr){
		t[pos].x = x*(r-l+1); 
		t[pos].lazy = x; 
		return; 
	} 
 
	int tm=(tl+tr)/2; 
 
	push_down(pos,tl,tm,tr);
 
	upd(l,min(r,tm),x,tl,tm,pos*2); 
	upd(max(l,tm+1),r,x,tm+1,tr,pos*2+1);
 
	t[pos].x = t[pos*2].x + t[pos*2+1].x; 
 
}
int get(int l, int r, int tl=1, int tr=mxx, int pos=1){
	if(l>r) return 0; 
 
	if(l==tl && r==tr) return t[pos].x; 
 
	int tm=(tl+tr)/2; 
 
	push_down(pos,tl,tm,tr);
 
	return get(l,min(r,tm),tl,tm,pos*2) + get(max(l,tm+1),r,tm+1,tr,pos*2+1); 
}

int main() {
    boost; IO();

    cin>>N>>Q; 

    FOR(i,1,N+1){
    	int x; cin>>x; 
    	a[i]=x; 
    	vec[x]++; 
    } 

    int ans=0;
    FOR(i,1,mxx+1){
    	int x=vec[i]/2; 
    	vec[i+1]+=x; 
    	vec[i]&=1; 

    	if(vec[i]) ans=i; 
    }

    FOR(i,1,mxx+1) upd(i,i,vec[i]); 

    while(Q--){
    	int k,x; cin>>k>>x;

    	int i=a[k];  

		int l=i, r=mxx, idx;
		while(l<=r){
			int m=(l+r)/2; 
			if(get(i,m)){
				idx=m; 
				r=m-1; 
			}
			else l=m+1; 
		}
		upd(i,idx-1,1);
		upd(idx,idx,0); 



		a[k]=x; 
		i=a[k];

		l=i, r=mxx, idx=i-1;
		while(l<=r){
			int m=(l+r)/2; 
			if(get(i,m)==(m-i+1)){
				idx=m; 
				l=m+1;
			}
			else r=m-1; 
		}
		upd(i,idx,0); 
		upd(idx+1,idx+1,1); 

		l=1, r=mxx, idx;
		while(l<=r){
			int m=(l+r)/2; 
			if(get(m,mxx)){
				idx=m; 
				l=m+1;
			}
			else r=m-1; 
		}
		cout << idx << endl;
    }



    

    return 0;
}
//Change your approach 