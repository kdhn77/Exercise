#include <stdio.h>
#include <stdlib.h>

void input_value(int **matrix,int setnum)
{
	int row=0,col=-1,s=1;
	int i;
	int size=0,num=0;
	
	size=setnum; 
	num=size*size;

	while(size!=0) //사이즈가 0이 아닐때까지
	{
		for(i=0;i<size;i++) //가로(열) 숫자입력
		{
			col=col+s;
			matrix[row][col]=num;
			num--;
		}
		size--; //가로에서 세로로 바뀔때 사이즈 감소
		for(i=0;i<size;i++) //세로(행) 숫자입력
		{
			row=row+s;
			matrix[row][col]=num;
			num--;
		}함
		s=s*-1; //1씩 증가하던 좌표를 1씩 감소하도록 
	}
}
void print_value(int **matrix,int setnum)
{
	int i,j;
	for(i=0;i<setnum;i++)
	{
		for(j=0;j<setnum;j++)
		{
			printf("%4d ",matrix[i][j]);
		}
		printf("\n");
	}
}



int main(void)
{
	int setnum,i;
	int **matrix;
	printf("배열의 크기 : ");
	scanf("%d",&setnum);
	printf("%d * %d \n",setnum,setnum);

	matrix=(int**)malloc(sizeof(int*)*setnum);
	//이중 포인터에 (int 포인터크기 * setnum)만큼 행할당
	for(i=0;i<setnum;i++)
	{
		matrix[i]=(int*)malloc(sizeof(int)*setnum);
	//생성한 이중 포인터에 (int 포인터크기 * setnum)만큼 열할당
	}
	input_value(matrix,setnum);
	print_value(matrix,setnum);

	for(i=0;i<setnum;i++)
	{
		free(matrix[i]);
	}
	free(matrix);

	return 0;
}

