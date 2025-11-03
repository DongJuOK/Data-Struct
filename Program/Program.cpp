#include <iostream>

using namespace std;

// 그래프 : 여러 개의 점들이 선으로 연결된 구조를 나타내는 수학적인 개념

// 정점(Vertex) : 그래프에서 하나의 점 (data 저장)

// 간선(Edge) : 그래프에서 노드와 노드를 연결하는 선

// 무방향 그래프 : -- 일자 구조 (진입 진출 동시)
 
// 방향 그래프 : -> 내가 원하는 방향으로

// 차수 : 노드에 연결된 간선의 수

// 진입 차수 : 들어오는 것

// 진출 차수 : 나가는 것

// 사이클 : 그래프에서 동일한 노드로 되돌아오는 경로

// 가중치 : 간선에 저장되어 있는 값

// 그래프의 표현 : 인접 행렬, 인접 리스트

// 인접 행렬 : 2차원 배열로 그래프를 나타내는 자료 구조입니다.
//            노드의 개수를 N이라고 할 때 N x N 크기의 행렬을
//            사용하여 노드 사이의 연결 관계를 표현합니다.

//     장점 : 인접한 노드의 존재 여부를 확인하기 쉽고, 간선의 존재 여부를 0(1) 시간에 확인할 수 있다.
//     단점 : 노드 수가 많고, 간선이 적은 희소 그래프의 경우 메모리를 많이 사용하는 단점이 존재합니다.

template <typename T>
class Graph
{
private:
    int size;  // 정점의 개수
    int count;  // 인접 행렬의 크기
    int capacity;  // 최대 용량

    T * vertex;  // 정점의 집합
    int ** matrix;  // 인접 행렬

public:
    Graph()
    {
        size = 0;
        count = 0;
        capacity = 0;

        vertex = nullptr;
        matrix = nullptr;
    }

    void push(T data)
    {
        if (capacity <= 0)
        {
            resize(1);
        }
        else if (size >= capacity)
        {
            resize(capacity * 2);
        }

        vertex[size++] = data;
    }

    void resize(int newSize)
    {
        capacity = newSize;

        T * container = new T[capacity];

        for (int i = 0; i < capacity; i++)
        {
            container[i] = NULL;
        }

        for (int i = 0; i < size; i++)
        {
            container[i] = vertex[i];
        }

        delete[] vertex;

        vertex = container;
    }
    
    void edge(int i, int j)
    {
        if (size <= 0) // vertex가 존재하지 않을 때
        {
            cout << "adjacency matrix is empty" << endl;
        }
        else if (size < i || size < j) // vertex가 존재하는 범위보다 더 넓게 간선을 연결했을 때
        {
            cout << "index out of range" << endl;
        }
        else
        {
            count = size;

            matrix = new int * [count];

            for (int i = 0; i < count; i++)
            {
                matrix[i] = new int[count];
            }

            for (int i = 0; i < count; i++)
            {
                for (int j = 0; j < count; j++)
                {
                    matrix[i][j] = 0;
                }
            }

            matrix[i][j] = 1;
            matrix[j][i] = 1;
        }
    }
};

int main()
{
    Graph<char> graph;

    graph.push('A');
    graph.push('B');
    graph.push('C');

    return 0;
}