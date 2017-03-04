#include <cstdio>
#include <algorithm>
using namespace std;
 
const int NUM_MAX = 100000;
int N, M, query;
 
struct NODE{
    int g, m, p, id, way, rank, crank;
    double gp, mp;
};
NODE node[NUM_MAX], node1[NUM_MAX];
 
int cmp(const void * a, const void * b) {
    return (*(NODE *)a).id > (*(NODE *)b).id ? 1:-1;
}
int cmp1(const void * a, const void * b) {
    return (*(NODE *)a).g < (*(NODE *)b).g ? 1:-1;
}
int cmp2(const void * a, const void * b) {
    return (*(NODE *)a).m < (*(NODE *)b).m ? 1:-1;
}
int cmp3(const void * a, const void * b) {
    return (*(NODE *)a).gp < (*(NODE *)b).gp ? 1:-1;
}
int cmp4(const void * a, const void * b) {
    return (*(NODE *)a).mp < (*(NODE *)b).mp ? 1:-1;
}
 
void Rank1() {
    node[0].crank = 1;
    if(node[0].rank > 1) {
        node[0].rank = 1;
        node[0].way = 1;
    }
    for(int i=1; i<M; i++) {
        if(node[i].g == node[i-1].g) {
            node[i].crank = node[i-1].crank;
        }else {
            node[i].crank = i + 1;
        }
        if(node[i].crank < node[i].rank) {
            node[i].rank = node[i].crank;
            node[i].way = 1;
        }
    }
}
void Rank2() {
    node[0].crank = 1;
    if(node[0].rank > 1) {
        node[0].rank = 1;
        node[0].way = 2;
    }
    for(int i=1; i<M; i++) {
        if(node[i].m == node[i-1].m) {
            node[i].crank = node[i-1].crank;
        }else {
            node[i].crank = i + 1;
        }
        if(node[i].crank < node[i].rank) {
            node[i].rank = node[i].crank;
            node[i].way = 2;
        }
    }
}
void Rank3() {
    node[0].crank = 1;
    if(node[0].rank > 1) {
        node[0].rank = 1;
        node[0].way = 3;
    }
    for(int i=1; i<M; i++) {
        if(node[i].gp == node[i-1].gp) {
            node[i].crank = node[i-1].crank;
        }else {
            node[i].crank = i + 1;
        }
        if(node[i].crank < node[i].rank) {
            node[i].rank = node[i].crank;
            node[i].way = 3;
        }
    }
}
void Rank4() {
    node[0].crank = 1;
    if(node[0].rank > 1) {
        node[0].rank = 1;
        node[0].way = 4;
    }
    for(int i=1; i<M; i++) {
        if(node[i].mp == node[i-1].mp) {
            node[i].crank = node[i-1].crank;
        }else {
            node[i].crank = i + 1;
        }
        if(node[i].crank < node[i].rank) {
            node[i].rank = node[i].crank;
            node[i].way = 4;
        }
    }
}
 
void RankAll() {
    qsort(node, M, sizeof(node[0]), cmp1);
    Rank1();
    qsort(node, M, sizeof(node[0]), cmp2);
    Rank2();
    qsort(node, M, sizeof(node[0]), cmp3);
    Rank3();
    qsort(node, M, sizeof(node[0]), cmp4);
    Rank4();
    qsort(node, M, sizeof(node[0]), cmp);
}
 
int main() {
    while(scanf("%d %d", &N, &M) == 2) {
        for (int i = 0; i<N; i++) {
            scanf("%d %d %d", &node1[i].g, &node1[i].m, &node1[i].p);
            node1[i].id = i;
            node1[i].gp = (double)node1[i].g / node1[i].p;
            node1[i].mp = (double)node1[i].m / node1[i].p;
        }
        for(int i = 0; i < M; i++) {
            scanf("%d", &query);
            node[i].g = node1[query].g;
            node[i].m = node1[query].m;
            node[i].gp = node1[query].gp;
            node[i].mp = node1[query].mp;
            node[i].rank = NUM_MAX + 1;
            node[i].id = i;
        }
        RankAll();
        for (int i = 0; i<M; i++) {
            printf("%d:%d\n",node[i].rank, node[i].way);
        }
        printf("\n");
    }
    return 0;
}