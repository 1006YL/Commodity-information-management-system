/**************************************************************************************

		�༶���������ѧ�뼼�� <1> ��
		
		��������ٽ�
		
		��ţ�38
		
		ѧ�ţ�1720502149
		
	���㣺1����������������ÿ�ΰ��س��� 
		  2�������빦�ܣ����޸ģ�����ܱ���Ϊ�ļ��� 
		  3��ҳ��ֻ��һ�棬���������鿴���ϲ�ֻ��ʾ��Ʒ��Ϣ����ʾ��Ϣֻ��ʾ���²� 
		  4��ѡ�����ܣ�ֱ�������ƶ�ѡ�������������ɾ�����޸ġ�������ͳ�ƣ�
		  5���������ܼ���ȷ��ģ��Ϊһ�壬�ɶ༶��ѯ
		  6��ͳ�ƿ����Ϊ�ļ�
		  
	ȱ�㣺1��ҳ������������󣡣���δ�ҵ����õĽ������
		  2����Щѡ��ܷ�����һ��
		  3���޸�ָ����Ϣʱ����Щѡ���޲��޸�ѡ��
		  4����������������������޷������Խ�������޸ģ�ɾ���Ȳ���
		  5��ԭ�ƻ��Ķ��������δʵ�֣�ԭ�ƻ������κͱ�š�ǰ׺+����/������/��ĸ���� ����/������/��ĸ+��׺��������/������/��ĸ  ���ֿգ������δʵ��
		  6�����������죬������������������ܺ��ڴ棬�����Ѵ�1.12M 
		
***************************************************************************************/ 
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<string.h> 
#define header1  "       --------------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n"
#define header2  "      |                                                                                                                                                                           |\n"
#define header3  "      |                                                                    �� Ʒ �� Ϣ                                                                                            |\n"
#define header30 "      |                                                                    �� Ʒ �� Ϣ  �� %3d / %3d )                                                            ��һҳ  +       |\n"
#define header31 "      |      -    ��һҳ                                                   �� Ʒ �� Ϣ  �� %3d / %3d ��                                                           ��һҳ  +       |\n" 
#define header32 "      |      -    ��һҳ                                                   �� Ʒ �� Ϣ  �� %3d / %3d ��                                                                           |\n"
#define project  "      | ѡ�� | ��� |    ���    |         ����         |    ����    |        ������        |  ��� |   �ۼ�   |   ����   |  ���� |  ���� |     ����    |     �ɱ�    |    ����   |\n"
#define FORMAT   "      |  %-2s  |  %-2d  | %-10s | %-20s | %-10s | %-20s | %-5d | %-8.2lf | %-8.2lf | %-5d | %-5d | %-11.2lf | %-11.2lf | %-9.2lf |\n"
#define FORMAT2  "   ==>|  %-2s  |  %-2d  | %-10s | %-20s | %-10s | %-20s | %-5d | %-8.2lf | %-8.2lf | %-5d | %-5d | %-11.2lf | %-11.2lf | %-9.2lf |\n"
#define DATA      p->check,p->order,p->num,p->name,p->type,p->producer,p->rest,p->price,p->pprice,p->sold,p->amount,p->collect,p->total,p->profit
#define N 100 
typedef struct commodity{
	char check[2];
	int order;
	char num[10];
	char name[21];
	char type[11];
	char producer[21];
	int rest;
	double price;
	double pprice;
	int sold;
	int amount;
	double collect;
	double total;
	double profit;
}SPXX;

int saveflag=0;
char mi[11];
int page=1,arrow=0;

void exchangespxx(SPXX *temp1,SPXX *temp2){
	SPXX mix;
	mix=(*temp1);
	(*temp1)=(*temp2);
	(*temp2)=mix;
}

void delaspxx(SPXX *comdi,int n,int k){
	int i;
	for(i=k;i<n;i++) (*(comdi+i))=(*(comdi+i+1));
}

