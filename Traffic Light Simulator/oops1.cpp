#include<bits/stdc++.h>
using namespace std;
int main()
{
	time_t curtime;
	struct tm * timeinfo;
	char buffer[80];
	time(&curtime);
	timeinfo=localtime(&curtime);
	
//	strftime(buffer,80,"TIME: %I:%M:%S %p\n",timeinfo);
//	puts(buffer);
//	ofstream nodefile;
//	
//	clock_t ctime;
	
	ofstream myfile;
	myfile.open("traffic.txt");
	for(int i=0;i<600;i++)
	{
		myfile<<rand()%10<<" "<<rand()%10<<" "<<rand()%10<<" "<<rand()%10<<endl;
	}
	myfile.close();
	
	
	int a=0,b=0,c=0,d=0,num[4];
	ifstream f2;
	f2.open("traffic.txt");
	for(int i=0;i<600;i++)
	{
		f2>>num[0]>>num[1]>>num[2]>>num[3];
		a+=num[0];
		b+=num[1];
		c+=num[2];
		d+=num[3];
		if(i%4 == 3 && i%15==3)	
		{
			a-=min(1000,a);
			cout<<"Road A :: GREEN"<<endl;
			cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		}
		if(i%4 == 3 && i%15==7)	
		{
			b-=min(1000,b);
			cout<<"Road B :: GREEN"<<endl;
			cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		}
		if(i%4 == 3 && i%15==11)	
		{
			c-=min(1000,c);
			cout<<"Road C :: GREEN"<<endl;
			cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		}
		if(i%4 == 3 && i%15==0)	
		{
			d-=min(1000,d);
			cout<<"Road D :: GREEN"<<endl;
			cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		}
	
	}
	f2.close();
	return 0;
}
