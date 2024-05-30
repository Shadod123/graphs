#pragma once

#include "Shared.h"
#include "Node.h"
#include "LinkedList.h"
#include <string>

class Graph
{
public:
    int length;
    list<int> *graph;
    LinkedList *cycles;
    LinkedList *returnEdges;
    string cycle;
    int cycleCounter;

public:
    Graph(int length)
    {
        this->length = length;
        this->graph = new list<int>[length];
        this->cycles = new LinkedList();
        this->returnEdges = new LinkedList();
        this->cycleCounter = 0;
    }

public:
    void Insert(int v1, int v2)
    {
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    void PrintGraph (int v)
	{
	    for (int d = 0; d < v; ++d) {
	        cout << "\n" << d << ":";
	        for (auto x : graph[d])
	            cout << "->" << x;
	        printf("\n");
	    }
	}
    
    void DFS(int start)
    {
        bool *visited = new bool[length];
        _DFS(start, visited);
    }

    void _DFS(int v, bool *visited)
    {
        visited[v] = true;
    
        list<int>::iterator i;
        for (i = graph[v].begin(); i != graph[v].end(); ++i) {
            if (!visited[*i]) {
                list<int>::iterator j = graph[v].begin();
                ++j;
                while (j != graph[v].end()) {
                    string returnEdge = to_string(v);
                    returnEdge.push_back(*j + '0');
                    if (*j != *i && !IsEdgeRepeated(returnEdge)) { // !visited[*j] !IsEdgeRepeated(returnEdge)
                        returnEdges->AddNode(returnEdge);
                    }
                    ++j;
                }
                    
                _DFS(*i, visited);
            }
        }                  
    }

    void FindAllPaths(int v1, int v2)
    {
        bool* visited = new bool[length];
    
        int* path = new int[length];
        int pathIndex = 0;
    
        for (int i = 0; i < length; i++)
            visited[i] = false;
    
        _FindAllPaths(v1, v2, visited, path, pathIndex);
    }
    
    void _FindAllPaths(int v1, int v2, bool visited[], int path[], int& pathIndex)
    {
        visited[v1] = true;
        path[pathIndex] = v1;
        pathIndex++;
    
        if (v1 == v2 && pathIndex > 2) {
            cycle = "";
            for (int i = 0; i < pathIndex; i++) {
                cycle.push_back(path[i]+'0');
            }

            if (!IsCycleRepeated(cycle)) {
                cycles->AddNode(cycle);
                cycleCounter++;
            }   
            cycle = "";
        }
        else {
            list<int>::iterator i;
            for (i = graph[v1].begin(); i != graph[v1].end(); ++i)
                if (!visited[*i])
                    _FindAllPaths(*i, v2, visited, path, pathIndex);
        }
    
        pathIndex--;
        visited[v1] = false;
    }
    
    void FindAllCycles()
    {
        Node *tmp;
        int v1, v2;
        tmp = returnEdges->getHead();
        while (tmp != nullptr) {
            v1 = tmp->data[0] - '0';
            v2 = tmp->data[1] - '0';
            FindAllPaths(v1, v2);
            tmp = tmp->next;
        }
    }

private:

    bool Exists(int v1, int v2)
    {
        bool result = false;
        for (auto i = graph[v1].begin(); i != graph[v1].end(); i++) {
            if (*i == v2) {
                result = true;
            }
        }
        return result;
    }

    bool IsCycleRepeated(string sequence)
    {
        string cycle = sequence;
        bool result = cycles->Exists(cycle);
        return result;
    }

    bool IsEdgeRepeated(string sequence)
    {
        string edge = sequence;
        bool result = returnEdges->Exists(edge);
        return result;
    }
};
