#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

// 問題URL
// https://atcoder.jp/contests/abc414/tasks/abc414_c

// 8進数でも回文になっているか判定関数
bool isPalindromic(ll x, int A)
{
    string s;
    // A進数に直す基本的な方法
    while(x)
    {
        // 値 -> stringなので'0'を足す
        s += '0' + x%A;
        x /= A;
    }
    // 反対から読んだのと同じなら回文
    string rs = s;
    reverse(rs.begin(), rs.end());
    return s == rs;
}

int main(){
    int A;
    ll N;
    cin >> A;
    cin >> N;

    ll ans = 0;

    // ラムダ式[&]は外の変数を参照する。コピーして使いたい場合は[=]にする
    // この書き方だとansは参照して、他はコピー
    auto check = [=, &ans](string s)
    {
        // string -> long long
        ll y = stoll(s);

        // n以下で回文になっていたら足す
        if(y <= N && isPalindromic(y, A)) ans += y;
    };

    for(ll x = 1; x < 1e6; x++)
    {
        // xをstringに変換して　x = 123
        string s = to_string(x);
        // それをコピーして rs = 123
        string rs = s;
        // ひっくり返す rs = 321
        reverse(rs.begin(), rs.end());
        // sにくっつける s = 123321
        s += rs;

        check(s);
        
        // 一度チェックした s について真ん中の一文字消したやつもチェックする s = 12321 
        s.erase(s.begin() + (s.size() /2));
        check(s);
    }

    cout << ans << endl;

    return 0;
}