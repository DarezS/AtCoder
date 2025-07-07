#include <iostream>
#include <vector>
#include <set>
#include <deque>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    int Q;
    cin >> Q;

    deque<pair<ll, ll>> A;

    rep(i,Q)
    {
        // クエリタイプの入力
        int queryType;
        cin >> queryType;

        if(queryType == 1)
        {
            ll c, x;
            cin >> c >> x;
            // Aの末尾にxをc個追加
            A.push_back({x,c});
        }
        else
        {
            ll k;
            cin >> k;
            ll sumK = 0;
            while (k > 0) {
                // Aの先頭を取得
                auto &[val, cnt] = A.front();
                // valの足す回数を取得(kがcnt以下ならk個、cnt以上ならcnt個が足される)
                ll valNum = min(k, cnt);
                sumK += val * valNum;
                // k > cntの場合は次のAからも足し算をするので、差を出して次のループに回す　kが0になったらループから出る
                k -= valNum;
                cnt -= valNum;
                if (cnt == 0) A.pop_front();
            }
            // 出力
            cout << sumK << endl;
        }
    }

    return 0;
}