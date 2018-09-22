#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
#include<bits/stdc++.h>
#include<time.h>
#include<unistd.h>
#include<fstream>
#define NUM 4
int ambmultiply;
using namespace std;
ifstream m;
int TIMEE=0;
int A=100,B=100,C=100,D=100,chance=-1,amb,ambLocation=-60,rtime=0;
int yellowC=-1;
void DrawCircle(float cx, float cy, float r, int num_segments,int color) {
    int ii;
    int R=0,G=0,B=0;
    if(color==1) R=1;
    else if(color==2) R=G=1;
    else G=1;
    glColor3f(R,G,B);//printf("%d %d %d\n",R,G,B);
    glBegin(GL_POLYGON);
    for ( ii = 0; ii < num_segments; ii++)   {
        float theta = 2.0f * 3.1415926f * ((float)ii / num_segments);
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        glVertex2f(x + cx, y + cy);//output vertex
    }
    glEnd();
}
void make_traffic_lightH(int xx,int yy)
{
  glColor3f(0,0,0);
    glBegin(GL_POLYGON);
      glVertex2f(xx,yy);
      glVertex2f(xx,yy-30);
      glVertex2f(xx+90,yy-30);
      glVertex2f(xx+90,yy);
  glEnd();
}
void make_traffic_lightV(int xx,int yy)
{
  glColor3f(0,0,0);
    glBegin(GL_POLYGON);
      glVertex2f(xx,yy);
      glVertex2f(xx,yy-90);
      glVertex2f(xx+30,yy-90);
      glVertex2f(xx+30,yy);
  glEnd();
}
void make_road()
{
//road
  glColor3f(0,0,0);
      glBegin(GL_POLYGON);
        glVertex2f(-300,50);
        glVertex2f(300,50);
        glVertex2f(300,-50);
        glVertex2f(-300,-50);
      glEnd();
      glColor3f(0,0,0);
          glBegin(GL_POLYGON);
            glVertex2f(-50,300);
            glVertex2f(50,300);
            glVertex2f(50,-300);
            glVertex2f(-50,-300);
          glEnd();

  ///Divider
  glColor3f(1,1,0);
      glBegin(GL_POLYGON);
        glVertex2f(50,2);
        glVertex2f(300,2);
        glVertex2f(300,-2);
        glVertex2f(50,-2);
      glEnd();

      glColor3f(1,1,0);
        glBegin(GL_POLYGON);
          glVertex2f(2,-50);
          glVertex2f(2,-300);
          glVertex2f(-2,-300);
          glVertex2f(-2,-50);
      glEnd();

      glColor3f(1,1,0);
        glBegin(GL_POLYGON);
          glVertex2f(-50,-2);
          glVertex2f(-300,-2);
          glVertex2f(-300,2);
          glVertex2f(-50,2);
      glEnd();

      glColor3f(1,1,0);
        glBegin(GL_POLYGON);
          glVertex2f(2,50);
          glVertex2f(-2,50);
          glVertex2f(-2,300);
          glVertex2f(2,300);
      glEnd();

      int xx=-155,yy=90;
      make_traffic_lightH(xx,yy);
      xx=65,yy=-60;
      make_traffic_lightH(xx,yy);
      xx=65,yy=155;
      make_traffic_lightV(xx,yy);
      xx=-95,yy=-65;
      make_traffic_lightV(xx,yy);
}


void make_carH(int x,int y)
{
  glColor3f(1,0.5,0);
      glBegin(GL_POLYGON);
        glVertex2f(x+5,y-5);
        glVertex2f(x+20,y-5);
        glVertex2f(x+20,y-20);
        glVertex2f(x+5,y-20);
      glEnd();
      y=y-25;
      glColor3f(1,0.5,0);
          glBegin(GL_POLYGON);
            glVertex2f(x+5,y-5);
            glVertex2f(x+20,y-5);
            glVertex2f(x+20,y-20);
            glVertex2f(x+5,y-20);
          glEnd();
}

