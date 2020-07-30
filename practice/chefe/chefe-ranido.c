#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 1000000
#define INF (10001)

typedef enum {False,True} Boolean;
typedef struct adjnode adjnode;
typedef adjnode *adjnodeP;
struct adjnode {
  int idx;
  adjnodeP next;
};

typedef struct {
  int age;
  adjnode *adj;
} emplT;

typedef struct {
  int age,id;
} agesT;

int ancestor_age[MAX],id2idx[MAX],idx2id[MAX];
int N,M,Q,E;
emplT empl[MAX];
agesT ages[MAX];

int mycomp(const void *m, const void *n) {
  agesT *p,*q;
  p=(agesT *) m;
  q=(agesT *) n;
  return p->age - q->age;
}

void process(void) {
  int i,k,n,id;
  int set[MAX],nset;
  adjnodeP p;

  memset(ancestor_age,-1,N*sizeof(int));
  i=0;n=N;
  while (n>0) {
    id=ages[i].id;
    while (ancestor_age[id]!=-1) {
      i++;
      id=ages[i].id;
    }
    ancestor_age[id]=0;
    n--;
    i++;
    set[0]=id2idx[id];
    nset=1;
    while (nset>0) {
      nset--;
      p=empl[set[nset]].adj;
      while (p!=NULL) {
	k=p->idx;
	k=idx2id[k];
	if (ancestor_age[k]==-1) {
	  ancestor_age[k]=empl[id].age;
	  n--;
	  set[nset++]=p->idx;  // insert in set
	}
	else if (ancestor_age[k]==0) {
	  ancestor_age[k]=empl[id].age;
	}
	p=p->next;
      }
    }
  }
}

int main(void) {
  int i,q,x,y,changed,a,b,tmp;
  char instr;
  adjnodeP new;

  while (scanf("%d %d %d",&N,&M,&Q)==3) {
    for (i=0;i<N;i++) {
      scanf("%d",&empl[i].age);
      ages[i].age=empl[i].age;
      ages[i].id=i;
      empl[i].adj=NULL;
      id2idx[i]=i;
      idx2id[i]=i;
    }
    qsort(ages, N, sizeof(agesT), mycomp);
    for (i=0;i<M;i++) {
      scanf("%d %d\n", &x,&y);
      x--;y--;
      new=(adjnodeP)malloc(sizeof(struct adjnode));
      new->idx=y;
      new->next=empl[x].adj;
      empl[x].adj=new;
    }
    changed=True;
    for (q=0;q<Q;q++) {
      scanf("%c",&instr);
      if (instr=='T') {
	changed=True;
	scanf("%d %d\n",&a,&b);
	a--; b--;
	tmp=id2idx[a];
	id2idx[a]=id2idx[b];
	id2idx[b]=tmp;
	idx2id[id2idx[a]]=a;
	idx2id[id2idx[b]]=b;
      }
      else {
	if (changed) {
	  process();
	  changed=False;
	}
	scanf("%d\n",&E);
	E--;
	if (ancestor_age[E]==0)
	  printf("*\n");
	else
	  printf("%d\n",ancestor_age[E]);
      }
    }
  }
  return 0;
}
