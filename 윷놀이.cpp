#include<stdio.h>
#include<stdlib.h>
int result=0;
typedef struct g_node
{
	int weight;
	struct g_node * p;
	struct g_node * p2;
}NODE;

NODE * create(int w)
{
	NODE * new_node=(NODE *)calloc(1,sizeof(NODE));
	new_node->weight=w;
	return new_node;
}
void edge(NODE * a,NODE * b)
{
	a->p=b;
}
void edge2(NODE * a,NODE * b)
{
	a->p2=b;
}
void max(NODE * horse1, NODE * horse2,NODE * horse3,NODE * horse4,int cnt,int score,int target,int input[])
{
	if(cnt==10)
	{
		if(score>result)result=score;
		return;
	}
	//printf("(");
	switch(target)
	{
		case 1:
			//printf("(");
			if(horse1->p2==NULL)
			{
				for(int i=0;i<input[cnt];i++)
				{
					if(horse1->p!=NULL)horse1=horse1->p;
				}
				if(horse1==horse2||horse1==horse3||horse1==horse4&&horse1->p!=NULL) return;
			}
			else
			{
				horse1=horse1->p2;
				for(int i=0;i<input[cnt]-1;i++)
				{
					if(horse1->p!=NULL)horse1=horse1->p;
				}
				if(horse1==horse2||horse1==horse3||horse1==horse4&&horse1->p!=NULL) return;
			}
			//printf(")");
			break;
		case 2:
			if(horse2->p2==NULL)
			{
				if(horse2->p!=NULL)
				{
					for(int i=0;i<input[cnt];i++)
					{
						if(horse2->p!=NULL)horse2=horse2->p;
					}
					if(horse2==horse1||horse2==horse3||horse2==horse4&&horse2->p!=NULL) return;
				}
			}
			else
			{
				horse2=horse2->p2;
				for(int i=0;i<input[cnt]-1;i++)
				{
					if(horse2->p!=NULL)horse2=horse2->p;
				}
				if(horse2==horse1||horse2==horse3||horse2==horse4&&horse2->p!=NULL) return;
			}
			break;
		case 3:
			if(horse3->p2==NULL)
			{
				if(horse3->p!=NULL)
				{
					for(int i=0;i<input[cnt];i++)
					{
						if(horse3->p!=NULL)horse3=horse3->p;
					}
					if(horse3==horse1||horse3==horse2||horse3==horse4&&horse3->p!=NULL) return;
				}
			}
			else
			{
				horse3=horse3->p2;
				for(int i=0;i<input[cnt]-1;i++)
				{
					if(horse3->p!=NULL)horse3=horse3->p;
				}
				if(horse3==horse1||horse3==horse2||horse3==horse4&&horse3->p!=NULL) return;
			}
			break;
		case 4:
			if(horse4->p2==NULL)
			{
				if(horse4->p!=NULL)
				{
					for(int i=0;i<input[cnt];i++)
					{
						if(horse4->p!=NULL)horse4=horse4->p;
					}
					if(horse4==horse1||horse4==horse2||horse4==horse3&&horse4->p!=NULL) return;
				}
			}
			else
			{
				horse4=horse4->p2;
				for(int i=0;i<input[cnt]-1;i++)
				{
					if(horse4->p!=NULL)horse4=horse4->p;
				}
				if(horse4==horse1||horse4==horse2||horse4==horse3&&horse4->p!=NULL) return;
			}
			break;	
	}
	//printf(")");
	cnt++;
	//printf("%d %d %d\n",cnt,score,target);
	//printf("(");
	switch(target)
	{
		case 1:
			score+=horse1->weight;
			break;
		case 2:
			score+=horse2->weight;
			break;
		case 3:
			score+=horse3->weight;
			break;
		case 4:
			score+=horse4->weight;
			break;
	}
	//printf(")");
	max(horse1,horse2,horse3,horse4,cnt,score,1,input);
	max(horse1,horse2,horse3,horse4,cnt,score,2,input);
	max(horse1,horse2,horse3,horse4,cnt,score,3,input);
	max(horse1,horse2,horse3,horse4,cnt,score,4,input);
}
int main()
{
	NODE * st=(NODE *)calloc(1,sizeof(NODE)),*fin=(NODE *)calloc(1,sizeof(NODE));
	st->weight=0;fin->weight=0;fin->p=NULL;
	NODE * nodes[31];
	const int weights[31]={2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,13,16,19,22,24,28,27,26,25,30,35,40};
	int input[10]={5,1,2,3,4,5,5,3,2,4};
	for(int i=0;i<10;i++)
	{
		//printf("%d",input[i]);
		scanf("%d",&input[i]);
	}
	for(int i=0;i<31;i++)
	{
		nodes[i]=create(weights[i]);
		if(i>0&&i<19) edge(nodes[i-1],nodes[i]);
	}
	edge(st,nodes[0]);
	edge2(nodes[4],nodes[19]);
	edge(nodes[19],nodes[20]);
	edge(nodes[20],nodes[21]);
	edge(nodes[21],nodes[27]);
	edge2(nodes[9],nodes[22]);
	edge(nodes[22],nodes[23]);
	edge(nodes[23],nodes[27]);
	edge2(nodes[14],nodes[24]);
	edge(nodes[24],nodes[25]);
	edge(nodes[25],nodes[26]);
	edge(nodes[26],nodes[27]);
	edge(nodes[27],nodes[28]);
	edge(nodes[28],nodes[29]);
	edge(nodes[29],nodes[30]);
	edge(nodes[18],nodes[30]);
	edge(nodes[30],fin);
	max(st,st,st,st,0,0,1,input);
	max(st,st,st,st,0,0,2,input);
	max(st,st,st,st,0,0,3,input);
	max(st,st,st,st,0,0,4,input);
	printf("%d",result);
}
