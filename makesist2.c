#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>


struct _node{
	int key;
	struct _node *next;
};
typedef struct _node Node;
Node *head, *tail;//양쪽 빨래기둥
//모든 자료구조는 초기화가 있다.
void init_Node(void)
{
	head = (Node *)malloc(sizeof(Node));
	tail = (Node *)malloc(sizeof(Node));
	head->next=tail;
	tail->next=tail;
}

void ordered_insert(int data)
{
	Node *s,*p,*nw;    //search 찾는위치 포인터 pre s의 앞포인터
	p=head;
	s=p->next;
	while(s!=tail && s->key<=data)
	{
		p=p->next;
		s=p->next;
	}
	nw=(Node*)malloc(sizeof(Node));
	nw->key=data;
	p->next=nw;
	nw->next=s;
}
int find_data(int data)
{
	Node *s,*p;
	p=head;
	s=p->next;
	while(s->key!=data&&s!=tail)
	{
		p=p->next;
		s=p->next;
	}
	if(s->key==data)
		return 1;
	else
		return 0;
}
void printout_node()
{
	Node *p=(Node*)malloc(sizeof(Node));
	p=head->next;
	while(p!=tail)
	{
		printf("[%d] ",p->key);
		p=p->next;
	}
	//free(p);
}
int count_node()
{
	int cnt=0;
	Node *p=(Node*)malloc(sizeof(Node));
	p=head->next;
	while(p!=tail)
	{
		p=p->next;
		cnt++;
	}
	//free(p);
	return cnt;
}
void MovetoFront(int data)
{
	Node *s,*p;
	p=head;
	s=p->next;
	while(s->key!=data&&s!=tail)
	{
		p=p->next;
		s=p->next;
	}
	if(s->key==data)
	{
		p->next=s->next;
		s->next=head->next;
		head->next=s;
	}
}
void change_node(int data)
{
	Node *s,*p, *pp;
	pp=head;
	p=pp->next;
	s=p->next;
	if(p->key==data)
		return;
	while(s->key!=data &&s!=tail)
	{
		pp=pp->next;
		p=pp->next;
		s=p->next;
	}
	if(s->key==data)
	{
		//printf("14");
		p->next=s->next;
		pp->next=s;
		s->next=p;
	}
}

main()
{
	int data=0;
	int cnt;
	init_Node();
	srand(time(NULL));
	while(1)
	{
		system("cls");
		if(cnt=count_node()==10)
		{
			printf("완성되었습니다!\n출력 : ");
			printout_node();
			printf("\n");
			break;
		}
		
		data=(rand()%10)+1;
		printf("%d\n",data);
		Sleep(1);
		if(find_data(data)!=1)
		{
			ordered_insert(data);


			printout_node();
		}
		else
			printf("중복입니다.\n");
		

		
	}
	while(1)
	{
		printf("맨 앞쪽으로 옮겨야하는 정보를 입력하시오 : ");
		scanf("%d",&data);
		MovetoFront(data);
		printout_node();
		printf("\n");
		printf("앞노드와 바꿔야 하는 정보를 입력하시오 : ");
		scanf("%d",&data);
		change_node(data);
		printout_node();
		printf("\n");
	}

}







//void init_Node(void)
//{
//	head = (Node *)malloc(sizeof(Node));  //빨래기둥박기
//	tail = (Node *)malloc(sizeof(Node));
//	head->next=tail; //빨래줄연결
//	tail->next=tail; //끝에 넘어서는 동작을 막음
//}
//void insert_Node(int data)
//{
//	Node *nw = (Node *)malloc(sizeof(Node));
//	nw->key=data; //3
//
//	nw->next=head->next; //헤드가보고있던 주소를 줌
//	head->next=nw; //헤드가 new를 가리키게 함
//}
//void delete_Node(Node *prev)
//{
//	Node *kill=prev->next;
//	prev->next=kill->next;
//	free(kill);
//}
//Node* find_Node(int data) //2
//{
//	Node *link,*find;  //주소를 가리킬 노드와 찾을 노드
//	link=head;
//	find=link->next;
//
//	while(find->key != data && find!=tail) //못찾았다면 뒤로 한칸씩 간다.
//	{
//		link=link->next;
//		find=link->next; //find->next
//	}
//	if(find!=tail)
//		puts("찾았다");
//	return link;
//}
//void view_Node(void) //head 와 tail을 제외한 빨래만 보기
//{
//	Node *wk=head->next;//첫번째 노드의 주소를 받음
//	while(wk!=tail)
//	{
//		printf("%d\n",wk->key);
//		wk=wk->next;
//	}
//	//printf("%d\n",wk->key);
//	/*printf("%d\n",head->next->key);
//	printf("%d\n",head->next->next->key);*/
//}
//void ordered_insert_Node(int data)
//{
//	Node *nw = (Node *)malloc(sizeof(Node));
//	Node *p,*s;
//	p=head;
//	s=p->next;
//	while(s->key<=data && s!=tail)
//	{
//		p=p->next;
//		s=p->next; //쌍쌍으로 옆으로 옮김
//	}
//	//위치를 찾았으면 넣기
//	//Node *nw = (Node *)malloc(sizeof(Node));
//	nw->key=data;
//	p->next=nw;
//	nw->next=s;
//}
//main()
//{
//	Node *prev;
//	init_Node(); //연결리스트 초기화
//	
//	ordered_insert_Node(3);
//	ordered_insert_Node(4);
//	ordered_insert_Node(1);
//	ordered_insert_Node(5);
//	ordered_insert_Node(2);
//	
//	view_Node();
//	//insert_Node(3); //첫번째 거는빨래
//	//insert_Node(2);
//	//view_Node();
//
//	//prev=find_Node(3);
//	//	if(prev->next!=tail)
//	//		delete_Node(prev); //넘겨준 노드의 뒷노드를 삭제
//	//view_Node();
//	//
//}
//
//void Alarusse(int a, int b)
//{
//	int c=0;
//	while(a>0)
//	{
//		if(a&1)
//			c+=b;
//		a=a>>1;
//		b=b<<1;
//	}
//	printf("%d\n",c);
//}
//
//void Uf(int a, int b)
//{
//	int tmp;
//	while(b!=0)
//	{
//		a=a%b;
//		tmp=a;
//		a=b;
//		b=tmp;
//		/*if(a==0)
//		break;*/
//	}
//	printf("%d\n",a);
//}
//
//main()
//{
//	Alarusse(27,65);
//	Uf(220,37);
//}
//main()
//{
//	int i,rand_num;
//	srand(time(NULL));
//	for(i=0;i<10;i++)
//	{
//		rand_num=rand();
//		printf("[%d]",rand_num);
//	}
//}
