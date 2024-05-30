#include "Graph.h"

int main()
{
    Graph *graph = new Graph(6);

    graph->Insert(0, 1);
    graph->Insert(0, 3);
    graph->Insert(0, 4);
    graph->Insert(1, 2);
    graph->Insert(1, 3);
    graph->Insert(1, 4);
    graph->Insert(2, 3);
    graph->Insert(2, 4);
    graph->Insert(2, 5);
    graph->Insert(5, 3);
    graph->Insert(5, 4);

    cout<<"Graph:"<<endl;
    graph->PrintGraph(6);
    graph->DFS(0);
    cout<<endl;
    graph->FindAllCycles();
    cout<<"Cycles:"<<endl;
    graph->cycles->PrintCycles();
    cout<<endl;
    cout<<"Cycle Quantity = "<<graph->cycleCounter<<endl;
}