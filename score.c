int main(void)
{
	int i;
	struct score student[STUDENT];
	srand(time(NULL));
	for(i=0;i<STUDENT;i++)
	{
		//name
		student[i].name[0]=(rand()%26)+65;		
		//kor
		//srand(time(NULL));
		student[i].kor=(rand()%100)+1;
		//eng
		//srand(time(NULL));
		student[i].eng=(rand()%100)+1;
		//math
		//srand(time(NULL));
		student[i].math=(rand()%100)+1;
		//jpn
		//srand(time(NULL));
		student[i].jpn=(rand()%100)+1;
		//total
		student[i].total=student[i].kor+student[i].eng+student[i].math+student[i].jpn;
		//avg
		student[i].avg=(float)student[i].total/STUDENT;
	}
#ifdef DEBUG
	for(i=0;i<STUDENT;i++)
	{
		printf("student : %c /kor : %d /eng : %d /math : %d /jpn : %d /total : %d /avg : %.4f \n",student[i].name[0],student[i].kor,student[i].eng,student[i].math,student[i].jpn,student[i].total,student[i].avg);
	}
#endif
	return 0;
}
