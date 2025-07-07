#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

// 問題URL
// https://atcoder.jp/contests/abc413/tasks/abc413_a

int main(){
    int N, M;
    std::cin >> N >>M;

    int total = 0;
    bool isTrue = true;
    rep(i,N)
    {
        int a;
        cin >> a;
        total += a;
        // 合計した値がMを超えた場合は終了
        if(total > M)
        {
            isTrue = false;
            break;
        }
    }

    if(isTrue == true)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }


    
    return 0;
}