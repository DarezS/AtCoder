#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int N, M;
    cin >> N >> M;

    vector<ll> A(N);
    vector<ll> B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];

    sort(B.begin(), B.end());

    vector<ll> result;
    int startJ = 0;
    rep(i,N)
    {
        ll tgtA = A[i];
        bool addFlg = true;
        for(int j = startJ; j < M ; j++)
        {
            ll tgtB = B[j];
            if(tgtA == tgtB)
            {
                addFlg = false; // 追加しない
                startJ = j+1;
                break;
            }
        }
        if(addFlg) result.push_back(tgtA);
    }
    if(result.size() > 0)
    {
        rep(i, result.size()) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}