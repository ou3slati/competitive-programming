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

/*void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}*/

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("empty.in", "r", stdin); 
    freopen("empty.out", "w", stdout); 
#endif 
}

const int MX=3e6+10;
int p[MX];
bool taken[MX];
int pref[MX];

int findSet(int u){
	return p[u]==u ? u: p[u]=findSet(p[u]);
}

void unionSet(int a, int b){
	a=findSet(a); b=findSet(b);
	p[a]=b;
}


int32_t main(){
   boost;
   IO();

   int N,K; cin>>N>>K;
   for(int i=0; i<N; i++) p[i]=i,pref[i]=0,taken[i]=false;

   
   while(K--){
   	int X,Y,A,B; cin>>X>>Y>>A>>B;
   	for(int i=1; i<=Y; i++) pref[(A*i+B)%N]+=X;
   }

	for(int i=0; i<N; i++){
		int x=pref[i];
		while(x--){
			int j=findSet(i);
			//cout << j << endl;
			taken[j]=true;
			unionSet(j,(j+1)%N);
		}
	}



	for(int i=0; i<N; i++) if(!taken[i]){ cout << i << endl; return 0; }
	

   return 0;
}