void gotoxy(int x, int y) {
    COORD pos;
    pos.X = x - 1;
    pos.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void clears(void){
	int i,j;
	gotoxy(1,1);
	for(i=0;i<39;i++) printf("%186s\n"," ");
	gotoxy(1,1);
}

void clearx(void){
	int i,j;
	gotoxy(1,41);
	for(i=0;i<9;i++) printf("%186s\n"," ");
	gotoxy(1,41);
}

void inputint(int *num,char *notice){
	int m,errorflag;
	char ch;
	do{
		clearx();
		errorflag=0;
		printf(notice);
		errorflag=scanf("%d",&m);
		if(errorflag==0) errorflag=1;
		else errorflag=0;
		if(errorflag){
			printf("\n						==>���������벻Ҫ���������޹ص����ݣ���������������롣"); getch(); 
		}else{
			while((ch=getchar())!='\n'&&ch!=EOF) errorflag=1;
			if(errorflag){
				printf("\n						==>����������ֻ����������������������롣"); getch();
			}
		}
	}while(errorflag);
	(*num)=m;
}

void inputdouble(double *num,char *notice){
	int errorflag;
	double m;
	char ch;
	do{
		clearx();
		errorflag=0;
		printf(notice);
		errorflag=scanf("%lf",&m);
		if(errorflag==0) errorflag=1;
		else errorflag=0;
		if(errorflag){
			printf("\n						==>���������벻Ҫ���������޹ص����ݣ���������������롣%lf",m); getch(); 
		}else{
			while((ch=getchar())!='\n'&&ch!=EOF) errorflag=1;
			if(errorflag){
				printf("\n						==>����������ֻ����������������������롣"); getch();
			}
		}
	}while(errorflag);
	(*num)=m;
}

void inputcollect(double *num,char *notice,double colt){
	int errorflag;
	double m;
	char ch;
	do{
		errorflag=0;
		clearx();
		printf(notice,colt);
		errorflag=scanf("%lf",&m);
		if(errorflag==0) errorflag=1;
		else errorflag=0;
		if(errorflag){
			printf("\n						==>���������벻Ҫ���������޹ص����ݣ���������������롣"); getch(); 
		}else{
			while((ch=getchar())!='\n'&&ch!=EOF) errorflag=1;
			if(errorflag){
				printf("\n						==>����������ֻ����������������������롣"); getch(); 
			}
		}
	}while(errorflag);
	(*num)=m;
}

void inputchar(char *str,int lens,char *notice){
	char m,ch[256];
	int i,j,errorflag;
	do{
		clearx();
		errorflag=0;
		printf(notice);
		gets(ch);
		j=strlen(ch);
		if(j>(lens-1)){
			errorflag=1;
			printf("\n					==>�������ݹ��������Ȳ��ܴ��� %d �����������롣",lens); getch(); 
		}else{
			for(i=0;i<j;i++){
				m=(*(ch+i));
				if(m>0)
					if((m<32)||((32<m)&&(m<40))||((41<m)&&(m<45))||((46<m)&&(m<48))||((57<m)&&(m<65))||((90<m)&&(m<97))||(122<m)){
						errorflag=1; 
						printf("\n						==>������������ֻ������Ӣ�ġ����֡����š��ո�С����ͼ��š�"); getch(); break;
					}
			}
		} 
	}while(errorflag);
	strcpy(str,ch);
}

void inputnum(char *str,int lens,char *notice){
	char ch[256],m;
	int i,j,errorflag;
	SPXX *mix;
	do{
		clearx();
		errorflag=0;
		printf(notice);
		gets(ch);
		j=strlen(ch);
		if(j>(lens-1)){
			errorflag=1;
			printf("\n						==>�������ݹ��������Ȳ��ܴ��� %d �����������롣",lens); getch(); 
		}else{
			for(i=0;i<j;i++){
				m=(*(ch+i));
				if((m<32)||((32<m)&&(m<45))||((45<m)&&(m<48))||((57<m)&&(m<65))||((90<m)&&(m<97))||(122<m)){
					errorflag=1;
					printf("\n						==>������������ֻ����Ӣ����ĸ�����֡��ո�ͼ��š�"); getch(); break;
				}
			}
		}
	}while(errorflag);
	strcpy(str,ch);
} 

int allpage(int n){
	int pages;
	if(n==0) pages=0;
	else if(n%14==0) pages=n/14;
	else pages=n/14+1;
	return pages;
}

void arrowdown(int n){
	if(arrow>page*14-14) arrow--;
	else{
		if((page*14-1)<(n-1)) arrow=page*14-1;
		else if((page*14-1)==(n-1)) arrow=page*14-1;
		else if((page*14-14)<(n-1)) arrow=n-1;
	}
}

void arrowup(int n){
	if(((page*14-1)<(n-1))||((page*14-1)==(n-1))){
		if(arrow==(page*14-1)) arrow=page*14-14;
		else arrow++;
	}else{
		if(arrow==(n-1)) arrow=page*14-14;
		else arrow++;
	}
}

void pagedown(int n){
	if(n<15) return;
	if(page==1) return;
	page--;
	arrow=page*14-14;
}

void pageup(int n){
	if(n<15) return;
	if(page==allpage(n)) return;
	page++;
	arrow=page*14-14;
}

void welcome(void){
	printf("\n\n\n\n\n\n			 ___          ___                               ___                       ___                       ________________        ___\n");
	printf("			|   |        |   |                             |   |                     |   |                     |                |      |   |           \n");
	printf("			|   |        |   |                             |   |                     |   |                     |   _________    |      |   |              \n");
	printf("			|   |        |   |                             |   |                     |   |                     |   |        |   |      |   |        \n");
	printf("			|   |        |   |                             |   |                     |   |                     |   |        |   |      |   |         \n");
	printf("			|   |        |   |                             |   |                     |   |                     |   |        |   |      |   |        \n");
	printf("			|   |        |   |                             |   |                     |   |                     |   |        |   |      |   |       \n");
	printf("			|   |        |   |                             |   |                     |   |                     |   |        |   |      |   |           \n");
	printf("			|   |________|   |     ___________________     |   |                     |   |                     |   |        |   |      |   |               \n");
	printf("			|                |    |                   |    |   |                     |   |                     |   |        |   |      |   |                    \n");
	printf("			|    ________    |    |   _____________   |    |   |                     |   |                     |   |        |   |      |   |       \n");
	printf("			|   |        |   |    |  |             |  |    |   |                     |   |                     |   |        |   |      |   |              \n");
	printf("			|   |        |   |    |  |_____________|  |    |   |                     |   |                     |   |        |   |      |   |          \n");
	printf("			|   |        |   |    |                   |    |   |                     |   |                     |   |        |   |      |   |        \n");
	printf("			|   |        |   |    |   ________________|    |   |                     |   |                     |   |        |   |      |___|        \n");
	printf("			|   |        |   |    |  |                     |   |                     |   |                     |   |        |   |           \n");
	printf("			|   |        |   |    |  |________________     |   |________________     |   |________________     |   |________|   |       ___                \n");
	printf("			|   |        |   |    |                   |    |                    |    |                    |    |                |      |   |            \n");
	printf("			|___|        |___|    |___________________|    |____________________|    |____________________|    |________________|      |___|                \n");
	printf("\n\n\n\n\n\n");
}

void doubleisint(char *temp,int lenst){
	int i,j,flag=0;
	for(i=1;i<lenst;i++)
		if((*(temp+i))=='.'){
			j=i;
			if(i==(lenst-1)) flag=1;
			else{
				for(i=i+1;i<lenst;i++)
					if((*(temp+i))!='0') return;	
				flag=1;
			}break;
		}
	if(flag)
		for(i=lenst-1;i>j-1;i--)
			(*(temp+i))='\0';
} 

int cmpchar(char *temp,char *findmess,int swtch){
	int i,j=0,lenst,lensf;
	lenst=strlen(temp);
	if(swtch) doubleisint(temp,lenst);
	if(strcmp(temp,findmess)==0)	return 4;
	if(strstr(temp,findmess))	return 3;
	if(strstr(findmess,temp))	return 2;
	lensf=strlen(findmess);
	lenst=strlen(temp);
	for(i=0;i<lensf;i++){
		for(j=0;j<lenst;j++){
			if(((*(findmess+i))>0)&&((*(findmess+i))==(*(temp+j))))	return 1;
			else if(((*(findmess+i))<0)&&((*(findmess+i))==(*(temp+j)))&&((*(findmess+i+1))==(*(temp+j+1)))) return 1;
			}
	return 0;
	}
}

void sort(SPXX *comdi,int n,int selt){
	int sortnum[n][12];
	SPXX spxxmix[n];
	int i,j,x,y,k,flag;
	char *str[n],*str2[n],*strmix;
	int intm[n],intn[n],intmix;
	double doublem[n],doublen[n],doublemix;
	do{	//����� 
		do{//���0
			for(i=0;i<n;i++) str2[i]=str[i]=(&((*(comdi+i)).num));
			for(i=0;i<n-1;i++){	 
				k=i;
				for(j=i+1;j<n;j++){
					if(strcmp(str[k],str[j])>0) k=j;
				}if(i!=k){
					strmix=str[k];
					str[k]=str[i];
					str[i]=strmix;
				}
			}for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					if(str[i]==str2[j]){
						sortnum[j][0]=i+1; break;
					}
		}while(0);
		do{//����1
			for(i=0;i<n;i++) str2[i]=str[i]=(&((*(comdi+i)).name));
			for(i=0;i<n-1;i++){	 
				k=i;
				for(j=i+1;j<n;j++){
					if(strcmp(str[k],str[j])>0) k=j;
				}if(i!=k){
					strmix=str[k];
					str[k]=str[i];
					str[i]=strmix;
				}
			}for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					if(str[i]==str2[j])
						sortnum[j][1]=i+1; 
		}while(0);
		do{//����2
			for(i=0;i<n;i++) str2[i]=str[i]=(&((*(comdi+i)).type));
			for(i=0;i<n-1;i++){	 
				k=i;
				for(j=i+1;j<n;j++){
					if(strcmp(str[k],str[j])>0) k=j;
				}if(i!=k){
					strmix=str[k];
					str[k]=str[i];
					str[i]=strmix;
				}
			}for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					if(str[i]==str2[j])
						sortnum[j][2]=i+1;
		}while(0);
		do{//������3
			for(i=0;i<n;i++) str2[i]=str[i]=(&((*(comdi+i)).producer));
			for(i=0;i<n-1;i++){	 
				k=i;
				for(j=i+1;j<n;j++){
					if(strcmp(str[k],str[j])>0) k=j;
				}if(i!=k){
					strmix=str[k];
					str[k]=str[i];
					str[i]=strmix;
				}
			}for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					if(str[i]==str2[j])
						sortnum[j][3]=i+1;
		}while(0);
		do{//���4 
			for(i=0;i<n;i++) intm[i]=intn[i]=((*(comdi+i)).rest);
			for(i=0;i<n-1;i++){
				k=i;
				for(j=i+1;j<n;j++)
					if(intm[k]>intm[j]) k=j;
				if(i!=k){
					intmix=intm[k];
					intm[k]=intm[i];
					intm[i]=intmix;
				}
			}for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					if(intm[i]==intn[j])
						sortnum[j][4]=i+1;
		}while(0);
		do{//�ۼ�5 
			for(i=0;i<n;i++) doublem[i]=doublen[i]=((*(comdi+i)).price);
			for(i=0;i<n-1;i++){
				k=i;
				for(j=i+1;j<n;j++)
					if(doublem[k]>doublem[j]) k=j;
				if(i!=k){
					doublemix=doublem[k];
					doublem[k]=doublem[i];
					doublem[i]=doublemix;
				}
			}for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					if(doublem[i]==doublen[j])
						sortnum[j][5]=i+1;
		}while(0);
		do{//����6 
			for(i=0;i<n;i++) doublem[i]=doublen[i]=((*(comdi+i)).pprice);
			for(i=0;i<n-1;i++){
				k=i;
				for(j=i+1;j<n;j++)
					if(doublem[k]>doublem[j]) k=j;
				if(i!=k){
					doublemix=doublem[k];
					doublem[k]=doublem[i];
					doublem[i]=doublemix;
				}
			}for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					if(doublem[i]==doublen[j])
						sortnum[j][6]=i+1;
		}while(0);
		do{//����7 
			for(i=0;i<n;i++) intm[i]=intn[i]=((*(comdi+i)).sold);
			for(i=0;i<n-1;i++){
				k=i;
				for(j=i+1;j<n;j++)
					if(intm[k]>intm[j]) k=j;
				if(i!=k){
					intmix=intm[k];
					intm[k]=intm[i];
					intm[i]=intmix;
				}
			}for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					if(intm[i]==intn[j])
						sortnum[j][7]=i+1;
		}while(0);
		do{//����8 
			for(i=0;i<n;i++) intm[i]=intn[i]=((*(comdi+i)).amount);
			for(i=0;i<n-1;i++){
				k=i;
				for(j=i+1;j<n;j++)
					if(intm[k]>intm[j]) k=j;
				if(i!=k){
					intmix=intm[k];
					intm[k]=intm[i];
					intm[i]=intmix;
				}
			}for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					if(intm[i]==intn[j])
						sortnum[j][8]=i+1;
		}while(0);
		do{//���ս��9 
			for(i=0;i<n;i++) doublem[i]=doublen[i]=((*(comdi+i)).collect);
			for(i=0;i<n-1;i++){
				k=i;
				for(j=i+1;j<n;j++)
					if(doublem[k]>doublem[j]) k=j;
				if(i!=k){
					doublemix=doublem[k];
					doublem[k]=doublem[i];
					doublem[i]=doublemix;
				}
			}for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					if(doublem[i]==doublen[j])
						sortnum[j][9]=i+1;
		}while(0);
		do{//�ɱ�10 
			for(i=0;i<n;i++) doublem[i]=doublen[i]=((*(comdi+i)).total);
			for(i=0;i<n-1;i++){
				k=i;
				for(j=i+1;j<n;j++)
					if(doublem[k]>doublem[j]) k=j;
				if(i!=k){
					doublemix=doublem[k];
					doublem[k]=doublem[i];
					doublem[i]=doublemix;
				}
			}for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					if(doublem[i]==doublen[j])
						sortnum[j][10]=i+1;
		}while(0);
		do{//����11 
			for(i=0;i<n;i++) doublem[i]=doublen[i]=((*(comdi+i)).profit);
			for(i=0;i<n-1;i++){
				k=i;
				for(j=i+1;j<n;j++)
					if(doublem[k]>doublem[j]) k=j;
				if(i!=k){
					doublemix=doublem[k];
					doublem[k]=doublem[i];
					doublem[i]=doublemix;
				}
			}for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					if(doublem[i]==doublen[j])
						sortnum[j][11]=i+1;
		}while(0);
	}while(0);
	if((selt%10)==0){	//�������� 
		selt/=10;
		selt-=1;
		for(i=1,x=0;i<n+1;i++)
			for(j=0;j<n;j++)
				if((sortnum[j][selt])==i)
					(*(spxxmix+(x++)))=(*(comdi+j));
	}else{	//�������� 
		selt-=1;
		selt/=10;
		selt-=1;
		for(i=n,x=0;i>0;i--)
			for(j=0;j<n;j++)
				if(sortnum[j][selt]==i)
					(*(spxxmix+(x++)))=(*(comdi+j));
	}
	for(i=0;i<n;i++) (*(comdi+i))=(*(spxxmix+i));
	for(i=0;i<n;i++) ((*(comdi+i)).order)=i;
}

void printfspxx(SPXX *comdi,int n){
	SPXX *p;
	int i;
	if(n==0){
		printf("\n\n\n\n\n\n\n\n								==>����Ʒ��Ϣ��");
	}
	else{
		printf("\n");
		printf(header1);
		printf(header2);
		if(allpage(n)==1) printf(header3);
		else if((page==1)&&(allpage(n)>1)) printf(header30,page,allpage(n));
		else if(page==allpage(n)) printf(header32,page,page);
		else printf(header31,page,allpage(n));
		printf(header1);
		printf(project);
		printf(header1);
		for(i=page*14-14;i<page*14&&i<n;i++){
			p=comdi+i;
			if(i==arrow){
				printf("\n");
				printf(header1);
				printf(FORMAT2,DATA);
				printf(header1);
				printf("\n");
			}else if(i==arrow+1){
				printf(header1);
				printf(FORMAT,DATA);
				printf(header1);
			}else{
				printf(FORMAT,DATA);
				printf(header1);
			}
		}
	}	
}

void save(SPXX *comdi,int n){
	FILE *fp;
	int i;
	fp=fopen("d:\\��Ʒ��Ϣ����ϵͳ\\��Ʒ��Ϣ.txt","w");
	if(!fp){
		printf("\n								==>��Ʒ��Ϣ�ļ���ʧ�ܣ��޷����̡�\n"); getch();
	}
	for(i=0;i<n;i++){
		if(fwrite(comdi+i,sizeof(SPXX),1,fp)==1);
		else break;
	}
	if(i!=n) printf("\n								==>����ʧ�ܣ��ѳɹ����� %d ����Ϣ��\n",i);
	if(i==n) printf("\n								==>����ɹ����� %d ����Ϣ��\n",i);
	getch();
	saveflag=0;
}
 
void query(SPXX *comdi,int n){
	SPXX *p,re[n];
	int condition[12];
	int i,j,k,x;
	char str[21],str2[21],ch;
	inputchar(str,21,"\n								==>�������ݣ� ֱ�ӻس������أ���");
	if(strlen(str)!=0){
		for(i=x=0;i<n;i++){
			j=0;
			p=comdi+i;
			condition[j++]=cmpchar(p->num,str,0);
			condition[j++]=cmpchar(p->name,str,0);
			condition[j++]=cmpchar(p->type,str,0);
			condition[j++]=cmpchar(p->producer,str,0);
			sprintf(str2,"%d",p->rest);
			condition[j++]=cmpchar(str2,str,0);
			sprintf(str2,"%lf",p->price);
			condition[j++]=cmpchar(str2,str,1);
			sprintf(str2,"%lf",p->pprice);
			condition[j++]=cmpchar(str2,str,1);
			sprintf(str2,"%d",p->sold);
			condition[j++]=cmpchar(str2,str,0);
			sprintf(str2,"%d",p->amount);
			condition[j++]=cmpchar(str2,str,0);
			sprintf(str2,"%lf",p->collect);
			condition[j++]=cmpchar(str2,str,1);
			sprintf(str2,"%lf",p->total);
			condition[j++]=cmpchar(str2,str,1);
			sprintf(str2,"%lf",p->profit);
			condition[j++]=cmpchar(str2,str,1);
			for(j=1,k=0;j<12;j++) if(condition[j]>condition[k]) k=j;
			switch(condition[k]){
				case 4:(*(re+(x++)))=(*(comdi+i));	strcpy((*(re+x-1)).check," 4"); break;
				case 3:(*(re+(x++)))=(*(comdi+i));	strcpy((*(re+x-1)).check," 3"); break;
				case 2:(*(re+(x++)))=(*(comdi+i));	strcpy((*(re+x-1)).check," 2"); break;
				case 1:(*(re+(x++)))=(*(comdi+i));	strcpy((*(re+x-1)).check," 1"); break;
			}
		}if(x==0){
			clearx();printf("\n								==>δ�ҵ��� %s ��ص���Ʒ��Ϣ!\n",str);getch();return;
		}
		for(i=0;i<x-1;i++){
			k=i;
			for(j=i+1;j<x;j++){
				if(strcmp((*(re+j)).check,(*(re+k)).check)>0) k=j;
			}if(i!=k) exchangespxx(re+i,re+k);
		}
		while(1){
			j=0;
			do{
				system("cls");
				printf("\n");
				printf(header1);
				printf(header2);
				if(allpage(x)==1) printf(header3);
				else if((page==1)&&(allpage(x)>1)) printf(header30,page,allpage(x));
				else if(page==allpage(x)) printf(header32,page,page);
				else printf(header31,page,allpage(x));
				printf(header1);
				printf("      | ��� | ��� |    ���    |         ����         |    ����    |        ������        |  ��� |   �ۼ�   |   ����   |  ���� |  ���� |     ����    |     �ɱ�    |    ����   |\n");
				printf(header1);
				for(i=page*14-14;i<page*14&&i<x;i++){
					p=re+i;
					if(i==arrow){
						printf("\n");
						printf(header1);
						printf(FORMAT2,DATA);
						printf(header1);
						printf("\n");
					}else if(i==arrow+1){
						printf(header1);
						printf(FORMAT,DATA);
						printf(header1);
					}else{
						printf(FORMAT,DATA);
						printf(header1);
					}
				}gotoxy(1,40);
				printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("\n								==> %s ������������ϣ��� %d ������ضȣ�\n",str,x);
				printf("\n						4 ��ȫ��ͬ          3 �������ݱ�����        2 ��������������        1 �����������ཻ\n");
				printf("\n\n								==>1 ��������             �������� �����ϲ�\n");
			}while(0);
			ch=getch();
			switch(ch){
				case '1':query(re,x);	break;
				case '/':arrowdown(x);	break;
				case '*':arrowup(x);	break;
				case '-':pagedown(x);	break;
				case '+':pageup(x);		break;
				default:j=1;			break;
			}if(j) break;
		}
	}
}

void count(SPXX *comdi,int n,int swtch){
	SPXX re[n];
	FILE *fp;
	char str[21],str2[21],ch,ch2,str3[31];
	int i,j,k,x,breakflag;
	double doublenum,doublenum2;
	int pagenum=page,arrownum=arrow;
	page=1;arrow=0;
	while(1){	countselt:
		breakflag=1;
		system("cls");
		printfspxx(comdi,n);
		gotoxy(1,40);
		printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		if(swtch==1) printf("\n									ͳ����ѡ\n");
		else if(swtch==2) printf("\n									ͳ������\n");
		printf("\n        1 �������                      2 ����ͳ��                      3 �ۼ�����                      4 ��������                      5 ���ս������                  6 �������          \n");
		printf("\n        7 ����ͳ��                      8 ������ͳ��                    9 ��������                      a ��������                      b   �ɱ�����                    c ��������          \n");
		printf("\n									�س� ����\n");
		ch=getch();
		switch(ch){
			case '/':arrowdown(n);breakflag=0;	break;
			case '*':arrowup(n);breakflag=0;	break;
			case '-':pagedown(n);breakflag=0;	break;
			case '+':pageup(n);breakflag=0;		break;
			case '1':{	//������� 
				insx:inputnum(str,10,"\n								==>������ޣ��������س������أ���");
				if(strlen(str)==0) goto countselt; 
				inxx:inputnum(str2,10,"\n								==>������ޣ��������س������أ���");
				if(strlen(str2)==0) goto insx; 
				if(strcmp(str,str2)>0){
					printf("\n								==>���޲���С�����ޣ�����������\n"); getch();goto inxx;
				}for(i=x=0;i<n;i++)
					if(((strcmp(str,((comdi+i)->num))<0)&&(strcmp(((comdi+i)->num),str2)<0))||(strcmp(((comdi+i)->num),str)==0)||(strcmp(((comdi+i)->num),str2)==0)) (*(re+(x++)))=(*(comdi+i));
				break;
			}
			case '2':{	//���� 
				inputchar(str,11,"\n								==>ͳ�����ͺ��У� �س������أ���");
				if(strlen(str)==0) goto countselt;
				for(i=x=0;i<n;i++){
					if(strcmp((*(comdi+i)).type,str)==0) (*(re+(x++)))=(*(comdi+i));
					else if(strstr((comdi+i)->type,str)) (*(re+(x++)))=(*(comdi+i));
				}break;
			}
			case '3':{	//�ۼ����� 
				inputdouble(&doublenum,"\n								==>�ۼ����ޣ���������");
				indouble2:inputdouble(&doublenum2,"\n								==>�ۼ����ޣ���������");
				if(doublenum>doublenum2){
					printf("\n								==>���޲���С�����ޣ�����������\n"); getch(); goto indouble2;
				}for(i=x=0;i<n;i++)
					if(((doublenum<((*(comdi+i)).price))&&(((*(comdi+i)).price)<doublenum2))||(((*(comdi+i)).price)==doublenum)||(((*(comdi+i)).price)==doublenum2))	(*(re+(x++)))=(*(comdi+i));
				break;
			}
			case '4':{	//�������� 
				inputint(&j,"\n								==>�������ޣ���������");
				ink:inputint(&k,"\n								==>�������ޣ���������");
				if(j>k){
					printf("\n									==>���޲���С�����ޣ�����������\n"); getch(); goto ink;
				}for(i=x=0;i<n;i++)
					if(((j<((*(comdi+i)).sold))&&(((*(comdi+i)).sold)<k))||(((*(comdi+i)).sold)==j)||(((*(comdi+i)).sold)==k)) (*(re+(x++)))=(*(comdi+i));
				break;
			}
			case '5':{	//���ս������ 
				inputdouble(&doublenum,"\n								==>���ս�����ޣ���������");
				indb2:inputdouble(&doublenum2,"\n								==>���ս�����ޣ���������");
				if(doublenum>doublenum2){
					printf("\n								==>���޲���С�����ޣ�����������\n"); getch(); goto indb2;
				}for(i=x=0;i<n;i++)
					if(((doublenum<((*(comdi+i)).collect))&&(((*(comdi+i)).collect)<doublenum2))||(((*(comdi+i)).collect)==doublenum)||(((*(comdi+i)).collect)==doublenum2))	(*(re+(x++)))=(*(comdi+i));
				break;
			}
			case '6':{	//������� 
				inputint(&j,"\n								==>������ޣ���������");
				ink2:inputint(&k,"\n								==>������ޣ���������");
				if(j>k){
					printf("\n									==>���޲���С�����ޣ�����������\n"); getch(); goto ink2;
				}for(i=x=0;i<n;i++)
					if(((j<((*(comdi+i)).rest))&&(((*(comdi+i)).rest)<k))||(((*(comdi+i)).rest)==j)||(((*(comdi+i)).rest)==k)) (*(re+(x++)))=(*(comdi+i));
				break;
			}
			case '7':{	//���� 
				inputchar(str,21,"\n								==>ͳ�����ƺ��У� �س������أ���");
				if(strlen(str)==0) goto countselt;
				for(i=x=0;i<n;i++){
					if(strcmp((*(comdi+i)).name,str)==0) (*(re+(x++)))=(*(comdi+i));
					else if(strstr((comdi+i)->name,str)) (*(re+(x++)))=(*(comdi+i));
				}break;
			}
			case '8':{	//������ 
				inputchar(str,21,"\n								==>ͳ�������̺��У� �س������أ���");
				if(strlen(str)==0) goto countselt;
				for(i=x=0;i<n;i++){
					if(strcmp((*(comdi+i)).producer,str)==0) (*(re+(x++)))=(*(comdi+i));
					else if(strstr((comdi+i)->producer,str)) (*(re+(x++)))=(*(comdi+i));
				}break;
			}
			case '9':{	//�������� 
				inputdouble(&doublenum,"\n								==>�������ޣ���������");
				indob2:inputdouble(&doublenum2,"\n								==>�������ޣ���������");
				if(doublenum>doublenum2){
					printf("\n								==>���޲���С�����ޣ�����������\n"); getch(); goto indob2;
				}for(i=x=0;i<n;i++)
					if(((doublenum<((*(comdi+i)).pprice))&&(((*(comdi+i)).pprice)<doublenum2))||(((*(comdi+i)).pprice)==doublenum)||(((*(comdi+i)).pprice)==doublenum2))	(*(re+(x++)))=(*(comdi+i));
				break;
			}
			case 'a':{	//�������� 
				inputint(&j,"\n								==>�������ޣ���������");
				ink3:inputint(&k,"\n								==>�������ޣ�");
				if(j>k){
					printf("\n									==>���޲���С�����ޣ�����������\n"); getch(); goto ink3;
				}for(i=x=0;i<n;i++)
					if(((j<((*(comdi+i)).amount))&&(((*(comdi+i)).amount)<k))||(((*(comdi+i)).amount)==j)||(((*(comdi+i)).amount)==k)) (*(re+(x++)))=(*(comdi+i));
				break;
			}
			case 'b':{	//�ɱ� 
				inputdouble(&doublenum,"\n								==>�ɱ����ޣ���������");
				indob3:inputdouble(&doublenum2,"\n								==>�ɱ� ���ޣ���������");
				if(doublenum>doublenum2){
					printf("\n								==>���޲���С�����ޣ�����������\n"); getch(); goto indob3;
				}for(i=x=0;i<n;i++)
					if(((doublenum<((*(comdi+i)).total))&&(((*(comdi+i)).total)<doublenum2))||(((*(comdi+i)).total)==doublenum)||(((*(comdi+i)).total)==doublenum2))	(*(re+(x++)))=(*(comdi+i));
				break;
			}
			case 'c':{	//���� 
				inputdouble(&doublenum,"\n								==>�������ޣ���������");
				indob4:inputdouble(&doublenum2,"\n								==>�������ޣ���������");
				if(doublenum>doublenum2){
					printf("\n								==>���޲���С�����ޣ�����������\n"); getch(); goto indob4;
				}for(i=x=0;i<n;i++)
					if(((doublenum<((*(comdi+i)).profit))&&(((*(comdi+i)).profit)<doublenum2))||(((*(comdi+i)).profit)==doublenum)||(((*(comdi+i)).profit)==doublenum2))	(*(re+(x++)))=(*(comdi+i));
				break;
			}
			case 13:page=pagenum;arrow=arrownum;return;
			default:printf("\n\n								==>��������������ѡ��\n"); getch(); breakflag=0; break;
		}if(breakflag) break;
	}if(x){
		while(1){
			breakflag=0;
			system("cls");
			for(i=0;i<x;i++) ((*(re+i)).order)=i;
			printfspxx(re,x);
			gotoxy(1,40);
			printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			switch(ch){
				case '1':printf("\n								==>����ڡ� %s ��%s ������Ʒ��Ϣ�� %d ������������\n",str,str2,x);							break;
				case '2':printf("\n								==>���ͺ� %s ���� %d ����������Ϣ����\n",str,x);											break;
				case '3':printf("\n								==>�ۼ��ڡ� %8.2lf ��%8.2lf ������Ʒ��Ϣ�� %d ������������\n",doublenum,doublenum2,x);		break;
				case '4':printf("\n								==>�����ڡ� %d ��%d ������Ʒ��Ϣ�� %d ������������\n",j,k,x);								break;
				case '5':printf("\n								==>���ս���ڡ� %8.2lf ��%8.2lf ������Ʒ��Ϣ�� %d ������������\n",doublenum,doublenum2,x);	break;
				case '6':printf("\n								==>����ڡ� %d ��%d ������Ʒ��Ϣ�� %d ������������\n",j,k,x);								break;
				case '7':printf("\n								==>���ƺ� %s ���� %d ����������Ϣ����\n",str,x);											break;
				case '8':printf("\n								==>�����̺� %s ���� %d ����������Ϣ����\n",str,x);											break;
				case '9':printf("\n								==>�����ڡ� %8.2lf ��%8.2lf ������Ʒ��Ϣ�� %d ������������\n",doublenum,doublenum2,x);		break;
				case 'a':printf("\n								==>�����ڡ� %d ��%d ������Ʒ��Ϣ�� %d ������������\n",j,k,x);								break;
				case 'b':printf("\n								==>�ɱ��ڡ� %11.2lf ��%11.2lf ������Ʒ��Ϣ�� %d ������������\n",doublenum,doublenum2,x);	break;
				case 'c':printf("\n								==>�����ڡ� %9.2lf ��%9.2lf ������Ʒ��Ϣ�� %d ������������\n",doublenum,doublenum2,x);		break;
			}printf("\n\n						1 ����ϱ����ļ�			�������� �������˵�\n");
			ch2=getch();
			switch(ch2){
				case '/':arrowdown(x);	break;
				case '*':arrowup(x);	break;
				case '-':pagedown(x);	break;
				case '+':pageup(x);		break;
				case '1':{
					clearx();
					inputchar(str2,21,"\n								==>�ļ����ƣ�");
					strcpy(str3,"d:\\��Ʒ��Ϣ����ϵͳ\\");
					strcat(str3,str2);
					strcat(str3,".txt");
					fp=fopen(str3,"w");
					if(!fp){
						printf("\n								==>�� %s ���ļ���ʧ�ܣ��޷�����ϱ�\n",str3);
					}else{
						for(i=0;i<x;i++){
							if(fwrite(re+i,sizeof(SPXX),1,fp)==1);
							else break;
						}if(i!=x) printf("\n								==>���ʧ�ܣ��ѳɹ����� %d ����Ϣ��\n",i);
						else if(i==x) printf("\n								==>����ɹ����� %d ����Ϣ��\n",i);
					}fclose(fp);
					getch();
					break;
				}
				default:return;
			}if(breakflag) break;
		}
	}else{
		clearx();
		switch(ch){
			case '1':printf("\n								==>δ�ҵ�����ڡ� %s ��%s ������Ʒ��Ϣ\n",str,str2);	break;
			case '2':printf("\n								==>δ�ҵ����ͺ� %s ����Ʒ��Ϣ\n",str);					break;
			case '3':printf("\n								==>δ�ҵ��ۼ��ڡ� %8.2lf ��%8.2lf ������Ʒ��Ϣ��",doublenum,doublenum2);	break;
			case '4':printf("\n								==>δ�ҵ������ڡ� %d ��%d ������Ʒ��Ϣ��\n",j,k);		break;
			case '5':printf("\n								==>δ�ҵ����ս���ڡ� %8.2lf ��%8.2lf ������Ʒ��Ϣ��",doublenum,doublenum2);break;
			case '6':printf("\n								==>δ�ҵ�����ڡ� %d ��%d ������Ʒ��Ϣ��\n",j,k);		break;
			case '7':printf("\n								==>δ�ҵ����ƺ� %s ����Ʒ��Ϣ\n",str);					break;
			case '8':printf("\n								==>δ�ҵ������̺� %s ����Ʒ��Ϣ\n",str);				break;
			case '9':printf("\n								==>δ�ҵ������ڡ� %8.2lf ��%8.2lf ������Ʒ��Ϣ��",doublenum,doublenum2);	break;
			case 'a':printf("\n								==>δ�ҵ������ڡ� %d ��%d ������Ʒ��Ϣ��\n",j,k);		break;
			case 'b':printf("\n								==>δ�ҵ��ɱ��ڡ� %11.2lf ��%11.2lf ������Ʒ��Ϣ��",doublenum,doublenum2);	break;
			case 'c':printf("\n								==>δ�ҵ������ڡ� %9.2lf ��%9.2lf ������Ʒ��Ϣ��",doublenum,doublenum2);	break;
		}getch();
	}page=pagenum;arrow=arrownum;				
}

int main(void){
	SPXX comdi[N],*p,re[N];
	int n,i,j,k,x;
	int breakflag;
	int pagenum,arrownum;
	int selt;
	double doublenum;
	char ch,str[21],str2[21];
	FILE *fp;
	do{ 	//��Ʒ��Ϣ 
		fp=fopen("d:\\��Ʒ��Ϣ����ϵͳ\\��Ʒ��Ϣ.txt","a+");
		if(!fp){
			printf("\n\n\n\n\n\n						==>��Ʒ��Ϣ�ļ���ʧ�ܣ�\n");	getch();
			return 0;
		}
		n=0;
		while(!feof(fp))
			if(fread(comdi+n,sizeof(SPXX),1,fp)==1) 	
				n++;    
		fclose(fp);
		for(i=0;i<n;i++) strcpy((*(comdi+i)).check,"");
	}while(0);
	do{ 	//���� 
		fp=fopen("d:\\��Ʒ��Ϣ����ϵͳ\\����.txt","a+");
		if(!fp){
			printf("\n\n\n\n\n\n						==>�����ļ���ʧ�ܣ�\n");	getch();
			return 0;
		}
		i=0;
		while(!feof(fp))
			if(fread(mi,sizeof(mi),1,fp)==1) 	
				i++;    
		fclose(fp);
		for(i=0;mi[i]!='\0';i++){
			mi[i]=mi[i]+9;
			mi[i]=mi[i]/2;
			mi[i]=mi[i]-5;
		}
	}while(0);
	welcome(); getch();
	while(1){
		breakflag=1;
		system("cls");
		welcome();
		if(strlen(mi)!=0){
			printf("								==>���루 1~10 λ����\n");
			printf("\n								   ֱ�ӻس�������\n");
			gotoxy(86,32);
			gets(str);
			if(strcmp(str,mi)!=0){
				printf("\n								==>�����������������\n");getch();
				breakflag=0;
			}
		}if(breakflag) break;
	}
	while(1){	seller:
		if(strlen(mi)==0){
			system("cls");
			printf("\n\n\n\n\n\n								==>��ǰ�����룬Ϊ�����ݰ�ȫ���뾡���޸����룡\n"); getch();
		}clears();
		for(i=0;i<n;i++) ((*(comdi+i)).order)=i;
		printfspxx(comdi,n);
		gotoxy(1,40);
		printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("\n        / �������                                                                                                                                                       * �������         \n");
		printf("\n        1 ���                 2 �޸�                 3 ����ѡ               4 ȡѡ                 5 ѡ����Ϣ             6  ȫ��ѡ              7 ͳ����ѡ             8 ������Ϣ         \n");
		printf("\n        a ɾ��                 b ����                 c ������               d ��ѡ                 e �޸�����             f  ȫ��ѡ              g ͳ������             h �˳�ϵͳ         \n");
		ch=getch();
		switch(ch){
			case '/':arrowdown(n);	break;
			case '*':arrowup(n);	break;
			case '-':pagedown(n);	break;
			case '+':pageup(n);		break;
			case '1':{	//��� 
				clearx();
				if(n==0){
					while(1){
						p=comdi+n;
						innum:inputnum(p->num,10,"\n								==>��ţ� ֱ�ӻس����˳���� ����");
						if(strlen(p->num)==0) break;
						inname:inputchar(p->name,21,"\n								==>���ƣ� ֱ�ӻس������� ����");
						if(strlen(p->name)==0) goto innum;
						intype:inputchar(p->type,11,"\n								==>���ͣ� ֱ�ӻس������� ����");
						if(strlen(p->type)==0) goto inname;
						inputchar(p->producer,21,"\n								==>�����̣� ֱ�ӻس������� ����");
						if(strlen(p->producer)==0) goto intype;
						inputdouble(&(p->pprice),"\n								==>�������ۣ�");
						inputint(&(p->amount),"\n								==>����������");
						inputdouble(&(p->price),"\n								==>�ۼۣ�");
						inputint(&(p->sold),"\n								==>���ۣ�");
						inputcollect(&(p->collect),"\n								==>���ս� ��ǰ�ۼ� * ���� = %11.2lf �� ��",(p->price)*(p->sold));
						(p->rest)=(p->amount)-(p->sold);
						(p->total)=(p->pprice)*(p->amount);
						(p->profit)=(p->collect)-(p->total);
						n++; saveflag=1;
						arrow=n-1;
						clears();
						printfspxx(comdi,n);
						clearx();
						if(n==N){
							printf("\n								==>���Ѵ�ɼ�¼���ޣ����ɼ������\n"); getch(); break;
						}
						printf("\n								==>�Ƿ������ָ����Ϣ���������Ϣ�� Y/N ���س� Y����\n");
						ch=getch();
						if(ch=='n'||ch=='N') break;
					}
				}else if(n==N){
					printf("\n								==>�Դﵽ�ɼ�¼�������ޣ�"); getch();
				}else{
					printf("\n								==>��ָ����Ϣ���ı߲�����Ϣ��\n");
					printf("\n								   1 ����          2 ����          ֱ�ӻس� ����");
					ch=getch();
					if(ch=='1') j=arrow;
					else if(ch=='2') j=arrow+1;
					else j=-2;
					if(j>(-2)){
						while(1){
							p=comdi+n;
							innum2:inputnum(p->num,10,"\n								==>��ţ� ֱ�ӻس����˳���� ����");
							if(strlen(p->num)==0) break;
							inname2:inputchar(p->name,21,"\n								==>���ƣ� ֱ�ӻس������� ����");
							if(strlen(p->name)==0) goto innum2;
							intype2:inputchar(p->type,11,"\n								==>���ͣ� ֱ�ӻس������� ����");
							if(strlen(p->type)==0) goto inname2;
							inputchar(p->producer,21,"\n								==>�����̣� ֱ�ӻس������� ����");
							if(strlen(p->producer)==0) goto intype2;
							inputdouble(&(p->pprice),"\n								==>�������ۣ�");
							inputint(&(p->amount),"\n								==>����������");
							inputdouble(&(p->price),"\n								==>�ۼۣ�");
							inputint(&(p->sold),"\n								==>���ۣ�");
							inputcollect(&(p->collect),"\n								==>���ս� ��ǰ�ۼ� * ���� = %11.2lf �� ��",(p->price)*(p->sold));
							(p->rest)=(p->amount)-(p->sold);
							(p->total)=(p->pprice)*(p->amount);
							(p->profit)=(p->collect)-(p->total);
							n++; saveflag=1;
							for(i=n-1;i>j;i--)	exchangespxx((comdi+i),(comdi+i-1));
							arrow=j;
							clears();
							printfspxx(comdi,n);
							if(n==N){
								printf("\n								==>���Ѵ�ɼ�¼���ޣ����ɼ������\n"); getch(); break;
							}
							clearx();
							printf("\n								==>�Ƿ������ָ����Ϣ���������Ϣ�� Y/N ���س� Y����\n");
							ch=getch();
							j++; arrow=j;
							if(ch=='n'||ch=='N'){
								arrow--;
								break;
							}
							
						}
					}
				}
				break;
			}
			case '2':{	//�޸�********** 
				clearx();
				if(n==0){
					printf("\n								==>����Ʒ��Ϣ��\n"); getch();
				}else{
					for(i=x=0;i<n;i++)
						if(strcmp((comdi+i)->check,"**")==0) x++;
					if(x==0){
						printf("\n								==>�Ƿ��޸�ָ������Ϣ�� Y/N �س�Y �� ��");
						ch=getch();
						if(ch=='n'||ch=='N'){
							clearx();
							printf("\n								==>��ȡ���޸�\n"); getch();
						}else{//�޸�********** 
							inputnum(str,10,"\n								==>��ţ� �س������޸� ����");
							if(strlen(str)!=0) strcpy((*(comdi+arrow)).num,str);
							inputchar(str,21,"\n								==>���ƣ� �س������޸� ����");
							if(strlen(str)!=0) strcpy((*(comdi+arrow)).name,str);
							inputchar(str,11,"\n								==>���ͣ� �س������޸� ����");
							if(strlen(str)!=0) strcpy((*(comdi+arrow)).type,str);
							inputchar(str,21,"\n								==>�����̣� �س������޸� ����");
							if(strlen(str)!=0) strcpy((*(comdi+arrow)).producer,str);
							inputdouble(&((*(comdi+arrow)).price),"\n								==>�ۼۣ�");
							inputdouble(&((*(comdi+arrow)).pprice),"\n								==>���ۣ�");
							inputint(&((*(comdi+arrow)).sold),"\n								==>������");
							inputint(&((*(comdi+arrow)).amount),"\n								==>������");
							inputcollect(&((*(comdi+arrow)).collect),"\n								==>���ս� ��ǰ���գ�%9.2lf ����",(((*(comdi+arrow)).price)*((*(comdi+arrow)).sold)));
							 ((*(comdi+arrow)).rest)=((*(comdi+arrow)).amount)-((*(comdi+arrow)).sold);
							 ((*(comdi+arrow)).total)=((*(comdi+arrow)).pprice)*((*(comdi+arrow)).amount);
							 ((*(comdi+arrow)).profit)=((*(comdi+arrow)).collect)-((*(comdi+arrow)).total);
						}
					}else{//�޸�
						pagenum=page;arrownum=arrow;page=1;arrow=0;
						for(i=0,k=0;i<n;i++) if(strcmp((*(comdi+i)).check,"**")==0) (*(re+(k++)))=(*(comdi+i));
						mdfselt:	
						system("cls");
						printfspxx(re,k);
						gotoxy(1,40);
						printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("\n        1 ͬ����                                             2 ͬ�ۼ�                                             3 ͬ����                                            4 ͬ���ս��        \n");
						printf("\n        5 ͬ����                                             6 ͬ������                                           7 ͬ����                                            8 ͬ����            \n");
						printf("\n                                                           �س� ����\n");
						ch=getch();
						clearx();
						switch(ch){
							case '/':arrowdown(k);	goto mdfselt;	break;
							case '*':arrowup(k);	goto mdfselt;	break;
							case '-':pagedown(k);	goto mdfselt;	break;
							case '+':pageup(k);		goto mdfselt;	break;
							case '1':{	//ͬ����
								inputchar(str,11,"\n								==>ͬ���ͣ� �س������أ���");
								if(strlen(str)==0) goto mdfselt;
								for(i=0;i<n;i++)
									if(strcmp((comdi+i)->check,"**")==0) strcpy((*(comdi+i)).type,str);
								break;
							}
							case '2':{	//ͬ�ۼ� 
								inputdouble(&doublenum,"\n								==>ͬ�ۼۣ�");
								for(i=0;i<n;i++)
									if(strcmp((comdi+i)->check,"**")==0) (*(comdi+i)).price=doublenum; 
								break;
							}
							case '3':{	//ͬ���� 
								inputint(&k,"\n								==>ͬ������");
								for(i=0;i<n;i++)
									if(strcmp((comdi+i)->check,"**")==0) (*(comdi+i)).sold=k; 
								break;
							}
							case '4':{	//ͬ���ս�� 
								inputdouble(&doublenum,"\n								==>ͬ���ս�");
								for(i=0;i<n;i++)
									if(strcmp((comdi+i)->check,"**")==0) (*(comdi+i)).collect=doublenum; 
								break;
							}
							case '5':{
								inputchar(str,21,"\n								==>ͬ���ƣ� �س������أ���");
								if(strlen(str)==0) goto mdfselt;
								for(i=0;i<n;i++)
									if(strcmp((*(comdi+i)).check,"**")==0)
										strcpy(((*(comdi+i)).name),str);
								break;
							}
							case '6':{	//ͬ������ 
								inputchar(str,21,"\n								==>ͬ�����̣� �س������أ���");
								if(strlen(str)==0) goto mdfselt;
								for(i=0;i<n;i++)
										if(strcmp((comdi+i)->check,"**")==0) strcpy((*(comdi+i)).producer,str);
								break;
							}
							case '7':{	//ͬ���� 
								inputdouble(&doublenum,"\n								==>ͬ���ۣ�");
								for(i=0;i<n;i++)
									if(strcmp((comdi+i)->check,"**")==0) (*(comdi+i)).pprice=doublenum; 
								break;
							}
							case '8':{	//ͬ���� 
								inputint(&k,"\n								==>ͬ������");
								for(i=0;i<n;i++)
									if(strcmp((comdi+i)->check,"**")==0) (*(comdi+i)).amount=k; 
								break;
							}
							case 13:page=pagenum;arrow=arrownum;goto seller; break;
							default:printf("\n\n								==>��������������ѡ��");getch(); goto mdfselt; break;
						}for(i=0,k=0;i<n;i++)
							if(strcmp((*(comdi+i)).check,"**")==0){
								((*(comdi+i)).rest)=((*(comdi+i)).amount)-((*(comdi+i)).sold);
							 	((*(comdi+i)).total)=((*(comdi+i)).pprice)*((*(comdi+i)).amount);
								 ((*(comdi+i)).profit)=((*(comdi+i)).collect)-((*(comdi+i)).total);
								 (*(re+(k++)))=(*(comdi+i));
							}
						while(1){
							breakflag=0;
							clears(); printfspxx(re,k);
							clearx(); printf("\n								==>�޸ĳɹ�!\n");
							ch=getch();
							switch(ch){
								case '/':arrowdown(k);	break;
								case '*':arrowup(k);	break;
								case '-':pagedown(k);	break;
								case '+':pageup(k);		break;
								default:breakflag=1;	break;
							}if(breakflag) break;
						}page=pagenum;arrow=arrownum;
					} 
				}break;
			}
			case '3':{	//����ѡ 
				clearx();
				if(n==0){
					printf("\n								==>������Ʒ��Ϣ������������Ʒ��Ϣ��\n"); getch();
				}else{
					for(i=x=0;i<n;i++)
						if(strcmp((comdi+i)->check,"**")==0) (*(re+(x++)))=(*(comdi+i));
					if(x==0){
						printf("\n								==>��ѡѡ����Ϣ��\n"); getch();
					}else{
						pagenum=page;arrownum=arrow;	page=1;arrow=0;
						query(re,x);
						page=pagenum;arrow=arrownum;
					}
				}break;
			}
			case '4':{	//ȡѡ 
				clearx();
				if(n==0){
					printf("\n								==>������Ʒ��Ϣ������������Ϣ��"); getch();
				}else strcpy((comdi+arrow)->check,"  ");
				break;
			}
			case '5':{	//ѡ�� 
				clearx();
				if(n==0){
					printf("\n								==>������Ʒ��Ϣ������������Ϣ��"); getch();
				}else strcpy((comdi+arrow)->check,"**");
				break;
			}
			case '6':{	//ȫ��ѡ 
				clearx();
				if(n==0){
					printf("\n								==>������Ʒ��Ϣ������������Ϣ��"); getch();
				}else for(i=0;i<n;i++) strcpy((comdi+i)->check,"**");
				break;
			}
			case '7':{	//ͳ����ѡ 
				for(i=x=0;i<n;i++)
					if(strcmp((comdi+i)->check,"**")==0)
						(*(re+(x++)))=(*(comdi+i));
				if(x) count(re,x,1);
				else{
					clearx();
					printf("\n								==>��ѡѡ����Ϣ��"); getch();
				}
				break;
			}
			case '8':{	//���� 
				while(1){	sortselt:
					breakflag=1;
					clearx();
					printf("\n        1 ���                           2 ����                           3 �ۼ�                           4 ����                           5 ���ս��                       6 ���         \n");
					printf("\n        7 ����                           8 ������                         9 ����                           a ����                           b   �ɱ�                         c ����         \n");
					printf("\n                                                                       �س� ����\n");
					ch=getch();
					switch(ch){
						case '1':selt=10;	break;
						case '2':selt=30;	break;
						case '3':selt=60;	break;
						case '4':selt=80;	break;
						case '5':selt=100;	break;
						case '6':selt=50;	break;
						case '7':selt=20;	break;
						case '8':selt=40;	break;
						case '9':selt=70;	break;
						case 'a':selt=90;	break;
						case 'b':selt=110;	break;
						case 'c':selt=120;	break;
						case  13:goto seller;	break;
						default:breakflag=0; printf("\n								==>��������������ѡ��\n");getch(); break;
					}if(breakflag) break;
				}
				while(1){
					breakflag=1;
					clearx();
					printf("\n								1 ����			2 ����			�س� ����\n");
					ch=getch();
					switch(ch){
						case '1': 	break;
						case '2':selt+=1;	break;
						case  13:goto sortselt;	break;
						default:breakflag=0; printf("\n								==>������������������\n");getch();	break;
					}if(breakflag) break;
				}
				sort(comdi,n,selt);
				clears();
				printfspxx(comdi,n);
				clearx();
				printf("\n								==>�޸�����ɹ���\n");getch();
				break;
			}
			case 'a':{	//ɾ��
				clearx(); 
				if(n==0){
					printf("\n								==>����Ʒ��Ϣ��"); getch();
				}
				else{
					for(i=k=0;i<n;i++)
						if(strcmp((comdi+i)->check,"**")==0) (*(re+(k++)))=(*(comdi+i));
					if(k==0){
						clearx();
						printf("\n								==>�Ƿ�ɾ��ָ������Ϣ�� Y/N �س�Y ) ?");
						ch=getch();
						if(ch=='n'||ch=='N'){
							clearx();
							printf("\n								==>��ȡѡɾ��\n"); getch();
						}else{
							delaspxx(comdi,n,arrow);
							n--; arrow--; saveflag=1;
							clears();
							printfspxx(comdi,n);
							clearx();
							printf("\n								==>�ѳɹ�ɾ����\n"); getch();
						}
					}else{
						pagenum=page;arrownum=arrow;
						page=1;arrow=0;
						while(1){
							breakflag=0;
							system("cls");
							printfspxx(re,k);
							gotoxy(1,40);
							printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
							printf("\n								==>�Ƿ�ɾ��������Ϣ�� Y/N �س�Y ) ?");
							ch=getch();
							switch(ch){
								case '/':arrowdown(n);	break;
								case '*':arrowup(n);	break;
								case '-':pagedown(n);	break;
								case '+':pageup(n);		break;
								default:breakflag=1;	break;
							}if(breakflag) break;
						}
						if(ch=='n'||ch=='N'){
							clearx();
							printf("\n								==>��ȡѡɾ��\n"); getch();
						}else{
							for(i=0;i<n;i++)
								while(strcmp((comdi+i)->check,"**")==0){
									delaspxx(comdi,n,i);
									n--;
								}
							saveflag=1;
							clears();
							printfspxx(comdi,n);
							clearx();
							printf("\n								==>�ѳɹ�ɾ����\n"); getch();
						}
					}									
				}
				break;
			}
			case 'b':clearx();	save(comdi,n); 	break;
			case 'c':{	//������
				clearx();
				if(n==0){
					printf("\n								==>������Ʒ��Ϣ������������Ʒ��Ϣ��\n"); getch();
				}else{
					pagenum=page;arrownum=arrow;	page=1;arrow=0;
					query(comdi,n);
					page=pagenum;arrow=arrownum;
				}break;
			}
			case 'd':{	//��ѡ 
				clearx();
				if(n==0){
					printf("\n								==>������Ʒ��Ϣ������������Ϣ��"); getch();
				}else for(i=0;i<n;i++){
						if(strcmp((comdi+i)->check,"**")==0) strcpy((comdi+i)->check,"  ");
						else strcpy((comdi+i)->check,"**");
					}
				break;
			}
			case 'e':{	//���� 
				clearx();
				if(strlen(mi)!=0){
					while(1){
						i=0;
						clearx();
						printf("\n\n\n\n								ֱ�ӻس����������˵�");
						gotoxy(1,41);
						printf("\n								==>ԭ���루 1~10 λ ����");
						gets(str);
						if(strlen(str)==0) goto seller;
						if(strcmp(mi,str)==0) break;
						else printf("\n\n								==>��������������������롣       ");
						getch(); clearx();
					}
				}
				setmi:
				clearx();
				printf("\n\n\n\n								ֱ�ӻس����������˵�");
				gotoxy(1,41);
				printf("\n								==>�����루 1~10 λ ����");
				gets(str);
				if(strlen(str)==0) break;
				else if(strlen(str)>10){
					printf("\n\n								==>���볤�ȳ�����Χ�����������롣"); getch(); goto setmi;
				}
				detm:
				clearx();
				printf("\n\n\n\n								ֱ�ӻس����������˵�");
				gotoxy(1,41);
				printf("\n								==>ȷ�������루 1~10 λ ����");
				gets(str2);
				if(strlen(str2)==0) break;
				else if(strlen(str2)>10){
					printf("\n\n								==>���볤�ȳ�����Χ�����������롣"); getch(); goto detm;
				}else if(strcmp(str,str2)!=0){
					printf("\n\n								==>�������벻��ͬ�����������롣"); getch(); goto detm;
				}
				strcpy(mi,str);
				clearx();
				printf("\n								==>�޸�����ɹ���"); getch();
				for(i=0;mi[i]!='\0';i++){	//���������ļ� 
					mi[i]=mi[i]+5;
					mi[i]=mi[i]*2;
					mi[i]=mi[i]-9;
				}
				fp=fopen("d:\\��Ʒ��Ϣ����ϵͳ\\����.txt","w");
				if(!fp){
					printf("\n								==>�����ļ���ʧ�ܣ��޷����̡�\n"); getch();
				}
				for(i=0;i<(strlen(mi));i++){
					if(fwrite(mi+i,1,1,fp)==1);
						else break;
				}
				if(i!=(strlen(mi))) printf("\n								==>�����������ļ�ʧ�ܣ��ѳɹ����� %d λ���룬�� %d λ���롣\n",i,strlen(mi));
				break;
			}
			case 'f':{	//ȫ��ѡ 
				clearx();
				if(n==0){
					printf("\n								==>������Ʒ��Ϣ������������Ϣ��"); getch();
				}else for(i=0;i<n;i++) strcpy((comdi+i)->check,"  ");
				break;
			}			
			case 'g':count(comdi,n,2);	break;	//ͳ������ 
			case 'h':{
				clearx();
				printf("\n								==>�˳�ϵͳ�� Y/N )��\n");
				ch=getch();
				if(ch=='y'||ch=='Y'){
					if(saveflag){
						clearx();
						printf("\n								==>�����޸����ݣ��Ƿ���̣� Y/N ����\n");
						ch=getch();
						if(ch=='y'||ch=='Y')	save(comdi,n);
						else{
							printf("\n								==>��ȡ������\n");getch();
						}
					}clearx();
					printf("\n								==>��л��ʹ�ñ�ϵͳ���ڴ��´μ���Ϊ������~~\n");	getch();
					return 0;
				}else printf("\n								==>��ȡ���˳�\n");getch();
				break;
			} 
			default:{
				printf("\n\n								==>��������������ѡ��"); getch();
				break;
			}
		}
	}return 0;
} 
