//Travelling Salesman Problem by dyanamic programming
//Prashant Suryavanshi 
//10D070051
#include<stdio.h>
#include<conio.h>
int main()
{
int l[10][10],g[10][10],i,j,k,n,a,temp,temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8;
//------------------------------------------------------
printf("TSP solution for total number of nodes in a directed graph= 4\n");
printf("Now enter the cost between two nodes\n");
//printf("\nEnter the no. of nodes in the graph=");
//scanf("%d", &n);
n=4;
//------------------------------------------------------
//entries of cost in the graph between two nodes
for (i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("\nl[%d][%d]=",i,j);
			scanf("%d", &a);
			l[i][j]=a;
		}
	}
//Reprinting the whole matrix
printf("\n The Cost Matrix");
for (i=1;i<=n;i++)
	{
		printf("\n");
		for(j=1;j<=n;j++)
		{
		printf("\t%d", l[i][j]);
		}
	}
//-----------------------------------------------
//When S={phi} i.e. no vertex to cover
for(i=1;i<=n;i++)
	{
		g[i][0]=l[i][1];
	}
//printf("\n\n g[2][0]=%d", g[2][0]);	

//-----------------------------------------------
//When S=1 means only one vertex to cover
//g[i][j] means starting from node 1 then i to j to 1
for(i=2;i<=n;i++)
	{
		for(j=2;j<=n;j++)
		{
			g[i][j]=l[i][j] + g[j][0];
		}
	}
//printf("\n\n g[2][3]=%d", g[2][3]);
//-----------------------------------------------

//When S=2 means two vertex to cover
//g[2][3,4] calculation
temp=l[2][3] + g[3][4];
temp1=l[2][4] + g[4][3];
if(temp<temp1)
	{
		g[2][3,4]=temp;
		//printf("\n\n g[2-3-4-1]");
	}
else 
	{
		g[2][3,4]=temp1;
		//printf("\n\n g[2-4-3-1]");
	}
//printf("\n\n g[2][3,4]=%d", g[2][3,4]);

//g[3][2,4] calculation
temp2=l[3][2] + g[2][4];
temp3=l[3][4] + g[4][2];
if(temp2<temp3)
	{
		g[3][2,4]=temp2;
		//printf("\n\n g[3-2-4-1]");
	}
else 
	{
		g[3][2,4]=temp3;
		//printf("\n\n g[3-4-2-1]");
	}
//printf("\n\n g[3][2,4]=%d", g[3][2,4]);

//g[4][2,3] calculation
temp4=l[4][2] + g[2][3];
temp5=l[4][3] + g[3][2];
if(temp4<temp5)
	{
		g[4][2,3]=temp4;
		//printf("\n\n g[4-2-3-1]");
	}
else
	{
		g[4][2,3]=temp5;
		//printf("\n\n g[4-3-2-1]");
	} 

//printf("\n\n g[4][2,3]=%d", g[4][2,3]);
//---------------------------------------------------------

//when S=3 means has to cover 3 vertex
temp6=l[1][2] + g[2][3,4];
temp7=l[1][3] + g[3][2,4];
temp8=l[1][4] + g[4][2,3];

	if(temp7>temp6 & temp8>temp6)
		{
			g[1][2,3,4]=temp6;
			if(temp<temp1)
			{
				printf("\n\n MINIMAL PATH is 1-2-3-4-1");
			}
			else 
			{
				printf("\n\n MINIMAL PATH is 1-2-4-3-1");	
			}
		}
	else if(temp7>temp8 & temp6>temp8)
		{
			g[1][2,3,4]=temp8;
			if(temp4<temp5)
			{
				printf("\n\n MINIMAL PATH is 1-4-2-3-1");
			}
			else 
			{
				printf("\n\n MINIMAL PATH is 1-4-3-2-1");	
			}
			
		}	
	else
		{
			g[1][2,3,4]=temp7;
			if(temp2<temp3)
			{
				printf("\n\n MINIMAL PATH is 1-3-2-4-1");
			}
			else 
			{
				printf("\n\n MINIMAL PATH is 1-3-4-2-1");	
			}
		}		
printf("\n\n and cost of MINIMAL PATH is:g[1][2,3,4]=%d", g[1][2,3,4]);	
//-------------------------------------------------------------------
//But what's the path direction
//can be determined by intermediate stages
//-------------------------------------------------------------------
//-------------------------------------------------------------------
//-------------------------------------------------------------------
//Now considering path starting from node 2 and also ends at 2
int temp9,temp10,temp11,temp12,temp13,temp14,temp15,temp16,temp17;
//-----------------------------------------------
//When S={phi} i.e. no vertex to cover
//path lengths ending at node 2
//g[i][0] => means starting from node i and ending at node 2 without covering any vertex
for(i=1;i<=n;i++)
	{
		g[i][0]=l[i][2];
	}
//printf("\n\n g[2][0]=%d", g[2][0]);	

