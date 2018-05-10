#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#pragma warning(disable:4996)

//typedef struct Salesview{
//	char item[100];
//	int price;
//	int sellcnt;
//	int salessum;
//}Salesview;
//Salesview contact;
//
//main()
//{
//	Salesview a;
//	FILE *frp1, *frp2;
//	char chkitem[30];
//	int cnt;
//	int i=1;
//	frp1=fopen("item.txt","r");
//	frp2=fopen("sales.txt","r");
//	
//	while(1)
//	{
//		fscanf(frp1,"%s %d",a.item,&a.price);
//		while(1)
//		{
//			fscanf(frp2,"%s %d",chkitem,&cnt);
//			if(strcmp(a.item,chkitem)==0)
//			{	
//				a.sellcnt=cnt;
//				a.salessum=a.price*a.sellcnt;
//				printf("%d\t\t%s\t\t%d\t\t%d\t\t%d\n",i,a.item,a.price,a.sellcnt,a.salessum);
//				i++;
//				break;
//			}
//		}
//		if(feof(frp1)!=0)
//			break;
//	}
//	fclose(frp1);
//	fclose(frp2);
//}


//main()
//{
//	FILE *frp, *fwp;
//	char buff[256];
//	int cnt;
//	int bytechk=0;
//	frp = fopen("1.jpg","rb");
//	fwp = fopen("backup.jpg","wb");
//
//	while(1)
//	{
//		cnt=fread(buff,1,256,frp); // 1바이트짜리 100개 
//		if(cnt<256)
//		{//파일의 끝 or 파일깨짐
//			if(feof(frp)!=0)//파일의 끝 //feof는 파일끝이 아니면 0값리턴
//			{
//				fwrite(buff,1,cnt,fwp);
//				bytechk+=cnt;
//				puts("복사완료");
//			}
//			else
//				puts("복사실패");
//			break;
//		}
//		fwrite(buff,1,256,fwp); // 복사
//		bytechk+=cnt;
//	}
//	printf("크기 : %d byte \n",bytechk);
//}
//main()
//{
//	FILE *fwp;
//	int a;
//	char b;
//	char c[30];
//
//	fwp = fopen("a.txt","w");
//	fprintf(fwp,"%d %c %s\n",1,'a',"BBB");
//	fclose(fwp);
//
//
//
//	fwp = fopen("a.txt","r+");
//	fprintf(fwp,"%d" ,7);
//	fclose(fwp);
//
//	fwp=fopen("a.txt","r");
//	fscanf(fwp,"%d %c %s", &a,&b,&c);
//	fclose(fwp);
//
//	fprintf(stdout,"%d %c %s\n",a,b,c);
//	printf("%d %c %s\n",a,b,c);
//}
//struct subject{
//	int subname[5]; // 국 , 영, 수, 총, 랭
//};
//struct sung{
//	char name[10];
//	float avg; //평균
//	struct subject sub;
//};
//
//void sum(struct sung *p)
//{
//	int i,j;
//	int sum=0;
//	for(i=0;i<3;i++)
//	{
//		for(j=0;j<3;j++)
//		{
//			sum+=(p+i)->sub.subname[j];
//		}
//		(p+i)->sub.subname[3]=sum;
//		sum=0;
//	}
//	
//}
//void avg(struct sung *p)
//{
//	int i;
//	for(i=0;i<3;i++)
//	{
//		p[i].avg=(float)p[i].sub.subname[3]/3;
//	}
//}
//void sort(struct sung *p)
//{
//	//순위값을 1로 전부 초기화하고 하나씩 비교하여 +1씩한다.
//}
//main()
//{
//	int i,j;
//	struct sung man[3];
//	struct sung *p;
//	p=man;
//	for(i=0;i<3;i++)
//	{
//		
//		printf("%d번째 사람이름 : ",i+1);
//		gets(man[i].name);
//		j=0;
//		printf("국어점수 : ");
//		scanf("%d",&(man[i].sub.subname[j]));
//		printf("영어점수 : ");
//		scanf("%d",&(man[i].sub.subname[j+1]));
//		printf("수학점수 : ");
//		scanf("%d",&(man[i].sub.subname[j+2]));
//		getchar();
//	}
//	sum(p);
//	avg(man);
//	printf("성명\t국어\t영어\t수학\t총점\t평균\t순위\n");
//	printf("----------------------------------------------------\n");
//
//	for(i=0;i<3;i++)
//	{
//		printf("%s\t",&(man[i].name));
//		for(j=0;j<4;j++)
//		{
//			printf("%d\t",man[i].sub.subname[j]);
//		}
//		printf("%.2f",man[i].avg);
//		printf("\n");
//	}
//
//}
//
//union num{
//	int a;
//	char b[4];
//};
//
//main()
//{
//	union num zz;
//	zz.a=0x12345678;
//
//	printf("%x\n",zz.b[0]);
//}

