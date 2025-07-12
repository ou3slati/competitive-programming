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
  
   set<pi> s;
   for(int i=0; i<N-1; i++){
   	int x,y; cin>>x>>y;
   	s.insert({x,y});
   }

   bool vis[N+1]={false};
   for(auto x: s){
   	vis[x.fi]=true;
   }


   vector<pair<int,pi>> vec;
   for(int i=2; i<=N; i++){
   	if(!vis[i]){
   		//cout << "heeeeeeeere" << endl;
   		vec.pb({1,{1,i}});
   		pi p,pp;
   		for(auto x: s) if(x.fi==1){p=x; pp=x; pp.fi=i;}
   		s.erase(p); s.insert(pp);
   		break;
   	}
   }

   //for(auto x:vec) cout << x.fi << ' ' << x.se.fi << ' ' << x.se.se << endl;
   //for(auto x: s) cout << x.fi << ' ' << x.se << endl;


   int t[N+1],tt[N+1];
   memset(t,-1,sizeof(t)); memset(tt,-1,sizeof(tt));
   for(auto x: s){
   	t[x.fi]=x.se;
   	tt[x.se]=x.fi;
   }

   for(int i=2; i<=N; i++){
   	if(t[i]==i-1) continue;
   	vec.pb({2,{i-1,t[i]}});

   	int tti=tt[i];
   	int ti=t[i];
   	int ttim1=tt[i-1];
 	
 	t[i]=i-1;
 	tt[i]=i;

 	t[ttim1]=ti;
   	tt[ti]=tti;	
               
   }

   cout << sz(vec) << endl;
   for(auto x: vec) cout << x.fi << ' ' << x.se.fi << ' ' << x.se.se << endl;
	

   return 0;
}

/*
2
1 2

*/