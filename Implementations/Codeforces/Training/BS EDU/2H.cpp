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
const ll INF = 1e14;
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

   str s; cin>>s;
   int a=0,b=0,c=0;
   for(auto x: s){
   	if(x=='B') a++;
   	else if(x=='S') b++;
   	else c++;
   }

   int nb,ns,nc; cin>>nb>>ns>>nc;
   int pb,ps,pc; cin>>pb>>ps>>pc;
   int R; cin>>R;

   int ans=-1;
   int l=0,r=INF;
   while(l<=r){
   	int m=(l+r)/2;
   	int val=max((ll)0,(m*a-nb))*pb + max((ll)0,(m*b-ns))*ps + max((ll)0,(m*c-nc))*pc;

   	if(val<=R){
   		ans=m;
   		l=m+1;
   	}
   	else r=m-1;
   }

   cout << ans << endl;

	

   return 0;
}

