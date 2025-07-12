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

// new_a(N) = multiplier[0][0] * a + multiplier * b
// new_b = a + b



int32_t main(){
   boost;
   IO();

   int N; cin>>N; 
   if(N==0 || N==1){
   	cout << N << endl;
   	return 0;
   }
   N-=2;

   int ma[2][2]={{0,1},{1,1}};
   int res[2][2]={{0,1},{1,1}};

   while(N>0){
   	if(N%2==1){
   		int pro[2][2]={0};
   		for(int i=0; i<2; i++) for(int j=0; j<2; j++) for(int k=0; k<2; k++) pro[i][j]+=res[i][k]*ma[k][j],pro[i][j]%=MOD;
   		for(int i=0; i<2; i++) for(int j=0; j<2; j++)  res[i][j]=pro[i][j];
   		
   	}
   	int pro[2][2]={0};
   	for(int i=0; i<2; i++) for(int j=0; j<2; j++) for(int k=0; k<2; k++) pro[i][j]+=ma[i][k]*ma[k][j],pro[i][j]%=MOD;
		for(int i=0; i<2; i++) for(int j=0; j<2; j++) ma[i][j]=pro[i][j];	


   	N/=2;
   }

   cout << res[1][1] << endl;


	

   return 0;
}

