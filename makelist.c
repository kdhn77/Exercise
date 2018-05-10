#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define swap(a,b) do{char t[7]; strcpy(t,a);strcpy(a,b);strcpy(b,t);}while(0)

//어떤값이 입력되든지 4의 배수 형태로 출력
//0 1 2 3 4 5 6 7 8 9 ....
//0 4 4 4 4 8 8 8 8 12......
main()
{
	int a;
	printf("숫자입력 : ");
	scanf("%d",&a);
	
	printf("-> %d \n",(a+3)&(0xffff)<<2);
}
// 입력된수의 n번째 비트부터 w개만큼 십진수로출력
//main()
//{
//	int a,n,w;
//	int r;
//	printf("십진수 입력: "); //684
//	scanf("%d",&a);
//	printf("n수 입력 : ");
//	scanf("%d",&n);
//	printf("w수 입력 : ");
//	scanf("%d",&w);
//	r=(a>>n)&(~(0xffff<<w));
//	printf("%d \n",r);
//}

//
//main()
//{
//	short int a = 0x1234;
//	short int b = ((x&0xff)<<8)|((x>>8)&0xff);
//
//
//	printf("x%",b);
//}


//main()
//{
//	int a=0xA5;
//	if(a&(1<<6))//if(a&0x40) // if(a&64)  //마스크
//		puts("true");
//	else
//		puts("false");
//	
//	printf("%x \n",a|(1<<3)+(1<<1));//printf("%x \n",a|0xa);//printf("%x \n",a|10);  //set
//	
//	a&=~((1<<2)+(1<<1));//(0x6);  //clear
//	printf("%x \n",a);
//
//	a=a&0xE0; 
//	printf("%x \n",a);
//}
//double linked list를 만들자
//typedef struct _dnode Dnode;
//struct _dnode{
//	int key;
//	struct _dnode *prev;
//	struct _dnode *next;
//};
//
//Dnode *head, *tail;
//
//void init_dnode()
//{
//	head=(Dnode*)malloc(sizeof(Dnode));
//	tail=(Dnode*)malloc(sizeof(Dnode));
//
//	head->next=tail;
//	head->prev=head;
//	tail->prev=head;
//	tail->next=tail;
//}
//void order_insert_dnode(int data)
//{
//	Dnode *s,*nw;
//	s=head->next;
//	while(s->key<=data && s!=tail)
//		s=s->next;
//	nw=(Dnode*)malloc(sizeof(Dnode));
//	nw->key=data;
//
//	s->prev->next=nw;
//	nw->prev=s->prev;
//	nw->next=s;
//	s->prev=nw;
//}
//
//void print_node_next()
//{
//	Dnode *m;
//	m=head->next;
//	while(m!=tail)
//	{
//		printf("[%d] ",m->key);
//		m=m->next;
//	}
//}
//void print_node_prev()
//{
//	Dnode *m;
//	m=tail->prev;
//	while(m!=head)
//	{
//		printf("[%d] ",m->key);
//		m=m->prev;
//	}
//}
//main()
//{
//	init_dnode(); // 더블링크의 초기화 (빨래기둥)
//
//	order_insert_dnode(3);
//	order_insert_dnode(4);
//	order_insert_dnode(1);
//	order_insert_dnode(5);
//	order_insert_dnode(2);
//
//	print_node_next();  //head ->tail 출력
//	printf("\n");
//	print_node_prev(); //tail->head 출력
//	printf("\n");
//}
////1. 라이브러리 제공하는 qsort를 위한 comp_d 함수 완성
////2. 라이브러리 제공하는 qsort를 위한 comp_s 함수 완성
////3. 라이브러리 qsort를 이용하여 2차원배열에 있는 문자열을 정렬합시다.
//
//#include <stdio.h>
//#include <stdlib.h>
//
//void printInt(int *arr, int size);
//void printDbl(double *arr, int size);
//void printstr(double (*arr)[10], int size);
//
//int comp_i(const void* a, const void* b) {
//	return (*(int*)a - *(int*)b);
//}
//
////라이브러리 제공하는 qsort를 위한 comp_d 함수 완성
//int comp_d(const void* a, const void* b) {
//
//	if(*(double*)a>*(double*)b)
//		return 1;
//	else if (*(double*)a<*(double*)b)
//		return -1;
//	else
//		return 0;
//}
//
////라이브러리 제공하는 qsort를 위한 comp_s 함수 완성
//int comp_s(const void* a, const void* b) {
//	return strcmp((char*)a,(char*)b);
//}
//
//
//
//
//int main(void) {
//	int arri[]= { 3,4,1,5,2,8,9,6,10,7 };
//	double arrd[] = { 3.2, 5.6, 4.3, 8.7, 2.3, 4.5, 2.1, 2.3, 4.6, 4.5};
//	char name[][7]={"김도환","김주홍","김중근","정지윤","한태승",
//		"문태승","박정효","백경규","서재학","송은아",
//		"오유준","이무원","김용석","김용환","허승회",
//		"유승훈"};
//
//	qsort(arri, sizeof(arri)/sizeof(arri[0]), sizeof(int), comp_i);
//	printInt(arri, sizeof(arri)/sizeof(arri[0]));
//
//	qsort(arrd, sizeof(arrd)/sizeof(arrd[0]), sizeof(double), comp_d);
//	printDbl(arrd, sizeof(arrd)/sizeof(arrd[0]));
//
//	//라이브러리 qsort를 이용하여 2차원배열에 있는 문자열을 정렬합시다.
//
//	qsort(name, sizeof(name)/sizeof(name[0]), sizeof(name[0]), comp_s);
//	printstr(name, sizeof(name)/sizeof(name[0]));
//
//	return 0;
//}
//void printInt(int *arr, int size) {
//	int dx=0;
//	for (dx=0; dx< size; ++dx) {
//		printf("%d ", arr[dx]);
//	}
//	printf("\n");
//}
//
//void printDbl(double *arr, int size) {
//	int dx=0;
//	for (dx=0; dx< size; ++dx) {
//		printf("%.1f  ", arr[dx]);
//	}
//	printf("\n");
//}
//
//void printstr(char (*arr)[7], int size) {
//	int dx=0;
//	for (dx=0; dx< size; ++dx) {
//		printf("%s ", arr[dx]);
//	}
//	printf("\n");
//}
//

