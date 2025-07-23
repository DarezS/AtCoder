#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

// 問題URL
// https://atcoder.jp/contests/abc415/tasks/abc415_b

int main(){
    
    string S;
    cin >> S;

    int N = S.size();

    // すでに一個読み取っているかフラグ
    bool isExistOne = false;

    rep(i,N)
    {
        char c = S[i];
        if(c == '#')
        {
            if(isExistOne != true)
            {
                isExistOne = true;
                cout << i+1;
                cout << ",";
            }
            else
            {
                cout << i+1 << endl;
                isExistOne = false;
            }
        }
        else
        {
            // do nothing
        }

    }

    return 0;
}