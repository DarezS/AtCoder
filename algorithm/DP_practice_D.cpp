#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

// 問題URL
// https://atcoder.jp/contests/abc032/tasks/abc032_d

const int NMAX = 100;
const int WMAX = 1e5;
ll dp[NMAX][WMAX] = {0};

int main(){
    int N, W;
    cin >> N >> W;

    vector<int> v(N);
    vector<int> w(N);
    rep(i,N) cin >> w[i] >> v[i];

    // 重さの総和sum(w)がW以下で価値sum(v)が最大をとる組み合わせを求める
    // 方針：dp[i][sum(w)]の最大値を更新していく
    
    rep(i,N)
    {
        for(int j=0; j <= W; j++)
        {
            //　今回の重みを足したらjになるインデックス
            int preIdx = j - w[i];

            // i=0の場合:dpの初期化
            if(i==0)
            {
                if(preIdx < 0) continue;
                dp[i][j] = v[i];
                continue;
            }

            // 0以下の場合はありえないから前の価値を引き継ぐ
            if(preIdx < 0)
            {
                dp[i][j] = dp[i-1][j];
                continue;
            }
            // 選ぶ場合：今回の重みを足したらjになるdp値 + 今回の価値
            ll Yes = dp[i-1][preIdx] + v[i];
            // 選ばない場合：前のdp値そのまま
            ll No = dp[i-1][j];
            if(Yes > No)
            {
                dp[i][j] = Yes;
            }
            else
            {
                dp[i][j] = No;
            }
        }
    }

    cout << dp[N-1][W] << endl;

    return 0;
}