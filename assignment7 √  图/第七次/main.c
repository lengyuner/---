#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Graph.h"
//using namespace std;

int main()
{
	
	int visit[MAXVER] = { 0 };
	char v[MAXVER] = { 'A', 'B','C','D','E','F','G','H','I','J' };
	char e[MAXEDG][2] = { { 'A','B' },{ 'A','D' },{ 'A','E' },{ 'A','G' },\
	{'B','F'},{ 'C','F' },{ 'C','H' },{ 'C','J' },{ 'D','G' },\
	{'E','J'},{ 'G','H' },{ 'G','I' },{ 'I','J' }
	};
	char res[MAXVER] = {'0'};
	char *p = res;
	Graph Gra;
	
	creatGraph(&Gra, v, e);

	printf("Print  Adjacency table:\n");	
	Print(&Gra);         

	DFS(&Gra,0,visit,&p);	
	printf("\n");
	printf("DFS:\n");


	for (int i = 0; i < MAXVER; i++)
	{
		printf("%c ", res[i]);
		visit[i] = 0;
	}
	printf("\n");
	BFS(&Gra,visit,res);
	printf("BFS:\n");
	for (int i = 0; i < MAXVER; i++)
	{
		printf("%c ", res[i]);
	}
	printf("\n");
	DestroyGraph(&Gra);
	return 0;
}