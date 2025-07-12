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

int matrix[2][2]={{19,7},{6,20}};
int res[2][2]={{1,0},{0,1}};
int product[2][2];

void mul(int t){
	for(int i=0; i<2; i++) for(int j=0; j<2; j++) product[i][j]=0;
	for(int i=0; i<2; i++) for(int j=0; j<2; j++) for(int k=0; k<2; k++){
		if(t) product[i][j]+=matrix[i][k]*matrix[k][j];
		else product[i][j]+=res[i][k]*matrix[k][j];
		product[i][j]%=MOD;
	}
		
}


int32_t main(){
   boost;
   IO();

   int N; cin>>N;

   while(N>0){
   	if(N%2==1){
   		mul(0);
   		for(int i=0; i<2; i++) for(int j=0; j<2; j++) res[i][j]=product[i][j];
   	}
   	mul(1);
   	for(int i=0; i<2; i++) for(int j=0; j<2; j++) matrix[i][j]=product[i][j];
   	N/=2;
   }

   cout << res[0][0] << endl;
	

   return 0;
}