//int partition(char (*arr)[7], int s, int e) 
//{ 
//	int big, small;
//	char pivot[7]; 
//	big = s; 
//	small = e + 1; 
//	strcpy(pivot,arr[big]); 
//	while(big < small)
//	{
//
//		//pivot보다 큰값을 찾는 구문
//		while(strcmp(arr[++big],pivot)<=0);
//		//pivot 보다 작거나 같은 값을 찾는 구문
//		while(strcmp(arr[--small],pivot)>0);
//
//		if(big < small){
//			swap(arr[big], arr[small]); 
//		}
//	} 
//	swap(arr[s], arr[small]);
//	return small; 
//} 
//void myqsort(char (*arr)[7], int s, int e) 
//{ 
//	int mid; 
//	if(s < e)
//	{ 
//		mid = partition(arr, s, e); 
//		myqsort(arr, s, mid - 1); 
//		myqsort(arr, mid + 1, e); 
//	} 
//}
//
//main()
//{
// //int arri[]= { 3,4,1,5,2,8,9,6,10,7 };
// //int dx;
//
// //myqsort(arri,0,9); //첫인덱스, 마지막인덱스
//
// //for(dx=0;dx<10;dx++)
//	// printf("%d ",arri[dx]);
//
//
// char a[][7]={"이무원","김용석","김용환","김주홍","김중근",
//			"문태승","박정효","백경규","서재학","송은아",
//			"오유준","김도환","정지윤","한태승","허승회",
//			"유승훈"};
//	//int b[]={3,4,1,5,2};
//	int dx;
//	myqsort(a,0,15);
//	for(dx=0;dx<16;dx++)
//		printf("%s\n ",a[dx]);
//
//	qsort(
//}



//void sort(char (*a)[7], int n)
//{
//	char t[7];
//	int i, j;
//	for (i = 1; i < n; i++) //삽입정렬
//	{
//		strcpy(t,a[i]); //t = a[i];  
//		j = i;
//		while (strcmp(a[j-1],t)>0 && j > 0)
//		{
//			strcpy(a[j],a[j-1]);
//			j--;
//		}
//		strcpy(a[j],t);
//	}
//}
//
//main()
//{
//	char a[][7]={"이무원","김용석","김용환","김주홍","김중근",
//			"문태승","박정효","백경규","서재학","송은아",
//			"오유준","김도환","정지윤","한태승","허승회",
//			"유승훈"};
//	//int b[]={3,4,1,5,2};
//	int dx;
//	sort(a,sizeof(a)/sizeof(a[0]));
//	for(dx=0;dx<16;dx++)
//		printf("%s\n ",a[dx]);
//}

//struct engine {
//	int piston;
//	int fan;
//	int pipe;
//};
//
//struct car {
//	struct engine *sedan, *sports;
//};
//
//void hyundai(struct car *man)
//{
//	struct engine *p=man->sedan;
//	p->piston=50;
//	p->fan=30;
//	p->pipe=20;
//}
//
//void main()
//{
//	struct car hi;
//	hi.sedan=(struct engine*)malloc(sizeof(struct engine));
//	hyundai(&hi);
//
//	printf("%d %d %d \n", hi.sedan->piston,hi.sedan->fan,hi.sedan->pipe);
//}
