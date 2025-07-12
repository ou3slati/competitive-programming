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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};


const int MXN=500009;
int N;
int a[MXN],p[MXN];

int QueryL[MXN]={0},QueryR[MXN]={0},QueryK[MXN]={0};

struct node {
    int pos;
    int l;
    int r;
    int val;
};

bool comp(node a, node b)
{
    if (a.val == b.val)
        return a.l > b.l;

    return a.val > b.val;
}


void update(int* BIT, int n, int idx)
{
    while (idx <= n) {
        BIT[idx]++;
        idx += idx & (-idx);
    }
}

int query(int* BIT, int idx)
{
    int ans = 0;
    while (idx) {
        ans += BIT[idx];

        idx -= idx & (-idx);
    }
    return ans;
}


int solveQuery1(int arr[], int n,int q)
{
    node a[n + q + 1000];

    for (int i = 1; i <= n; ++i) {
        a[i].val = arr[i - 1];
        a[i].pos = 0;
        a[i].l = 0;
        a[i].r = i;
    }

    for (int i = n + 1; i <= n + q; ++i) {
        a[i].pos = i - n;
        a[i].val = QueryK[i-n-1];
        a[i].l = QueryL[i-n-1];
        a[i].r = QueryR[i-n-1];
    }
    sort(a+1, a + n + q+1, comp);

    int BIT[n + 1000];

    memset(BIT, 0, sizeof(BIT));

    int ans[q + 1000];

    for (int i = 1; i <= n + q; ++i) {
        if (a[i].pos != 0) {
            int cnt = query(BIT, a[i].r) - query(BIT, a[i].l - 1);
            ans[a[i].pos] = cnt;
        }
        else {
            update(BIT, n, a[i].r);
        }
    }
    ans[0]=0;
    for (int i = 1; i <= q; ++i) {
       ans[i]+=ans[i-1];
       cout << ans[i] << endl;

    }
}


int32_t main(){
   boost;
   memset(a,1000000,MXN);
   cin>>N;
   for(int i=0; i<N;i++) cin>>a[i];
   for(int i=0; i<N;i++) cin>>p[i];


   for(int i=0; i<N; i++){
      int idx=p[i];
      QueryL[i]=1;
      QueryR[i]=idx-1;
      QueryK[i]=a[idx-1];
   }

   solveQuery1(a,N,N);


   return 0;
}

