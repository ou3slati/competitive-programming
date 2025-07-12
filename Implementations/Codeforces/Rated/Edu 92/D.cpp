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

int inter(int l, int r, int l2, int r2){
	if(!(l>=r2 || l2>=r)) return(min(r,r2)-max(l,l2));
	else return 0;
}

int32_t main(){
   boost;
   IO();

   int TC; cin>>TC;
   while(TC--){
   	int N,K; cin>>N>>K;
   	int l,r,l2,r2; cin>>l>>r>>l2>>r2;
   	if(l2<l){
   		swap(l,l2); swap(r,r2);
   	}

   	if(!(l>=r2 || l2>=r)) K-=(min(r,r2)-max(l,l2))*N;
   	if(K<=0){
   		cout << 0 << endl;
   		continue;
   	}

   	int res=0;


   	if(!(l>r2 || l2>r)){
   		res=min(K,(max(r2,r)-min(l,l2)-min(r,r2)+max(l,l2))*N);
   		K-=res;
   		if(K) res+=K*2;
   	}
   	else{
   		for(int i=0; i<N && K>0; i++){

	   		int gain=min(K,max(r2,r)-l-inter(l,r,l2,r2)*2); 


	   		int x=INF,y=INF;
	   		if(i) x=gain*2;
	   		y=gain; if(inter(l,r,l2,r2)==0) y+=l2-r;
	   		//cout << gain << ' ' << x << ' ' << y << endl;
	   		res+=min(x,y);
	   		K-=gain;
   	   }
   	   if(K) res+=K*2;
   	}


   	cout << res << endl;
   }
	

   return 0;
}

