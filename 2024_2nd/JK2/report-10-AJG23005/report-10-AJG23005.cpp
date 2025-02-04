//AJG23005 中 天花
//講義や課題に関するコメント
//前回のsetとvectorを使えて、とても良い復習になったと感じた。

#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define N_NODE 5
int s = 0; //始点となるノード番号
set<int> T; //Tを空集合として初期化
set<int> N; //Nをノード数N_NODEで初期化
vector<int> C(N_NODE, 10000); //最小コスト
vector<int> parent(N_NODE, -1); //親ノード

int graph[N_NODE][N_NODE] = {
/* ノード0, ノード1, ノード2, ノード3, ノード4 */
/*ノード0*/ 0, 3, 1, 10000, 10000,
/*ノード1*/ 3, 0, 1, 3, 10000,
/*ノード2*/ 1, 1, 0, 2, 5,
/*ノード3*/ 10000, 3, 2, 0, 1,
/*ノード4*/ 10000, 10000, 5, 1, 0,
};

int main() {
    cout << "始点となるノード番号を入力してください: ";
    cin >> s;
    // Nの設定
    for (int i = 0; i < N_NODE; i++) {
        if (i != s) {
            N.insert(i);
        }
    }
    C[s] = 0;
    for (int x=0; x<N_NODE; x++) {
        if (graph[s][x] < 10000) {
            C[x] = graph[s][x];
            parent[x] = s;
        } else {
            C[x] = 10000;
        }
    }
    while (!N.empty()) {
        int u = -1;
        int min_cost = 10000;
        for (set<int>::iterator i = N.begin(); i != N.end(); ++i) {
            int node = *i;
            if (C[node] < min_cost) {
                min_cost = C[node];
                u = node;
            }
        }
        // 全ノードに到達できない場合
        if (u == -1) break;
        T.insert(u);
        N.erase(u);
        for (int v = 0; v < N_NODE; v++) {
            if (N.count(v) && graph[u][v] < 10000) {
                if (C[v] > C[u] + graph[u][v]) {
                    C[v] = C[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }
    for (int i = 0; i < N_NODE; i++) {
        if (i != s && C[i] != 10000) {
            cout << "route from node " << s << " to node " << i << ": ";
            // 経路を復元する
            vector<int> path;
            parent[s] = -1;
            for (int current = i; current != -1; current = parent[current]) {
                path.push_back(current);
            }
            // 経路を逆順に出力
            for (vector<int>::reverse_iterator j = path.rbegin(); j != path.rend(); ++j) {
                if (j != path.rbegin()) {
                    cout << " -> ";
                }
                cout << *j;
            }
            cout << " cost = " << C[i] << endl;
        }
    }
    return 0;
}
