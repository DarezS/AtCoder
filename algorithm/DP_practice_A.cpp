#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

// 問題URL
// https://atcoder.jp/contests/dp/tasks/dp_a

int main(){
    int INF = 1000000;

    int N;
    cin >> N;

    int h[N];
    rep(i,N) cin >> h[i];

    vector<int> dp(N, INF);

    int sumCost1 = 0; // 1個前における総コスト
    int sumCost2 = 0; // 2個前における総コスト
    rep(i, N)
    {
        if(i==0)
        {
            dp[i] = 0;
        }
        else
        {
            if(i > 1)
            {
                int cost1 = abs(h[i] - h[i-1]);
                int cost2 = abs(h[i] - h[i-2]);
                sumCost1 = dp[i-1] + cost1;
                sumCost2 = dp[i-2] + cost2;
                int minCost = sumCost1;
                if(sumCost1 > sumCost2) minCost = sumCost2;
                dp[i] = minCost;
            }
            else // i=1 の時は足場0からの一通り
            {
                int cost1 = abs(h[i] - h[i-1]);
                dp[i] = cost1;
            }
        }
    }

    cout << dp[N-1] << endl;

    return 0;
}