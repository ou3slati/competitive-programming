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




struct Query
{
    int l, r, x, idx;
};

// structure to hold array
struct ArrayElement
{
    int val, idx;
};

// bool function to sort queries according to k
bool cmp1(Query q1, Query q2)
{
    return q1.x < q2.x;
}

// bool function to sort array according to its value
bool cmp2(ArrayElement x, ArrayElement y)
{
    return x.val < y.val;
}

// updating the bit array
void update(int bit[], int idx, int val, int n)
{
    for (; idx<=n; idx +=idx&-idx)
        bit[idx] += val;
}

// querying the bit array
int query(int bit[], int idx, int n)
{
    int sum = 0;
    for (; idx > 0; idx -= idx&-idx)
        sum += bit[idx];
    return sum;
}

void answerQueries(int n, Query queries[], int q,
                              ArrayElement arr[])
{
    // initialising bit array
    int bit[n+1];
    memset(bit, 0, sizeof(bit));

    // sorting the array
    sort(arr, arr+n, cmp2);

    // sorting queries
    sort(queries, queries+q, cmp1);

    // current index of array
    int curr = 0;

    // array to hold answer of each Query
    int ans[q];

    // looping through each Query
    for (int i=0; i<q; i++)
    {
        // traversing the array values till it
        // is less than equal to Query number
        while (arr[curr].val <= queries[i].x && curr<n)
        {
            // updating the bit array for the array index
            update(bit, arr[curr].idx+1, 1, n);
            curr++;
        }

        // Answer for each Query will be number of
        // values less than equal to x upto r minus
        // number of values less than equal to x
        // upto l-1
        ans[queries[i].idx] = query(bit, queries[i].r+1, n) -
                              query(bit, queries[i].l, n);
    }

    // printing answer for each Query
    for (int i=0 ; i<q; i++)
        cout << ans[i] << endl;
}



int32_t main(){
   boost;
   memset(a,1000000,MXN);
   int res=0;
   cin>>N;
   for(int i=0; i<N;i++) cin>>a[i];
   for(int i=0; i<N;i++) cin>>p[i];

   int queryL[N],queryR[N],queryK[N];
   for(int i=0; i<N; i++){
      int idx=p[i];
      queryL[i]=1;
      queryR[i]=idx;
      queryK[i]=a[idx-1];
   }

   solveQuery1(a,N,queryL,queryR,queryK,N);

   ArrayElement arr[N];
   for(int i=0; i<N; i++){
      arr[i].val=a[i];
      arr[i].idx=i;
   }
   Query queries[N];
   for(int i=0; i<N; i++){
      int idx=p[i];
      queries[i].l=idx-1;
      queries[i].r=N-1;
      queries[i].x=a[idx-1];
      queries[i].idx=i;
   }
   cout << endl;
   answerQueries(N, queries, N, arr);



   return 0;
}

