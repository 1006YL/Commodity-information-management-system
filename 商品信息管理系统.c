
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<string.h> 
#define header1  "       --------------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n"
#define header2  "      |                                                                                                                                                                           |\n"
#define header3  "      |                                                                    商 品 信 息                                                                                            |\n"
#define header30 "      |                                                                    商 品 信 息  （ %3d / %3d )                                                            下一页  +       |\n"
#define header31 "      |      -    上一页                                                   商 品 信 息  （ %3d / %3d ）                                                           下一页  +       |\n" 
#define header32 "      |      -    上一页                                                   商 品 信 息  （ %3d / %3d ）                                                                           |\n"
#define project  "      | 选定 | 序号 |    编号    |         名称         |    类型    |        生产商        |  库存 |   售价   |   进价   |  售量 |  进量 |     已收    |     成本    |    收益   |\n"
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
			printf("\n						==>输入有误！请不要输入与数无关的内容，按任意键重新输入。"); getch(); 
		}else{
			while((ch=getchar())!='\n'&&ch!=EOF) errorflag=1;
			if(errorflag){
				printf("\n						==>输入有误！请只输入数，按任意键重新输入。"); getch();
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
			printf("\n						==>输入有误！请不要输入与数无关的内容，按任意键重新输入。%lf",m); getch(); 
		}else{
			while((ch=getchar())!='\n'&&ch!=EOF) errorflag=1;
			if(errorflag){
				printf("\n						==>输入有误！请只输入数，按任意键重新输入。"); getch();
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
			printf("\n						==>输入有误！请不要输入与数无关的内容，按任意键重新输入。"); getch(); 
		}else{
			while((ch=getchar())!='\n'&&ch!=EOF) errorflag=1;
			if(errorflag){
				printf("\n						==>输入有误！请只输入数，按任意键重新输入。"); getch(); 
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
			printf("\n					==>输入内容过长！长度不能大于 %d 。请重新输入。",lens); getch(); 
		}else{
			for(i=0;i<j;i++){
				m=(*(ch+i));
				if(m>0)
					if((m<32)||((32<m)&&(m<40))||((41<m)&&(m<45))||((46<m)&&(m<48))||((57<m)&&(m<65))||((90<m)&&(m<97))||(122<m)){
						errorflag=1; 
						printf("\n						==>输入内容有误！只能有中英文、数字、括号、空格、小数点和减号。"); getch(); break;
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
			printf("\n						==>输入内容过长！长度不能大于 %d 。请重新输入。",lens); getch(); 
		}else{
			for(i=0;i<j;i++){
				m=(*(ch+i));
				if((m<32)||((32<m)&&(m<45))||((45<m)&&(m<48))||((57<m)&&(m<65))||((90<m)&&(m<97))||(122<m)){
					errorflag=1;
					printf("\n						==>输入内容有误！只能有英文字母、数字、空格和减号。"); getch(); break;
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
	do{	//升序表 
		do{//编号0
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
		do{//名称1
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
		do{//类型2
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
		do{//生产商3
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
		do{//库存4 
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
		do{//售价5 
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
		do{//进价6 
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
		do{//售量7 
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
		do{//进量8 
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
		do{//已收金额9 
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
		do{//成本10 
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
		do{//收益11 
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
	if((selt%10)==0){	//升序排序 
		selt/=10;
		selt-=1;
		for(i=1,x=0;i<n+1;i++)
			for(j=0;j<n;j++)
				if((sortnum[j][selt])==i)
					(*(spxxmix+(x++)))=(*(comdi+j));
	}else{	//降序排序 
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
		printf("\n\n\n\n\n\n\n\n								==>无商品信息！");
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
	fp=fopen("d:\\商品信息管理系统\\商品信息.txt","w");
	if(!fp){
		printf("\n								==>商品信息文件打开失败！无法存盘。\n"); getch();
	}
	for(i=0;i<n;i++){
		if(fwrite(comdi+i,sizeof(SPXX),1,fp)==1);
		else break;
	}
	if(i!=n) printf("\n								==>保存失败！已成功保存 %d 条信息。\n",i);
	if(i==n) printf("\n								==>保存成功！共 %d 条信息。\n",i);
	getch();
	saveflag=0;
}
 
void query(SPXX *comdi,int n){
	SPXX *p,re[n];
	int condition[12];
	int i,j,k,x;
	char str[21],str2[21],ch;
	inputchar(str,21,"\n								==>搜索内容（ 直接回车：返回）：");
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
			clearx();printf("\n								==>未找到与 %s 相关的商品信息!\n",str);getch();return;
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
				printf("      | 相关 | 序号 |    编号    |         名称         |    类型    |        生产商        |  库存 |   售价   |   进价   |  售量 |  进量 |     已收    |     成本    |    收益   |\n");
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
				printf("\n								==> %s 的搜索结果如上，共 %d 条，相关度：\n",str,x);
				printf("\n						4 完全相同          3 搜索内容被包含        2 搜索内容所包含        1 与搜索内容相交\n");
				printf("\n\n								==>1 继续查找             其他按键 返回上层\n");
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
		if(swtch==1) printf("\n									统计已选\n");
		else if(swtch==2) printf("\n									统计整表\n");
		printf("\n        1 编号区间                      2 类型统计                      3 售价区间                      4 售量区间                      5 已收金额区间                  6 库存区间          \n");
		printf("\n        7 名称统计                      8 生产商统计                    9 进价区间                      a 进量区间                      b   成本区间                    c 收益区间          \n");
		printf("\n									回车 返回\n");
		ch=getch();
		switch(ch){
			case '/':arrowdown(n);breakflag=0;	break;
			case '*':arrowup(n);breakflag=0;	break;
			case '-':pagedown(n);breakflag=0;	break;
			case '+':pageup(n);breakflag=0;		break;
			case '1':{	//编号区间 
				insx:inputnum(str,10,"\n								==>编号下限（包含，回车：返回）：");
				if(strlen(str)==0) goto countselt; 
				inxx:inputnum(str2,10,"\n								==>编号上限（包含，回车：返回）：");
				if(strlen(str2)==0) goto insx; 
				if(strcmp(str,str2)>0){
					printf("\n								==>上限不能小于下限！请重新输入\n"); getch();goto inxx;
				}for(i=x=0;i<n;i++)
					if(((strcmp(str,((comdi+i)->num))<0)&&(strcmp(((comdi+i)->num),str2)<0))||(strcmp(((comdi+i)->num),str)==0)||(strcmp(((comdi+i)->num),str2)==0)) (*(re+(x++)))=(*(comdi+i));
				break;
			}
			case '2':{	//类型 
				inputchar(str,11,"\n								==>统计类型含有（ 回车：返回）；");
				if(strlen(str)==0) goto countselt;
				for(i=x=0;i<n;i++){
					if(strcmp((*(comdi+i)).type,str)==0) (*(re+(x++)))=(*(comdi+i));
					else if(strstr((comdi+i)->type,str)) (*(re+(x++)))=(*(comdi+i));
				}break;
			}
			case '3':{	//售价区间 
				inputdouble(&doublenum,"\n								==>售价下限（包括）：");
				indouble2:inputdouble(&doublenum2,"\n								==>售价上限（包括）：");
				if(doublenum>doublenum2){
					printf("\n								==>上限不能小于下限！请重新输入\n"); getch(); goto indouble2;
				}for(i=x=0;i<n;i++)
					if(((doublenum<((*(comdi+i)).price))&&(((*(comdi+i)).price)<doublenum2))||(((*(comdi+i)).price)==doublenum)||(((*(comdi+i)).price)==doublenum2))	(*(re+(x++)))=(*(comdi+i));
				break;
			}
			case '4':{	//售量区间 
				inputint(&j,"\n								==>售量下限（包括）：");
				ink:inputint(&k,"\n								==>售量上限（包括）：");
				if(j>k){
					printf("\n									==>上限不能小于下限！请重新输入\n"); getch(); goto ink;
				}for(i=x=0;i<n;i++)
					if(((j<((*(comdi+i)).sold))&&(((*(comdi+i)).sold)<k))||(((*(comdi+i)).sold)==j)||(((*(comdi+i)).sold)==k)) (*(re+(x++)))=(*(comdi+i));
				break;
			}
			case '5':{	//已收金额区间 
				inputdouble(&doublenum,"\n								==>已收金额下限（包括）：");
				indb2:inputdouble(&doublenum2,"\n								==>已收金额上限（包括）：");
				if(doublenum>doublenum2){
					printf("\n								==>上限不能小于下限！请重新输入\n"); getch(); goto indb2;
				}for(i=x=0;i<n;i++)
					if(((doublenum<((*(comdi+i)).collect))&&(((*(comdi+i)).collect)<doublenum2))||(((*(comdi+i)).collect)==doublenum)||(((*(comdi+i)).collect)==doublenum2))	(*(re+(x++)))=(*(comdi+i));
				break;
			}
			case '6':{	//库存区间 
				inputint(&j,"\n								==>库存下限（包括）：");
				ink2:inputint(&k,"\n								==>库存上限（包括）：");
				if(j>k){
					printf("\n									==>上限不能小于下限！请重新输入\n"); getch(); goto ink2;
				}for(i=x=0;i<n;i++)
					if(((j<((*(comdi+i)).rest))&&(((*(comdi+i)).rest)<k))||(((*(comdi+i)).rest)==j)||(((*(comdi+i)).rest)==k)) (*(re+(x++)))=(*(comdi+i));
				break;
			}
			case '7':{	//名称 
				inputchar(str,21,"\n								==>统计名称含有（ 回车：返回）；");
				if(strlen(str)==0) goto countselt;
				for(i=x=0;i<n;i++){
					if(strcmp((*(comdi+i)).name,str)==0) (*(re+(x++)))=(*(comdi+i));
					else if(strstr((comdi+i)->name,str)) (*(re+(x++)))=(*(comdi+i));
				}break;
			}
			case '8':{	//生产商 
				inputchar(str,21,"\n								==>统计生产商含有（ 回车：返回）；");
				if(strlen(str)==0) goto countselt;
				for(i=x=0;i<n;i++){
					if(strcmp((*(comdi+i)).producer,str)==0) (*(re+(x++)))=(*(comdi+i));
					else if(strstr((comdi+i)->producer,str)) (*(re+(x++)))=(*(comdi+i));
				}break;
			}
			case '9':{	//进价区间 
				inputdouble(&doublenum,"\n								==>进价下限（包括）：");
				indob2:inputdouble(&doublenum2,"\n								==>进价上限（包括）：");
				if(doublenum>doublenum2){
					printf("\n								==>上限不能小于下限！请重新输入\n"); getch(); goto indob2;
				}for(i=x=0;i<n;i++)
					if(((doublenum<((*(comdi+i)).pprice))&&(((*(comdi+i)).pprice)<doublenum2))||(((*(comdi+i)).pprice)==doublenum)||(((*(comdi+i)).pprice)==doublenum2))	(*(re+(x++)))=(*(comdi+i));
				break;
			}
			case 'a':{	//进量区间 
				inputint(&j,"\n								==>进量下限（包括）：");
				ink3:inputint(&k,"\n								==>进量上限：");
				if(j>k){
					printf("\n									==>上限不能小于下限！请重新输入\n"); getch(); goto ink3;
				}for(i=x=0;i<n;i++)
					if(((j<((*(comdi+i)).amount))&&(((*(comdi+i)).amount)<k))||(((*(comdi+i)).amount)==j)||(((*(comdi+i)).amount)==k)) (*(re+(x++)))=(*(comdi+i));
				break;
			}
			case 'b':{	//成本 
				inputdouble(&doublenum,"\n								==>成本下限（包括）：");
				indob3:inputdouble(&doublenum2,"\n								==>成本 上限（包括）：");
				if(doublenum>doublenum2){
					printf("\n								==>上限不能小于下限！请重新输入\n"); getch(); goto indob3;
				}for(i=x=0;i<n;i++)
					if(((doublenum<((*(comdi+i)).total))&&(((*(comdi+i)).total)<doublenum2))||(((*(comdi+i)).total)==doublenum)||(((*(comdi+i)).total)==doublenum2))	(*(re+(x++)))=(*(comdi+i));
				break;
			}
			case 'c':{	//收益 
				inputdouble(&doublenum,"\n								==>收益下限（包括）：");
				indob4:inputdouble(&doublenum2,"\n								==>收益上限（包括）：");
				if(doublenum>doublenum2){
					printf("\n								==>上限不能小于下限！请重新输入\n"); getch(); goto indob4;
				}for(i=x=0;i<n;i++)
					if(((doublenum<((*(comdi+i)).profit))&&(((*(comdi+i)).profit)<doublenum2))||(((*(comdi+i)).profit)==doublenum)||(((*(comdi+i)).profit)==doublenum2))	(*(re+(x++)))=(*(comdi+i));
				break;
			}
			case 13:page=pagenum;arrow=arrownum;return;
			default:printf("\n\n								==>输入有误！请重新选择\n"); getch(); breakflag=0; break;
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
				case '1':printf("\n								==>编号在【 %s ，%s 】的商品信息有 %d 条，具体如上\n",str,str2,x);							break;
				case '2':printf("\n								==>类型含 %s 的有 %d 个，具体信息如上\n",str,x);											break;
				case '3':printf("\n								==>售价在【 %8.2lf ，%8.2lf 】的商品信息有 %d 条，具体如上\n",doublenum,doublenum2,x);		break;
				case '4':printf("\n								==>售量在【 %d ，%d 】的商品信息有 %d 条，具体如上\n",j,k,x);								break;
				case '5':printf("\n								==>已收金额在【 %8.2lf ，%8.2lf 】的商品信息有 %d 条，具体如上\n",doublenum,doublenum2,x);	break;
				case '6':printf("\n								==>库存在【 %d ，%d 】的商品信息有 %d 条，具体如上\n",j,k,x);								break;
				case '7':printf("\n								==>名称含 %s 的有 %d 个，具体信息如上\n",str,x);											break;
				case '8':printf("\n								==>生产商含 %s 的有 %d 个，具体信息如上\n",str,x);											break;
				case '9':printf("\n								==>进价在【 %8.2lf ，%8.2lf 】的商品信息有 %d 条，具体如上\n",doublenum,doublenum2,x);		break;
				case 'a':printf("\n								==>进量在【 %d ，%d 】的商品信息有 %d 条，具体如上\n",j,k,x);								break;
				case 'b':printf("\n								==>成本在【 %11.2lf ，%11.2lf 】的商品信息有 %d 条，具体如上\n",doublenum,doublenum2,x);	break;
				case 'c':printf("\n								==>收益在【 %9.2lf ，%9.2lf 】的商品信息有 %d 条，具体如上\n",doublenum,doublenum2,x);		break;
			}printf("\n\n						1 输出上表至文件			其它按键 返回主菜单\n");
			ch2=getch();
			switch(ch2){
				case '/':arrowdown(x);	break;
				case '*':arrowup(x);	break;
				case '-':pagedown(x);	break;
				case '+':pageup(x);		break;
				case '1':{
					clearx();
					inputchar(str2,21,"\n								==>文件名称：");
					strcpy(str3,"d:\\商品信息管理系统\\");
					strcat(str3,str2);
					strcat(str3,".txt");
					fp=fopen(str3,"w");
					if(!fp){
						printf("\n								==>（ %s ）文件打开失败！无法输出上表。\n",str3);
					}else{
						for(i=0;i<x;i++){
							if(fwrite(re+i,sizeof(SPXX),1,fp)==1);
							else break;
						}if(i!=x) printf("\n								==>输出失败！已成功保存 %d 条信息。\n",i);
						else if(i==x) printf("\n								==>输出成功！共 %d 条信息。\n",i);
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
			case '1':printf("\n								==>未找到编号在【 %s ，%s 】的商品信息\n",str,str2);	break;
			case '2':printf("\n								==>未找到类型含 %s 的商品信息\n",str);					break;
			case '3':printf("\n								==>未找到售价在【 %8.2lf ，%8.2lf 】的商品信息！",doublenum,doublenum2);	break;
			case '4':printf("\n								==>未找到售量在【 %d ，%d 】的商品信息！\n",j,k);		break;
			case '5':printf("\n								==>未找到已收金额在【 %8.2lf ，%8.2lf 】的商品信息！",doublenum,doublenum2);break;
			case '6':printf("\n								==>未找到库存在【 %d ，%d 】的商品信息！\n",j,k);		break;
			case '7':printf("\n								==>未找到名称含 %s 的商品信息\n",str);					break;
			case '8':printf("\n								==>未找到生产商含 %s 的商品信息\n",str);				break;
			case '9':printf("\n								==>未找到进价在【 %8.2lf ，%8.2lf 】的商品信息！",doublenum,doublenum2);	break;
			case 'a':printf("\n								==>未找到进量在【 %d ，%d 】的商品信息！\n",j,k);		break;
			case 'b':printf("\n								==>未找到成本在【 %11.2lf ，%11.2lf 】的商品信息！",doublenum,doublenum2);	break;
			case 'c':printf("\n								==>未找到收益在【 %9.2lf ，%9.2lf 】的商品信息！",doublenum,doublenum2);	break;
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
	do{ 	//商品信息 
		fp=fopen("d:\\商品信息管理系统\\商品信息.txt","a+");
		if(!fp){
			printf("\n\n\n\n\n\n						==>商品信息文件打开失败！\n");	getch();
			return 0;
		}
		n=0;
		while(!feof(fp))
			if(fread(comdi+n,sizeof(SPXX),1,fp)==1) 	
				n++;    
		fclose(fp);
		for(i=0;i<n;i++) strcpy((*(comdi+i)).check,"");
	}while(0);
	do{ 	//密码 
		fp=fopen("d:\\商品信息管理系统\\密码.txt","a+");
		if(!fp){
			printf("\n\n\n\n\n\n						==>密码文件打开失败！\n");	getch();
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
			printf("								==>密码（ 1~10 位）：\n");
			printf("\n								   直接回车：返回\n");
			gotoxy(86,32);
			gets(str);
			if(strcmp(str,mi)!=0){
				printf("\n								==>密码错误！请重新输入\n");getch();
				breakflag=0;
			}
		}if(breakflag) break;
	}
	while(1){	seller:
		if(strlen(mi)==0){
			system("cls");
			printf("\n\n\n\n\n\n								==>当前无密码，为了数据安全，请尽快修改密码！\n"); getch();
		}clears();
		for(i=0;i<n;i++) ((*(comdi+i)).order)=i;
		printfspxx(comdi,n);
		gotoxy(1,40);
		printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("\n        / 光标上移                                                                                                                                                       * 光标下移         \n");
		printf("\n        1 添加                 2 修改                 3 搜已选               4 取选                 5 选定信息             6  全都选              7 统计已选             8 排序信息         \n");
		printf("\n        a 删除                 b 保存                 c 搜整表               d 反选                 e 修改密码             f  全不选              g 统计整表             h 退出系统         \n");
		ch=getch();
		switch(ch){
			case '/':arrowdown(n);	break;
			case '*':arrowup(n);	break;
			case '-':pagedown(n);	break;
			case '+':pageup(n);		break;
			case '1':{	//添加 
				clearx();
				if(n==0){
					while(1){
						p=comdi+n;
						innum:inputnum(p->num,10,"\n								==>编号（ 直接回车：退出添加 ）：");
						if(strlen(p->num)==0) break;
						inname:inputchar(p->name,21,"\n								==>名称（ 直接回车：返回 ）：");
						if(strlen(p->name)==0) goto innum;
						intype:inputchar(p->type,11,"\n								==>类型（ 直接回车：返回 ）：");
						if(strlen(p->type)==0) goto inname;
						inputchar(p->producer,21,"\n								==>生产商（ 直接回车：返回 ）：");
						if(strlen(p->producer)==0) goto intype;
						inputdouble(&(p->pprice),"\n								==>进货单价：");
						inputint(&(p->amount),"\n								==>进货数量：");
						inputdouble(&(p->price),"\n								==>售价：");
						inputint(&(p->sold),"\n								==>已售：");
						inputcollect(&(p->collect),"\n								==>已收金额（ 当前售价 * 已售 = %11.2lf ） ：",(p->price)*(p->sold));
						(p->rest)=(p->amount)-(p->sold);
						(p->total)=(p->pprice)*(p->amount);
						(p->profit)=(p->collect)-(p->total);
						n++; saveflag=1;
						arrow=n-1;
						clears();
						printfspxx(comdi,n);
						clearx();
						if(n==N){
							printf("\n								==>现已达可记录上限，不可继续添加\n"); getch(); break;
						}
						printf("\n								==>是否继续在指定信息下面添加信息（ Y/N ，回车 Y）？\n");
						ch=getch();
						if(ch=='n'||ch=='N') break;
					}
				}else if(n==N){
					printf("\n								==>以达到可记录条数上限！"); getch();
				}else{
					printf("\n								==>在指定信息的哪边插入信息？\n");
					printf("\n								   1 上面          2 下面          直接回车 返回");
					ch=getch();
					if(ch=='1') j=arrow;
					else if(ch=='2') j=arrow+1;
					else j=-2;
					if(j>(-2)){
						while(1){
							p=comdi+n;
							innum2:inputnum(p->num,10,"\n								==>编号（ 直接回车：退出添加 ）：");
							if(strlen(p->num)==0) break;
							inname2:inputchar(p->name,21,"\n								==>名称（ 直接回车：返回 ）：");
							if(strlen(p->name)==0) goto innum2;
							intype2:inputchar(p->type,11,"\n								==>类型（ 直接回车：返回 ）：");
							if(strlen(p->type)==0) goto inname2;
							inputchar(p->producer,21,"\n								==>生产商（ 直接回车：返回 ）：");
							if(strlen(p->producer)==0) goto intype2;
							inputdouble(&(p->pprice),"\n								==>进货单价：");
							inputint(&(p->amount),"\n								==>进货数量：");
							inputdouble(&(p->price),"\n								==>售价：");
							inputint(&(p->sold),"\n								==>已售：");
							inputcollect(&(p->collect),"\n								==>已收金额（ 当前售价 * 已售 = %11.2lf ） ：",(p->price)*(p->sold));
							(p->rest)=(p->amount)-(p->sold);
							(p->total)=(p->pprice)*(p->amount);
							(p->profit)=(p->collect)-(p->total);
							n++; saveflag=1;
							for(i=n-1;i>j;i--)	exchangespxx((comdi+i),(comdi+i-1));
							arrow=j;
							clears();
							printfspxx(comdi,n);
							if(n==N){
								printf("\n								==>现已达可记录上限，不可继续添加\n"); getch(); break;
							}
							clearx();
							printf("\n								==>是否继续在指定信息下面添加信息（ Y/N ，回车 Y）？\n");
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
			case '2':{	//修改********** 
				clearx();
				if(n==0){
					printf("\n								==>无商品信息！\n"); getch();
				}else{
					for(i=x=0;i<n;i++)
						if(strcmp((comdi+i)->check,"**")==0) x++;
					if(x==0){
						printf("\n								==>是否修改指定的信息（ Y/N 回车Y ） ？");
						ch=getch();
						if(ch=='n'||ch=='N'){
							clearx();
							printf("\n								==>已取消修改\n"); getch();
						}else{//修改********** 
							inputnum(str,10,"\n								==>编号（ 回车：不修改 ）：");
							if(strlen(str)!=0) strcpy((*(comdi+arrow)).num,str);
							inputchar(str,21,"\n								==>名称（ 回车：不修改 ）：");
							if(strlen(str)!=0) strcpy((*(comdi+arrow)).name,str);
							inputchar(str,11,"\n								==>类型（ 回车：不修改 ）：");
							if(strlen(str)!=0) strcpy((*(comdi+arrow)).type,str);
							inputchar(str,21,"\n								==>生产商（ 回车：不修改 ）：");
							if(strlen(str)!=0) strcpy((*(comdi+arrow)).producer,str);
							inputdouble(&((*(comdi+arrow)).price),"\n								==>售价：");
							inputdouble(&((*(comdi+arrow)).pprice),"\n								==>进价：");
							inputint(&((*(comdi+arrow)).sold),"\n								==>售量：");
							inputint(&((*(comdi+arrow)).amount),"\n								==>进量：");
							inputcollect(&((*(comdi+arrow)).collect),"\n								==>已收金额（ 当前已收：%9.2lf ）：",(((*(comdi+arrow)).price)*((*(comdi+arrow)).sold)));
							 ((*(comdi+arrow)).rest)=((*(comdi+arrow)).amount)-((*(comdi+arrow)).sold);
							 ((*(comdi+arrow)).total)=((*(comdi+arrow)).pprice)*((*(comdi+arrow)).amount);
							 ((*(comdi+arrow)).profit)=((*(comdi+arrow)).collect)-((*(comdi+arrow)).total);
						}
					}else{//修改
						pagenum=page;arrownum=arrow;page=1;arrow=0;
						for(i=0,k=0;i<n;i++) if(strcmp((*(comdi+i)).check,"**")==0) (*(re+(k++)))=(*(comdi+i));
						mdfselt:	
						system("cls");
						printfspxx(re,k);
						gotoxy(1,40);
						printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("\n        1 同类型                                             2 同售价                                             3 同售量                                            4 同已收金额        \n");
						printf("\n        5 同名称                                             6 同生产商                                           7 同进价                                            8 同进量            \n");
						printf("\n                                                           回车 返回\n");
						ch=getch();
						clearx();
						switch(ch){
							case '/':arrowdown(k);	goto mdfselt;	break;
							case '*':arrowup(k);	goto mdfselt;	break;
							case '-':pagedown(k);	goto mdfselt;	break;
							case '+':pageup(k);		goto mdfselt;	break;
							case '1':{	//同类型
								inputchar(str,11,"\n								==>同类型（ 回车：返回）：");
								if(strlen(str)==0) goto mdfselt;
								for(i=0;i<n;i++)
									if(strcmp((comdi+i)->check,"**")==0) strcpy((*(comdi+i)).type,str);
								break;
							}
							case '2':{	//同售价 
								inputdouble(&doublenum,"\n								==>同售价：");
								for(i=0;i<n;i++)
									if(strcmp((comdi+i)->check,"**")==0) (*(comdi+i)).price=doublenum; 
								break;
							}
							case '3':{	//同售量 
								inputint(&k,"\n								==>同售量：");
								for(i=0;i<n;i++)
									if(strcmp((comdi+i)->check,"**")==0) (*(comdi+i)).sold=k; 
								break;
							}
							case '4':{	//同已收金额 
								inputdouble(&doublenum,"\n								==>同已收金额：");
								for(i=0;i<n;i++)
									if(strcmp((comdi+i)->check,"**")==0) (*(comdi+i)).collect=doublenum; 
								break;
							}
							case '5':{
								inputchar(str,21,"\n								==>同名称（ 回车：返回）：");
								if(strlen(str)==0) goto mdfselt;
								for(i=0;i<n;i++)
									if(strcmp((*(comdi+i)).check,"**")==0)
										strcpy(((*(comdi+i)).name),str);
								break;
							}
							case '6':{	//同生产商 
								inputchar(str,21,"\n								==>同生产商（ 回车：返回）：");
								if(strlen(str)==0) goto mdfselt;
								for(i=0;i<n;i++)
										if(strcmp((comdi+i)->check,"**")==0) strcpy((*(comdi+i)).producer,str);
								break;
							}
							case '7':{	//同进价 
								inputdouble(&doublenum,"\n								==>同进价：");
								for(i=0;i<n;i++)
									if(strcmp((comdi+i)->check,"**")==0) (*(comdi+i)).pprice=doublenum; 
								break;
							}
							case '8':{	//同进量 
								inputint(&k,"\n								==>同进量：");
								for(i=0;i<n;i++)
									if(strcmp((comdi+i)->check,"**")==0) (*(comdi+i)).amount=k; 
								break;
							}
							case 13:page=pagenum;arrow=arrownum;goto seller; break;
							default:printf("\n\n								==>输入有误！请重新选择");getch(); goto mdfselt; break;
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
							clearx(); printf("\n								==>修改成功!\n");
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
			case '3':{	//搜已选 
				clearx();
				if(n==0){
					printf("\n								==>暂无商品信息！请先输入商品信息。\n"); getch();
				}else{
					for(i=x=0;i<n;i++)
						if(strcmp((comdi+i)->check,"**")==0) (*(re+(x++)))=(*(comdi+i));
					if(x==0){
						printf("\n								==>请选选定信息！\n"); getch();
					}else{
						pagenum=page;arrownum=arrow;	page=1;arrow=0;
						query(re,x);
						page=pagenum;arrow=arrownum;
					}
				}break;
			}
			case '4':{	//取选 
				clearx();
				if(n==0){
					printf("\n								==>暂无商品信息！请先输入信息。"); getch();
				}else strcpy((comdi+arrow)->check,"  ");
				break;
			}
			case '5':{	//选定 
				clearx();
				if(n==0){
					printf("\n								==>暂无商品信息！请先输入信息。"); getch();
				}else strcpy((comdi+arrow)->check,"**");
				break;
			}
			case '6':{	//全都选 
				clearx();
				if(n==0){
					printf("\n								==>暂无商品信息！请先输入信息。"); getch();
				}else for(i=0;i<n;i++) strcpy((comdi+i)->check,"**");
				break;
			}
			case '7':{	//统计已选 
				for(i=x=0;i<n;i++)
					if(strcmp((comdi+i)->check,"**")==0)
						(*(re+(x++)))=(*(comdi+i));
				if(x) count(re,x,1);
				else{
					clearx();
					printf("\n								==>请选选定信息！"); getch();
				}
				break;
			}
			case '8':{	//排序 
				while(1){	sortselt:
					breakflag=1;
					clearx();
					printf("\n        1 编号                           2 类型                           3 售价                           4 售量                           5 已收金额                       6 库存         \n");
					printf("\n        7 名称                           8 生产商                         9 进价                           a 进量                           b   成本                         c 收益         \n");
					printf("\n                                                                       回车 返回\n");
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
						default:breakflag=0; printf("\n								==>输入有误！请重新选择\n");getch(); break;
					}if(breakflag) break;
				}
				while(1){
					breakflag=1;
					clearx();
					printf("\n								1 升序			2 降序			回车 返回\n");
					ch=getch();
					switch(ch){
						case '1': 	break;
						case '2':selt+=1;	break;
						case  13:goto sortselt;	break;
						default:breakflag=0; printf("\n								==>输入有误！请重新输入\n");getch();	break;
					}if(breakflag) break;
				}
				sort(comdi,n,selt);
				clears();
				printfspxx(comdi,n);
				clearx();
				printf("\n								==>修改排序成功！\n");getch();
				break;
			}
			case 'a':{	//删除
				clearx(); 
				if(n==0){
					printf("\n								==>无商品信息！"); getch();
				}
				else{
					for(i=k=0;i<n;i++)
						if(strcmp((comdi+i)->check,"**")==0) (*(re+(k++)))=(*(comdi+i));
					if(k==0){
						clearx();
						printf("\n								==>是否删除指定的信息（ Y/N 回车Y ) ?");
						ch=getch();
						if(ch=='n'||ch=='N'){
							clearx();
							printf("\n								==>已取选删除\n"); getch();
						}else{
							delaspxx(comdi,n,arrow);
							n--; arrow--; saveflag=1;
							clears();
							printfspxx(comdi,n);
							clearx();
							printf("\n								==>已成功删除！\n"); getch();
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
							printf("\n								==>是否删除以上信息（ Y/N 回车Y ) ?");
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
							printf("\n								==>已取选删除\n"); getch();
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
							printf("\n								==>已成功删除！\n"); getch();
						}
					}									
				}
				break;
			}
			case 'b':clearx();	save(comdi,n); 	break;
			case 'c':{	//搜整表
				clearx();
				if(n==0){
					printf("\n								==>暂无商品信息！请先输入商品信息。\n"); getch();
				}else{
					pagenum=page;arrownum=arrow;	page=1;arrow=0;
					query(comdi,n);
					page=pagenum;arrow=arrownum;
				}break;
			}
			case 'd':{	//反选 
				clearx();
				if(n==0){
					printf("\n								==>暂无商品信息！请先输入信息。"); getch();
				}else for(i=0;i<n;i++){
						if(strcmp((comdi+i)->check,"**")==0) strcpy((comdi+i)->check,"  ");
						else strcpy((comdi+i)->check,"**");
					}
				break;
			}
			case 'e':{	//改密 
				clearx();
				if(strlen(mi)!=0){
					while(1){
						i=0;
						clearx();
						printf("\n\n\n\n								直接回车：返回主菜单");
						gotoxy(1,41);
						printf("\n								==>原密码（ 1~10 位 ）：");
						gets(str);
						if(strlen(str)==0) goto seller;
						if(strcmp(mi,str)==0) break;
						else printf("\n\n								==>密码错误！请重新输入密码。       ");
						getch(); clearx();
					}
				}
				setmi:
				clearx();
				printf("\n\n\n\n								直接回车：返回主菜单");
				gotoxy(1,41);
				printf("\n								==>新密码（ 1~10 位 ）：");
				gets(str);
				if(strlen(str)==0) break;
				else if(strlen(str)>10){
					printf("\n\n								==>密码长度超出范围！请重新输入。"); getch(); goto setmi;
				}
				detm:
				clearx();
				printf("\n\n\n\n								直接回车：返回主菜单");
				gotoxy(1,41);
				printf("\n								==>确定新密码（ 1~10 位 ）：");
				gets(str2);
				if(strlen(str2)==0) break;
				else if(strlen(str2)>10){
					printf("\n\n								==>密码长度超出范围！请重新输入。"); getch(); goto detm;
				}else if(strcmp(str,str2)!=0){
					printf("\n\n								==>与新密码不相同！请重新输入。"); getch(); goto detm;
				}
				strcpy(mi,str);
				clearx();
				printf("\n								==>修改密码成功！"); getch();
				for(i=0;mi[i]!='\0';i++){	//加密密码文件 
					mi[i]=mi[i]+5;
					mi[i]=mi[i]*2;
					mi[i]=mi[i]-9;
				}
				fp=fopen("d:\\商品信息管理系统\\密码.txt","w");
				if(!fp){
					printf("\n								==>密码文件打开失败！无法存盘。\n"); getch();
				}
				for(i=0;i<(strlen(mi));i++){
					if(fwrite(mi+i,1,1,fp)==1);
						else break;
				}
				if(i!=(strlen(mi))) printf("\n								==>保存密码至文件失败！已成功保存 %d 位密码，共 %d 位密码。\n",i,strlen(mi));
				break;
			}
			case 'f':{	//全不选 
				clearx();
				if(n==0){
					printf("\n								==>暂无商品信息！请先输入信息。"); getch();
				}else for(i=0;i<n;i++) strcpy((comdi+i)->check,"  ");
				break;
			}			
			case 'g':count(comdi,n,2);	break;	//统计整表 
			case 'h':{
				clearx();
				printf("\n								==>退出系统（ Y/N )？\n");
				ch=getch();
				if(ch=='y'||ch=='Y'){
					if(saveflag){
						clearx();
						printf("\n								==>您已修改内容，是否存盘（ Y/N ）？\n");
						ch=getch();
						if(ch=='y'||ch=='Y')	save(comdi,n);
						else{
							printf("\n								==>已取消存盘\n");getch();
						}
					}clearx();
					printf("\n								==>感谢您使用本系统！期待下次继续为您服务~~\n");	getch();
					return 0;
				}else printf("\n								==>已取消退出\n");getch();
				break;
			} 
			default:{
				printf("\n\n								==>输入有误！请重新选择。"); getch();
				break;
			}
		}
	}return 0;
} 
