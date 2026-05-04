#include "Graph.hpp"

#include <algorithm>

using namespace std;

//пустой граф
//при чтении пересоздаем
Graph::Graph() : n(0), timer(0) {}

//рекурсивно обходим граф
void Graph::dfs(int v, int p) {
    //пометка посещенной вершины
    used[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0; //кол прямых потомков
    
    for (int to : g[v]) {
        if (to == p) continue;
        
        if (used[to]) {
            //обратное ребро
            low[v] = min(low[v], tin[to]);
        } else {
            //прямое ребро
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            children++;
            
//условие точки сочленения
            if (p != -1 && low[to] >= tin[v]) {
                points.insert(v);
            }
        }
    }
    
    if (p == -1 && children > 1) {
        points.insert(v);
    }
}

//кол ребер и вершин
void Graph::read(istream& in) {
    int m;
    in >> n >> m;
   
//очистка
    g.clear();
    g.resize(n);
    used.assign(n, false);
    tin.assign(n, 0);
    low.assign(n, 0);
    points.clear();
    timer = 0;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        in >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

//поиск точек сочленения
void Graph::findPoints() {
    used.assign(n, false);
    timer = 0;
    points.clear();
    
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i, -1);
        }
    }
}

void Graph::print(ostream& out) const {
    if (points.empty()) {
        out << "НЕТ точек сочленения";
    } else {
        bool first = true;
        for (int v : points) {
            if (!first) out << " ";
            out << v + 1;
            first = false;
        }
    }
}


//дружественные операторы
istream& operator>>(istream& in, Graph& gr) {
    gr.read(in);
    return in;
}

ostream& operator<<(ostream& out, const Graph& gr) {
    gr.print(out);
    return out;
}
