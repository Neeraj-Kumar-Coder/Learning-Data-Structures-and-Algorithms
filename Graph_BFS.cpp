#include <iostream>
#include "C:\Neeraj Kumar\Learning C++ Language\My_Header_Files\Queue_ADT.cpp"
#include "C:\Neeraj Kumar\Learning C++ Language\My_Header_Files\Stack_ADT.cpp"

using namespace std;

class Graph
{
private:
    int number_of_vertex;
    int number_of_edges;
    bool **graph;

public:
    Graph(void)
    {
        number_of_vertex = number_of_edges = 0;
    }
    void input(void)
    {

        cout << "Enter the number of vertex in your graph: ";
        cin >> number_of_vertex;
        cout << "Enter the number of edges in your graph: ";
        cin >> number_of_edges;

        graph = new bool *[number_of_vertex];
        for (int i = 0; i < number_of_vertex; i++)
        {
            graph[i] = new bool[number_of_vertex];
            for (int j = 0; j < number_of_vertex; j++)
            {
                graph[i][j] = false;
            }
        }

        int vertex_1, vertex_2;
        while (number_of_edges--)
        {
            cout << "Enter the edge: ";
            cin >> vertex_1 >> vertex_2;
            if (vertex_1 >= 0 && vertex_2 >= 0 && vertex_1 < number_of_vertex && vertex_2 < number_of_vertex)
                graph[vertex_1][vertex_2] = true, graph[vertex_2][vertex_1] = true;
            else
                cout << "Enter a Valid Vertex!\n", number_of_edges++;
        }
    }
    void BFS(void)
    {
        int initialVertex;
        cout << "Enter the initial vertex: ";
        cin >> initialVertex;

        Queue<int> indexQueue;
        bool isVisited[number_of_vertex];
        for (int i = 0; i < number_of_vertex; i++)
        {
            isVisited[i] = false;
        }

        indexQueue.enqueue(initialVertex);
        cout << initialVertex << ' ';
        isVisited[initialVertex] = true;
        int index;
        while (!indexQueue.isEmpty())
        {
            index = indexQueue.dequeue();
            for (int i = 0; i < number_of_vertex; i++)
            {
                if (graph[index][i] && !isVisited[i])
                {
                    cout << i << ' ';
                    isVisited[i] = true;
                    indexQueue.enqueue(i);
                }
            }
        }
        cout << '\n';
    }
    void DFS(void)
    {
        int initialVertex;
        cout << "Enter the initial vertex: ";
        cin >> initialVertex;

        Stack<int> indexStack;
        bool isVisited[number_of_vertex];
        for (int i = 0; i < number_of_vertex; i++)
        {
            isVisited[i] = false;
        }

        indexStack.push(initialVertex);
        cout << initialVertex << ' ';
        isVisited[initialVertex] = true;
        int index;
        while (!indexStack.isEmpty())
        {
            index = indexStack.pop();
            for (int i = 0; i < number_of_vertex; i++)
            {
                if (graph[index][i] && !isVisited[i])
                {
                    cout << i << ' ';
                    isVisited[i] = true;
                    indexStack.push(index);
                    index = i;
                    i = 0;
                }
            }
        }
        cout << '\n';
    }
    void print_graph(void)
    {
        for (int i = 0; i < number_of_vertex; i++)
        {
            for (int j = 0; j < number_of_vertex; j++)
            {
                cout << graph[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
};

int main(void)
{
    Graph grph;
    grph.input();
    grph.print_graph();
    grph.BFS();
    grph.DFS();
    return 0;
}