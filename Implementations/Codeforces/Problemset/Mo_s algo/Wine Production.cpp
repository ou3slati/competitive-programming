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
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

int S;
bool mo(pair<pi,int> a,pair<pi,int>b){
	if(a.fi.fi/S!=b.fi.fi/S) return a.fi.fi/S<b.fi.fi/S;
	return a.fi.fi/S&1 ? a.fi.se<b.fi.se : a.fi.se>b.fi.se;
}

const int MX=3e4+10;
int N,Q;
int a[MX];

int cnt[MX];
vi bit(MX,0);  

int lsb(int idx){return idx&-idx;}
void update(int idx, int v){
	if(idx==0) return;
	while(idx<MX){
		bit[idx]+=v;
		idx+=lsb(idx);
	}
}
int getSum(int idx){
	int ans=0;
	while(idx>0){
		ans+=bit[idx];
		idx-=lsb(idx);
	}
	return ans;
}

int ans=0;

void add(int x){
	update(cnt[x],-1);
	cnt[x]++;
	update(cnt[x],1);
	if(getSum(N)-getSum(ans)>=ans+1) ans++;
}
void remove(int x){
	update(cnt[x],-1);
	cnt[x]--;
	update(cnt[x],1);
	if(getSum(N)-getSum(ans-1)<ans) ans--;
}

int main(){
   boost;
   IO();

   cin>>N>>Q;
   S=ceil(sqrt(N));
   memset(cnt,0,sizeof(cnt));
   for(int i=0; i<N; i++) cin>>a[i];

   vpi vec;
	for(int i=0; i<N; i++) vec.pb({a[i],i});

	sort(all(vec));
	int cntr=1;
	for(int i=0; i<N;){
		int x=vec[i].fi;
		while(i<N && vec[i].fi==x) vec[i].fi=cntr,i++;
		cntr++;
	}
	for(auto x: vec) a[x.se]=x.fi;

   vector <pair<pi,int>> q;
   for(int i=0; i<Q; i++){
   	int l,r; cin>>l>>r; l--; r--;
   	q.pb({{l,r},i});
   }

   sort(all(q),mo);

   int res[Q];
   int cl=0,cr=-1;
   for(auto x: q){
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

   	/*int ans=0;
   	int lb=1,rb=S;
   	while(lb<=rb){
   		int mb=(lb+rb)/2;
   		if(getSum(S)-getSum(mb-1)>=mb){
   			ans=max(ans,mb);
   			lb=mb+1;
   		}
   		else rb=mb-1;
   	}*/
   	
   	res[idx]=ans;
   }

   for(int i=0; i<Q; i++) cout << res[i] << endl;
	

   return 0;
}