//-----------------------------------------------
//When S=1 means only one vertex to cover
//g[i][j] means starting from node i to j to 2
for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			g[i][j]=l[i][j] + g[j][0];
		}
	}
//printf("\n\n g[3][1]=%d", g[3][1]);
//-----------------------------------------------

//When S=2 means two vertex to cover
//g[1][3,4] calculation
temp9=l[1][3] + g[3][4];
temp10=l[1][4] + g[4][3];
if(temp9<temp10)
	{
		g[1][3,4]=temp9;
		//printf("\n\n g[1-3-4-2]");
	}
else 
	{
		g[1][3,4]=temp10;
		//printf("\n\n g[1-4-3-2]");
	}
//printf("\n\n g[1][3,4]=%d", g[1][3,4]);

//g[3][1,4] calculation
temp11=l[3][1] + g[1][4];
temp12=l[3][4] + g[4][1];
if(temp11<temp12)
	{
		g[3][1,4]=temp11;
		//printf("\n\n g[3-1-4-2]");
	}
else 
	{
		g[3][1,4]=temp12;
		//printf("\n\n g[3-4-1-2]");
	}
//printf("\n\n g[3][1,4]=%d", g[3][1,4]);

//g[4][1,3] calculation
temp13=l[4][1] + g[1][3];
temp14=l[4][3] + g[3][1];
if(temp13<temp14)
	{
		g[4][1,3]=temp13;
		//printf("\n\n g[4-1-3-2]");
	}
else
	{
		g[4][1,3]=temp14;
		//printf("\n\n g[4-3-1-2]");
	} 

//printf("\n\n g[4][1,3]=%d", g[4][1,3]);
//---------------------------------------------------------

//when S=3 means has to cover 3 vertex
temp15=l[2][1] + g[1][3,4];
temp16=l[2][3] + g[3][1,4];
temp17=l[2][4] + g[4][1,3];
//printf("\n\n g[2][1,,]=%d", temp15);
//printf("\n\n g[2][3,,]=%d", temp16);
//printf("\n\n g[2][4,,]=%d", temp17);

	if(temp16>temp15 & temp17>temp15)
		{
			g[2][1,3,4]=temp15;
			if(temp9<temp10)
			{
				printf("\n\n MINIMAL PATH is 2-1-3-4-2");
			}
			else 
			{
				printf("\n\n MINIMAL PATH is 2-1-4-3-2");	
			}
		}
	else if(temp16>temp17 & temp15>temp17)
		{
			g[2][1,3,4]=temp17;
			if(temp13<temp14)
			{
				printf("\n\n MINIMAL PATH is 2-4-1-3-2");
			}
			else 
			{
				printf("\n\n MINIMAL PATH is 2-4-3-1-2");	
			}
			
		}	
	else
		{
			g[2][1,3,4]=temp16;
			if(temp11<temp12)
			{
				printf("\n\n MINIMAL PATH is 2-3-1-4-2");
			}
			else 
			{
				printf("\n\n MINIMAL PATH is 2-3-4-1-2");	
			}
		}		
printf("\n\n and cost of MINIMAL PATH is:g[2][1,3,4]=%d", g[2][1,3,4]);	
//------------------------------------------------------------------------
//------------------------------------------------------------------------
//-------------------------------------------------------------------
//--------------------------------------------------------------------
//Now considering path starting from node 3 and also ends at 3
int temp20,temp21,temp22,temp23,temp24,temp25,temp26,temp27,temp28;
//When S={phi} i.e. no vertex to cover
for(i=1;i<=n;i++)
	{
		g[i][0]=l[i][3];
	}
//printf("\n\n g[2][0]=%d", g[2][0]);	

//-----------------------------------------------
//When S=1 means only one vertex to cover
//g[i][j] means starting from node 1 then i to j to 1
for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			g[i][j]=l[i][j] + g[j][0];
		}
	}
//printf("\n\n g[2][3]=%d", g[2][3]);
//-----------------------------------------------

//When S=2 means two vertex to cover
//g[1][2,4] calculation
temp20=l[1][2] + g[2][4];
temp21=l[1][4] + g[4][2];
if(temp20<temp21)
	{
		g[1][2,4]=temp20;
		//printf("\n\n g[1-2-4-3]");
	}
else 
	{
		g[1][2,4]=temp21;
		//printf("\n\n g[1-4-2-3]");
	}
//printf("\n\n g[1][2,4]=%d", g[1][2,4]);

//g[2][1,4] calculation
temp22=l[2][1] + g[1][4];
temp23=l[2][4] + g[4][1];
if(temp22<temp23)
	{
		g[2][1,4]=temp22;
		//printf("\n\n g[2-1-4-3]");
	}
else 
	{
		g[2][1,4]=temp23;
		//printf("\n\n g[2-4-1-3]");
	}
//printf("\n\n g[2][1,4]=%d", g[2][1,4]);

//g[4][1,2] calculation
temp24=l[4][1] + g[1][2];
temp25=l[4][2] + g[2][1];
if(temp24<temp25)
	{
		g[4][1,2]=temp24;
		//printf("\n\n g[4-1-2-3]");
	}
