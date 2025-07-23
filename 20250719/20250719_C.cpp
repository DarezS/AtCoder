#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

// 問題URL
// https://atcoder.jp/contests/abc415/tasks/abc415_c

// 状態 = 薬品の組み合わせ

void solve()
{
    int n; string s;
    cin >> n >> s;

    // 左シフト(nの2乗を2bitで表現) これにより薬品iがあるなし のn×２通りを試せる
    // n = 3（桁）なら n2 = 8 となる
    int n2 = 1 << n;

    // すでに訪れているか n2 通りを試すことになる
    vector<bool> visited(n2);
    // q : 状態を積み上げていく
    queue<int> q;

    // 初期状態 0 0 0 は到達できる　qに状態追加
    visited[0] = true;
    q.push(0);

    // 状態が空っぽになるまで繰り返して、その過程でvisited[n2-1]に到達している -> 全ての薬品混ぜた状態作れてる
    while(!q.empty())
    {
        // 状態を取り出す
        int t = q.front();
        // 取り出した状態は消す
        q.pop();
        // 今取り出した状態から次のステップをすべて試す
        // 試す段階で到達可能な状態はqに追加する
        // 追加した状態から同じ作業を繰り返す
        rep(i,n)
        {
            // tは状態 i桁目を1に変えたnt
            int nt = t | 1 << i;
            // そのntがtと同じならもう探索済みってことでcontinue
            if(nt == t) continue;
            // この状態が危険な状態なら到達不可なのでcontinue
            if(s[nt-1] == '1') continue;
            // すでに到達している状態なら積み上げないからconitinue
            if(visited[nt]) continue;

            // 新たに到達可能な状態ならばvisited = trueにしてqに積み上げる
            visited[nt] = true;
            q.push(nt);
        }
    }

    if(visited[n2-1] == true) cout << "Yes" << endl;
    else cout << "No" << endl;
}
int main(){
    int T;
    cin >> T;

    rep(ti, T) solve();

    return 0;
}