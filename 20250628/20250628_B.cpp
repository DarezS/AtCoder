#include <iostream>
#include <vector>
#include <cctype>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

// 問題URL
// https://atcoder.jp/contests/abc412/tasks/abc412_b

int main(){
    string S, T;

    cin >> S;
    cin >> T;

    // 問題の条件を満たすか否か
    bool isTrue = true;

    for(int i = 1; i < S.size(); i++)
    {
        // 一文字ずつ取り出して
        char tgtS = S[i];
        // 大文字の場合
        if(isupper(tgtS))
        {
            // 取り出した文字の一文字前を取り出す
            char aheadS = S[i-1];
            // それがTに存在するか否か
            bool isExists = false;
            for(char t : T)
            {
                if(aheadS == t)
                {
                    isExists = true;
                    break;
                }
            }
            // 一度でも存在しなかったら条件を満たさない
            if(isExists != true)
            {
                isTrue = false;
                break;
            } 
        }
    } 
    if(isTrue)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}