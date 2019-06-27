#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include <GL/glut.h>
#include<math.h>
#include<time.h>
#include<GL/glu.h>
#include<GL/glext.h>
#include<GL/gl.h>
#include<bits/stdc++.h>
#define PI 3.14
float angleMoon=0.0, angleEarth=0.0,angleAstroid=0.0,
                  angleMars=0.0,
                   angleMercury=0.0,
                   angleVenus=0.0,
                   angleJupiter=0.0,
                   angleSaturn=0.0,
                   angleUranus=30.0,
                   angleNeptune=60.0;
GLfloat sx=0.15,sy=0.15,sz=0.15;
int planet1;

GLfloat black[]={0.0f,0.0f,0.0f,1.0f};
/*GLfloat white[]={1.0f,1.0f,1.0f,1.0f};
GLfloat blue[]={0.0f,0.0f,0.9f,1.0f};
GLfloat er[]={0.0f,5.0f,0.9f,1.0f};*/
GLfloat yellow[]={0.7f,0.2f,0.0f,1.0f};
GLfloat qAmb[]={0.1,0.1,0.1,1.0};
GLfloat qDif[]={1.0,1.0,1.0,1.0};
GLfloat qSpec[]={.50,.50,.50,.10};
GLfloat qPos[]={0,0,0,0.1};
GLfloat sc[8]={0.295 , 0.40,0.50, 0.60,0.80,1.0,1.05,1.13};
double ang=2*PI/300;
double angular=2*PI/50;


void initLighting()
{

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT7);

    glLightfv(GL_LIGHT7,GL_AMBIENT,qAmb);
    glLightfv(GL_LIGHT7,GL_DIFFUSE,qDif);
    glLightfv(GL_LIGHT7,GL_SPECULAR,qSpec);

}
void myinit()
{
   glClearColor(0.0,0.0,0.0,0.0);
   glPointSize(1.0);
   glLineWidth(2.0);

}
void renderBitmapString(float x, float y, void *font,const char *string){
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}


float eyeX = .02f;
float eyeY = .006f;
float eyeZ = .006f;

int s = 1;
int e = 0;
int m = 0;
int v = 0;
int a = 0;
int j = 0;
int u = 0;
int n = 0;

void keyboard(unsigned char key, int xx, int yy) {
    switch (key) {
    case 'e':
      sndPlaySound("e.wav",SND_ASYNC);
        s = 0;
        e = 1;
        m = 0;
        v = 0;
        a = 0;
        j = 0;
        u = 0;
        n = 0;
        break;

    case 's':
        sndPlaySound("s.wav",SND_ASYNC);
        s = 1;
        e = 0;
        m = 0;
        v = 0;
        a = 0;
        j = 0;
        u = 0;
        n = 0;

        break;

    case 'm':
        sndPlaySound("m.wav",SND_ASYNC);
        s = 0;
        e = 0;
        m = 1;
        v = 0;
        a = 0;
        j = 0;
        u = 0;
        n = 0;
        break;

    case 'v':
        sndPlaySound("v.wav",SND_ASYNC);
        s = 0;
        e = 0;
        m = 0;
        v = 1;
        a = 0;
        j = 0;
        u = 0;
        n = 0;
        break;

    case 'a':
        sndPlaySound("a.wav",SND_ASYNC);
        s = 0;
        e = 0;
        m = 0;
        v = 0;
        a = 1;
        j = 0;
        u = 0;
        n = 0;
        break;

    case 'j':
        sndPlaySound("j.wav",SND_ASYNC);
        s = 0;
        e = 0;
        m = 0;
        v = 0;
        a = 0;
        j = 1;
        u = 0;
        n = 0;
        break;

    case 'u':
        sndPlaySound("u.wav",SND_ASYNC);
        e = 0;
        m = 0;
        v = 0;
        a = 0;
        j = 0;
        u = 1;
        n = 0;
        break;

   case 'n':
        sndPlaySound("n.wav",SND_ASYNC);
        s = 0;
        e = 0;
        m = 0;
        v = 0;
        a = 0;
        j = 0;
        u = 0;
        n = 1;
        break;

    }
}

