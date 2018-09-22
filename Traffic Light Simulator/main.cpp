#include<bits/stdc++.h>
using namespace std;
#define MAXTIME 350
#define MAXEMERGENCY 4
#define AMBON 1
#define AMBOFF 0

class TimeEstimator{
protected:
  int estimate_time;
public:
  TimeEstimator(int t1){
    estimate_time=t1;
  }
  void rRabin(int roadLoad);
};


void TimeEstimator::rRabin(int roadLoad)
{
		if(roadLoad<500)  estimate_time=max(2,(int)ceil( (float)roadLoad/20 ) );
		else              estimate_time=30;
}


class EmergencyHandler{
private:
  int static emergencyCounter;
  int ambulance[MAXEMERGENCY];
  int ambulancePath[MAXEMERGENCY];
  int ambulanceTime;
protected:
  bool emergencySignal;
  int emergencyTime;    //Time required to pass ambulance
  int emergencyPath;    //The emergency path
public:
  EmergencyHandler(bool b1,int t2,int t3){
    emergencySignal=b1;
    emergencyTime=t2;
    emergencyPath=t3;
    ifstream infile;
	  infile.open("emergency.txt");
	  if(!infile){
	    perror("Error in opening output.txt\n\n");
	    exit(1);
	  }
	  for(int i=0;i<MAXEMERGENCY;i++){
	    infile>>ambulance[i]>>ambulancePath[i];
	  }
	  infile.close();
  }
  bool isEmergency(int presentTime);
  int getEmergencyPath();
  void evalEmergencyTime(int load);
};
int EmergencyHandler::emergencyCounter=0;


bool EmergencyHandler::isEmergency(int presentTime)
{
  if(ambulance[emergencyCounter]==presentTime){
    emergencySignal=true;
    emergencyPath=ambulancePath[emergencyCounter];
    emergencyCounter++;
  }
  else{
    emergencySignal=false;
  }
  return emergencySignal;
}


int  EmergencyHandler::getEmergencyPath()
{
  return emergencyPath;
}


void  EmergencyHandler::evalEmergencyTime(int load)
{
  emergencyTime=max( 2 ,  (int)ceil(load/(float)20) );
}


class TrafficLight: public TimeEstimator,public EmergencyHandler{
	int road[4];
	int road_time[4];
	int counter;
	int rate;
	bool change;
	int prev_path;
public:
	TrafficLight(int rate):TimeEstimator(0),EmergencyHandler(false,-1,0){
	  this->rate=rate;
		change=true;
		counter=-1;
		for(int i=0;i<4;i++){
		  road[i]=road_time[i]=0;
		}
	}

	void traffic_flow(int presentTime,ofstream &outfile){
	  if(isEmergency(presentTime)){
	    cout<<"Emergency occurred | ";
      prev_path=counter;
      counter=emergencyPath;
      cout<<"Path changed from "<<prev_path<<" to "<<counter<<" | ";
      evalEmergencyTime(road[counter]);
      cout<<"EmergencyTime "<<emergencyTime<<" | ";
      road_time[counter]=emergencyTime;
    }
    else
	  if(emergencyTime>0){
		  emergencyTime--;

		  cout<<"EmergencyTime "<<emergencyTime<<" | ";
		}
		else
		if(change && (emergencySignal==false) ){
			counter=(counter+1)%4;
			rRabin(road[counter]);
			road_time[counter]=estimate_time;
			cout<<" Estimate time "<<estimate_time<<" | ";
			//display();
			change=false;
		}

    if(emergencyTime==0){
        cout<<"Path resumed from "<<counter<<" to "<<prev_path<<" | ";
		    counter=prev_path;
		    emergencyTime--;
		}
    outfile<<counter<<" "<<( (emergencySignal||emergencyTime>0) ? 1:0 )<<" "<<road_time[counter]<<endl;
		road_time[counter]=max(road_time[counter]-1,0);
		if(road_time[counter]==0 && !emergencySignal )	change=true;


		road[counter]=max(0,road[counter]-rate);
    cout<<" Counter "<<counter<<" | ";

	}

  void setRoad(int load[4]){
		for(int i=0;i<4;i++){
			road[i]+=load[i];
		}
	}

	int get_road(int ctr){
	  return road[ctr];
	}
/*
	void display(){
		cout<<"Road "<<counter<<" Green\n";
		cout<<"Load on Roads:";
		for(int i=0;i<4;i++)	cout<<road[i]<<" ";	cout<<endl;
		cout<<"Estimate Time alloated:"<<estimate_time<<endl;
		cout<<endl;
	}
*/
};


int main()
{
  TrafficLight n1(20);    //rate
  ifstream f1;
  f1.open("traffic.txt");
  if(!f1){
    perror("Error in opening traffic.txt\n\n");
    exit(5);
  }
  int amb=0,ambtime=2;
	ofstream outfile;
	outfile.open("output.txt");
  int load[4];
  for(int i=1;i<=MAXTIME;i++){
    cout<<"i "<<i<<" | ";
    f1>>load[0]>>load[1]>>load[2]>>load[3];

    n1.setRoad(load);

    for(int j=0;j<4;j++){
      cout<<n1.get_road(j)<<" ";
    }
    cout<<"| ";
    for(int j=0;j<4;j++)
      outfile<<n1.get_road(j)<<" ";

    n1.traffic_flow(i,outfile);

    cout<<endl;
  }
  f1.close();
  outfile.close();
  return 0;
}
