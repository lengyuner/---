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
int locate_v_id(int n, VertexType ver[], char v) {
	int i = 0;
	for (i = 0; i < n; i++) {
		if (ver[i] == v) return i;
	}
	return -1;
}

void creatGraph(Graph* G, VertexType ver[], char edge[][2])
{
	ENode* e;
	int i,j;
	G->vexnum = MAXVER;
	G->edgenum = MAXEDG;

	for (i = 0; i < G->vexnum; i++) {
		G->vertexs[i].val = ver[i];
		G->vertexs[i].first_edge = NULL;
	}

	for (i = 0; i < G->edgenum; i++)
	{
		e = (ENode*)malloc(sizeof(ENode));
		e->v_id = locate_v_id(G->vexnum, ver, edge[i][1]);
		j = locate_v_id(G->vexnum, ver, edge[i][0]);
		e->next_edge = (struct ENode*)G->vertexs[j].first_edge;
		G->vertexs[j].first_edge = e;

		e = (ENode*)malloc(sizeof(ENode));
		e->v_id = locate_v_id(G->vexnum, ver, edge[i][0]);
		j = locate_v_id(G->vexnum, ver, edge[i][1]);
		e->next_edge = (struct ENode*)G->vertexs[j].first_edge;
		G->vertexs[j].first_edge = e;
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
	ENode* e;
	_visit[k] = 1;
	**ret = G->vertexs[k].val;
	(*ret)++;
	e = G->vertexs[k].first_edge;
	while (e != NULL) {
		if (_visit[e->v_id]==0)
		{
			DFS(G, e->v_id, _visit, ret);
		}
		e = (ENode*)e->next_edge;
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
	int i;
	ENode* e;
	PQueue Q;
	Q = CreatQueue(MAXVER);
	_visit[0] = 1;
	*res = G->vertexs[0].val;
	res++;

	Insert(Q, 0);
	while (!Empty(Q)) {
		Delete(Q, &i);
		e = G->vertexs[i].first_edge;
		while (e != NULL) {
			if (_visit[e->v_id] == 0) {
				_visit[e->v_id] = 1;
				*res = G->vertexs[e->v_id].val;
				res++;
				Insert(Q, e->v_id);
			}
			e = (ENode*)e->next_edge;
		}
	}
	DestroyQueue(Q);
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
	int i;
	ENode* e;
	ENode* ee;
	for (i = 0; i < G->vexnum; i++) {
		e = G->vertexs[i].first_edge;
		while (e != NULL) {
			ee = (ENode*)e->next_edge;
			free(e);
			e = NULL;
			e = ee;
		}
		G->vertexs[i].first_edge = NULL;
	}
}


/*
Function: Print adjacency list
Args:    G:  Pointer to a gragh
Description: None

*/
void Print(Graph*G)
{
	ENode* cur;
	int i;
	for ( i = 0; i < MAXVER; i++)
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
