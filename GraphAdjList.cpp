
#include <iostream>
#include <string.h>
#include <forward_list>
#include <queue>
#include <vector>
#include <stack>
#define PI 3.14
using namespace std;

// Graph implemented by Adjacency list
struct node
{
public:
    int vertex;
    node *next;
};

class adjList
{
    private:
        int vertex;
        node *start;

    public:
        adjList();
        void setVertex(int);
        void addNode(int);
        void deleteFirstNode();
        void print();
        void BFS(int,int);
        void DFS(int,int);
        ~adjList();
};
adjList::adjList()
{
    start = NULL;
}
void adjList::setVertex(int v)
{
    vertex = v;
}
void adjList::addNode(int n)
{
    node *t = new node;
    t->vertex = n;
    t->next = NULL;
    if (start == NULL)
        start = t;
    else
    {
        t->next = start;
        start = t;
    }
}
void adjList::deleteFirstNode()
{
    if (start)
    {
        node *t = start->next;
        delete start;
        start = t;
    }
}
void adjList::print()
{
    node *t = this->start;
    while (t)
    {
        cout << "V" << t->vertex << " ";
        t = t->next;
    }
    cout << endl;
}
void adjList::BFS(int NoOfVertex, int start1)
{
    adjList *arr1 = this;
    int *ptr = new int[NoOfVertex];
    for (int i = 0; i < NoOfVertex; i++)
        ptr[i] = 0;

    queue<node*> q;
    node *m, *t;
    q.emplace(arr1[start1].start);
    ptr[start1] = 1;
    cout<<"BFS-> ";
    cout << " V" << arr1[start1].vertex << "  ";
    while (!q.empty())
    {
        m = q.front();
        q.pop();
        t = m;
        while (t)
        {
            if (ptr[t->vertex] == 0)
            {
                cout << "V" << t->vertex << "  ";
                q.emplace(arr1[t->vertex].start);
                ptr[t->vertex] = 1;
            }
            t = t->next;
        }
    }
    delete ptr;
}
void adjList::DFS(int NoOfVertex, int start1)
{
    adjList *arr= this;
    int *ptr=new int[NoOfVertex];
    for(int i = 0; i < NoOfVertex; i++)
        ptr[i]=0;
    stack<int>s;
    s.emplace(start1);
    ptr[start1]=1;
    cout<<"DFS-> ";
    node*t=NULL;
    int m;
    while (!s.empty())
    {
        m=s.top();
        cout<<"V"<<m<<"  ";
        s.pop();
        t=arr[m].start;
        while (t)
        {
            if(ptr[t->vertex]==0)
            {
                s.emplace(t->vertex);
                ptr[t->vertex]=1;
            }
            t=t->next;
        }
    }                                   //1 2 2 3 2 3 3 1 0 2 2 1
    delete ptr;
}
adjList::~adjList()
{
    while (start)
        deleteFirstNode();
}

class graph  // Graph implemented Using self made list
{
private:
    int vcount;
    adjList *arr;

public:
    graph();
    graph(int);
    void createGraph1(int,int);
    void addAdjecentVertex(int);
    void printGraph1();
    void BFSGraph(int);
    void DFSGraph(int);
    ~graph();
};
graph::graph()
{
    vcount = 0;
    arr = NULL;
}
graph::graph(int n)
{
    vcount = n;
    arr = NULL;
}
void graph::createGraph1(int v, int direction)
    {
        vcount = v;
        int e, ver;
        arr = new adjList[vcount];
        for (int i = 0; i < vcount; i++)
        {
            arr[i].setVertex(i);
            cout << "How many adjecent Node V" << i << endl;
            cin >> e;
            for (int j = 0; j < e; j++)
            {
                cout << "Enter the vertex number : ";
                cin >> ver;
                arr[i].addNode(ver);
                // directed->0
                // undirected->1
                //  if(direction==1)
                //      arr[ver].addNode(i);
            }
        }
    }
void graph::addAdjecentVertex(int vertex)
{
    int v, data;
    cout << "Enter the vertex number to add in V" << vertex << endl;
    cin >> v;
    arr[vertex].addNode(v);
}
void graph::printGraph1()
{
    for (int i = 0; i < vcount; i++)
    {
        cout << "V" << i << "->";
        arr[i].print();
    }
    cout << endl;
}
void graph::BFSGraph(int start)
{

    arr->BFS(vcount, start);
}
void graph::DFSGraph(int start1)
{
    arr->DFS(vcount,start1);
}
graph::~graph()
{
    delete []arr;
}