void background()
{
    glBegin(GL_QUADS);
      glColor3f(0.0,1.00,0.00);
      glVertex3f(-01.00,01.00,1);
      glColor3f(.20,0.0,0.70);
      glVertex3f(01.00,1.00,1);
      glColor3f(0,0.0,0.0);
      glVertex3f(1.00,-1.00,1);
      glColor3f(.70,.10,.20);
      glVertex3f(-1.00,-1.00,1);
    glEnd();
}

void orbit()
{
glColor3f(0.5,0.5,0.5);


int i=0;
for(i=0;i<8;i++){
glPushMatrix();
glRotatef(63,1.0,0.0,0.0);
glScalef(sc[i],sc[i],sc[i]);
glBegin(GL_POINTS);
double ang1=0.0;
  int i=0;
  for(i=0;i<300;i++)
  {glVertex2d(cos(ang1),sin(ang1));
   ang1+=ang;  }
glEnd();
glPopMatrix();
}
}


void earthdis(){

 glPushMatrix();
         //glRotatef(angleEarth,0.0,1.0,-0.5);
         glTranslatef(0.6,0.2,0.0);
         glColor3f(0.0,0.7,0.0);
         glScalef(0.13,0.13,0.13);
         glutSolidSphere(1,50,50);
            glPushMatrix();
             glRotatef(angleMoon,0.0,0.1,0.05);
             glTranslatef(1.3,0.0,0.0);
             glColor3f(1.0,1.0,1.0);
             glScalef(0.5,0.5,0.5);
             glutSolidSphere(0.5,50,50);
           glPopMatrix();//moon made
       glPopMatrix();//earth made
    glPopMatrix();

           glLineWidth(3);
    glColor3f(0.0,3.0,0.0);
    renderBitmapString(-0.5f,0.7f,GLUT_BITMAP_TIMES_ROMAN_24,"----THE EARTH----");
     glColor3f(2.0,2.0,2.0);
	renderBitmapString(-0.95f,0.5f,GLUT_BITMAP_TIMES_ROMAN_24,"1.Earth is the third planet from the Sun and ");
	renderBitmapString(-0.95f,0.4f,GLUT_BITMAP_TIMES_ROMAN_24,"   the only astronomical object known to harbor life.");
	renderBitmapString(-0.95f,0.3f,GLUT_BITMAP_TIMES_ROMAN_24,"2.According to radiometric dating and other sources of evidence,");
	renderBitmapString(-0.95f,0.2f,GLUT_BITMAP_TIMES_ROMAN_24,"   Earth formed over 4.5 billion years ago.");
	renderBitmapString(-0.95f,0.1f,GLUT_BITMAP_TIMES_ROMAN_24,"3.Earth's gravity interacts with other objects in space.");
    renderBitmapString(-0.95f,0.0f,GLUT_BITMAP_TIMES_ROMAN_24,"4.especially the Sun and the Moon, Earth's only natural satellite.");
	renderBitmapString(-0.95f,-0.1f,GLUT_BITMAP_TIMES_ROMAN_24,"5.Radius: 6,371 km.");
	renderBitmapString(-0.95f,-0.2f,GLUT_BITMAP_TIMES_ROMAN_24,"6.Distance from Sun: 149.6 million km.");

}

void mercurydis(){

 glPushMatrix();

         glTranslatef(0.6,0.2,0.0);
         glScalef(0.13,0.13,0.13);
         glPushMatrix();
         glRotatef(angleMercury,0.0,1.0,-0.5);
         glColor3f(0.4,0.4,0.4);
         glutSolidSphere(1,50,50);
         glPopMatrix();
glPopMatrix();
           glLineWidth(3);
   // glColor3f(0.0,3.0,0.0);
    renderBitmapString(-0.5f,0.7f,GLUT_BITMAP_TIMES_ROMAN_24,"----THE MERCURY----");
     glColor3f(2.0,2.0,2.0);
	renderBitmapString(-0.95f,0.5f,GLUT_BITMAP_TIMES_ROMAN_24,"1.Mercury is the smallest and innermost planet in the Solar System.");
	renderBitmapString(-0.95f,0.3f,GLUT_BITMAP_TIMES_ROMAN_24,"2.Its orbital period around the Sun of 87.97 days is the ");
	renderBitmapString(-0.95f,0.2f,GLUT_BITMAP_TIMES_ROMAN_24,"   shortest of all the planets in the Solar System.");
	renderBitmapString(-0.95f,0.1f,GLUT_BITMAP_TIMES_ROMAN_24,"3.Average orbital speed‎: ‎47.362 km/s.");
    renderBitmapString(-0.95f,0.0f,GLUT_BITMAP_TIMES_ROMAN_24,"4.Mean radius‎: 2,439.7±1.0 km.");
	renderBitmapString(-0.95f,-0.1f,GLUT_BITMAP_TIMES_ROMAN_24,"5.Mass‎: ‎3.3022×1023 kg.");


}

