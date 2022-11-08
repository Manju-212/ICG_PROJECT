#include <GL/glut.h>
using namespace std;
#include <bits/stdc++.h>
#include <math.h>
int n = 300;
int n1 = 300;
int pl = 0;
int truck_movement = -200;
int plane_movement = -300;
int bus_movement = 1500;
int cloud_movement1 = 0;
int cloud_movement2 = 0;
float clear_r = 0.5,clear_g = 0.8,clear_b = 0.9;
void cloud_circle(float a,float b,int radius);
void Airplane();
void Bus();
void truck();
void road();
void Sun();
void Building();
void Bird();
void clouds();
void Mountain();
void white_building1();
void white_building2();
void airplane_pole();
void sky_scraper();
int refsec = 10;
void Timer(int value) 
{	
    glutTimerFunc(refsec, Timer, 10); // next Timer call milliseconds later
    if(truck_movement<=2500)
    {
      truck_movement = truck_movement + 1;
    }
    else
    {
        truck_movement = -200;
    }
     if(bus_movement>=-1500)
    {
      bus_movement = bus_movement - 1;
    }
    else
    {
        bus_movement = 1500;
    }
    if(plane_movement<=2500)
    {
        plane_movement = plane_movement + 5;
    }
    else
    {
     
        plane_movement = -300;
    }
    //cloud movement  1
     if(cloud_movement1>=-2000)
    {
        cloud_movement1 = cloud_movement1 - 5;
    }
    else
    {
        cloud_movement1 = 2200;
    }
    //cloud movement 2
    if(cloud_movement2>=-700)
    {
        cloud_movement2 = cloud_movement2 - 5;
    }
    else
    {
        cloud_movement2 = 2200;
    }
    if(clear_r>=0.36)
    {
        clear_r -= 0.0001;
    }
    if(clear_g>=0.32)
    {
        clear_g -= 0.0001;
    }
    if(clear_b>=0.64)
    {
        clear_b -= 0.0001;
    }
	glutPostRedisplay();      // Post re-paint request to activate display()
}
void display()
{
    glClearColor(clear_r,clear_g,clear_b,1.0f);
    // glClearColor(1,1,1, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // gluOrtho2D(-500, 500, -500, 500);
    gluOrtho2D(0, 2000, 0, 2000);

    Mountain();
    road();
    sky_scraper();
    Sun();
    // Bird();
    if(clear_r>=0.38 && clear_g>=0.34 && clear_b>=0.66)
    {
        clouds();
    }
    Airplane();
    Building();
    airplane_pole();
    truck();
    white_building1();
    white_building2();
    Bus();

    glFlush(); // Render now
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    case 'n':
        clear_r = 0.36;
        clear_g = 0.32;
        clear_b = 0.64;
        display();
        break;
    }
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);                 // Initialize GLUT
    glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
    glutInitWindowSize(320, 320);          // Set the window's initial width & height
    glutInitWindowPosition(100, 100);      // Position the window's initial top-left corner
    glutDisplayFunc(display);              // Register display callback handler for window re-paint
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, Timer, 0);
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
void cloud_circle(float a,float b,int radius)
{
    float x = radius;
    float y = 0;
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        x = radius * cos(i);
        y = radius * sin(i);
        glVertex2f(x + a, y + b);
    }
    glEnd();
}
void clouds()
{
    //cloud 1 
    cloud_circle(1600 + cloud_movement1,1600,100);
    cloud_circle(1700 + cloud_movement1,1500,100);
    cloud_circle(1690 + cloud_movement1,1400,100);
    cloud_circle(1610 + cloud_movement1,1450,100);
    cloud_circle(1600 + cloud_movement1,1500,100);

    //cloud 2
    cloud_circle(600 + cloud_movement2,1700,100);
    cloud_circle(650 + cloud_movement2,1680,100);
    cloud_circle(580 + cloud_movement2,1570,100);
    cloud_circle(490 + cloud_movement2,1650,100);
    cloud_circle(590 + cloud_movement2,1670,100);

}
void truck()
{
    glPushMatrix();
    glTranslated(truck_movement,30, 0.0);
    glColor3ub(37,174,170);
    // outer layer
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(0,80);
    glVertex2f(300, 80);
    glVertex2f(300, 0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(200,80);
    glVertex2f(200,160);
    glVertex2f(250, 160);
    glVertex2f(300, 80);


    glColor3ub(232, 15, 136);
    glVertex2f(210,100);
    glVertex2f(250,100);
    glVertex2f(250, 140);
    glVertex2f(210, 140);
    glEnd();
    glPopMatrix();


    glPushMatrix(); // front tyre
    glTranslated(-50+truck_movement,-40,0.0);
    glScaled(25.0, 25.0, 0.0);
    glColor3f(0.78,0.05,0.227);
    glBegin(GL_POLYGON);
    glVertex2f(3.0, 2.5);
    glVertex2f(3.0, 2.6);
    glVertex2f(3.15, 3.1);
    glVertex2f(3.2, 3.2);
    glVertex2f(3.3, 3.35);
    glVertex2f(3.4, 3.4);
    glVertex2f(3.5, 3.45);
    glVertex2f(3.6, 3.55);
    glVertex2f(3.7, 3.6);
    glVertex2f(3.8, 3.63);
    glVertex2f(4.0, 3.65);
    glVertex2f(4.2, 3.7);
    glVertex2f(4.4, 3.7);
    glVertex2f(4.6, 3.65);
    glVertex2f(4.8, 3.55);
    glVertex2f(5.0, 3.45);
    glVertex2f(5.1, 3.4);
    glVertex2f(5.2, 3.25);
    glVertex2f(5.3, 3.2);
    glVertex2f(5.4, 3.0);
    glVertex2f(5.5, 2.5);

    glVertex2f(5.45, 2.15);
    glVertex2f(5.4, 1.9);
    glVertex2f(5.35, 1.8);
    glVertex2f(5.2, 1.6);
    glVertex2f(5.0, 1.5);
    glVertex2f(4.9, 1.4);
    glVertex2f(4.7, 1.3);
    glVertex2f(4.6, 1.27);
    glVertex2f(4.4, 1.25);
    glVertex2f(4.0, 1.25);
    glVertex2f(3.9, 1.3);
    glVertex2f(3.75, 1.35);
    glVertex2f(3.6, 1.4);
    glVertex2f(3.45, 1.55);
    glVertex2f(3.3, 1.7);
    glVertex2f(3.2, 1.8);
    glVertex2f(3.1, 2.2);
    glEnd();
    glPopMatrix();



    glPushMatrix(); // front tyre
    glTranslated(140+truck_movement,-40,0.0);
    glScaled(25.0, 25.0, 0.0);
    glColor3f(0.78,0.05,0.227);
    glBegin(GL_POLYGON);
    glVertex2f(3.0, 2.5);
    glVertex2f(3.0, 2.6);
    glVertex2f(3.15, 3.1);
    glVertex2f(3.2, 3.2);
    glVertex2f(3.3, 3.35);
    glVertex2f(3.4, 3.4);
    glVertex2f(3.5, 3.45);
    glVertex2f(3.6, 3.55);
    glVertex2f(3.7, 3.6);
    glVertex2f(3.8, 3.63);
    glVertex2f(4.0, 3.65);
    glVertex2f(4.2, 3.7);
    glVertex2f(4.4, 3.7);
    glVertex2f(4.6, 3.65);
    glVertex2f(4.8, 3.55);
    glVertex2f(5.0, 3.45);
    glVertex2f(5.1, 3.4);
    glVertex2f(5.2, 3.25);
    glVertex2f(5.3, 3.2);
    glVertex2f(5.4, 3.0);
    glVertex2f(5.5, 2.5);

    glVertex2f(5.45, 2.15);
    glVertex2f(5.4, 1.9);
    glVertex2f(5.35, 1.8);
    glVertex2f(5.2, 1.6);
    glVertex2f(5.0, 1.5);
    glVertex2f(4.9, 1.4);
    glVertex2f(4.7, 1.3);
    glVertex2f(4.6, 1.27);
    glVertex2f(4.4, 1.25);
    glVertex2f(4.0, 1.25);
    glVertex2f(3.9, 1.3);
    glVertex2f(3.75, 1.35);
    glVertex2f(3.6, 1.4);
    glVertex2f(3.45, 1.55);
    glVertex2f(3.3, 1.7);
    glVertex2f(3.2, 1.8);
    glVertex2f(3.1, 2.2);
    glEnd();
    glPopMatrix();
}
void Sun()
{
    glPushMatrix();
    float radius = 100;
    float x = radius;
    float y = 0;
    glColor3f(0.9, 0.7, 0.07);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        x = radius * cos(i);
        y = radius * sin(i);
        glVertex2f(x + 1700, y + 1800);
    }
    glEnd();
    glPopMatrix();
}
void road()
{
    glPushMatrix();
    glColor3f(0, 0, 0);
    // outer layer
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(0, 400);
    glVertex2f(2000, 400);
    glVertex2f(2000, 0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    int inc = 0;
    for (int i = 0; i <= 16; i++)
    {
        glVertex2f(20 + inc, 220);
        glVertex2f(120 + inc, 220);
        glVertex2f(120 + inc, 180);
        glVertex2f(20 + inc, 180);
        inc = inc + 140;
    }
    glEnd();
    glPopMatrix();
}
void sky_scraper()
{

    glPushMatrix();
    glTranslated(1000, 400, 0.0);
    // glScaled(0.5,0.5,0.0);
    // outer layer
    glBegin(GL_QUADS);
    glColor3ub(92, 77, 69);
    glVertex2f(0, 0);
    glVertex2f(200, 0);
    glVertex2f(200, 700);
    glVertex2f(0, 700);

    glColor3ub(65, 72, 79);
    glVertex2f(200, 0);
    glVertex2f(200, 700);
    glVertex2f(400, 700);
    glVertex2f(400, 0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(193, 215, 215);
    int inc = 0;
    for (int i = 0; i < 9; i++)
    {
        glVertex2f(250, 40 + inc);
        glVertex2f(250, 70 + inc);
        glVertex2f(350, 70 + inc);
        glVertex2f(350, 40 + inc);
        inc = inc + 70;
    }
    glEnd();

    // building 1 glass
    glBegin(GL_QUADS);
    glColor3ub(193, 215, 215);
    inc = 0;
    for (int i = 0; i < 9; i++)
    {
        glVertex2f(30, 30 + inc);
        glVertex2f(30, 70 + inc);
        glVertex2f(50, 70 + inc);
        glVertex2f(50, 30 + inc);

        glVertex2f(80, 30 + inc);
        glVertex2f(80, 70 + inc);
        glVertex2f(100, 70 + inc);
        glVertex2f(100, 30 + inc);

        glVertex2f(130, 30 + inc);
        glVertex2f(130, 70 + inc);
        glVertex2f(150, 70 + inc);
        glVertex2f(150, 30 + inc);

        inc = inc + 70;
    }
    glEnd();
    glPopMatrix();
}
void Mountain()
{
    glPushMatrix();
    // glScaled(0.5,0.5,0.0);
    // outer layer
    glBegin(GL_POLYGON);
    glColor3f(0, 0.7, 0);
    glVertex2f(0, 500);
    glVertex2f(100, 400);
    glVertex2f(300, 900);
    glVertex2f(500, 1000);
    glVertex2f(800, 800);
    glVertex2f(1300, 500);
    glVertex2f(1400, 400);
    glVertex2f(0, 400);
    // glVertex2f(1500,300);
    // glVertex2f(2000,600);
    // glVertex2f(2100, 400);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.7, 0);
    glVertex2f(1200, 400);
    glVertex2f(1400, 600);
    glVertex2f(1700, 800);
    glVertex2f(2200, 400);
    glVertex2f(1200, 400);
    glEnd();
    glPopMatrix();
}
void white_building1()
{

    glTranslated(100, 400, 0.0);
    glScaled(0.8, 2, 0.0);
    glColor3f(1, 1, 1);
    // outer layer
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(0, 300);
    glVertex2f(100, 300);
    glVertex2f(100, 0);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(0, 300);
    glVertex2f(100, 300);
    glVertex2f(60, 350);
    glVertex2f(40, 350);
    glEnd();
    // yellow region
    glColor3f(1, 0.64, 0);
    glBegin(GL_QUADS);
    glVertex2f(20, 325);
    glVertex2f(80, 325);
    glVertex2f(80, 0);
    glVertex2f(20, 0);
    glEnd();

    // green lines
    glColor3f(0, 1, 0);
    glLineWidth(2);
    glBegin(GL_LINES);
    for (int i = 0; i <= 10; i++)
    {
        glVertex2f(0, 30 * i);
        glVertex2f(100, 30 * i);
    }
    glVertex2f(50, 0);
    glVertex2f(50, 400);
    glEnd();
}
void white_building2()
{
    // white building 2 and 3
    glTranslated(250, 0, 0.0);
    // glScaled(0.8, 2, 0.0);
    glColor3f(1, 1, 1);
    // outer layer building 1
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(0, 350);
    glVertex2f(150, 350);
    glVertex2f(150, 0);

    glVertex2f(0, 350);
    glVertex2f(150, 350);
    glVertex2f(150, 400);
    glVertex2f(0, 350);
    glEnd();
    glColor3f(0, 0, 0);
    glLineWidth(5);
    glBegin(GL_LINES);
    for (int i = 0; i <= 11; i++)
    {
        glVertex2f(0, 30 * i);
        glVertex2f(150, 30 * i);
    }

    // vertical lines
    glVertex2f(50, 350);
    glVertex2f(50, 0);

    glVertex2f(100, 350);
    glVertex2f(100, 0);
    glEnd();
    // outer layer building 2
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex2f(170, 0);
    glVertex2f(170, 300);
    glVertex2f(270, 300);
    glVertex2f(270, 0);

    glVertex2f(170, 300);
    glVertex2f(170, 350);
    glVertex2f(270, 300);
    glVertex2f(170, 300);
    glEnd();
    glColor3f(0, 0, 0);
    glLineWidth(5);
    glBegin(GL_LINES);
    for (int i = 0; i <= 10; i++)
    {
        glVertex2f(170, 30 * i);
        glVertex2f(270, 30 * i);
    }
    // vertical lines
    glVertex2f(200, 300);
    glVertex2f(200, 0);

    glVertex2f(230, 300);
    glVertex2f(230, 0);
    glEnd();
}
void airplane_pole()
{
    glPushMatrix();
    glTranslated(1500, 400, 0.0);
    // glScaled(0.5,0.5,0.0);
    // outer layer
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex2f(100, 0);
    glVertex2f(100, 200);
    glVertex2f(150, 200);
    glVertex2f(150, 0);

    glColor3f(1, 0, 1);
    glVertex2f(50, 200);
    glVertex2f(200, 200);
    glVertex2f(200, 250);
    glVertex2f(50, 250);

    glColor3f(0, 1, 1);
    glVertex2f(50, 250);
    glVertex2f(200, 250);
    glVertex2f(250, 300);
    glVertex2f(0, 300);

    glColor3f(0.5, 0.5, 1);
    glVertex2f(0, 300);
    glVertex2f(250, 300);
    glVertex2f(250, 350);
    glVertex2f(0, 350);

    glColor3f(1, 0.5, 1);
    glVertex2f(0, 350);
    glVertex2f(250, 350);
    glVertex2f(170, 420);
    glVertex2f(80, 420);

    glColor3f(0.8, 0.5, 0.8);
    glVertex2f(80, 420);
    glVertex2f(170, 420);
    glVertex2f(190, 450);
    glVertex2f(60, 450);

    glColor3f(0.7, 0.5, 0.7);
    glVertex2f(60, 450);
    glVertex2f(190, 450);
    glVertex2f(190, 480);
    glVertex2f(60, 480);

    glEnd();
    glPopMatrix();
}
void Building()
{
    glPushMatrix();
    glTranslated(600, 400, 0.0);
    glScaled(0.8, 2, 0.0);
    glColor3f(0, 0, 1);
    // outer layer
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(0, 200);
    glVertex2f(50, 200);
    glVertex2f(50, 0);

    glVertex2f(50, 0);
    glVertex2f(50, 300);
    glVertex2f(100, 300);
    glVertex2f(100, 0);

    glVertex2f(100, 0);
    glVertex2f(100, 500);
    glVertex2f(150, 500);
    glVertex2f(150, 0);

    glVertex2f(150, 0);
    glVertex2f(150, 550);
    glVertex2f(250, 550);
    glVertex2f(250, 0);

    glVertex2f(250, 0);
    glVertex2f(250, 400);
    glVertex2f(300, 400);
    glVertex2f(300, 0);

    glVertex2f(300, 0);
    glVertex2f(300, 250);
    glVertex2f(350, 250);
    glVertex2f(350, 0);

    glVertex2f(350, 0);
    glVertex2f(350, 100);
    glVertex2f(400, 100);
    glVertex2f(400, 0);
    glEnd();

    glPopMatrix();
    // glColor3f(1,1,1);
    // glPointSize(10);
    // glBegin(GL_LINES);
    // glVertex2f(0, 0);
    // glVertex2f(0, 200);
    // glVertex2f(50, 200);
    // glVertex2f(50, 300);
    // glVertex2f(100, 300);
    // glVertex2f(100, 500);
    // glVertex2f(150, 500);
    // glVertex2f(150, 550);
    // glVertex2f(250, 550);
    // glVertex2f(250, 400);
    // glVertex2f(300, 400);
    // glVertex2f(300, 250);
    // glVertex2f(350, 250);
    // glVertex2f(350, 100);
    // glVertex2f(400, 100);
    // glVertex2f(400, 0);
    // glEnd();

    // Windows left 2
    glPushMatrix();
    glTranslated(600, 400, 0.0);
    glScaled(0.8, 2, 0.0);
    glColor3f(1, 1, 0);
    int b = 20;
    int l = 25;
    int check = 0;
    int inc = 0;
    for (int i = 0; i < 7; i++)
    {
        glBegin(GL_QUADS);
        glVertex2f(70, 5 + inc);
        glVertex2f(80, 5 + inc);
        glVertex2f(80, 30 + inc);
        glVertex2f(70, 30 + inc);
        glEnd();
        inc = inc + 40;
    }
    glPopMatrix();

    // Windows left 1
    glPushMatrix();
    glTranslated(600, 400, 0.0);
    glScaled(0.8, 2, 0.0);
    glColor3f(1, 1, 0);
    inc = 0;
    for (int i = 0; i < 12; i++)
    {
        glBegin(GL_QUADS);
        glVertex2f(130, 5 + inc);
        glVertex2f(140, 5 + inc);
        glVertex2f(140, 30 + inc);
        glVertex2f(130, 30 + inc);
        glEnd();
        inc = inc + 40;
    }
    glPopMatrix();

    // Windows middle
    glPushMatrix();
    glTranslated(600, 400, 0.0);
    glScaled(0.8, 2, 0.0);
    glColor3f(1, 1, 0);
    inc = 0;
    for (int i = 0; i < 13; i++)
    {
        glBegin(GL_QUADS);
        glVertex2f(190, 5 + inc);
        glVertex2f(200, 5 + inc);
        glVertex2f(200, 30 + inc);
        glVertex2f(190, 30 + inc);
        glEnd();
        inc = inc + 40;
    }
    glPopMatrix();

    // Windows right 1
    glPushMatrix();
    glTranslated(600, 400, 0.0);
    glScaled(0.8, 2, 0.0);
    glColor3f(1, 1, 0);

    inc = 0;
    for (int i = 0; i < 10; i++)
    {
        glBegin(GL_QUADS);
        glVertex2f(270, 5 + inc);
        glVertex2f(280, 5 + inc);
        glVertex2f(280, 30 + inc);
        glVertex2f(270, 30 + inc);
        glEnd();
        inc = inc + 40;
    }
    glPopMatrix();

    // Windows right 2
    glPushMatrix();
    glTranslated(600, 400, 0.0);
    glScaled(0.8, 2, 0.0);
    glColor3f(1, 1, 0);

    inc = 0;
    for (int i = 0; i < 6; i++)
    {
        glBegin(GL_QUADS);
        glVertex2f(320, 5 + inc);
        glVertex2f(330, 5 + inc);
        glVertex2f(330, 30 + inc);
        glVertex2f(320, 30 + inc);
        glEnd();
        inc = inc + 40;
    }
    glPopMatrix();
}
void Airplane()
{
    glPushMatrix();
    glTranslatef(plane_movement + 100, 1800, 0);
    glScaled(5, 5, 0);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON); // rectangular body
    glVertex2f(0.0, 30.0 / 3);
    glVertex2f(0.0, 55.0 / 3);
    glVertex2f(135.0 / 3, 55.0 / 3);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(135.0 / 3, 30.0 / 3);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON); // upper triangle construction plane
    glVertex2f(135.0 / 3, 55.0 / 3);
    glVertex2f(150.0 / 3, 50.0 / 3);
    glVertex2f(155.0 / 3, 45.0 / 3);
    glVertex2f(160.0 / 3, 40.0 / 3);
    glVertex2f(135.0 / 3, 40.0 / 3);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP); // outline of upper triangle plane
    glVertex2f(135.0 / 3, 55.0 / 3);
    glVertex2f(150.0 / 3, 50.0 / 3);
    glVertex2f(155.0 / 3, 45.0 / 3);
    glVertex2f(160.0 / 3, 40.0 / 3);
    glVertex2f(135.0 / 3, 40.0 / 3);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON); // lower triangle
    glVertex2f(135.0 / 3, 40.0 / 3);
    glVertex2f(160.0 / 3, 40.0 / 3);
    glVertex2f(160.0 / 3, 37.0 / 3);
    glVertex2f(145.0 / 3, 30.0 / 3);
    glVertex2f(135.0 / 3, 30.0 / 3);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON); // back wing
    glVertex2f(0.0, 55.0 / 3);
    glVertex2f(0.0, 80.0 / 3);
    glVertex2f(10.0 / 3, 80.0 / 3);
    glVertex2f(40.0 / 3, 55.0 / 3);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON); // left side wing
    glVertex2f(65.0 / 3, 55.0 / 3);
    glVertex2f(50.0 / 3, 70.0 / 3);
    glVertex2f(75.0 / 3, 70.0 / 3);
    glVertex2f(90.0 / 3, 55.0 / 3);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON); // rightside wing
    glVertex2f(70.0 / 3, 40.0 / 3);
    glVertex2f(100.0 / 3, 40.0 / 3);
    glVertex2f(80.0 / 3, 15.0 / 3);
    glVertex2f(50.0 / 3, 15.0 / 3);
    glEnd();
    glPopMatrix();
}
void Bus()
{
    glTranslated(-400, -400, 0);
    glPushMatrix();
    glTranslated(bus_movement, 50.0, 0.0);
    glScaled(40.0, 40.0, 0.0);
    glColor3f(0.5, 0.0, 0.0);
    // bus out line
    glBegin(GL_POLYGON);
    glVertex2f(25, 8);
    glVertex2f(25, 9.5);
    glVertex2f(26, 11);
    glVertex2f(32, 11);
    glVertex2f(32, 8);
    glEnd();
    // window frame
    glColor3f(0, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(26.1, 9.5);
    glVertex2f(26.1, 10.5);
    glVertex2f(31.8, 10.5);
    glVertex2f(31.8, 9.5);
    glEnd();
    // Doors
    glColor3f(1, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2f(26.2, 9);
    glVertex2f(26.2, 10.4);
    glVertex2f(27.7, 10.4);
    glVertex2f(27.7, 9);
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(27, 8.4);
    glVertex2f(27, 10.4);
    glVertex2f(27.7, 10.4);
    glVertex2f(27.7, 8.4);
    glEnd();
    // small windows
    glColor3f(0, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(27.8, 9.6);
    glVertex2f(27.8, 10.4);
    glVertex2f(29, 10.4);
    glVertex2f(29, 9.6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(29.1, 9.6);
    glVertex2f(29.1, 10.4);
    glVertex2f(30.2, 10.4);
    glVertex2f(30.2, 9.6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(30.3, 9.6);
    glVertex2f(30.3, 10.4);
    glVertex2f(31.7, 10.4);
    glVertex2f(31.7, 9.6);
    glEnd();

    // driver window
    glColor3f(0, 0.8, 1);
    glBegin(GL_POLYGON);
    glVertex2f(25, 9.5);
    glVertex2f(26, 11);
    glVertex2f(26, 9.5);
    glEnd();
    glPopMatrix();
    // tyre
    glPushMatrix(); // front tyre
    glTranslated(bus_movement + 970, 320, 0.0);
    glScaled(20.0, 20.0, 0.0);
    glColor3f(0.9, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(3.0, 2.5);
    glVertex2f(3.0, 2.6);
    glVertex2f(3.15, 3.1);
    glVertex2f(3.2, 3.2);
    glVertex2f(3.3, 3.35);
    glVertex2f(3.4, 3.4);
    glVertex2f(3.5, 3.45);
    glVertex2f(3.6, 3.55);
    glVertex2f(3.7, 3.6);
    glVertex2f(3.8, 3.63);
    glVertex2f(4.0, 3.65);
    glVertex2f(4.2, 3.7);
    glVertex2f(4.4, 3.7);
    glVertex2f(4.6, 3.65);
    glVertex2f(4.8, 3.55);
    glVertex2f(5.0, 3.45);
    glVertex2f(5.1, 3.4);
    glVertex2f(5.2, 3.25);
    glVertex2f(5.3, 3.2);
    glVertex2f(5.4, 3.0);
    glVertex2f(5.5, 2.5);

    glVertex2f(5.45, 2.15);
    glVertex2f(5.4, 1.9);
    glVertex2f(5.35, 1.8);
    glVertex2f(5.2, 1.6);
    glVertex2f(5.0, 1.5);
    glVertex2f(4.9, 1.4);
    glVertex2f(4.7, 1.3);
    glVertex2f(4.6, 1.27);
    glVertex2f(4.4, 1.25);
    glVertex2f(4.0, 1.25);
    glVertex2f(3.9, 1.3);
    glVertex2f(3.75, 1.35);
    glVertex2f(3.6, 1.4);
    glVertex2f(3.45, 1.55);
    glVertex2f(3.3, 1.7);
    glVertex2f(3.2, 1.8);
    glVertex2f(3.1, 2.2);
    glEnd();
    glPopMatrix();

    glPushMatrix(); // back tyre
    glTranslated(bus_movement + 1140, 320, 0.0);
    glScaled(20.0, 20.0, 0.0);
    glColor3f(0.9, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(3.0, 2.5);
    glVertex2f(3.0, 2.6);
    glVertex2f(3.15, 3.1);
    glVertex2f(3.2, 3.2);
    glVertex2f(3.3, 3.35);
    glVertex2f(3.4, 3.4);
    glVertex2f(3.5, 3.45);
    glVertex2f(3.6, 3.55);
    glVertex2f(3.7, 3.6);
    glVertex2f(3.8, 3.63);
    glVertex2f(4.0, 3.65);
    glVertex2f(4.2, 3.7);
    glVertex2f(4.4, 3.7);
    glVertex2f(4.6, 3.65);
    glVertex2f(4.8, 3.55);
    glVertex2f(5.0, 3.45);
    glVertex2f(5.1, 3.4);
    glVertex2f(5.2, 3.25);
    glVertex2f(5.3, 3.2);
    glVertex2f(5.4, 3.0);
    glVertex2f(5.5, 2.5);

    glVertex2f(5.45, 2.15);
    glVertex2f(5.4, 1.9);
    glVertex2f(5.35, 1.8);
    glVertex2f(5.2, 1.6);
    glVertex2f(5.0, 1.5);
    glVertex2f(4.9, 1.4);
    glVertex2f(4.7, 1.3);
    glVertex2f(4.6, 1.27);
    glVertex2f(4.4, 1.25);
    glVertex2f(4.0, 1.25);
    glVertex2f(3.9, 1.3);
    glVertex2f(3.75, 1.35);
    glVertex2f(3.6, 1.4);
    glVertex2f(3.45, 1.55);
    glVertex2f(3.3, 1.7);
    glVertex2f(3.2, 1.8);
    glVertex2f(3.1, 2.2);
    glEnd();
    glPopMatrix();
}