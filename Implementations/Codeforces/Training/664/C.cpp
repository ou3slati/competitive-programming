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

   int N,M; cin>>N>>M;
   int a[N],b[M];
   for(int i=0; i<N; i++) cin>>a[i];
   for(int i=0; i<M; i++) cin>>b[i];

   for(int x=0; x<((1)<<(9)); x++){
   	bool pos=true;

   	for(int i=0; i<N; i++){ 
   		bool found=false;

   		for(int j=0; j<M; j++){
   			bool yh=true;
	   		int y=(a[i])&(b[j]);
	   		for(int bit=0; bit<10; bit++) if(((y)&((1)<<(bit)))>0 && ((x)&((1)<<(bit)))==0) yh=false;
	   		if(yh){found=true; break;}
   		}

   		if(!found){pos=false; break;}
   	}

   	if(pos){cout << x << endl; return 0;}
   }
	

   return 0;
}

