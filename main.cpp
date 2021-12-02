#include <GLFW/glfw3.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

#define M_PI 3.14159265358979323846

GLfloat prevX = 400, prevY = 500, i = 5;
void drawSnowflake(GLdouble angle, GLfloat side_length, GLint iter)
{
    GLfloat newX;
    GLfloat newY;
    GLdouble radians_angle = M_PI / 180.0 * angle;
    newX = prevX + side_length * cos(radians_angle);
    newY = prevY + side_length * sin(radians_angle);

    if (iter == 0){
        glVertex2f(prevX, prevY);
        glVertex2f(newX, newY);
        prevX = newX;
        prevY = newY;
    }

    else{
        iter--;
        drawSnowflake(angle, side_length, iter);
        angle += 60;
        drawSnowflake(angle, side_length, iter);
        angle -= 120;
        drawSnowflake(angle, side_length, iter);
        angle += 60;
        drawSnowflake(angle, side_length, iter);
    }
}

void display(){
    const double random_red = rand() % 256;
	const double random_green = rand() % 256;
    const double random_blue = rand() % 256;
	
    glColor3f(random_red/255, random_green/255, random_blue/255);
	
    glBegin(GL_LINES);
	
    drawSnowflake(0, 2, i);
    drawSnowflake(-120, 2, i);
    drawSnowflake(120, 2, i);
	
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(1280, 720);


    glutCreateWindow("Diachenko Snowflake");
    gluOrtho2D(0, 1280, 0, 720);
	
    glClearColor(0, 0, 0, 0);

    glClearDepth(1);
    glClear(GL_COLOR_BUFFER_BIT);
	
    glutDisplayFunc(display);
	
    glutMainLoop();
    return 0;
}