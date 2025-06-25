#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); i++)

// 問題URL
// https://atcoder.jp/contests/abc410/tasks/abc410_c

int main(){
    // 入力
    ll N, Q;
    cin >> N >> Q;

    // 整数列A
    vector<ll> A(N);
    rep(i,N) A[i] = i+1;

    // 先頭インデックス 初期は0
    ll top = 0;

    // クエリの処理
    rep(i, Q)
    {
        // クエリのタイプを入力
        ll typeInt;
        cin >> typeInt;

        if(typeInt == 1)
        {
            // Apをxに変更する
            ll p, x;
            cin >> p >> x;
            ll tgtIdx = (p-1 +top) % N;
            /*
            if(tgtIdx >= N)
            {
                tgtIdx = tgtIdx - N;
            }
            */
            A[tgtIdx] = x;
        }
        else if(typeInt == 2)
        {
            // Apを出力する
            ll p;
            cin >> p;
            ll outIdx = (p-1  + top) % N;
            /*
            if(outIdx >= N)
            {
                outIdx = outIdx - N;
            }
            */
            cout << A[outIdx] << endl;
        }
        else
        {
            // 先頭を末尾にする = 先頭インデックスを変更する
            ll x;
            cin >> x;
            top = (top + x) % N;
            // Nもxも値域は同じだが、xがNの二倍以上の場合に、top - Nをしても top > Nになりえて領域外アクセスしてしまう
            /*
            if(top >= N)
            {
                top = top - N;
            }
            */
        }
    }
    return 0;
}