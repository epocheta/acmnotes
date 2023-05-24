# graph theory

#### 邻接表 Vector 存图

```cpp
struct Graph {
    int N, M;
    std::vector<std::vector<std::pair<int, int>>> adj;
    std::vector<int> dis;

    Graph() {}
    Graph(int n) {
        init(n);
    }

    void init(int n) {
        N = n;
        adj.resize(n);
        dis.resize(n, -1);
    }

    void add(int u, int v, int d) {
        adj[u].emplace_back(v, d);
        M++;
    }

    void dijkstra_naive() {
        std::vector<int> dis_temp(N, 1e9), vis_temp(N, 1);
        dis_temp[0] = 0;

        for (int _ = 0; _ < N; _++) {
            auto min_dis = inf, u = 0;
            for (int i = 0; i < N; i++) {
                if (vis_temp[i] && dis_temp[i] < min_dis) {
                    u = i, min_dis = dis_temp[i];
                }
            }
            vis_temp[u] = 0;

            for (auto [v, w] : adj[u]) {
                dis_temp[v] = std::min(dis_temp[v], dis_temp[u] + w);
            }
        }
        dis = dis_temp;
    }

    void dijkstra() {
        std::vector<int> dis_temp(N, -1);
        std::priority_queue<std::pair<int, int>> h;
        h.emplace(0, 0);

        while (!h.empty()) {
            auto [u, d] = h.top();
            h.pop();

            if (dis_temp[u] != -1) continue;

            dis_temp[u] = -d;
            for (auto [v, w] : adj[u]) {
                h.emplace(d - w, v);
            }
        }
        dis = dis_temp;
    }

    void dfs(int u) {
        std::vector<int> vis(N, 1);

        auto recursive = [&](auto self, auto cur) -> void {
            vis[cur] = 0;

            for (auto [v, w] : adj[cur]) {
                if (vis[v] == 0) continue;
                self(self, v); 
            }
        };

        recursive(recursive, u);
    }

    void bfs(int origin) {
        std::vector<int> vis(N, 1);
        std::queue<int> q;
        q.emplace(origin);

        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            vis[u] = 0;
            
            for (auto [v, _] : adj[u]) {
                if (vis[v] == 0) continue;
                q.emplace(v);
            }
        }
    }

};
```
