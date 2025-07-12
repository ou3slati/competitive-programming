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



int32_t main(){
   boost;
   IO();

   int N; cin>>N; 
   int t[N],tt[N];
   unordered_map<int,int> mp;

   for(int i=0; i<N; i++){
   	cin>>t[i];
   }

   for(int i=0; i<N; i++){
   	cin>>tt[i];
   	mp[tt[i]]=i;
   }

   int ans=INF;
   vector<pair<char,int>> vres;

   for(int idx=0; idx<N; idx++){

   	
   	vpi f,b; int nb[N]={0};
   	for(int j=0; j<N; j++) if(idx!=j){
   		if(mp[t[idx]]>mp[t[j]]) f.pb({mp[t[j]],t[j]});
   		else{b.pb({mp[t[j]],t[j]}); if(j<idx) nb[j]++;}
   	}
   	sort(rall(f)); sort(all(b));

   	for(int j=1;j<N; j++) nb[j]=nb[j]+=nb[j-1];

   	/*for(auto x: f) cout << x.se << ' '; cout<< endl;
   	for(auto x: b) cout << x.se << ' '; cout<< endl;*/


   	vi v;
   	for(int i=0; i<N; i++) v.pb(t[i]);

   	vector<pair<char,int>> vcnt;
   	int cnt=0;

   	for(int i=0; i<sz(f); i++){
   		for(int j=0; j<N; j++) if(j-nb[j]!=mp[v[j]]  && v[j]==f[i].se){
   			vcnt.pb({'F',j+1});
   			cnt++;
   			v.erase(v.begin()+j);
   			v.insert(v.begin(),f[i].se);
   			break;
   		}
   	}


   	for(int i=0; i<sz(b); i++){
   		for(int j=0; j<N; j++) if(j-sz(b)+1+i!=mp[v[j]] && v[j]==b[i].se){
   			vcnt.pb({'B',j+1});
   			cnt++;
   			v.erase(v.begin()+j);
   			v.pb((b[i].se));
   			break;
   		}
   	}

   	//for(auto x: b) cout << x.se << ' '; cout << endl;

   	for(auto x: vcnt) cout << x.fi << ' ' << x.se << endl;
   		cout << endl;
   	//cout <<sz(f) << ' '<< sz(b) << ' ' << cnt << endl;
   	if(ans>cnt){
   		ans=sz(vcnt);
   		vres.assign(all(vcnt));
   	}
	}

	cout << ans << endl;
	for(auto x: vres) cout << x.fi << ' ' << x.se << endl;
  
   



	

   return 0;
}

