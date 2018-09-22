#include<bits/stdc++.h>
using namespace std;
#define MAXTIME 350
#define MAXEMERGENCY 4
class InputGenerator{
  int random[4];
  int emergencyPath,emergencyTime;
  public:
    void randomGenLoad(ofstream &f2);
    void randomGenEmergency(ofstream &f3);
};

void InputGenerator::randomGenLoad(ofstream &f2)
{
  for(int j=1;j<=MAXTIME;j++){
    for(int i=0;i<4;i++){
      random[i]=rand()%10 + (rand()%3);
      f2<<random[i]<<" ";
    }
    f2<<endl;
  }
}

void InputGenerator::randomGenEmergency(ofstream &f3)
{
  f3<<100<<" "<<2<<endl;
  for(int j=2;j<=MAXEMERGENCY;j++){
    emergencyTime=rand()%100 + 120*(j-1);
    emergencyPath=rand()%4;
    f3<<emergencyTime<<" "<<emergencyPath<<endl;
  }
}

int main()
{
  InputGenerator inputload,inputemergency;

  ofstream f2;
  f2.open("traffic.txt");
  inputload.randomGenLoad(f2);
  f2.close();

  ofstream f3;
  f3.open("emergency.txt");
  inputemergency.randomGenEmergency(f3);
  f3.close();
  return 0;
}
