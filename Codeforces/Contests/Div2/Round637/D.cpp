/*
CF 637D - Nastya and Scoreboard
https://codeforces.com/contest/1341/problem/D

Make max number with k changes on 7-segment
n ≤ 2000, k ≤ 2000

Key: DP[pos][changes] = possible to make suffix
*/

#include <bits/stdc++.h>
using namespace std;

const vector<string> digits = {
    "1110111", "0010010", "1011101", "1011011", "0111010",
    "1101011", "1101111", "1010010", "1111111", "1111011"
};

int cost(string& from, string& to) {
    int res = 0;
    for(int i = 0; i < 7; i++) {
        if(from[i] == '1' && to[i] == '0') return -1;
        if(from[i] == '0' && to[i] == '1') res++;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<string> a(n);
    for(auto& s : a) cin >> s;
    
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    dp[n][0] = 1;
    
    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j <= k; j++) {
            for(int d = 9; d >= 0; d--) {
                int c = cost(a[i], digits[d]);
                if(c != -1 && j >= c && dp[i+1][j-c] != -1) {
                    dp[i][j] = d;
                    break;
                }
            }
        }
    }
    
    if(dp[0][k] == -1) {
        cout << "-1\n";
        return 0;
    }
    
    int pos = 0, rem = k;
    while(pos < n) {
        int d = dp[pos][rem];
        cout << d;
        rem -= cost(a[pos], digits[d]);
        pos++;
    }
    cout << '\n';
    
    return 0;
}
