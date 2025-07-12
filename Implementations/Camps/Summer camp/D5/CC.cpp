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

   int TC; cin>>TC;
   while(TC--){
	   int N,K,L; cin>>N>>K>>L;
	   int t[N],tt[N];

	   vpi a,b; 
	   int ca[N]={false},cb[N]={false};

	   for(int i=0; i<N; i++){
	   	int x; cin>>x;
	   	t[i]=x;
	   	a.pb({x,i});
	   }

	   for(int i=0; i<N; i++){
	   	int x; cin>>x;
	   	tt[i]=x;
	   	b.pb({x,i});
	   }

	   sort(rall(a)); sort(rall(b));

	   for(int i=0; i<K; i++){
	   		ca[a[i].se]=true;
	   		cb[b[i].se]=true;
	   }

	   int res=0;
	   vpi v;
	   int cnt=0;

	   for(int i=0; i<N; i++){
	   	if(ca[i] && cb[i] && cnt<L){
	   		res+=t[i]+tt[i];
	   		cnt++;
	    }
	    else{
	    	v.pb({t[i]+tt[i],i});
	    }
       }

       sort(rall(v));

       for(int i=0; i<L-cnt; i++){
       	res+=v[i].fi;
       	ca[v[i].se]=cb[v[i].se]=true;
       }

       vi m,n;
       for(int i=0; i<N; i++) if(!ca[i]) m.pb(t[i]);
       	for(int i=0; i<N; i++) if(!cb[i]) n.pb(tt[i]);

       sort(rall(m)); sort(rall(n));
   for(int i=0; i<K-L; i++) res+=m[i]+n[i];

   	cout << res << endl;




	   /*vector<pair<int,int>> vec;
	   for(int i=0; i<N; i++) cin>>t[i];
	   for(int i=0; i<N; i++){
	   	cin>>tt[i];
	   	vec.pb({tt[i]+t[i],i});   
		}

	   sort(rall(vec));
	   bool chosen[N]={false};

	   int res=0;
	   for(int i=0; i<L; i++){
		chosen[vec[i].se]=true;
		res+=vec[i].fi;
	  }

	  vi a,b;
	  for(int i=0; i<N; i++){
	  	if(!chosen[i]){
	  		a.pb(t[i]); b.pb(tt[i]);
	  	}

	  }

	  sort(rall(a)); sort(rall(b));

	  for(int i=0; i<K-L; i++) res+=a[i],res+=b[i];

	  	cout << res << endl;*/

	}

   return 0;
}