//struct num{
//	int fir;
//	int sec;
//};
//
//int func1(int a, int b)  //합
//{
//	return a+b;
//}
//int func2(struct num *p) //곱
//{
//	return p->fir*p->sec;
//}
//int func3(struct num *p) //합
//{
//	return p->fir  + p->sec + (p+1)->fir  + (p+1)->sec;
//}
//main()
//{
//	int result;
//	struct num a={1,2},b={3,4},c[2]={5,6,7,8};
//	result=func1(a.fir,a.sec);
//	printf("%d %d %d \n ",result,func2(&b),func3(c));
//
//}
//main()
//{
//	int strcnt;
//	char **p;
//	int i;
//	char buff[100];
//	printf("원하는 문장의 갯수를 입력하세요 : ");
//	scanf("%d",&strcnt);
//	getchar(); // scanf 의 엔터를 gets가 먹기때문에  사용
//	p=(char **)malloc(strcnt*sizeof(char*));
//	for(i=0;i<strcnt;i++)
//	{	
//		printf("%d번째 문장입력 : ",i+1);
//		p[i]=(char *)malloc(sizeof(char)*strlen(buff)+1);
//		gets(p[i]);
//		//strcpy(p[i],buff);
//	}
//	for(i=0;i<strcnt;i++)
//	{
//		printf("%d번째 문장출력 : ",i+1);
//		printf("%s \n",p[i]);
//	}
//	for(i=0;i<strcnt;i++)
//		free(p[i]);
//	free(p);
//}
//자신의 주소를 입력받아서
//주소 길이만큼 동적할당하고
//해당영역에 주소를 넣어 출력해보자

//main()
//{
//	char a[100];
//	char *p;
//	int len;
//	gets(a);
//	//scanf("%s",a);
//	printf("%s\n",a);
//	len=strlen(a);
//	p=(char*)malloc(len*sizeof(char)+1); //string 은 마지막에 null공간이 필요하므로 +1을 해줘야함
//	strcpy(p,a);
//	printf("%s\n",p);
//	free(p); // 무조건해야함
//	
//}
//main()
//{
//	char amessage[]="now is the time";
//	char *pmessage ="now is the time";
//
//	amessage[0]='h';
//	*(pmessage+1)='h';
//	printf("%s \n",amessage);
//	printf("%s \n",pmessage);
//}

//#define square(x) (x)*(x)
////25/square(5) = 1  이 되도록 square 매크로 작성
//
//#define PR(x) printf("%d \n",x)
////PR(x)    x값을 출력하는 PR 매크로 함수 작성
//
//#define ABS(x) (x<0)? (x*-1):x
////절대값   을 출력해주는 매크로 작성
//
//#define THREE_MAX(a,b,c) (a>b)? (a>c)? a:c : (b>c)?b:c  //(a>b)? ((a>c)? a:c) : (b>c)?b:c
////최대값 (three_max)   3개의 값중 가장 큰 값을 출력하는 매크로 작성
//
//#define SWAP(x,y) do{int t; t=x; x=y; y=t;}while(0)
//
//main()
//{
//	int sq=6;
//	int a=10, b=5;
//	printf("%d \n",25/(square(sq)));
//	PR(sq);
//	printf("%d \n",ABS(sq));
//
//	if(sq>5)
//		SWAP(a,b);
//	else
//		SWAP(a,sq);
//
//	printf("%d %d\n",a,b);
//}
//