// when adjecent list use of STL
class Node
{
public:
    int vertex;
    node *next;
    Node()
    {
        vertex = -1;
        next = NULL;
    }
    Node(int v)
    {
        vertex = v;
        next = NULL;
    }
    void setVertex(int v)
    {
        vertex = v;
    }
};
class graph2
{
private:
    int vcount;
    forward_list<Node*>*arr;

public:
    graph2();
    graph2(int);
    void createGraph2(int);
    void addAdjacentNode(int,int);
    void printGraph2();
    ~graph2();
    
};

graph2::graph2()
{
    vcount = 0;
    arr = NULL;
}
graph2::graph2(int n)
{
    vcount = n;
    arr = NULL;
}
void graph2::createGraph2(int v)
{
    vcount = v;
    int e, ver;
    arr = new forward_list<Node*>[vcount];
    for (int i = 0; i < vcount; i++)
    {

        cout << "How many adjecent Node V" << i << endl;
        cin >> e;
        for (int j = 0; j < e; j++)
        {
            cout << "Enter the vertex number : ";
            cin >> ver;
            Node *n = new Node(ver);
            arr[i].emplace_front(n);
        }
    }
}
void graph2::addAdjacentNode(int vertexNo, int v)
{
    Node *n = new Node(v);
    arr[vertexNo].emplace_front(n);
}
void graph2::printGraph2()
{
    forward_list<Node *>::iterator i;
    for (int j = 0; j < vcount; j++)
    {
        cout << "V" << j << "->";
        for (i = arr[j].begin(); i != arr[j].end(); i++)
        {
            cout << "V" << (*(i))->vertex << "  "; // 1 2 2 2 3 3 3 1 0 2 2 1
        }
        cout << endl;
    }
}
graph2::~graph2()
{
    arr->~forward_list();
    for (int i = 0; i < vcount; i++)
    {
        delete []arr;
    }
    
}






int main()
{
    graph2 A;
    A.createGraph2(4); // createGraph(No of vertex, direction)
    A.printGraph2();
    // A.DFSGraph(0);
    // A.printGraph();
    // A.BFSGraph(0);              //BFSGraph(starting vertex of search)
    return 0;
}

// MySirG code
/*
#include<iostream>
#include<stdio.h>
// #include "DynArray.cpp"
using namespace std;
struct node
{
    int item;
    int vertex;
    node *next;
};
class AdjList
{
    private:
        node *start;
        int vertex;
    public:
        AdjList();
        AdjList(int);
        node* getStart();
        void setVertex(int);
        void addNode(int,int );
        void removeFirstNode();
        void printList();
        ~AdjList();
};
node* AdjList::getStart()
{
    return start;
}
void AdjList::printList()
{
    node *t;
    t=start;
    while(t)
    {
        cout<<t->vertex<<","<<t->item<<" ";
        t=t->next;
    }cout<<endl;
}
AdjList::~AdjList()
{
    while(start)
        removeFirstNode();
}
void AdjList::removeFirstNode()
{
    node *r;
    if(start)
    {
        r=start;
        start=start->next;
        delete r;
    }
}
void AdjList::setVertex(int v)
{
    vertex=v;
}
void AdjList::addNode(int v,int data)
{
    node *n=new node;
    n->item=data;
    n->vertex=v;
    n->next=start;
    start=n;
}
AdjList::AdjList()
{
    start=NULL;
}
AdjList::AdjList(int v)
{
    start=NULL;
    vertex=v;
}
class Graph
{
    private:
        int v_count;
        AdjList *arr;
    public:
        Graph();
        int getVCount();
        // DynArray& adjacentNodes(int);
        void createGraph(int);
        void printGraph();
        ~Graph();

};
// DynArray& Graph::adjacentNodes(int n)
// {
//     DynArray *p=new DynArray(1);
//     node *t=this->arr[n].getStart();
//     while(t)
//     {
//         p->append(t->vertex);
//         t=t->next;
//     }
//     return *p;
// }
int Graph::getVCount()
{
    return v_count;
}
void Graph::printGraph()
{
    for(int i=0;i<v_count;i++)
    {
        cout<<"V"<<i<<"->";
        arr[i].printList();
    }
}
Graph::~Graph()
{
    delete []arr;
}
void Graph::createGraph(int vno)
{
    int n,v,data;
    v_count=vno;
    arr=new AdjList[v_count];
    for(int i=0;i<v_count;i++)
    {
        // arr[i].setVertex(i);
        cout<<"\nHow many adjacent nodes of V"<<i<<":";
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cout<<"\nEnter vertex number: ";
            cin>>v;
            cout<<"\nEnter data to store: ";
            cin>>data;
            // data=10;
            arr[i].addNode(v,data);
        }

    }

}
Graph::Graph()
{
    v_count=0;
    arr=NULL;
}
int main()
{
    Graph G;
    G.createGraph(3);
    G.printGraph();
    cout<<endl;
    return 0;

}


*/