void venusdis(){

 glPushMatrix();
         //glRotatef(angleEarth,0.0,1.0,-0.5);
         glTranslatef(0.6,0.2,0.0);
           glScalef(0.13,0.13,0.13);
          glPushMatrix();
         glRotatef(angleVenus,0.0,1.0,-0.5);
         glColor3f(0.9,0.1,0.0);
         glutSolidSphere(1,50,50);
       glPopMatrix();
glPopMatrix();
           glLineWidth(3);
   // glColor3f(0.0,3.0,0.0);
    renderBitmapString(-0.5f,0.7f,GLUT_BITMAP_TIMES_ROMAN_24,"----THE VENUS----");
     glColor3f(2.0,2.0,2.0);
	renderBitmapString(-0.95f,0.5f,GLUT_BITMAP_TIMES_ROMAN_24,"1.Venus is the second planet from the Sun,  ");
	renderBitmapString(-0.95f,0.4f,GLUT_BITMAP_TIMES_ROMAN_24,"   orbiting it every 224.7 Earth days.");
	renderBitmapString(-0.95f,0.3f,GLUT_BITMAP_TIMES_ROMAN_24,"2.It has the longest rotation period of any planet in the Solar System,");
	renderBitmapString(-0.95f,0.2f,GLUT_BITMAP_TIMES_ROMAN_24,"   and rotates in the opposite direction to most other planets.");
	renderBitmapString(-0.95f,0.1f,GLUT_BITMAP_TIMES_ROMAN_24,"3.It does not have any natural satellites.");
    renderBitmapString(-0.95f,0.0f,GLUT_BITMAP_TIMES_ROMAN_24,"4.Orbital period: 225 days.");
	renderBitmapString(-0.95f,-0.1f,GLUT_BITMAP_TIMES_ROMAN_24,"5.Radius: 6,051.8 km.");
	renderBitmapString(-0.95f,-0.2f,GLUT_BITMAP_TIMES_ROMAN_24,"6.Distance from Sun: 108.2 million km.");
}

void marsdis(){

 glPushMatrix();
         //glRotatef(angleEarth,0.0,1.0,-0.5);
         glTranslatef(0.6,0.2,0.0);
           glScalef(0.13,0.13,0.13);
          glPushMatrix();
         glRotatef(angleMars,0.0,1.0,-0.5);
         glColor3f(1.0,0.5,0.0);
         glutSolidSphere(1,50,50);
       glPopMatrix();

       glPopMatrix();
           glLineWidth(3);
   // glColor3f(0.0,3.0,0.0);
    renderBitmapString(-0.5f,0.7f,GLUT_BITMAP_TIMES_ROMAN_24,"----THE MARS----");
     glColor3f(2.0,2.0,2.0);
	renderBitmapString(-0.95f,0.5f,GLUT_BITMAP_TIMES_ROMAN_24,"1.Mars is the fourth planet from the Sun and the second-,  ");
	renderBitmapString(-0.95f,0.4f,GLUT_BITMAP_TIMES_ROMAN_24,"   smallest planet in the Solar System after Mercury.");
	renderBitmapString(-0.95f,0.3f,GLUT_BITMAP_TIMES_ROMAN_24,"2.It's still noticeable and stronger in some areas than others.");
	renderBitmapString(-0.95f,0.1f,GLUT_BITMAP_TIMES_ROMAN_24,"3.Mars is one of the most explored bodies in our solar system.");
    renderBitmapString(-0.95f,0.0f,GLUT_BITMAP_TIMES_ROMAN_24,"4.Orbital period‎: ‎686.971 days.");
	renderBitmapString(-0.95f,-0.1f,GLUT_BITMAP_TIMES_ROMAN_24,"5.Radius: 3,389.5 km.");

}

