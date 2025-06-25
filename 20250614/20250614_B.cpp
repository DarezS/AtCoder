#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

// 問題URL
// https://atcoder.jp/contests/abc410/tasks/abc410_b

int main(){
    int N, Q;
    std::cin >> N;
    cin >> Q;

    vector<int> B(N,0);

    rep(i,Q)
    {
        int x;
        cin >> x;

        if(x == 0)
        {
            // 一番少ない箱に入れる
            int minB = 999;
            int idx = 999;
            rep(j,N)
            {
                if(B[j] < minB)
                {
                    minB = B[j];
                    idx = j;
                }
            }
            B[idx]++;
            cout << idx+1<<" ";
        }
        else
        {
            B[x-1]++;
            cout << x << " ";
        }
    }

    cout << endl;
    return 0;
}