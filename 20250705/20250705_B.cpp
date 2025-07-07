#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

// 問題URL
// https://atcoder.jp/contests/abc413/tasks/abc413_b

int main(){
    int N;
    cin >> N;
    // 連結した文字列を格納するset
    set<string> stSet;
    // 入力文字列を格納するvector
    vector<string> stVec;
    // input
    rep(i,N)
    {
        string s;
        cin >> s;
        stVec.push_back(s);
    }

    rep(i,N)
    {
        for(int j=0; j < N; j++)
        {
            // 重複は考慮しない
            if(i==j) continue;
            // 連結した文字列を追加
            string concatS = stVec[i] + stVec[j];
            stSet.insert(concatS);
        }
    }
    // 連結文字列のサイズを出力
    cout << stSet.size() << endl;
    return 0;
}