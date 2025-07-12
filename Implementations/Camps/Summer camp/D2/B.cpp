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
int hashh[MX];
int N,K,Q;
vi bit(MX,0);

int lsb(int idx){return idx&-idx;}
void update(int idx, int v){
	while(idx<MX){
		bit[idx]+=v;
		idx+=lsb(idx);
	}
}
int sum(int idx){
	int ans=0;
	while(idx>0){
		ans+=bit[idx];
		idx-=lsb(idx);
	}
	return ans;
}

int32_t main(){
   boost;
   IO();
   cin>>N>>K>>Q;
   for(int i=0; i<N; i++){
   	int l,r; cin>>l>>r;
   	update(l,1);
   	update(r+1,-1);
   }

   for(int i=0; i<MX; i++) hashh[i]=0;
   for(int i=1; i<=(int)(2e5); i++) if(sum(i)>=K) hashh[i]=1;
   for(int i=1; i<=(int)(2e5); i++) hashh[i]+=hashh[i-1];

   while(Q--){
   	int l,r; cin>>l>>r;
   	cout << hashh[r]-hashh[l-1] << endl;
   }


   return 0;
}

