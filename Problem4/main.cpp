#include<iostream>
using namespace std;
int alice[3][3],bob[3][3],gameNum[3][3],AliceGame,BobGame,a,b;
//alice and bob game a,b first line Example 2 
int k,ans1,ans2,sm1,sm2;
void points(int x,int y)
{
	if(x==y)
	{
	  	return;
	}   
	if(x==3 && y==2 || x==2 && y==1 || x==1 && y==3)
	{
	 sm1++;
	}
	else
	{
	 sm2++;
	}
}
void Playing()
{
	int num=0,sum1=0,sum2=0,a=AliceGame,b=BobGame;
	while(gameNum[AliceGame][BobGame]==0 && num<k)
	{
		num++;
		points(AliceGame,BobGame);
		gameNum[AliceGame][BobGame]=num;
		int t1=AliceGame,t2=BobGame;
		AliceGame=alice[t1][t2];
		BobGame=bob[t1][t2];
	}
	ans1+=sm1; //nategt alice 2
	ans2+=sm2; //pop 1
	k-=num; //8-4=4
	if(AliceGame!=a || BobGame!=b) //2 1 ,1 1
	{
		num=num-gameNum[AliceGame][BobGame]+1;
		// num 3
	}
	sum1=sm1;
	sum2=sm2;
	sm1=sm2=0;
	while(a!=AliceGame || b!=BobGame) //2 1 ,1 1
	{
		points(a,b); //1 1 
		int t1=a,t2=b; 
		a=alice[t1][t2],b=bob[t1][t2];
	}
	sm1=sum1-sm1; //2
	sm2=sum2-sm2; //1
	ans1+=sm1*(k/num); //2+2 * 4/3 =4
	ans2+=sm2*(k/num);//2
	k%=num; //1
	sm1=sm2=0;
	while(k>0)
	{
		k--; //0
		points(AliceGame,BobGame); //2 1
		int t1=AliceGame,t2=BobGame;
		AliceGame=alice[t1][t2];
		BobGame=bob[t1][t2];
	}
	ans1+=sm1;
	ans2+=sm2;
	cout<<ans1<<" "<<ans2;
}
int main(void)
{ 
    cout<<"enter k ,a ,b" <<endl;
	cin>>k>>AliceGame>>BobGame;
	cout<<"enter matrix a "<<endl;
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>alice[i][j];
		}
	}
	cout<<"enter matrix b "<<endl;
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>bob[i][j];
		}
	}
		
	Playing();
	
	return 0;
}

