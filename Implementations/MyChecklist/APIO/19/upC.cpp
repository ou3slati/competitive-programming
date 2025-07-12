//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
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

vi bit(MX,0);
void update(int i, int v){
	for(;i<MX;i+=i&-i) bit[i]+=v;
}
int get(int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=bit[i];
	return ans;
}


int ans[MX]; //ans for the queries

int N,Q;
str s;


int R[MX],T[MX]; // R[i]: right endpoint of intervals beginning at i
				//T[i]: the time the interval starting at i began

int find_left(int i){
	int left=i;
	int l=0,r=i-1;
	while(l<=r){
		int m=(l+r)/2;
		if(get(i-1+1)-get(m-1+1)==(i-m)){
			left=m;
			r=m-1;
		}
		else l=m+1;
	}
	return left;
}

int find_right(int i){
	int right=i;
	int l=i+1,r=N-1;
	while(l<=r){
		int m=(l+r)/2;
		if(get(m+1)-get(i+1)==(m-i)){
			right=m;
			l=m+1;
		}
		else r=m-1;
	}
	return right;
}

struct interval{
	int l,r,tb,te,ty; //endpoints, end_time, type(query=1,interval=0)
};

V<interval> vec;

void toggle(int i, int moment){ //update bit + update intervals (time and right endpoint)
	int left=find_left(i),right=find_right(i);

	if(s[i]=='1'){ // 111 1 111 --> 111 0 111
		vec.pb({left,right,T[left],moment,0});

		R[left]=T[left]=-1;
		if(left!=i) R[left]=i-1,T[left]=moment;
		if(right!=i) R[i+1]=right,T[i+1]=moment;

		update(i+1,-1);
		s[i]='0';
	}
	else{ // 111 0 111 --> 111 1 111
		if(left!=i) vec.pb({left,i-1,T[left],moment,0});
		if(right!=i) vec.pb({i+1,right,T[i+1],moment,0});
		

		R[left]=right;
		T[left]=moment;
		if(right!=i) T[i+1]=R[i+1]=-1;

		update(i+1,1);
		s[i]='1';
	}
}

bool cmp(interval a, interval b){
	return (a.te < b.te);
}


//Segment tree of fenwick trees

vi all_lefts[MX]; //for queries whose endpoint is i

struct node{
	vi bit;
	unordered_map<int,int> mp;
	vi lefts;
};

V<node> t(4*MX);

void assign_sizes(int l=0, int r=N-1, int pos=1){
	(t[pos].bit).assign(r-l+5,0);
	vi lefts;
	FOR(i,l,r+1) for(int j: all_lefts[i]) lefts.pb(j);
	sort(all(lefts));
	int cnt=0;
	for(auto i: lefts) if(!t[pos].mp.count(i)) t[pos].mp[i]=++cnt;
	assert(cnt<sz(t[pos].bit));
	
	t[pos].lefts.assign(all(lefts));
	/*dbgs(l,r);
	dbgv(lefts);*/

	if(l==r) return;
	int m=(l+r)/2;
	assign_sizes(l,m,pos*2);
	assign_sizes(m+1,r,pos*2+1);
}

void add(int pos, int tl, int tr, int i, int v){
	/*dbgs(tl,tr);
	dbg(i);*/
	i=t[pos].mp[i]; //index in the bit
	//dbgs(i,sz(t[pos].bit))

	for(;i<sz(t[pos].bit); i+=i&-i) t[pos].bit[i]+=v;
}

void update_segtree(int l, int r, int v, int pos=1, int tl=0, int tr=N-1){
	//dive to the node representing [r,r]
	//add (r-l+1) to bit[l] for each node I encounter

	add(pos,tl,tr,l,v);

	if(tl==tr) return;
	int mid=(tl+tr)/2;
	if(r<=mid) update_segtree(l,r,v,pos*2,tl,mid);
	else update_segtree(l,r,v,pos*2+1,mid+1,tr);
}

int query(int l, int r, int v, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return 0;
	if(l==tl && r==tr){
		vi vec=t[pos].lefts;
		int it=upper_bound(all(vec),v)-vec.begin();
		if(it==0) return 0;
		it--; v=it+1; 

		int ans=0;
		for(;v; v-=v&-v) ans+=t[pos].bit[v];
		return ans;
	}
	int mid=(tl+tr)/2;
	return query(l, min(r,mid), v, pos*2, tl, mid)
		+ query(max(mid+1,l), r, v, pos*2+1, mid+1, tr);
}


int32_t main() {
    boost; IO();

    cin>>N>>Q>>s;

    int cnt=0;
    fill(R,R+N,-1);
    fill(T,T+N,-1);
    FOR(i,0,N){
    	if(s[i]=='0'){
    		if(cnt) R[i-cnt]=i-1;
    		cnt=0;
    	}
    	else cnt++;
    }
    if(cnt) R[N-cnt]=N-1;

    FOR(i,0,N) if(R[i]!=-1) T[i]=0;

    FOR(i,0,N) update(i+1,(s[i]=='1'));

    //FOR(i,0,N) cout << R[i] << ' '; cout << endl;

    //Part 1: build intervals + answer the online part
    fill(ans,ans+Q+1,0);
    FOR(moment,1,Q+1){
    	str t; cin>>t;
    	if(t=="toggle"){
    		int i; cin>>i; i--;
    		toggle(i,moment);
    	}
    	else{
    		int l,r; cin>>l>>r; l--; r-=2;
    		vec.pb({l,r,moment,moment,1});
    		if(get(r+1)-get(l)<(r-l+1)) continue;
    		int left=find_left(l);
    		ans[moment]+=moment-T[left]; 
    		
    	}
    }

    //FOR(i,0,N) cout << R[i] << ' '; cout << endl;
    //for(auto x: vec) cout << x.l << ' ' << x.r << ' ' << x.t << endl;
    
    sort(all(vec),cmp);
    //for(auto x: vec) cout << x.l << ' ' << x.r << ' ' << x.ty << endl;

    for(auto x: vec) if(x.ty==0) all_lefts[x.r].pb(x.l);

    assign_sizes();
    FOR(i,0,sz(vec)){
    	interval cur=vec[i];
    	int l=cur.l,r=cur.r;
    	if(cur.ty==0){
    		//in seg_tree[r], add r-l+1 to bit[l] 
    		update_segtree(l,r,cur.te-cur.tb);
    	}
    	else{
    		//intervals whose right endpoint is in [r,N-1] 
    		//and left endpoint in [0,l]
    		//cout << query(r,N-1,l) << endl;
    		ans[cur.tb]+=query(r,N-1,l); 
    	}
    }

    for(auto x: vec) if(x.ty==1){
    	cout << ans[x.tb] << endl;
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