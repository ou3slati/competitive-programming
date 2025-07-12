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
    freopen("in.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

const int MX=1e5+10;
int N,T; 
int t[MX*2];

int32_t main(){
   boost;
   IO();
   cin>>N>>T;
   for(int i=0; i<N; i++) {
	 cin>>t[i];	
	 t[i+N]=t[i];
   }

   for(int i=1; i<2*N; i++) t[i]+=t[i-1];
   for(int i=2*N; i<2*MX; i++) t[i]=INF;

   //for(int i=0; i<N; i++) cout << t[i] <<' ';

   int res=0;
   for(int i=0; i<N; i++){
   	int r=T;
   	if(i) r+=t[i-1];
   	auto it=upper_bound(t,t+2*MX,r)-t;
   	it--;
   	res=max(res,min(N,it-i+1));
   }
   cout << res << endl;



   return 0;
}

