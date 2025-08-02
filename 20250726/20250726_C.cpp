#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int N, K, X;
    cin >> N >> K >> X;

    vector<string> S(N);

    rep(i,N) cin >> S[i];

    vector<string> result;

    function<void(string, int)> dfs = [&](string current, int depth)
    {
        if(depth == K)
        {
            result.push_back(current);
            return;
        }
        rep(i,N) dfs(current + S[i], depth+1);
    };

    // dfsで全ての文字列の組み合わせを作成しておく
    dfs("", 0);

    // 組み合わせの並び替え
    sort(result.begin(), result.end());

    cout << result[X-1] << endl;


    return 0;
}