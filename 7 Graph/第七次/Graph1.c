#include"Graph.h"
#include"Queue.h"
#include<stdlib.h>

/*
Function:  Creat an undirected graph
Args:     
    *G:    Pointer to a gragh
    *ver:  An array of vertex value
	*edge: An array of edges 
Description: Construct a graph which is stored in the form of an adjacency list

*/
void creatGraph(Graph* G, VertexType ver[], char edge[][2])
{	
	int N_Vertex = MAXVER;// sizeof(ver);// / sizeof(ver[0]);
	int N_Edge = MAXEDG;// sizeof(edge);// / sizeof(edge[0]);
	G->vexnum = N_Vertex;	
	G->edgenum = N_Edge;
	//printf("%s10", ver);
	//printf("N_Vertex=%d\n", N_Vertex);
	//printf("N_Edge=%d\n", N_Edge);
	//cout << "N_Edge" << N_Edge << endl;

	
	//G1 = (Graph)malloc(sizeof(Graph));

	int i, j, k;
	for (i = 0;i<G->vexnum; i++)
	{
		G->vertexs[i].val = ver[i];
		G->vertexs[i].first_edge = NULL;	
	}

	ENode *pe;
	for (k = 0; k < G->edgenum; k++)
	{
		i = edge[k][0] - 'A';
		j = edge[k][1] - 'A';

		pe = (ENode*)malloc(sizeof(ENode));
		pe->v_id = j;
		//pe->next_edge
		pe->next_edge = G->vertexs[i].first_edge;
		G->vertexs[i].first_edge = pe;

		/*pe = (ENode*)malloc(sizeof(ENode));
		pe->v_id = i;
		pe->next_edge = G->vertexs[j].first_edge;
		G->vertexs[j].first_edge = pe;*/
	}
}


/*
Function:    Tranverse the graph Depth-first
Args:    
    *G:      Pointer to a gragh
    *k:      Current index of vertex node
	*_visit: An array helping judging whether the vertex is visited
    *ret:    An array storing the vertexs in Depth-first consequence 
Description: None

*/
void DFS(Graph* G,int k,int*_visit,char**ret)
{
	ENode *p;
	_visit[k] = 1;
	printf("%d\n", k);
	//printf("%s\n", k+'A');
	p = G->vertexs[k].first_edge;
	while (p != NULL)
	{		
		if (_visit[p->v_id] == 0)
		{
			DFS(G, p->v_id, _visit, ret);
		}
		p = p->next_edge;
	}
}


/*
Function:    Tranverse the graph Breadth-first
Args:    
    *G:      Pointer to a gragh
    *_visit: An array helping judging whether the vertex is visited
    *ret:    An array storing the vertexs in Breadth-first consequence
Description: None

*/

void BFS(Graph* G,int*_visit,char res[])
{
	/*int v = 0;
	for (v = 0; v < G->vexnum; v++)
	{
		_visit[v] = 0;
	}
	for (v = 0; v < G->vexnum; v++)
	{
		if (!_visit[v])
		{
			_visit[v] = 1;
			q.push(v);
		}

	}
	*/
}


/*
Function:    Destroy a graph
Args:    
    *G:      Pointer to a gragh
    *_visit: An array helping judging whether the vertex is visited
    *ret:    An array storing the vertexs in Breadth-first consequence
Description: None

*/
void DestroyGraph(Graph*G)
{

}


/*
Function: Print adjacency list
Args:    G:  Pointer to a gragh
Description: None

*/
void Print(Graph*G)
{
	ENode* cur;
	for (int i = 0; i < MAXVER; i++)
	{
		cur = G->vertexs[i].first_edge;
		printf("%c: ", G->vertexs[i].val);
		while (cur != NULL)
		{
			printf("%c ", G->vertexs[cur->v_id].val);
			cur = cur->next_edge;
	
		}
		printf("\n");
	}
}