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
   int N; cin>>N;
   int coef[5]; coef[0]=1; coef[1]=5; coef[2]=10; coef[3]=20; coef[4]=50;
   int cnt[5]={0};
   for(int i=0; i<N; i++){
	   	int K; cin>>K;
	   	int s=0;
	   	for(int i=0; i<5; i++){
	   		int x; cin>>x;
	   		cnt[i]+=x;
	   		if(i==0) s+=1*x;
	   		else if(i==1) s+=5*x;
	   		else if(i==2) s+=10*x;
	   		else if(i==3) s+=20*x;
	   		else if(i==4) s+=50*x;
	   	}
	   	int r=s-K;
	   	/*cout << r << endl;
	   	for(int i=0; i<5; i++) cout << cnt[i] << ' '; cout << endl;*/
	   	for(int i=4; i>=0 && r; i--){
	   		while(cnt[i]>0 && r-coef[i]>=0){r-=coef[i]; cnt[i]--;}
	   	}
	   	if(r>0){cout << "no"<< endl; return 0;}
   }

   cout << "yes" << endl;
	

   return 0;
}

