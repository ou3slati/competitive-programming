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

vector< pair<int, int> > findSubArrays(int arr[], int n)
{
    unordered_map<int, vector<int> > map;
    vector <pair<int, int>> out;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
            out.push_back(make_pair(0, i));
        if (map.find(sum) != map.end())
        {
            vector<int> vc = map[sum];
            for (auto it = vc.begin(); it != vc.end(); it++)
                out.push_back(make_pair(*it + 1, i));
        }

        map[sum].push_back(i);
    }
    return out;
}

void print(vector<pair<int, int>> out)
{
    for (auto it = out.begin(); it != out.end(); it++)
        cout << "Subarray found from Index " <<
            it->first << " to " << it->second << endl;
}

int32_t main(){
   boost;
   int N; cin>>N;
   int t[N];
   for (int i=0; i<N; i++) cin>>t[i];

   vector<pair<int, int> > vec = findSubArrays(t, N);
   sort(all(vec));

   //print(vec);

   vi v;
   if(vec[0].se!=0) v.pb(vec[0].se);
   for (int i=0; i<sz(vec)-1; i++){
      if(vec[i].se<=vec[i+1].se-1){
         v.pb(vec[i+1].se-vec[i].se);
         v.pb(-1*(vec[i+1].se-(vec[i].fi+1)));
      }
   }

   int l=sz(vec);
   //if(vec[l-1].se!=N-1) v.pb(N-1-vec[l-1].fi);
   v.pb(N-vec[l-1].fi-1);
   v.pb(-1*(vec[l-1].se-vec[l-1].fi-1));
   for (int i=0; i<sz(v); i++) cout << v[i] << ' ';
   int res=0;
   for (int i=0; i<sz(v); i++){
      if(v[i]>0) res+=((v[i]+1)*v[i])/2;
      else{
         v[i]=-v[i];
         res-=((v[i]+1)*v[i])/2;
      }
   }

   cout << res << endl;




}

