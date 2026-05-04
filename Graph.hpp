#include <vector>
#include <set>
#include <iostream>

class Graph {
private:
    int n; //вершины
    std::vector<std::vector<int>> g; //список смежности
    std::set<int> points; //точки сочлененич
    std::vector<bool> used; //флаг, посещена ли вершина при обходе
    std::vector<int> tin, low; //время входа , мин время
    int timer; //счетчик
    
//рекурсивный обход графа
    void dfs(int v, int p);
    
public:
    Graph();
    void read(std::istream& in); //чтение из потока
    void findPoints(); //поиск точек сочленения
    void print(std::ostream& out) const;
    
//дружественная функция
    friend std::istream& operator>>(std::istream& in, Graph& gr);
    friend std::ostream& operator<<(std::ostream& out, const Graph& gr);
};
