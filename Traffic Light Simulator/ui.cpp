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
int A=100,B=100,C=100,D=100,chance,amb,ambLocation=-60;
void DrawCircle(float cx, float cy, float r, int num_segments,int color) {
    int ii;
    int R=0,G=0,B=0;
    if(color==1) R=1;
    else G=1;
    glColor3f(R,G,B);
    glBegin(GL_POLYGON);
    for ( ii = 0; ii < num_segments; ii++)   {
        float theta = 2.0f * 3.1415926f * ((float)ii / num_segments);
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        glVertex2f(x + cx, y + cy);//output vertex
    }
    glEnd();
}
void figure(){

    int i,j;
    int roadA[NUM][2]={{50,50},{50,-50},{A+50,-50},{A+50,50}};
    int roadB[NUM][2]={{50,50},{-50,50},{-50,B+50},{50,B+50}};
    int roadC[NUM][2]={{-50,50},{-50,-50},{-C-50,-50},{-C-50,50}};
    int roadD[NUM][2]={{-50,-50},{50,-50},{50,-D-50},{-50,-D-50}};

	glColor3f(0.5,0,0.5);
	glBegin(GL_POLYGON);
		for( i=0;i<NUM;++i)
			glVertex2f(roadA[i][0],roadA[i][1]);
	glEnd();

	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
		for( i=0;i<NUM;++i)
			glVertex2f(roadB[i][0],roadB[i][1]);
	glEnd();

	glColor3f(0,0,1);
	glBegin(GL_POLYGON);
		for( i=0;i<NUM;++i)
			glVertex2f(roadC[i][0],roadC[i][1]);
	glEnd();

	glColor3f(0.5,0.5,0);
	glBegin(GL_POLYGON);
		for( i=0;i<NUM;++i)
			glVertex2f(roadD[i][0],roadD[i][1]);
	glEnd();

	if(amb)
	{
	  glColor3f(1,0,0);
	  glBegin(GL_POLYGON);
	  switch(chance){
	    case 0:
	      {
	        glVertex2f(ambLocation+50,50);
	        glVertex2f(ambLocation+50,-50);
	        glVertex2f(ambLocation+50+5,-50);
	        glVertex2f(ambLocation+50+5,50);
	        glEnd();
	        break;
	      }
	    case 1:
	      {
	        glVertex2f(50,ambLocation+50);
	        glVertex2f(50,ambLocation+50+5);
	        glVertex2f(-50,ambLocation+50+5);
	        glVertex2f(-50,ambLocation+50);
	        glEnd();
	        break;
	      }
	    case 2:
	      {
	        glVertex2f(-50-ambLocation,50);
	        glVertex2f(-50-ambLocation-5,50);
	        glVertex2f(-50-ambLocation-5,-50);
	        glVertex2f(-50-ambLocation,-50);
	        glEnd();
	        break;
	      }
	    case 3:
	      {
	        glVertex2f(-50,-50-ambLocation);
	        glVertex2f(-50,-50-ambLocation-5);
	        glVertex2f(50,-50-ambLocation-5);
	        glVertex2f(50,-50-ambLocation);
	        glEnd();
	        break;
	      }

	  }
	}
    
	int col[4];
	for(int i=0;i<4;i++)
	{
	    if(i==chance) col[i]=0;
	    else col[i]=1;
	}

	DrawCircle(43, 0, 7, 100,col[0]);
	DrawCircle(0, 43, 7, 100,col[1]);
  DrawCircle(-43, 0, 7, 100,col[2]);
	DrawCircle(0, -43, 7, 100,col[3]);



}

void draw(){
while(!m.eof()){
cout<<"TIMEEE"<<TIMEE++<<endl;
    m>>A>>B>>C>>D;
    m>>chance>>amb;
    if(amb){
      ambmultiply=3;
    }
    else{
      ambmultiply=2;
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
	glColor3f(0,0,0);
    	glBegin(GL_LINES);
    		glVertex2i(-300,0);
    		glVertex2i(300,0);
    		glVertex2i(0,300);
    		glVertex2i(0,-300);

    		glVertex2i(-50,300);
    		glVertex2i(-50,50);

    		glVertex2i(-300,50);
    		glVertex2i(-50,50);

    		glVertex2i(-300,-50);
    		glVertex2i(-50,-50);

    		glVertex2i(-50,-300);
    		glVertex2i(-50,-50);

    		glVertex2i(50,-300);
    		glVertex2i(50,-50);

    		glVertex2i(300,-50);
    		glVertex2i(50,-50);

    		glVertex2i(300,50);
    		glVertex2i(50,50);

    		glVertex2i(50,300);
    		glVertex2i(50,50);

    	glEnd();
	figure();
	glFlush();
	usleep(ambmultiply*100000);}
}

void Init(){
	glClearColor(1,1,1,0);
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
