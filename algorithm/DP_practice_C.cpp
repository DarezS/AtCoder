#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

// 問題URL
// https://atcoder.jp/contests/dp/tasks/dp_c

int main(){
    int N; cin >> N;

    vector<int> dpA(N,0);
    vector<int> dpB(N,0);
    vector<int> dpC(N,0);

    // i番目にa, b, cそれぞれの行動をとる中での最大値を計算していく
    rep(i,N)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int maxA = 0;
        int maxB = 0;
        int maxC = 0;

        if(i==0)
        {
            dpA[i] = a;
            dpB[i] = b;
            dpC[i] = c;
        }
        else
        {
            // maxAの計算
            int scoreA1 = dpB[i-1] + a;
            int scoreA2 = dpC[i-1] + a;
            if(scoreA1 < scoreA2)
            {
                maxA = scoreA2;
            }
            else
            {
                maxA = scoreA1;
            }
            dpA[i] = maxA;
            // maxBの計算
            int scoreB1 = dpA[i-1] + b;
            int scoreB2 = dpC[i-1] + b;
            if(scoreB1 < scoreB2)
            {
                maxB = scoreB2;
            }
            else
            {
                maxB = scoreB1;
            }
            dpB[i] = maxB;
            // maxCの計算
            int scoreC1 = dpA[i-1] + c;
            int scoreC2 = dpB[i-1] + c;
            if(scoreC1 < scoreC2)
            {
                maxC = scoreC2;
            }
            else
            {
                maxC = scoreC1;
            }
            dpC[i] = maxC;
        }
    }

    // 最後にどのa,b,cで終わるかを決める
    int result = max({dpA[N-1], dpB[N-1], dpC[N-1]});
    cout << result << endl;
    return 0;
}