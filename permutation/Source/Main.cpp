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

    string s = "012345";
    int n = s.size();
    cout<<"Graph:"<<endl;
    graph->PrintGraph(n);
    cout<<endl;
    graph->Permute(s, 0, n-1);
    cout<<"Cycles:"<<endl;
    graph->cycles->PrintCycles();
    cout<<endl;
    cout<<"Cycle Quantity = "<<graph->cycleCounter<<endl;
}