void jupiterdis(){

 glPushMatrix();
         //glRotatef(angleEarth,0.0,1.0,-0.5);
         glTranslatef(0.6,0.2,0.0);
           glScalef(0.13,0.13,0.13);
          glPushMatrix();
         glRotatef(angleJupiter,0.0,1.0,-0.5);
         glColor3f(0.3,0.0,0.0);
         glutSolidSphere(1,50,50);
         glPushMatrix();
             glRotatef(angleMoon,1.0,-0.5,0.0);
             glTranslatef(0.0,0,1.1);
             glColor3f(1.0,1.0,1.0);
             glScalef(0.1,0.1,0.1);
             glutSolidSphere(0.5,50,50);
           glPopMatrix();//moon made
       glPopMatrix();
glPopMatrix();
           glLineWidth(3);
   glColor3f(1.0,0.0,0.0);
    renderBitmapString(-0.5f,0.7f,GLUT_BITMAP_TIMES_ROMAN_24,"----THE JUPITER----");
     glColor3f(2.0,2.0,2.0);
	renderBitmapString(-0.95f,0.5f,GLUT_BITMAP_TIMES_ROMAN_24,"1.Jupiter is the fifth planet from the Sun and the");
	renderBitmapString(-0.95f,0.4f,GLUT_BITMAP_TIMES_ROMAN_24,"   largest in the Solar System.");
	renderBitmapString(-0.95f,0.3f,GLUT_BITMAP_TIMES_ROMAN_24,"2.It is a giant planet with a mass one-thousandth that is two-and-a-half ");
	renderBitmapString(-0.95f,0.2f,GLUT_BITMAP_TIMES_ROMAN_24,"    times that of all the other planets in the Solar System .");
	renderBitmapString(-0.95f,0.1f,GLUT_BITMAP_TIMES_ROMAN_24,"3.It's often said to be at least 300 years old, and it may be.");
    renderBitmapString(-0.95f,0.0f,GLUT_BITMAP_TIMES_ROMAN_24,"4.Mass: 1.898 × 10^27 kg.");
	renderBitmapString(-0.95f,-0.1f,GLUT_BITMAP_TIMES_ROMAN_24,"5.Radius: 69,911 km.");
	renderBitmapString(-0.95f,-0.2f,GLUT_BITMAP_TIMES_ROMAN_24,"6.Distance from Sun: 778.5 million km.");

}

void uranusdis(){

 glPushMatrix();
         //glRotatef(angleEarth,0.0,1.0,-0.5);
         glTranslatef(0.6,0.2,0.0);
           glScalef(0.13,0.13,0.13);
          glPushMatrix();
         glRotatef(angleUranus,0.0,1.0,-0.5);
         glColor3f(0.0,0.5,1.0);
         glutSolidSphere(1,50,50);
       glPopMatrix();
glPopMatrix();
           glLineWidth(3);

    renderBitmapString(-0.5f,0.7f,GLUT_BITMAP_TIMES_ROMAN_24,"----THE URANUS----");
     glColor3f(2.0,2.0,2.0);
	renderBitmapString(-0.95f,0.5f,GLUT_BITMAP_TIMES_ROMAN_24,"1.Uranus is the seventh planet from the Sun. ");
	renderBitmapString(-0.95f,0.4f,GLUT_BITMAP_TIMES_ROMAN_24,"2.It has the third-largest planetary radius and fourth-largest planetary");
	renderBitmapString(-0.95f,0.3f,GLUT_BITMAP_TIMES_ROMAN_24,"  mass in the Solar System. Uranus is similar in composition ");
	renderBitmapString(-0.95f,0.2f,GLUT_BITMAP_TIMES_ROMAN_24," to Neptune,and both have bulk chemical compositions.");
	renderBitmapString(-0.95f,0.1f,GLUT_BITMAP_TIMES_ROMAN_24,"3.Orbital period: 84 years.");
    renderBitmapString(-0.95f,0.0f,GLUT_BITMAP_TIMES_ROMAN_24,"4.Mass: 1.898 * 10^27 kg.");
	renderBitmapString(-0.95f,-0.1f,GLUT_BITMAP_TIMES_ROMAN_24,"5.Radius: 25,362 km.");
	renderBitmapString(-0.95f,-0.2f,GLUT_BITMAP_TIMES_ROMAN_24,"6.Distance from Sun: 2.871 billion km.");

}