//alt + f7 // 구성속성//디버깅//명령인수란에 쓰기

//void func1(void){ puts("func1"); }
//void func2(void){ puts("func2"); }
//void func3(void){ puts("func3"); }
//void func4(void){ puts("func4"); }
//
//#define call(x) func##x
//
//main()
//{
//	int dx;
//	for(dx=1;dx<5;dx++)
//		call(dx)(); //funcdx();
//}


//int add(int a, int b){return a+b;}
//int sub(int a, int b){return a-b;}
//int mul(int a, int b){return a*b;}
//int divv(int a, int b){return a/b;}
//main()
//{
//	int sel;
//	int a=10,b=5;
//	int dex;
//	void *arr[5][2]={{add,"ADDITION"},{sub,"SUBTRACION"},{mul,"MULTIPLY"},{divv,"DIVIDE"},{0,"0"}};
//	printf("/* 계산..0
//		기0 프로그램 */\n");
//	for(dex=0;dex<5;dex++)
//		printf("%d. %s\n",dex+1,(char*)arr[dex][1]);
//	printf("번호를 선택하세요 : ");
//	scanf("%d",&sel); //3 p[2][0] : mul
//	
//	printf("결과는 %d \n",((int(*)(int,int))arr[sel-1][0])(a,b));
//}

//main()
//{
//	char a[]="sun";
//	void *p;
//	p=a;
//	printf("%c\n",*(char*)p);
//}
//
//









//main()
//{
//	char a='A';
//	int b;
//	float c;
//	double d;
//	b=(int)a;
//	c=(float)b;
//	d=(double)c;
//	
//	printf("%lf\n",d);
//}





//int add(int a, int b)
//{
//	return a+b;
//}
//int sub(int a, int b)
//{
//	return a-b;
//}
//
//int temp(int(*p_func)(int,int),int a,int b)
//{
//	return p_func(a,b);
//}
//
//void main()
//{
//	int a=10, b=5;
//	
//
//
//	printf("%d\n",temp(add,a,b));
//
//	
//	printf("%d\n",temp(sub,a,b));
//}





//int mul(int a, int b)
//{
//	return a*b;
//}
//int dvv(int a, int b)
//{
//	return a/b;
//}
//typedef unsigned int unit;
//typedef int (*myfb)(int,int);
//
//typdef (int*p){int{
//main()
//{
//	int (*p[4])(int, int)={add,sub,mul,dvv};
//	int dx;
//
//	for(dx=0;dx<4;dx++)
//		printf("%d\n",p[dx](1,2));
//}
//



//int main(int argc, char **argv)
//{
//	int a, b;
//
//	a=atoi(argv[1]);
//	b=atoi(argv[3]);
//	
//	
//	switch(argv[2][0])
//	{
//	case '+':
//		printf("%d + %d = %d\n",a,b,a+b);
//		break;
//	} 
//	return 0;
//}
//





//
//void connect(int *pa,int **pp)
//{
//	*pp=pa;
//}
//
//main()
//{
//	int a=77;
//	int *p;
//
//	connect(&a,&p);
//	printf("%d\n",*p); //77
//}


//void arr2d(int (*p)[3])
//{
//	p[0][1]=3;
//}
//
//void arr1d(int *p)
//{
//	p[2]=5;
//}
//
//main()
//{
//	int a[2][3];
//	arr2d(a);
//	printf("%d\n",a[0][1]);
//	arr1d(a[0]);
//	printf("%d\n",a[0][2]);
//}

//char mystrcpy(char *d, const char *s)
//{
//	while(*d++=*s++); //null까지 복사후 그것을 거짓처리
//}
//
//int mystrlen(char *s)
//{
//	char *wk=s;
//	while(*wk)
//		*wk++;
//	return wk-s;
//}
//
//char mystrcat(char *d, char *a)
//{
//	char *save=d;
//	while(*d)
//		d++;
//	while(*d++=*a++);
//	return save;
//}
//
//main()
//{
//	char d[100];
//	char s[]="abc";
//	mystrcpy(d,s);
//	puts(d);
//}
