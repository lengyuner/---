#ifndef  GRAPH_H_
#define  GRAPH_H_
#define  MAXVER 10
#define  MAXEDG 13
typedef char VertexType;

typedef struct EdgeNode
{
	int v_id;              
	struct ENode* next_edge;

}ENode;


typedef struct VertexNode
{
	VertexType val;
	ENode* first_edge;

}VNode;

typedef struct Graph
{
	int vexnum;
	int edgenum;
	VNode  vertexs[MAXVER];
}Graph;

void creatGraph(Graph* G,VertexType ver[],char edge[][2]);
void DFS(Graph* G,int k,int*_visit,char** res);
void BFS(Graph* G,int*_visit, char res[]);
void DestroyGraph(Graph*G);
void Print(Graph*G);
#endif // ! GRAPH_H_

