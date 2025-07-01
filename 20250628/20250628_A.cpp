#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

// 問題URL
// https://atcoder.jp/contests/abc412/tasks/abc412_a

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    int cnt = 0;
    rep(i,N)
    {
        cin >> A[i] >> B[i];
        // 目標Bより完了タスクAが多い日をカウントする
        if(A[i] < B[i]) cnt++;
    }

    cout << cnt << endl;


    return 0;
}