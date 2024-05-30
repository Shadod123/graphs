#pragma once

#include "Shared.h"
#include "Node.h"
#include "LinkedList.h"

class Graph
{
public:
    int length;
    list<int> *graph;
    LinkedList *cycles;
    int cycleCounter;

public:
    Graph(int length)
    {
        this->length = length;
        this->graph = new list<int>[length];
        this->cycles = new LinkedList();
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

    void Permute(string a, int l, int r)
    {
        if (l == r) {
            //cout<<a<<endl;
            if (IsPathViable(a)) {
                //cout<<"Yes"<<endl;
                CycleFinder(a);
            } 
            else {
                //cout<<"No"<<endl;
            }
        }
        else {
            for (int i = l; i <= r; i++) {
                swap(a[l], a[i]);
                Permute(a, l+1, r);
                swap(a[l], a[i]);
            }
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

    bool IsPathViable(string path)
    {
        bool result = true;
        int n = path.size()-1;
        for (int i = 0; i < n; ++i) {
            if (!Exists(path[i]-'0', path[i+1]-'0')) {
                result = false;
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

    void CycleFinder(string path)
    {
        int n = path.size();
        string sequence;
        string cycle;
        for (int i = 0; i < n; ++i) {
            sequence.push_back(path[i]);
            if (i > 1 && Exists(path[i]-'0', path[0]-'0') && !IsCycleRepeated(sequence)) {
                cycle = sequence;
                cycles->AddNode(cycle);
                cycle = "";
                cycleCounter++;
            }
        }
    }
};
