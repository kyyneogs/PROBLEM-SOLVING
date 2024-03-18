#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        int N, M, t, ans=1;
        deque<pair<int, int>> que;
        deque<int> impo;
        cin >> N >> M;

        for(int i=0; i<N; i++){
            cin >> t;
            impo.emplace_back(t);
            que.emplace_back(make_pair(i, t));
        }
        sort(impo.begin(), impo.end(), greater<>());
        while(!que.empty()){
            if (que[0].second < impo[0]){
                que.emplace_back(que.front());
                que.pop_front();
                continue;
            }
            if (que[0].first == M) break;
            que.pop_front();
            impo.pop_front();
            ans++;
        }
        cout << ans << "\n";
    }
}