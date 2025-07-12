#include <bits/stdc++.h>
#include "xylophone.h"
using namespace std;

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

//-----------------------------------------------------------//


void IO(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}


	
int main(){
	IO();

	int N; cin>>N; 
	vi a(N); iota(all(a),1);
	random_shuffle(all(a));
	
	cout << N << endl;
	FOR(i,0,N) cout << a[i] << ' '; cout << endl;


}