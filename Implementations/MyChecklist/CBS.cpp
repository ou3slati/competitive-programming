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
    freopen("cbs.in", "r", stdin); 
    freopen("cbs.out", "w", stdout); 
#endif 
}
// assign the nxt, assign numbers to the paths, count colums with closing parth.

int32_t main(){
   boost;
   IO();

   int K,N; cin>>K>>N;
   str s[K];
   for(int i=0; i<K; i++) cin>>s[i];

   int nxt[K][N];
	for(int i=0; i<K; i++) for(int j=0; j<N; j++) nxt[i][j]=-1;
	
	for(int i=0; i<K; i++){
		str cur=s[i];
		vi vec;
		for(int j=0; j<N; j++) {
			if(cur[j]=='(') vec.pb(j);
			else if(!vec.empty()){nxt[i][vec.back()]=j; vec.pop_back();}
			if(cur[j]==')' && j<N-1 && cur[j+1]=='(') nxt[i][j]=j+1;
		}
	}

	//for(int i=0; i<K; i++){for(int j=0; j<N; j++) cout << nxt[i][j] << ' '; cout << endl;}

	int num[K][N];
	for(int i=0; i<K; i++) for(int j=0; j<N; j++) num[i][j]=-1;

	for(int i=0; i<K; i++){
		int cnt=0;
		for(int j=0; j<N; j++) if(num[i][j]==-1 && s[i][j]=='(') {
			int idx=j;
			while(idx!=-1){
				num[i][idx]=cnt;
				idx=nxt[i][idx];
			}
			cnt++;
		}
	}

	//for(int i=0; i<K; i++){for(int j=0; j<N; j++) cout << num[i][j] << ' '; cout << endl;}

	map<vi,vi> mp;
	
	for(int i=0; i<N;i++){
		bool y=true;
		vi v(K);
		for(int j=0; j<K; j++){if(s[j][i]=='(') y=false; v[j]=num[j][i];}
		//for(auto x: v) cout << x << ' '; cout << endl;
		if(y){
			mp[v].pb(i);
			/*for(auto x: v) cout << x << ' '; cout << endl;
			for(auto x: mp[v]) cout << x << ' '; cout << endl;
			cout << endl;*/
		}
	}

	/*for(auto x: mp){
		vi v=x.fi,vv=x.se;
		for(auto y: v) cout << y <<  ' '; cout << endl;
		for(auto y: vv) cout << y <<  ' '; cout << endl;
		cout << endl;
	}*/

	int res=0;
	for(int i=0; i<N; i++){
		bool y=true;
		vi v(K);
		for(int j=0; j<K; j++){if(s[j][i]==')') y=false; else v[j]=num[j][i];}
		if(y){
			if(!mp.count(v)) continue;
			vi v2=mp[v];
			//for(auto x:v2) cout << x << ' '; cout << endl;
			auto it=lower_bound(all(v2),i)-v2.begin();
			res+=sz(v2)-it;
		}
		//cout << res << endl;
	}
	cout << res << endl;
   
	

   return 0;
}

