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

const int MX=3e5+15;

vi bit(MX,0),bit2(MX,0); // ri
vpi vec;

int lsb(int i){return i&-i;}
void update(int idx){
	while(idx<MX){
		bit[idx]++;
		idx+=lsb(idx);
	}
}
void update2(int idx, int x){
	while(idx<MX){
		bit2[idx]+=x;
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
int sum2(int idx){
	int ans=0;
	while(idx>0){
		ans+=bit2[idx];
		idx-=lsb(idx);
	}
	return ans;
}


int cnt[MX]={0};

int32_t main(){
   boost;
   IO();

   int N,Q; cin>>N>>Q;
   vpi vec;

   for(int i=0; i<N; i++){
   	int l,r; cin>>l>>r;
   	update(r);
   	update2(l,1);
   	update2(r+1,-1);
   	if(r!=l) cnt[r]++;
   }

   while(Q--){
   		int l,r; cin>>l>>r;
   		int ans=0;
   		ans+=sum(r);
   		ans-=sum(l-1);
   		ans-=sum2(l);
   		ans+=cnt[l];

   		cout << ans << endl;
   }

   return 0;
}

