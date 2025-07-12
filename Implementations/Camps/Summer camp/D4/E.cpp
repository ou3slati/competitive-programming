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

int pow(int u){
	return (int)(pow(2,u)+0.5);

}

int32_t main(){
   boost;
   IO();
   int N;cin>>N;
   multiset <int> s;
   s.insert(0);

   for(int i=0; i<N; i++){
   	char c; cin>>c;
   	int x; cin>>x;
   	if(c=='+') s.insert(x);
   	else if(c=='-') s.erase(s.find(x));
   	else{
   		int res[31];
   		int sm=0;
   		bool found=false;
   		for(int i=30; i>=0; i--){
   			int bit=((x)&((1)<<(i)));

   			if(bit>0) bit=1;
   			
   			else bit=0;

   			int needed=1-bit;
   			int used=bit;
   			//cout << bit  << ' ' << needed << endl;
   			int l=sm+needed*pow(i),r=l+pow(i)-1;
   			auto it=s.lower_bound(l);
   			if(it==s.end() || *it>r) res[i]=0;
   			else {
   				found=true;
   				res[i]=1;
   				used=needed;
   			}
   			if(found) sm+=used*pow(i);

   		}
   		//for(int i=0; i<N; i++) cout << res[i] << ' '; cout << endl;
   		int ans=0;
   		for(int i=0; i<=30; i++) ans+=res[i]*pow(i);
   		cout << ans << endl;

   		/*ans=0;
   		for(auto yy: s){
   			ans=max(ans,(x)^(yy));
   		}
   		cout << ans << endl
   		; cout << endl;*/

   	}
   }
	

   return 0;
}

/*
14
+ 9999
+ 9999
? 500
- 9999
+ 656
? 55
?555
? 603
+999999999
?6666666
?555555555
+ 0
? 550
? 0

*/