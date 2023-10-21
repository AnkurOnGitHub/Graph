#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
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
        void adjcentNode(int);
        bool isIsolate(int);
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
void graph::adjcentNode(int n)
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
    G.createGraph(4,4);
    G.printMatrix();
    cout<<endl;
    G.printGraph();
    return 0;
}//GraphAdjMatrix.cpp