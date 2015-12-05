#ifndef _AGRAPH_
#define _AGRAPH_

#ifndef _VINFO_
#define _VINFO_

#define MAXV 5
#define INFI 9999

enum VSTATUS {DIS, UNDIS, VISITED};

#endif


struct ArcNode {
    int adjvex;
    int weight;
    struct ArcNode* nextarc;
};

struct VNode {
    char data;
    struct ArcNode* firstarc;
};

struct AGraph {
    int n, e;
    VNode adjlist[MAXV];
};

#endif
