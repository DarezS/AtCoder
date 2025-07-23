#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

// 問題URL
// https://atcoder.jp/contests/abc415/tasks/abc415_a

int main(){
    
    int N;
    cin >> N;

    vector<int> A(N);
    rep(i,N) cin >> A[i];

    int X;
    cin >> X;

    rep(i,N)
    {
        if(X == A[i])
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}