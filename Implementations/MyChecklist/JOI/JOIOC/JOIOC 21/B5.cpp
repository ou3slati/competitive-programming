#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi; 
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}
//---------------------------------------------------//

const int MX=3e5;
void ckmax(int &x, int y){x=max(x,y);}

int N,D; 
vi a(MX);

int main() {
    IO();
    
    cin>>N>>D;
    FOR(i,0,N) cin>>a[i];

    if(D!=N) return 0;

    vi vec;
    FOR(i,0,N){
    	int it=lower_bound(all(vec),a[i])-vec.begin();
    	if(it==sz(vec)) vec.pb(a[i]);
    	else vec[it]=a[i];
    }
    cout << sz(vec) << endl;
    

    return 0;
}
//Change your approach 