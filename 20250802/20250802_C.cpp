#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int N;
    cin >> N;

    vector<int> A(N);
    rep(i,N) cin >> A[i];

    // j-i == A[i] + A[j]
    // -> j - A[j] == i + A[i]
    ll cnt = 0;
    unordered_map<int, int> freq;

    for(int j = 0; j < N; j++)
    {
        int tmp = j - A[j];
        if(freq.count(tmp))
        {
            cnt += freq[tmp];
        }
        // i + A[i] の値をカウント
        ll tmp2 = j + A[j];
        freq[tmp2]++;
    }

    cout << cnt << endl;
    return 0;
}