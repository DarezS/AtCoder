#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

// 問題URL
// https://atcoder.jp/contests/abc414/tasks/abc414_a

int main(){
    int N, L, R;
    std::cin >> N >> L >> R;

    // 結果のリスナー数
    int cnt = 0;

    rep(i, N)
    {
        int x, y;
        cin >> x >> y;
        // 配信時間(L, R)が(x, y)の中に収まっているか
        if(x <= L && y >= R) cnt++;
    }

    // output 
    cout << cnt << endl;
    return 0;
}