#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

// 問題URL
// https://atcoder.jp/contests/dp/tasks/dp_b

int main(){
    // コストの最大値は1e8
    const int INF = 1e9;

    int N, K;
    cin >> N >> K;

    vector<int> h(N);
    rep(i, N) cin >> h[i];

    // dpをINFで初期化
    vector<int> dp(N, INF);

    dp[0] = 0;
    
    for(int i = 1; i < N ; i++)
    {
        // 最小コストの初期化
        int minCost = INF; 
        
        // i番目の足場までのK通りのコストを計算し最小コストを算出
        for(int j = 1; j <= K; j++)
        {
            if(i - j < 0) continue;
            int cost = dp[i-j] + abs(h[i] - h[i-j]);
            if(cost < minCost) minCost = cost;
        }

        // 最小コストをi番目のdpとする
        dp[i] = minCost;

    }

    cout << dp[N-1] << endl;

    return 0;
}