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

const int MX=2e5+10;

int N,M,Q;
int p[MX],a[MX];

int before[MX],track[MX],pa[MX],jump[MX][18];


int32_t main(){
   boost;
   IO();


   cin>>N>>M>>Q;
   
   for(int i=0; i<N; i++) cin>>p[i];

   for(int i=1; i<N; i++) before[p[i]]=p[i-1];
   before[p[0]]=p[N-1];

   for(int j=0; j<M; j++) cin>>a[j];

	for(int i=1; i<=N; i++) track[i]=-1;
	for(int i=0; i<M; i++) pa[i]=-1;
   for(int i=0; i<M; i++){
   	if(track[before[a[i]]]!=-1) pa[i]=track[before[a[i]]];
   	track[a[i]]=i;
   }

   //for(int i=0; i<M; i++) cout << pa[i] << ' '; cout << endl;

   //for(int i=0; i<=17; i++) jump[0][i]=0;
   for(int i=1; i<=M; i++){
   	jump[i][0]=pa[i-1]+1;
   	for(int j=1; j<=17; j++) jump[i][j]=jump[jump[i][j-1]][j-1];
   }

	//for(int i=1; i<=M; i++) cout << jump[i][0] << endl;

	int left[M+1]; for(int i=0; i<=M; i++) left[i]=-1;
	for(int i=1; i<=M; i++){
		int ii=i;
		int x=N-1;
		for(int j=0; j<=17; j++) if((x)&((1)<<(j))) ii=jump[ii][j];
		left[i]=ii;
	}

	int leftmost[M+1];
	leftmost[1]=left[1];
	for(int i=2; i<=M; i++){
		leftmost[i]=max(left[i],leftmost[i-1]);
	}

	while(Q--){
		int l,r; cin>>l>>r; 
		if(leftmost[r]<l) cout <<0;
		else cout<<1;
	}


	

   return 0;
}

