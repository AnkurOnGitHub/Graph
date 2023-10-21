#include <iostream>
#include <queue>
#include <stack>
#define PI 3.14
using namespace std;


//Graph implemented by Adjacency Matrix
class graph
{
    private:
        int vCount;
        int eCount;
        int **adj;
    public:
        void createGraph(int,int);
        void printMatrix();
        void printGraph();
        void IsAdjcentNode(int);
        bool isIsolate(int);
        void BFS(int);
        void DFS(int);
        ~graph();
        
};
void graph::createGraph(int vertex, int edge)
{
    int a,b;
    vCount=vertex;
    eCount=edge;
    adj=new int*[vCount];
    for (int i = 0; i < vCount; i++)
        adj[i]=new int[vCount];

    for (int i = 0; i < vCount; i++)
        for (int j = 0; j < vCount; j++)
            adj[i][j]=0;
        
    for (int i = 0; i < eCount; i++)
    {
        cout<<"Enter the edges : ";
        cin>>a>>b;
        adj[a][b]=1;
        adj[b][a]=1;
    }
}
void graph::IsAdjcentNode(int n)
{
    cout<<"Adjcent Nodes : ";
    for (int i = 0; i < vCount; i++)
    {
        if(adj[n][i]==1)
        {
            cout<<"V"<<i<<" ";
        }
    }
    
}
void graph::printMatrix()
{
    for (int i = 0; i < vCount; i++)
    {
        for (int j = 0; j < vCount; j++)
        {
            cout<<adj[i][j]<<"  ";
        }cout<<endl;
        
    }
    
}
void graph::printGraph()
{
    for (int i = 0; i < vCount; i++)
    {
        cout<<"V"<<i<<"->";
        for (int j = 0; j < vCount; j++)
        {
            if(adj[i][j]==1)
            {
                cout<<"V"<<j<<"  ";
            }
        }cout<<endl;
        
    }
    
}
bool graph::isIsolate(int node)
{
    for (int i = 0; i < vCount; i++)
        if(adj[node][i]==1)
        {
            return false;
            break;
        }
    return true;
    
}
void graph::BFS(int start)
{
    int *ptr=new int[vCount];
    for (int i = 0; i < vCount; i++)
        ptr[i]=0;

    queue<int>q;
    q.emplace(start);
    ptr[start]=1;
    cout<<"BFS-> ";
    int p;
    while (!q.empty())
    {
        p=q.front();
        cout<<"V"<<p<<"  ";
        q.pop();
        for (int i = 0; i < vCount; i++)
        {
            if(adj[p][i]==1)
            {
                if(ptr[i]==0)
                {
                    q.emplace(i);
                    ptr[i]=1;
                }
            }
        }
    }
}
void graph::DFS(int start)
{
    int *ptr=new int[vCount];
    for(int i=0; i < vCount; i++)
        ptr[i]=0;

    stack<int>s;
    s.emplace(start);
    ptr[start]=1;
    cout<<"DFS-> ";
    int t;
    while (!s.empty())
    {
        t=s.top();
        cout<<"V"<<t<<"  ";
        s.pop();
        for (int i = 0; i < vCount; i++)
        {
            if(adj[t][i]==1)
            {
                if(ptr[i]==0)
                {
                    s.emplace(i);
                    ptr[i]=1;
                    // temp=i; 
                    //0 2 2 1 1 3 3 2
                }
            }
        }
        
    }
    
    
}
graph::~graph()
{
    for (int i = 0; i < vCount; i++)
        delete []adj[i];
    delete []adj;
    cout<<"\nDestructor"<<endl;
}

int main()
{
    graph G;
    G.createGraph(6,9);
    G.printMatrix();
    cout<<endl;
    G.printGraph();
    cout<<endl;
    G.BFS(0);
    return 0;
}//GraphAdjMatrix.cpp