void neptunedis(){

 glPushMatrix();
         //glRotatef(angleEarth,0.0,1.0,-0.5);
         glTranslatef(0.6,0.2,0.0);
           glScalef(0.13,0.13,0.13);
          glPushMatrix();
         glRotatef(angleNeptune,0.0,1.0,-0.5);
         glColor3f(0.0,0.0,0.9);
         glutSolidSphere(1,50,50);
       glPopMatrix();
glPopMatrix();
           glLineWidth(3);
glColor3f(0.0,0.0,1.0);
    renderBitmapString(-0.5f,0.7f,GLUT_BITMAP_TIMES_ROMAN_24,"----THE NEPTUNE----");
     glColor3f(2.0,2.0,2.0);
	renderBitmapString(-0.95f,0.5f,GLUT_BITMAP_TIMES_ROMAN_24,"1.Neptune is the eighth planet from the Sun in the Solar System. ");
	renderBitmapString(-0.95f,0.4f,GLUT_BITMAP_TIMES_ROMAN_24,"2.In the Solar System, it is the fourth-largest planet by diameter, ");
	renderBitmapString(-0.95f,0.3f,GLUT_BITMAP_TIMES_ROMAN_24,"  the third-most-massive planet, and the densest giant planet.");
	renderBitmapString(-0.95f,0.2f,GLUT_BITMAP_TIMES_ROMAN_24,"3.Neptune is 17 times the mass of Earth.");
    renderBitmapString(-0.95f,0.1f,GLUT_BITMAP_TIMES_ROMAN_24,"4.Orbital period‎: ‎164.8 yr; 60,182 days.");
	renderBitmapString(-0.95f,0.0f,GLUT_BITMAP_TIMES_ROMAN_24,"5.Radius: 25,362 km.");
	renderBitmapString(-0.95f,-0.1f,GLUT_BITMAP_TIMES_ROMAN_24,"6.Distance from Sun: 4.495 billion km.");

}


void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();

if(s == 1)
{

background();
gluLookAt(	eyeX, eyeY, eyeZ,
            0.0f, 0.0f,  0.05f,
            0.05f, 0.5f,  0.05f);


 orbit();

    glPushMatrix();

    glEnable(GL_DEPTH_TEST);
   glEnable(GL_COLOR_MATERIAL);
       glPushMatrix();
       glColor3f(1.0,1.0,0.0);
       glScalef(sx,sy,sz);
      glLightfv(GL_LIGHT7,GL_POSITION,qPos);
      glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,yellow);

       glutSolidSphere(1,50,50);
       glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);
       glPopMatrix();

       glScalef(0.2,0.2,0.2);
       glPushMatrix();
         glRotatef(angleMercury,0.0,1.0,-0.5);
         glTranslatef(1.5,0.0,0.0);
         glColor3f(0.4,0.4,0.4);
         glScalef(0.08,0.08,0.08);
         glutSolidSphere(1,50,50);
       glPopMatrix();

       glPushMatrix();
         glRotatef(angleVenus,0.0,1.0,-0.5);
         glTranslatef(2.0,0.0,0.0);
         glColor3f(0.9,0.1,0.0);
         glScalef(0.1,0.1,0.1);
         glutSolidSphere(1,50,50);
       glPopMatrix();

       glPushMatrix();
         glRotatef(angleEarth,0.0,1.0,-0.5);
         glTranslatef(2.5,0.0,0.0);
         glColor3f(0.0,0.7,0.0);
         glScalef(0.23,0.23,0.23);
         glutSolidSphere(1,50,50);
            glPushMatrix();
             glRotatef(angleMoon,0.0,0.1,0.05);
             glTranslatef(1.3,0.0,0.0);
             glColor3f(1.0,1.0,1.0);
             glScalef(0.5,0.5,0.5);
             glutSolidSphere(0.5,50,50);
           glPopMatrix();//moon made
       glPopMatrix();//earth made

       glPushMatrix();
         glRotatef(angleMars,0.0,1.0,-0.5);
         glTranslatef(-3.0,0.0,0.0);

         glColor3f(1.0,0.5,0.0);
         glScalef(0.17,0.17,0.17);
         glutSolidSphere(1,50,50);
       glPopMatrix();

       glPushMatrix();
         glRotatef(angleJupiter,0.0,1.0,-0.5);
         glTranslatef(-4.0,0.0,0.0);

         glColor3f(0.3,0.0,0.0);

         glScalef(0.5,0.5,0.5);
         glutSolidSphere(1,50,50);
         glPushMatrix();
             glRotatef(angleMoon,1.0,-0.5,0.0);
             glTranslatef(0.0,0,1.1);
             glColor3f(1.0,1.0,1.0);
             glScalef(0.1,0.1,0.1);
             glutSolidSphere(0.5,50,50);
           glPopMatrix();//moon made
       glPopMatrix();

       glPushMatrix();
         glRotatef(angleUranus,0.0,1.0,-0.5);
         glTranslatef(5.2,0.0,0.0);
         glColor3f(0.0,0.5,0.9);
         glScalef(0.23,0.23,0.23);
         glutSolidSphere(1,50,50);
       glPopMatrix();

       glPushMatrix();
         glRotatef(angleNeptune,0.0,1.0,-0.5);
         glTranslatef(-5.7,0.0,0.0);
         glColor3f(0.0,0.0,0.9);
         glScalef(0.2,0.2,0.2);
         glutSolidSphere(1,50,50);
       glPopMatrix();


