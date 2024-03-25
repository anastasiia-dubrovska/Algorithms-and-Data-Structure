#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <locale.h>

using namespace std;

// Структура даних граф
struct Graph {
    int V; // Кількість вершин
    vector<vector<pair<int, int>>> adj; // Список суміжностей
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    // Функція додавання ребра
    void addEdge(int u, int v, int w) {
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }
};

vector<int> dijkstra(Graph& graph, int src) {
    // Створення вектору дистанцій та ініціалізація його значень як "нескінченності"
    vector<int> dist(graph.V, INT_MAX);
    // Пріоритетна черга для зберігання пар <вершина, відстань>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // Додавання початкової вершини до черги та встановлення її дистанції на 0
    pq.push({ 0, src });
    dist[src] = 0;
    // Обхід графа за допомогою алгоритму Дейкстри
    while (!pq.empty()) {
        // Отримання вершини з черги з найменшою дистанцією
        int u = pq.top().second;
        pq.pop();
        // Обхід всіх суміжних вершин
        for (auto i : graph.adj[u]) {
            int v = i.first;
            int weight = i.second;
            // Якщо знайдено коротший шлях до вершини, оновлюємо дистанцію та додаємо вершину до черги
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({ dist[v], v });
            }
        }
    }
    // Повернення вектору дистанцій
    return dist;
}


int main() {
    setlocale(LC_ALL, "Ukrainian");
    // Створення графа
    int V = 5; // Кількість вершин
    Graph graph(V);
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 1);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 2);
    graph.addEdge(2, 4, 5);
    graph.addEdge(3, 4, 4);
    // Виконання алгоритму Дейкстри
    int startVertex = 0; // Стартова вершина
    vector<int> distances = dijkstra(graph,startVertex);
    // Вивід результатів
    for (int i = 0; i < V; i++) {
        cout << "Вiдстань вiд вершини " << startVertex << " до вершини " << i << " : " << distances[i] << endl;
    }
    return 0;
}

/*#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "x64/Debug/Алгоритм.90aace33.tlog/doctest.h"
TEST_CASE("Test 1") {
    Graph graph(5);
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 1);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 2);
    graph.addEdge(2, 4, 1);
    graph.addEdge(3, 4, 4);
    vector<int> expected_distances = { 0, 2, 5, 1, 5 };
    vector<int> actual_distances = dijkstra(graph, 0);
    CHECK(actual_distances == expected_distances);
}

TEST_CASE("Test 2") {
    Graph graph(6);
    graph.addEdge(0, 1, 1);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 3, 1);
    graph.addEdge(2, 4, 3);
    graph.addEdge(3, 4, 2);
    graph.addEdge(3, 5, 6);
    vector<int> expected_distances = { 0, 1, 3, 4, 6, 10 };
    vector<int> actual_distances = dijkstra(graph, 0);
    CHECK(actual_distances == expected_distances);
}

TEST_CASE("Test 3") {
    Graph graph(4);
    graph.addEdge(0, 1, 1);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 4);
    graph.addEdge(2, 3, 2);
    vector<int> expected_distances = { 0, 1, 2, 4 };
    vector<int> actual_distances = dijkstra(graph, 0);
    CHECK(actual_distances == expected_distances);
}*/


