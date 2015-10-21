#include "head.h"
#include <stdlib.h>

#define InitSize 100
#define Increment 10

typedef int ElemType;

typedef struct {
  ElemType *elem;// base address
  int length;//current real length
  int listsize;//current malloc length
}SqList;

Status InitList(SqList L) {
  L.elem = (ElemType *)malloc(InitSize * sizeof(ElemType));
  if (!L.elem)
    exit(OVERFLOW);
  L.length = 0;
  L.listsize = InitSize;
  return OK;
}

Status ListInsert(SqList L, int i, ElemType e) {
  if (i<1 || i>L.length+1)// insert range from 1 to n+1
    return ERROR;
  ElemType *newbase;
  ElemType *q;
  ElemType *p;
  if (L.length >= L.listsize) {
    newbase = (ElemType *)realloc(L.elem,
      (L.listsize + Increment)*sizeof(ElemType));
    if(!newbase)
      exit(OVERFLOW);
    L.elem = newbase;
    L.listsize += Increment;
  }
  q = &(L.elem[i-1]);
  for(p = &(L.elem[L.length-1]); p>= q; --p)
    *(p+1) = *p;
  *q = e;
  ++L.length;
  return OK;
}

