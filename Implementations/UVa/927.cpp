#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int d,k;

int enumarate(){
   int n=1;
   while(true){
      if( ((d+ n*d)*n)/2 >=k ) return n;
      n++;
   }
}

int32_t main(){
   boost;
   int t; cin>>t;
   while(t--){
      int N; cin>>N;
      int p[N+1];
      for (int i=0; i<=N; i++) cin>>p[i];
      cin >>d>>k;
      int x=enumarate();
      unsigned long long sum=0;
      unsigned long long pr=1;
      for (int i=0; i<=N; i++){int y=p[i]; sum+=pr*y; pr*=x;}
      cout << sum;
      cout << endl;
   }

}
/*#include <iostream>

using namespace std;

typedef unsigned long long ull;

int deg;
int coefficients[21];

ull eval(int n, ull currentNPowVals, int coeff)
{
    if (coeff > deg)
        return 0;

    return coefficients[coeff] * currentNPowVals + eval(n, n * currentNPowVals, coeff + 1);
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        cin >> deg;
        for (int i = 0; i <= deg; ++i)
            cin >> coefficients[i];

        int d, k;
        cin >> d >> k;

        int position = 1, inc = d, count = 1;

        for (; count <= k; ++position, inc += d)
        {
            count += inc;
        }

        cout << eval(position - 1, 1, 0) << '\n';
    }
}*/