void make_carV(int x,int y)
{
  glColor3f(1,0.5,0);
      glBegin(GL_POLYGON);
        glVertex2f(x+5,y-5);
        glVertex2f(x+20,y-5);
        glVertex2f(x+20,y-20);
        glVertex2f(x+5,y-20);
      glEnd();
      x=x+25;
      glColor3f(1,0.5,0);
          glBegin(GL_POLYGON);
            glVertex2f(x+5,y-5);
            glVertex2f(x+20,y-5);
            glVertex2f(x+20,y-20);
            glVertex2f(x+5,y-20);
          glEnd();
}


void make_ambulanceH(int x,int y)
{
  glColor3f(1,1,1);
      glBegin(GL_POLYGON);
        glVertex2f(x+2,y-4);
        glVertex2f(x+23,y-4);
        glVertex2f(x+23,y-46);
        glVertex2f(x+2,y-46);
      glEnd();
      glColor3f(1,0,0);
          glBegin(GL_POLYGON);
            glVertex2f(x+4,y-22);
            glVertex2f(x+21,y-22);
            glVertex2f(x+21,y-28);
            glVertex2f(x+4,y-28);
          glEnd();
          glColor3f(1,0,0);
              glBegin(GL_POLYGON);
                glVertex2f(x+10,y-8);
                glVertex2f(x+14,y-8);
                glVertex2f(x+14,y-42);
                glVertex2f(x+10,y-42);
              glEnd();
}

void make_ambulanceV(int x,int y)
{
  glColor3f(1,1,1);
      glBegin(GL_POLYGON);
        glVertex2f(x+4,y-2);
        glVertex2f(x+46,y-2);
        glVertex2f(x+46,y-23);
        glVertex2f(x+4,y-23);
      glEnd();
      glColor3f(1,0,0);
          glBegin(GL_POLYGON);
            glVertex2f(x+8,y-10);
            glVertex2f(x+8,y-14);
            glVertex2f(x+42,y-14);
            glVertex2f(x+42,y-10);
          glEnd();
          glColor3f(1,0,0);
              glBegin(GL_POLYGON);
                glVertex2f(x+22,y-4);
                glVertex2f(x+22,y-21);
                glVertex2f(x+28,y-21);
                glVertex2f(x+28,y-4);
              glEnd();
}
void Display_traffic_light(bool a,bool b,bool c,bool d,bool Y)
{
  int radius=10;//printf("hello ");cout<<a<<" "<<b<<" "<<c<< " "<<endl;
  if(a || (Y && (chance+1)%4==0) )
  {
    if((chance+1)%4==0 && Y) DrawCircle(110, -75, radius, 100,2);
    else DrawCircle(140, -75, radius, 100,0);
  }
  else DrawCircle(80, -75, radius, 100,1);

  if(b || (Y && (chance+1)%4==1) )
  {
    if((chance+1)%4==1 && Y) DrawCircle(80, 110, radius, 100,2);
    else DrawCircle(80, 80, radius, 100,0);
  }
  else DrawCircle(80, 140, radius, 100,1);

  if(c || (Y && (chance+1)%4==2) )
  {
     if((chance+1)%4==2 && Y)DrawCircle(-110, 75, radius, 100,2);
     else DrawCircle(-80, 75, radius, 100,0);
  }
  else DrawCircle(-140, 75, radius, 100,1);

  if(d || (Y && (chance+1)%4==3) )
  {
    if((chance+1)%4==3 && Y)DrawCircle(-80, -110, radius, 100,2);
    else DrawCircle(-80, -140, radius, 100,0);
  }
  else DrawCircle(-80, -80, radius, 100,1);

}
/*void Display_traffic_light(bool a,bool b,bool c,bool d)
{
  int radius=10;//printf("hello ");cout<<a<<" "<<b<<" "<<c<< " "<<endl;
  if(a) DrawCircle(140, -75, radius, 100,0);
  else DrawCircle(80, -75, radius, 100,1);

  if(b) DrawCircle(80, 80, radius, 100,0);
  else DrawCircle(80, 140, radius, 100,1);

  if(c) DrawCircle(-80, 75, radius, 100,0);
  else DrawCircle(-140, 75, radius, 100,1);

  if(d) DrawCircle(-80, -140, radius, 100,0);
  else DrawCircle(-80, -80, radius, 100,1);

}*/