else
	{
		g[4][1,2]=temp25;
		//printf("\n\n g[4-2-1-3]");
	} 

//printf("\n\n g[4][1,2]=%d", g[4][1,2]);
//---------------------------------------------------------

//when S=3 means has to cover 3 vertex
temp26=l[3][1] + g[1][2,4];
temp27=l[3][2] + g[2][1,4];
temp28=l[3][4] + g[4][1,2];

	if(temp27>temp26 & temp28>temp26)
		{
			g[3][1,2,4]=temp26;
			if(temp20<temp21)
			{
				printf("\n\n MINIMAL PATH is 3-1-2-4-3");
			}
			else 
			{
				printf("\n\n MINIMAL PATH is 3-1-4-2-3");	
			}
		}
	else if(temp27>temp28 & temp26>temp28)
		{
			g[3][1,2,4]=temp28;
			if(temp24<temp25)
			{
				printf("\n\n MINIMAL PATH is 3-4-1-2-3");
			}
			else 
			{
				printf("\n\n MINIMAL PATH is 3-4-2-1-3");	
			}
			
		}	
	else
		{
			g[3][1,2,4]=temp27;
			if(temp22<temp23)
			{
				printf("\n\n MINIMAL PATH is 3-2-1-4-3");
			}
			else 
			{
				printf("\n\n MINIMAL PATH is 3-2-4-1-3");	
			}
		}		
printf("\n\n and cost of MINIMAL PATH is:g[3][1,2,4]=%d", g[3][1,2,4]);	
//-------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------
//-------------------------------------------------------------------
//Now considering path starting from node 4 and also ends at 4
int temp30,temp31,temp32,temp33,temp34,temp35,temp36,temp37,temp38;
//-----------------------------------------------
//When S={phi} i.e. no vertex to cover
for(i=1;i<=n;i++)
	{
		g[i][0]=l[i][4];
	}
//printf("\n\n g[2][0]=%d", g[2][0]);	

//-----------------------------------------------
//When S=1 means only one vertex to cover
//g[i][j] means starting from node i to j to 4
for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			g[i][j]=l[i][j] + g[j][0];
		}
	}
//printf("\n\n g[2][3]=%d", g[2][3]);
//-----------------------------------------------

//When S=2 means two vertex to cover
//g[1][2,3] calculation
temp30=l[1][2] + g[2][3];
temp31=l[1][3] + g[3][2];
if(temp30<temp31)
	{
		g[1][2,3]=temp30;
		//printf("\n\n g[1-2-3-4]");
	}
else 
	{
		g[1][2,3]=temp31;
		//printf("\n\n g[1-3-2-4]");
	}
//printf("\n\n g[1][2,3]=%d", g[1][2,3]);

//g[2][1,3] calculation
temp32=l[2][1] + g[1][3];
temp33=l[2][3] + g[3][1];
if(temp32<temp33)
	{
		g[2][1,3]=temp32;
		//printf("\n\n g[2-1-3-4]");
	}
else 
	{
		g[2][1,3]=temp33;
		//printf("\n\n g[2-3-1-4]");
	}
//printf("\n\n g[3][2,4]=%d", g[3][2,4]);

//g[3][1,2] calculation
temp34=l[3][1] + g[1][2];
temp35=l[3][2] + g[2][1];
if(temp34<temp35)
	{
		g[3][1,2]=temp34;
		//printf("\n\n g[3-1-2-4]");
	}
else
	{
		g[3][1,2]=temp35;
		//printf("\n\n g[3-2-1-4]");
	} 

//printf("\n\n g[3][1,2]=%d", g[3][1,2]);
//---------------------------------------------------------

//when S=3 means has to cover 3 vertex
temp36=l[4][1] + g[1][2,3];
temp37=l[4][2] + g[2][1,3];
temp38=l[4][3] + g[3][1,2];

	if(temp37>temp36 & temp38>temp36)
		{
			g[4][1,2,3]=temp36;
			if(temp30<temp31)
			{
				printf("\n\n MINIMAL PATH is 4-1-2-3-4");
			}
			else 
			{
				printf("\n\n MINIMAL PATH is 4-1-3-2-4");	
			}
		}
	else if(temp37>temp38 & temp36>temp38)
		{
			g[4][1,2,3]=temp38;
			if(temp34<temp35)
			{
				printf("\n\n MINIMAL PATH is 4-3-1-2-4");
			}
			else 
			{
				printf("\n\n MINIMAL PATH is 4-3-2-1-4");	
			}
			
		}	
	else
		{
			g[4][1,2,3]=temp37;
			if(temp32<temp33)
			{
				printf("\n\n MINIMAL PATH is 4-2-1-3-4");
			}
			else 
			{
				printf("\n\n MINIMAL PATH is 4-2-3-1-4");	
			}
		}		
printf("\n\n and cost of MINIMAL PATH is:g[4][1,2,3]=%d", g[4][1,2,3]);	
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
getch();	
}
