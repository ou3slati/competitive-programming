#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
//#define int ll
typedef double db;
typedef long double ld;

typedef pair<int,int> pi;
#define mp make_pair
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int MOD = 1e9+7; //1000000007
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};
#define MAXN   100001

// stores smallest prime factor for every number
int spf[MAXN];


void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)

        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;

    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)

                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        if(spf[x]!=0) x = x / spf[x];
    }
    return ret;
}

int main(){
   boost;
   sieve();
   int a,b; cin>>a>>b;
   vi vec=getFactorization(a);
   vi vecc;
   for (int i=1; i<=b; i++) {
      vi veccc=getFactorization(i);
      for (int j=0; j<sz(veccc); j++) vecc.pb(veccc[j]);
   }
   //for (int j=0; j<sz(vecc); j++) cout << vecc[j] << ' ';
   //cout << endl;

   set <int> s;
   multiset <int>f;
   multiset <int>ff;

   for (int i=0; i<sz(vec); i++){
      s.insert(vec[i]);
      f.insert(vec[i]);
   }
   for (int i=0; i<sz(vecc); i++){
      ff.insert(vecc[i]);
   }
   int res=999999;
   for (auto x:s){
      //cout << x << endl;
      int c=f.count(x);
      int d=ff.count(x);
      //cout << c << ' ' << d << endl;
      int xx=0;
      if(c!=0) xx=d/c;
      res=min(res,xx);
   }
   cout << res << endl;
}

