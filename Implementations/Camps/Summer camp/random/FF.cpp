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

const int MX=1e6+10;
vi prime;
vi spf(MX,-1);

void sieve(){
	for(int i=2; i<MX; i++)if(spf[i]==-1){
		prime.pb(i);
		for(int j=i; j<MX; j+=i) spf[j]=i;
	}

}

int32_t main(){
   boost;
   IO();
   sieve();
   int X2; cin>>X2;

   int res=INF;
   for(auto p: prime) if(X2%p==0){ // around 20 loops
   		int alpha=X2/p; //fixed prime and alpha
   		for(int X1=p*alpha-p+1; X1<=p*alpha; X1++){ // max=max(prime)<1e6
   			vi f;
   			int XX=X1;
   			while(XX>1){
   				f.pb(spf[XX]);
   				int x=spf[XX];
   				while(XX%x==0) XX/=x;
   			}
   			for(auto pp: f) if(X1%pp==0){
   				int beta=X1/pp;
   				if(pp*(beta-1)+1>=3)
   					res=min(res,pp*(beta-1)+1);
   			}
   		}

   }

   cout << res << endl;


	

   return 0;
}