void figure(){
    make_road();

    if(!amb)
    {
      if(rtime<=3)
      Display_traffic_light(chance==0,chance==1,chance==2,chance==3,true);
      else
      Display_traffic_light(chance==0,chance==1,chance==2,chance==3,false);
    }
    else Display_traffic_light(chance==0,chance==1,chance==2,chance==3,false);
    //Display_yellow_light();
    int i,j;
    if(A>0)
    {
      int lA=0;
      for(int ii=0;lA<A&& ii<25;ii++,lA+=25){
        if(chance==0 && amb && ambLocation+50>=(50+(ii)*(25)) && ambLocation+50<(50+(ii+1)*(25)) ){
          make_ambulanceH(50+(ii)*(25),0);

        }
        else
        make_carH(50+ii*(25),0);
      }
    }
    if(C>0)
    {

      int lC=0;
      for(int ii=0;lC<C&& ii<25;ii++,lC+=25){
        if(chance==2 && amb && -ambLocation-50>=(-75+(ii)*(-25)) && -ambLocation-50<(-75+(ii-1)*(-25)) ){
          make_ambulanceH(-75+ii*(-25),50);

        }
        else
          make_carH(-75+ii*(-25),50);
      }
    }
    if(B>0){
      int lB=0;
      for(int ii=0;lB<B&& ii<25;ii++,lB+=25){
        if(chance==1 && amb && ambLocation+50>=(50+25*ii) && ambLocation+50<(50+25*(ii+1)) ){
          make_ambulanceV(0,75+25*ii);
        }
        else
        make_carV(0,75+25*ii);
      }
    }
    if(D>0){
      int lD=0;
      for(int ii=0;lD<D&& ii<25;ii++,lD+=25){
        if(chance==3 && amb && -ambLocation-50<=(-50+(-25)*ii) && -ambLocation-50>(-50+(-25)*(ii+1) ) ){
          make_ambulanceV(-50,-50+(-25)*ii);

        }
        else
        make_carV(-50,-50+(-25)*ii);
      }
    }

}

void draw(){
while(!m.eof()){
cout<<"TIMEEE"<<TIMEE++<<endl;
    m>>A>>B>>C>>D;
    m>>chance>>amb>>rtime;

    if(amb){
      ambmultiply=7;
    }
    else{
      ambmultiply=5;
    }
    if(amb){
      if(ambLocation<=0){
        switch(chance){
          case 0:
            ambLocation=A;
            break;
          case 1:
            ambLocation=B;
            break;
          case 2:
            ambLocation=C;
            break;
          case 3:
            ambLocation=D;
            break;
        }

      }
      else{
          ambLocation-=20;
      }
    }
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glFlush();
	make_road();
	figure();
	glFlush();
	usleep(ambmultiply*100000);}
}

void Init(){
	glClearColor(0.513,0.545,0.513,0);
  //glClearColor(1,0.804,0.580,0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glFlush();
    	glPointSize(1.0f);
	glMatrixMode(GL_PROJECTION);
    	glLoadIdentity();
    	gluOrtho2D(-300,300,-300,300);
}

int main(int argc,char *argv[]){

m.open("output.txt");
glutInit(&argc,argv);
glutInitWindowSize(600,600);
glutCreateWindow("Test");
Init();

glutDisplayFunc(draw);
glutMainLoop();

return 0;
}
