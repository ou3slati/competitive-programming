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

const int MX=1e5+10;
int N,M,A,B,C;
int x[MX],y[MX],p[MX],q[MX];

int convert(int t){t=abs(t); return A*t*t+B*t+C;}

int32_t main(){
   boost;
   IO();

   cin>>N>>M>>A>>B>>C;
   map<pi,vector<pair<pi,int>>> adj;

   vi obtainable[N+1];
   for(int i=0; i<M; i++){
		cin>>x[i]>>y[i]>>p[i]>>q[i];
		obtainable[y[i]].pb(q[i]);
		adj[{x[i],p[i]}].pb({{y[i],q[i]},q[i]-p[i]});
		if(x[i]==1) adj[{1,0}].pb({{1,p[i]},p[i]+convert(p[i])});
   }

   for(int i=0; i<M; i++){
   	int s=x[i],mom=p[i];
   	for(auto x: obtainable[s]) if(x<=mom) adj[{s,x}].pb({{s,mom},mom-x+convert(mom-x)});
   }

   
   priority_queue<pair<int,pi>,vector<pair<int,pi>>, greater<pair<int,pi>>> q;
   q.push({0,{1,0}});
   unordered_map<int,int> dist[1001];

   dist[0][1]=0;

   int ans=INF;
   while(!q.empty()){
   	int u=q.top().se.fi,time=q.top().se.se,d=q.top().fi;
   	q.pop();
   	if(u==N) ans=min(ans,d);
   	if(d>dist[time][u]) continue;
   	for(auto v: adj[{u,time}]) if(!dist[v.fi.se].count(v.fi.fi) || dist[v.fi.se][v.fi.fi]> dist[time][u]+v.se){
   		dist[v.fi.se][v.fi.fi]= dist[time][u]+v.se;
   		q.push({dist[v.fi.se][v.fi.fi],{v.fi.fi,v.fi.se}});
   	}
   }

   cout << ans << endl;
	

   return 0;
}