glPopMatrix();
}

else if(e == 1)
{
  glLoadIdentity();

  earthdis();

}
else if(m == 1)
{
  glLoadIdentity();
  mercurydis();

}
else if(v == 1)
{
  glLoadIdentity();
  venusdis();

}
else if(a == 1)
{
  glLoadIdentity();
  marsdis();

}
else if(j == 1)
{
  glLoadIdentity();
  jupiterdis();

}
else if(u == 1)
{
  glLoadIdentity();
  uranusdis();

}

else if(n == 1)
{
  glLoadIdentity();
  neptunedis();

}

     glFlush();
}


void update(int value){

angleMoon+=2;
if(angleMoon>360){
    angleMoon-=360;}
    angleEarth+=0.7;
if(angleEarth>360){
    angleEarth-=360;}
angleMercury+=2;
if(angleMercury>360){
    angleMercury-=360;}
angleVenus+=0.9;
if(angleVenus>360){
    angleVenus-=360;}
angleMars+=0.5;
if(angleMars>360){
    angleMars-=360;}
angleJupiter+=0.3;
if(angleJupiter>360){
    angleJupiter-=360;}
angleSaturn+=0.2;
if(angleSaturn>360){
    angleSaturn-=360;}


angleUranus+=0.1;
if(angleUranus>360){
    angleUranus-=360;}


angleNeptune+=0.09;
if(angleNeptune>360){
    angleNeptune-=360;}


angleAstroid+=0.09;
if(angleAstroid>360){
    angleAstroid-=360;}


glutPostRedisplay();
glutTimerFunc(20,update,0);
}

void mouse(int button, int state, int x, int y)
{
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
            glutIdleFunc(draw);
            break;
        case GLUT_RIGHT_BUTTON:
           if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
            break;
    }
}

void keyboardSpecial(int key, int xx, int yy)
{
    switch (key) {

    case GLUT_KEY_UP:
        eyeY -= 0.001f;
        eyeZ -= 0.001f;
        break;
    case GLUT_KEY_DOWN:
        eyeY += 0.001f;
        eyeZ += 0.001f;
        break;

    case GLUT_KEY_RIGHT:
        eyeX += 0.001f;
       eyeZ += 0.001f;
        break;

     case GLUT_KEY_LEFT:
        eyeX -= 0.001f;
        eyeZ -= 0.001f;
        break;


    }
}


int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(1200,600);
    glutCreateWindow("The Solar System");
    initLighting();
    myinit();

    glutDisplayFunc(draw);
     glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
   glutSpecialFunc(keyboardSpecial);
    glutTimerFunc(25,update,0);
    glutMainLoop();
    return 0;
}
