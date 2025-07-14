#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

// 問題URL
// https://atcoder.jp/contests/abc414/tasks/abc414_b

int main(){
    int N;
    cin >> N;

    // 文字列の長さの上限
    const ll LENMAX = 100;

    // 連結文字列の長さ
    ll strLen = 0;
    // 連結文字列
    string result = "";
    // 有効か否か
    bool isValid = true;
    
    rep(i, N)
    {
        string c;
        cin >> c;

        ll l;
        cin >> l;

        // 文字列の長さを足す
        strLen += l;
        // 長さが閾値以上なら無効化
        if(strLen > LENMAX)
        {
            isValid = false;
            break;
            // 追記
            // breakで外に出なくても、return 0 してあげればisValidが不要になる
        }
        else
        {
            rep(j, l) result += c;
        }
    }

    // output
    if(true == isValid)
    {
        cout << result << endl;
    }
    else
    {
        cout << "Too Long" << endl;
    }
    return 0;
}