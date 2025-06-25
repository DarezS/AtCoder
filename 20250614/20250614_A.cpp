#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

// 問題URL
// https://atcoder.jp/contests/abc410/tasks/abc410_a

int main(){
    int N;
    std::cin >> N;

    int A[N];
    rep(i,N) cin >> A[i];

    int K;
    cin >> K;

    int cnt = 0;
    rep(i,N)
    {
        if(A[i] >= K)
        {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}