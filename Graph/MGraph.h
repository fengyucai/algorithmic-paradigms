#ifndef _MGRAPH_
#define _MGRAPH_
#include <cstdio>

#ifndef _VINFO_
#define _VINFO_

#define MAXV 32 
#define INFI 9999

enum VSTATUS {DIS, UNDIS, VISITED};
enum ESTATUS {TREE, BACKWARD, FORWARD, CROSS};

#endif 

struct Vertex {
    char data;
};

struct MGraph {
    int n, e;  
    int E[MAXV][MAXV]; 
    Vertex V[MAXV];
};

void createMGraph(MGraph* G) {
    FILE* fp = fopen("input.dat", "r");
    int i, j, k, w;
    printf( "正在输入顶点数和边数...\n");
    fscanf(fp, "%d %d", &(G->n), &(G->e));

    printf("正在输入各顶点信息...\n");
    for (i = 0; i < G->n; i++) 
        fscanf(fp, " %c", &(G->V[i].data));
    //初始化邻接矩阵
    for (i = 0; i < G->n; i++)
        for (int j = 0; j < G->n; j++) 
            G->E[i][j] = ((i == j) ? 0 : INFI);
    printf("正在输入i, j, w...\n");
    for (k = 0; k < G->e; k++) {
        fscanf(fp, " %d %d %d", &i, &j, &w);
        G->E[i][j] = w;
    }
}

void printMGraph(MGraph* G) {
    int i, j;
    printf("顶点数: %d, 边数: %d\n", G->n, G->e);
    printf("%d个顶点的信息:\n", G->n);
    for (i = 0; i < G->n; i++)
        printf("v%d:  %c\n", i, G->V[i].data);
    printf("各顶点领接的情况:\n");
    printf("\t");
    for (j = 0; j < G->n; j++)
        printf("[%d]\t", j);
    printf("\n");
    for (i = 0; i < G->n; i++) {
        printf("[%d]\t", i);
        for (j = 0; j < G->n; j++) {
            if (G->E[i][j] == INFI)
                printf("∞\t");
            else
                printf("%d\t", G->E[i][j]);
        }
        printf("\n");
    }
}
#endif
