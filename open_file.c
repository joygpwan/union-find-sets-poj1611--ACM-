#include <stdio.h>


void Init(int n);
int find(int x);
void connect(int a,int b);


int  father[1000];
int  h[1000];
int  num[1000];


int  main()
{

	FILE *fp;
	char buffer[100],*buf;
	int  m,n,rn,a,b,i,j,x;



	fp=fopen("test_input.txt","r");
	if(NULL==fp){
		printf("open  error!\n");
		return  -1;

	}
	while(1){
		printf("in  while\n");

		Init(1000);
		buf=buffer;
		if(fgets(buf, 100, fp) != NULL){
			sscanf(buf,"%d",&m);
		

			while(*buf != ' ')
				buf++;

			if  (m==0)
				return -1;

			while(*buf == ' ')
				buf++;
			sscanf(buf,"%d",&n);

			if(n==0){
				printf("reslut 1\n");
				break;
			}

			for( i=0;i<n;i++){
				buf=buffer;
				if(fgets(buf, 100, fp) == NULL)
					return -1;
				sscanf(buf,"%d",&rn);

				while(*buf != ' ')
					buf++;
				while(*buf == ' ')
					buf++;
				sscanf(buf,"%d",&a);

				while(*buf != ' ')
					buf++;
				for( j=0;j<rn-1;j++){
					while(*buf == ' ')
						buf++;
					sscanf(buf,"%d",&b);
					while(*buf != ' '){
						if(j==rn-2)
							break;
						buf++;
					}

					connect( a, b);  

				}

			}
			x=find(0);
			printf("result  is :%d\n",num[x]);

		}
		else{
		
			return 1;;
		
		}
	}	
	fclose(fp);



}



void Init(int n)
{
	int i;
	for( i=0;i<n;i++)
    {
		father[i]=i;
		h[i]=0;
		num[i]=1;
	}
}



int find(int x)
{
	if(x!=father[x])
	father[x]=find(father[x]);
	return father[x];
 }


void connect(int a,int b)
{
	int x,y;
	x=find(a);
	y=find(b);
	if(x==y)
		return ;
	if(h[x]<h[y]){
		father[x]=y;
		num[y]+=num[x];
	}
	else
		{
			if(h[x]==h[y])
				h[x]++;
			father[y]=x;
			num[x]+=num[y];
	    }
	}




