#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265358979323846

GLfloat i = 0.0f;

GLfloat position_car = 0.0f;
GLfloat speed_car = 0.09f;

GLfloat position_sun = 0.0f;
GLfloat position_sun_down = 0.0f;
GLfloat speed_sun = 0.0575f;

GLfloat position_moon = 0.0f;
GLfloat position_moon_down = 0.0f;
GLfloat speed_moon = 0.0575f;

GLfloat position_cloud = 0.0f;
GLfloat speed_cloud = 0.04f;

GLfloat position_bird = 0.0f;
GLfloat speed_bird = 0.05f;

void load_Start();

void load_Restart(int x)
{
    glutDisplayFunc(load_Start);
}

void Idle()
{
    glutPostRedisplay();
}

void update_car(int value)
{

    if(position_car <-1.0)
    {
        position_car = 1.0f;
    }
    position_car -= speed_car;

	glutTimerFunc(100, update_car, 0);
}

void update_sun(int value)
{

    if(position_sun <-1.0)
    {
        position_sun = 1.0f;
        position_sun_down = 1.0f;
    }
    position_sun -= speed_sun;
    position_sun_down -= speed_sun/3;

	glutTimerFunc(135, update_sun, 0);
}

void update_moon(int value)
{
    if(position_moon <-1.0)
    {
        position_moon = 1.0f;
        position_moon_down = 1.0f;
    }
    position_moon -= speed_moon;
    position_moon_down -= speed_moon/3;

	glutTimerFunc(80, update_moon, 0);
}

void update_cloud(int value)
{

    if(position_cloud <-1.0)
    {
        position_cloud = 1.0f;
    }
    position_cloud -= speed_sun;

	glutTimerFunc(100, update_cloud, 0);
}

void update_bird(int value)
{
    if(position_bird <-1.0)
    {
        position_bird = 1.0f;
    }
    position_bird -= speed_bird;

	glutTimerFunc(100, update_bird, 0);
}

void floor()
{
    glBegin(GL_QUADS);
    glColor3ub(245, 244, 203);
    glVertex2f(-0.8f,-0.55f);///TOP LEFT
    glVertex2f(0.8f,-0.55f); ///TOP RIGHT
    glVertex2f(0.8f,-0.9f); /// BOTTOM RIGHT
    glVertex2f(-0.8f,-0.9f); /// BOTTOM LEFT
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(1, 1, 1);
    glVertex2f(-0.8f,-0.55f);///TOP LEFT
    glVertex2f(0.8f,-0.55f); ///TOP RIGHT
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(1, 1, 1);
    glVertex2f(0.8f,-0.9f); /// BOTTOM RIGHT
    glVertex2f(-0.8f,-0.9f); /// BOTTOM LEFT
    glEnd();
}

void gate()
{
    glBegin(GL_QUADS);
    glColor3ub(92, 82, 7);
    glVertex2f(-0.15f,-0.65f);///TOP LEFT
    glVertex2f(0.15f,-0.65f); ///TOP RIGHT
    glVertex2f(0.15f,-0.9f); /// BOTTOM RIGHT
    glVertex2f(-0.15f,-0.9f); /// BOTTOM LEFT
    glEnd();
}

void window()
{
    glBegin(GL_QUADS);
    glColor3ub(245, 245, 0);
    glVertex2f(-0.7f,-0.6f);///TOP LEFT
    glVertex2f(-0.4f,-0.6f); ///TOP RIGHT
    glVertex2f(-0.4f,-0.8f); /// BOTTOM RIGHT
    glVertex2f(-0.7f,-0.8f); /// BOTTOM LEFT
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(1, 1, 1);
    glVertex2f(-0.55f,-0.6f);///TOP LEFT
    glVertex2f(-0.55f,-0.8f); ///TOP RIGHT
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(1, 1, 1);
    glVertex2f(-0.7f,-0.7f);///TOP LEFT
    glVertex2f(-0.4f,-0.7f); ///TOP RIGHT
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(245, 245, 0);
    glVertex2f(0.7f,-0.6f);///TOP LEFT
    glVertex2f(0.4f,-0.6f); ///TOP RIGHT
    glVertex2f(0.4f,-0.8f); /// BOTTOM RIGHT
    glVertex2f(0.7f,-0.8f); /// BOTTOM LEFT
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(1, 1, 1);
    glVertex2f(0.55f,-0.6f);///TOP LEFT
    glVertex2f(0.55f,-0.8f); ///TOP RIGHT
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(1, 1, 1);
    glVertex2f(0.7f,-0.7f);///TOP LEFT
    glVertex2f(0.4f,-0.7f); ///TOP RIGHT
    glEnd();
}

void basementFloor()
{
    floor();
    gate();
    window();
}

void upperfloors()
{
    glTranslatef(0.0, 0.35, 0.0);
    floor();
    window();
    //glLoadIdentity();
    glTranslatef(0.0, 0.35, 0.0);
    floor();
    window();
    //glLoadIdentity();
    glTranslatef(0.0, 0.35, 0.0);
    floor();
    window();
    //glLoadIdentity();
    glTranslatef(0.0, 0.35, 0.0);
    floor();
    window();
    //glLoadIdentity();
}

void building()
{
    basementFloor();
    upperfloors();
}

void grass_night()
{
    glBegin(GL_QUADS);
    glColor3ub(51, 145, 10);
    glVertex2f(-1.0f, 0.2f);
    glVertex2f(1.0f, 0.2f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();
}

void grass_day()
{
    glBegin(GL_QUADS);
    glColor3ub(0,154,23);
    glVertex2f(-1.0f, 0.2f);
    glVertex2f(1.0f, 0.2f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();
}

void bench()
{
    glBegin(GL_QUADS);
    glColor3ub(84, 84, 77);
    glVertex2f(-0.6f,0.65f);///TOP LEFT
    glVertex2f(-0.5f,0.65f); ///TOP RIGHT
    glVertex2f(-0.5f,-0.6f); /// BOTTOM RIGHT
    glVertex2f(-0.6f,-0.6f); /// BOTTOM LEFT
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(84, 84, 77);
    glVertex2f(0.5f,0.65f);///TOP LEFT
    glVertex2f(0.6f,0.65f); ///TOP RIGHT
    glVertex2f(0.6f,-0.6f); /// BOTTOM RIGHT
    glVertex2f(0.5f,-0.6f); /// BOTTOM LEFT
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(84, 84, 77);
    glVertex2f(-0.8f,-0.2f);///TOP LEFT
    glVertex2f(-0.7f,-0.2f); ///TOP RIGHT
    glVertex2f(-0.7f,-0.7f); /// BOTTOM RIGHT
    glVertex2f(-0.8f,-0.7f); /// BOTTOM LEFT
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(84, 84, 77);
    glVertex2f(0.7f,-0.2f);///TOP LEFT
    glVertex2f(0.8f,-0.2f); ///TOP RIGHT
    glVertex2f(0.8f,-0.7f); /// BOTTOM RIGHT
    glVertex2f(0.7f,-0.7f); /// BOTTOM LEFT
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(184, 155, 29);
    glVertex2f(-0.75f,-0.1f);///TOP LEFT
    glVertex2f(0.75f,-0.1f); ///TOP RIGHT
    glVertex2f(0.9f,-0.4f); /// BOTTOM RIGHT
    glVertex2f(-0.9f,-0.4f); /// BOTTOM LEFT
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(184, 155, 29);
    glVertex2f(-0.75f,0.05f);///TOP LEFT
    glVertex2f(0.75f,0.05f); ///TOP RIGHT
    glVertex2f(0.75f,0.2f); /// BOTTOM RIGHT
    glVertex2f(-0.75f,0.2f); /// BOTTOM LEFT
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(184, 155, 29);
    glVertex2f(-0.75f,0.25f);///TOP LEFT
    glVertex2f(0.75f,0.25f); ///TOP RIGHT
    glVertex2f(0.75f,0.4f); /// BOTTOM RIGHT
    glVertex2f(-0.75f,0.4f); /// BOTTOM LEFT
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(184, 155, 29);
    glVertex2f(-0.75f,0.45f);///TOP LEFT
    glVertex2f(0.75f,0.45f); ///TOP RIGHT
    glVertex2f(0.75f,0.6f); /// BOTTOM RIGHT
    glVertex2f(-0.75f,0.6f); /// BOTTOM LEFT
    glEnd();

}

void lamppost()
{
    glBegin(GL_QUADS);
    glColor3ub(207, 204, 194);
    glVertex2f(-0.5f,0.6f);///TOP LEFT
    glVertex2f(-0.4f,0.6f); ///TOP RIGHT
    glVertex2f(-0.4f,-0.9f); /// BOTTOM RIGHT
    glVertex2f(-0.5f,-0.9f); /// BOTTOM LEFT
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(207, 204, 194);
    glVertex2f(-0.4f,0.6f);///TOP LEFT
    glVertex2f(0.3f,0.6f); ///TOP RIGHT
    glVertex2f(0.3f,0.5f); /// BOTTOM RIGHT
    glVertex2f(-0.4f,0.5f); /// BOTTOM LEFT
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(239, 255, 59);
    glVertex2f(-0.1f,0.5f);///TOP LEFT
    glVertex2f(0.3f,0.5f); ///TOP RIGHT
    glVertex2f(0.25f,0.4f); /// BOTTOM RIGHT
    glVertex2f(-0.05f,0.4f); /// BOTTOM LEFT
    glEnd();
}

void lamppost_light()
{
    glBegin(GL_QUADS);
    glColor3ub(248, 252, 202);
    glVertex2f(-0.05f,0.4f);///TOP LEFT
    glVertex2f(0.25f,0.4f); ///TOP RIGHT
    glVertex2f(0.65f,-0.9f); /// BOTTOM RIGHT
    glVertex2f(-0.35f,-0.9f); /// BOTTOM LEFT
    glEnd();
}

void tree()
{
    glBegin(GL_TRIANGLES);
    glColor3ub(36, 105, 6);
    glVertex2f(-0.55f,0.2f);
    glVertex2f(0.55f,0.2f);
    glVertex2f(0.0f,0.9f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(36, 105, 6);
    glVertex2f(-0.6f,0.0f);
    glVertex2f(0.6f,0.0f);
    glVertex2f(0.0f,0.7f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(161, 127, 10);
    glVertex2f(-0.14f,0.001f);///TOP LEFT
    glVertex2f(0.14f,0.001f); ///TOP RIGHT
    glVertex2f(0.14f,-0.9f); /// BOTTOM RIGHT
    glVertex2f(-0.14f,-0.9f); /// BOTTOM LEFT
    glEnd();
}

void Sun()
{
    glPushMatrix();
    glTranslatef(-position_sun, 0.0/*position_sun_down*/, 0.0f);
        int is;
        GLfloat xs=-0.8f;
        GLfloat ys=0.8f;
        GLfloat radiuss =.14f;
        int triangleAmounts = 100;
        GLfloat twicePis = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(255, 209, 26);
        glVertex2f(xs, ys);
        for(is = 0; is <= triangleAmounts; is++)
        {
            glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
        }
        glEnd();
	glPopMatrix();
	glLoadIdentity();
}

void Cloud()
{
    glPushMatrix();
    glTranslatef(position_cloud, 0.0f, 0.0f);
        float xC,yC,radiusC,triangleAmountC,twicePiC;
        xC= -0.4f, yC= 0.7f, radiusC =.09f;
        triangleAmountC = 20;
        twicePiC = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(230, 255, 255);
        glVertex2f(xC, yC);
        for(int iC = 0; iC <= triangleAmountC;iC++)
        {
            glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
        }
        glEnd();
        xC= -0.3f, yC= 0.7f, radiusC =.09f;
        triangleAmountC = 20;
        twicePiC = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(204, 255, 255);
        glVertex2f(xC, yC);
        for(int iC = 0; iC <= triangleAmountC;iC++)
        {
            glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
        }
        glEnd();
        xC= -0.37f, yC= 0.67f, radiusC =.09f;
        triangleAmountC = 20;
        twicePiC = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(204, 255, 255);
        glVertex2f(xC, yC);
        for(int iC = 0; iC <= triangleAmountC;iC++)
        {
            glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
        }
        glEnd();


        glTranslatef(0.5f,0.1,0);
        xC= -0.4f, yC= 0.7f, radiusC =.09f;
        triangleAmountC = 20;
        twicePiC = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(230, 255, 255);
        glVertex2f(xC, yC);
        for(int iC = 0; iC <= triangleAmountC;iC++)
        {
            glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
        }
        glEnd();
        xC= -0.3f, yC= 0.7f, radiusC =.09f;
        triangleAmountC = 20;
        twicePiC = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(204, 255, 255);
        glVertex2f(xC, yC);
        for(int iC = 0; iC <= triangleAmountC;iC++)
        {
            glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
        }
        glEnd();
        xC= -0.37f, yC= 0.67f, radiusC =.09f;
        triangleAmountC = 20;
        twicePiC = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(204, 255, 255);
        glVertex2f(xC, yC);
        for(int iC = 0; iC <= triangleAmountC;iC++)
        {
            glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
        }
        glEnd();

        glTranslatef(0.5f,-0.19,0);
        xC= -0.4f, yC= 0.7f, radiusC =.09f;
        triangleAmountC = 20;
        twicePiC = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(230, 255, 255);
        glVertex2f(xC, yC);
        for(int iC = 0; iC <= triangleAmountC;iC++)
        {
            glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
        }
        glEnd();
        xC= -0.3f, yC= 0.7f, radiusC =.09f;
        triangleAmountC = 20;
        twicePiC = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(204, 255, 255);
        glVertex2f(xC, yC);
        for(int iC = 0; iC <= triangleAmountC;iC++)
        {
            glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
        }
        glEnd();
        xC= -0.37f, yC= 0.67f, radiusC =.09f;
        triangleAmountC = 20;
        twicePiC = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(204, 255, 255);
        glVertex2f(xC, yC);
        for(int iC = 0; iC <= triangleAmountC;iC++)
        {
            glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
        }
        glEnd();
	glPopMatrix();
	glLoadIdentity();
}

void Bird()
{
    glPushMatrix();
    glTranslatef(-position_bird, 0.0f, 0.0f);
    int i;

	GLfloat mm=0.182f; GLfloat nn=.801f; GLfloat radiusmm =.01f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mm, nn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mm + (radiusmm * cos(i *  twicePi / triangleAmount)),
			    nn + (radiusmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(0.1f,0.8f);
    glVertex2f(0.11f,0.79f);
    glVertex2f(0.12f,0.78f);
    glVertex2f(0.16f,0.77f);
    glVertex2f(0.19f,0.79f);
    glVertex2f(0.201f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.15f,0.8f);
    glVertex2f(0.14f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.144f,0.8f);
    glVertex2f(0.12f,0.83f);
    glEnd();
	/////2nd bird////
	glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.02f,0.8f);
    glVertex2f(-0.01f,0.79f);
    glVertex2f(0.0f,0.78f);
    glVertex2f(0.04f,0.77f);
    glVertex2f(0.07f,0.79f);
    glVertex2f(0.081f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.03f,0.8f);
    glVertex2f(0.02f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.024f,0.8f);
    glVertex2f(0.0f,0.83f);
    glEnd();

	GLfloat mmm=0.062f; GLfloat nnn=.801f; GLfloat radiusmmm =.01f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmm, nnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
			    nnn + (radiusmmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	/////3rd bird/////
	glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.72f,0.8f);
    glVertex2f(-0.71f,0.79f);
    glVertex2f(-0.7f,0.78f);
    glVertex2f(-0.66f,0.77f);
    glVertex2f(-0.63f,0.79f);
    glVertex2f(-0.619f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.67f,0.8f);
    glVertex2f(-0.68f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.676f,0.8f);
    glVertex2f(-0.7f,0.83f);
    glEnd();

	GLfloat mmmm=-0.638f; GLfloat nnnn=.801f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmmm,nnnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
			    nnnn + (radiusmmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	////4th bird////
	GLfloat mmmmm=-0.518f; GLfloat nnnnn=.801f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmmmm, nnnnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmmmm + (radiusmm * cos(i *  twicePi / triangleAmount)),
			    nnnnn + (radiusmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.6f,0.8f);
    glVertex2f(-0.59f,0.79f);
    glVertex2f(-0.58f,0.78f);
    glVertex2f(-0.54f,0.77f);
    glVertex2f(-0.51f,0.79f);
    glVertex2f(-0.499f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.56f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.556f,0.8f);
    glVertex2f(-0.58f,0.83f);
    glEnd();
    glPopMatrix();

}

void Moon()
{
    glPushMatrix();
    glTranslatef(position_moon, 0.0/*position_moon_down*/, 0.0f);
    int is;
    GLfloat xs=0.8f;
	GLfloat ys=0.85f;
	GLfloat radiuss =.1f;
    int triangleAmounts = 100;
    GLfloat twicePis = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,240);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
    glEnd();

    glTranslatef(0.04,0.05,0.0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(44,62,80);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
    glEnd();
    glLoadIdentity();
    glPopMatrix();
}

void drawCircle(float x1, float y1,double radius)
{
    float x2, y2;
    float angle;
    glBegin(GL_POLYGON);
    for (angle = .1f; angle<361.0f; angle += 1.0f)
    {
        x2 = x1 + sin(angle)*radius;
        y2 = y1 + cos(angle)*radius;
        glVertex2f(x2, y2);
    }
    glEnd();
}

void Stars()
{
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(255,255,240);
    drawCircle(0.2,0.9,0.006);
    drawCircle(0.4,0.9,0.006);
    drawCircle(0.6,0.9,0.006);
    drawCircle(0.8,0.9,0.006);
    drawCircle(-0.2,0.9,0.006);
    drawCircle(-0.4,0.9,0.006);
    drawCircle(-0.6,0.9,0.006);
    drawCircle(-0.8,0.9,0.006);
    drawCircle(-0.9,0.8,0.006);
    drawCircle(-0.7,0.8,0.006);
    drawCircle(-0.5,0.8,0.006);
    drawCircle(-0.3,0.8,0.006);
    drawCircle(-0.0,0.9,0.006);
    drawCircle(-0.1,0.8,0.006);
    drawCircle(0.1,0.8,0.006);
    drawCircle(0.3,0.8,0.006);
    drawCircle(0.5,0.8,0.006);
    drawCircle(0.7,0.8,0.006);
    drawCircle(0.9,0.8,0.006);

    drawCircle(0.2,0.7,0.006);
    drawCircle(0.4,0.7,0.006);
    drawCircle(0.6,0.7,0.006);
    drawCircle(0.8,0.7,0.006);
    drawCircle(-0.2,0.7,0.006);
    drawCircle(-0.4,0.7,0.006);
    drawCircle(-0.6,0.7,0.006);
    drawCircle(-0.8,0.7,0.006);
    drawCircle(-0.9,0.6,0.006);
    drawCircle(-0.7,0.6,0.006);
    drawCircle(-0.5,0.6,0.006);
    drawCircle(-0.3,0.6,0.006);
    drawCircle(-0.0,0.7,0.006);
    drawCircle(-0.1,0.6,0.006);
    drawCircle(0.1,0.6,0.006);
    drawCircle(0.3,0.6,0.006);
    drawCircle(0.5,0.6,0.006);
    drawCircle(0.7,0.6,0.006);
    drawCircle(0.9,0.6,0.006);

    drawCircle(0.2,0.5,0.006);
    drawCircle(0.4,0.5,0.006);
    drawCircle(0.6,0.5,0.006);
    drawCircle(0.8,0.5,0.006);
    drawCircle(-0.2,0.5,0.006);
    drawCircle(-0.4,0.5,0.006);
    drawCircle(-0.6,0.5,0.006);
    drawCircle(-0.8,0.5,0.006);
    drawCircle(-0.9,0.4,0.006);
    drawCircle(-0.7,0.4,0.006);
    drawCircle(-0.5,0.4,0.006);
    drawCircle(-0.3,0.4,0.006);
    drawCircle(-0.0,0.5,0.006);
    drawCircle(-0.1,0.4,0.006);
    drawCircle(0.1,0.4,0.006);
    drawCircle(0.3,0.4,0.006);
    drawCircle(0.5,0.4,0.006);
    drawCircle(0.7,0.4,0.006);
    drawCircle(0.9,0.4,0.006);
    glPopMatrix();
    glEnd();
}

void road_devider()
{
    glBegin(GL_QUADS);
    glColor3ub(249, 250, 187);
    glVertex2f(-0.99f, -0.43f);
    glVertex2f(-0.79f, -0.43f);
    glVertex2f(-0.79f, -0.47f);
    glVertex2f(-0.99f, -0.47f);
    glEnd();
}

void road()
{
    glBegin(GL_QUADS);
    glColor3ub(133, 126, 126);
    glVertex2f(-1.0f, -0.15f);
    glVertex2f(1.0f, -0.15f);
    glVertex2f(1.0f, -0.75f);
    glVertex2f(-1.0f, -0.75f);
    glEnd();

    road_devider();
    glTranslatef(0.3,0.0,0.0);
        road_devider();
    glLoadIdentity();
    road_devider();
    glTranslatef(0.6,0.0,0.0);
        road_devider();
    glLoadIdentity();
    road_devider();
    glTranslatef(0.9,0.0,0.0);
        road_devider();
    glLoadIdentity();
    road_devider();
    glTranslatef(1.2,0.0,0.0);
        road_devider();
    glLoadIdentity();
    road_devider();
    glTranslatef(1.5,0.0,0.0);
        road_devider();
    glLoadIdentity();
    road_devider();
    glTranslatef(1.8,0.0,0.0);
        road_devider();
    glLoadIdentity();
}

void car_wheel(float x_axis, float y_axis)
{
    int is;
    GLfloat xs = x_axis;
	GLfloat ys = y_axis;
	GLfloat radiuss =.08f;
    int triangleAmounts = 100;
    GLfloat twicePis = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
    glEnd();

    radiuss =.05f;
    twicePis = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(222, 217, 218);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
    glEnd();

    radiuss =.015f;
    twicePis = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
    glEnd();

    glTranslatef(xs,ys,0.0);
    glPushMatrix();
    glRotatef(i,0.0,0.0,1.0);
        glBegin(GL_TRIANGLES);
        glColor3ub(0,0,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0225f, -0.0225f);
        glVertex2f(0.06f, -0.03f);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3ub(0,0,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(-0.0225f, -0.0225f);
        glVertex2f(-0.06f, -0.03f);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3ub(0,0,0);
        glVertex2f(0.0, 0.0);
        glVertex2f( -0.01f, 0.03f);
        glVertex2f(0.00f, 0.06f);
        glEnd();
    glPopMatrix();
    //glLoadIdentity();
    //glLoadIdentity();

    i+=-0.7f;
}

void car_window(int R, int G, int B)
{
    glBegin(GL_QUADS);
    glColor3ub(202, 218, 222);
    glVertex2f(-0.5f, -0.15f);
    glVertex2f(-.35f, -0.15f);
    glVertex2f(-0.2f, -0.25f);
    glVertex2f(-0.5f, -0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(R, G, B);
    glVertex2f(-0.36f, -0.15f);
    glVertex2f(-.35f, -0.15f);
    glVertex2f(-0.35f, -0.25f);
    glVertex2f(-0.36f, -0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(R, G, B);
    glVertex2f(-0.6f, -0.15f);
    glVertex2f(-.35f, -0.15f);
    glVertex2f(-0.35f, -0.16f);
    glVertex2f(-0.6f, -0.16f);
    glEnd();
}

void car_body(int R, int G, int B)
{
    glBegin(GL_QUADS);
    glColor3ub(R,G,B);
    glVertex2f(-0.6f, -0.15f);
    glVertex2f(-.35f, -0.15f);
    glVertex2f(-0.2f, -0.42f);
    glVertex2f(-0.6f, -0.42f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(R,G,B);
    glVertex2f(-0.35f, -0.25f);
    glVertex2f(-0.1f, -0.25f);
    glVertex2f(-0.1f, -0.42f);
    glVertex2f(-0.35f, -0.42f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(R,G,B);
    glVertex2f(-0.8f, -0.25f);
    glVertex2f(-0.6f, -0.15f);
    glVertex2f(-0.6f, -0.42f);
    glVertex2f(-0.8f, -0.42f);
    glEnd();
}

void car(int R, int G, int B)
{
    glScalef(0.8, 0.8, 0.0);
    car_body(R, G, B);
    car_window(R, G, B);
    car_wheel(-0.65f, -0.42f);
    //glScalef(0.8, 0.8, 0.0);
    car_wheel(0.40f, 0.00f);
}

void traffic_light()
{
    ///Box
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.1f, 0.35f);
    glVertex2f(0.1f, 0.35f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glEnd();
    ///Stand
    glBegin(GL_QUADS);
    glColor3ub(171, 169, 164);
    glVertex2f(-0.05f, 0.0f);
    glVertex2f(0.05f, 0.0f);
    glVertex2f(0.05f, -0.75f);
    glVertex2f(-0.05f, -0.75f);
    glEnd();
    ///LIGHTS
    int is;
    GLfloat xs = 0.0;
	GLfloat ys = 0.0;
	GLfloat radiuss =.04f;
    int triangleAmounts = 100;
    GLfloat twicePis = 2.0f * PI;
    ///RED
    xs = 0.0;
	ys = 0.28;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(140, 0, 0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
    glEnd();
    ///YELLOW
    xs = 0.0;
	ys = 0.18;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(175, 181, 0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
    glEnd();
    ///GREEN
    xs = 0.0;
	ys = 0.08;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(111, 255, 92);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
    glEnd();
}

void Day_Sky()
{

    glBegin(GL_QUADS);
    glColor3ub(0, 153, 255);
    glVertex2f(-1.0, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, .95f);
    glVertex2f(-1.0f, .95f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(26, 163, 255);
    glVertex2f(-1.0, .95f);
    glVertex2f(1.0f, .95f);
    glVertex2f(1.0f, .90f);
    glVertex2f(-1.0f, .90f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(51, 173, 255);
    glVertex2f(-1.0, .90f);
    glVertex2f(1.0f, .90f);
    glVertex2f(1.0f, .85f);
    glVertex2f(-1.0f, .85f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(77, 184, 255);
    glVertex2f(-1.0, .85f);
    glVertex2f(1.0f, .85f);
    glVertex2f(1.0f, .80f);
    glVertex2f(-1.0f, .80f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 194, 255);
    glVertex2f(-1.0, .80f);
    glVertex2f(1.0f, .80f);
    glVertex2f(1.0f, .70f);
    glVertex2f(-1.0f, .70f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 204, 255);
    glVertex2f(-1.0, .70f);
    glVertex2f(1.0f, .70f);
    glVertex2f(1.0f, .60f);
    glVertex2f(-1.0f, .60f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(153, 214, 255);
    glVertex2f(-1.0, .60f);
    glVertex2f(1.0f, .60f);
    glVertex2f(1.0f, .40f);
    glVertex2f(-1.0f, .40f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 224, 255);
    glVertex2f(-1.0, .40f);
    glVertex2f(1.0f, .40f);
    glVertex2f(1.0f, .15f);
    glVertex2f(-1.0f, .15f);
    glEnd();
}

void Night_Sky()
{
    glBegin(GL_QUADS);
    glColor3ub(44,62,80);
    glVertex2f(-1.0, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, -0.2f);
    glVertex2f(-1.0f, -0.2f);
    glEnd();
}

void night_view()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Night_Sky();

    grass_night();
    road();
    Moon();
    Stars();

    glTranslatef(0.7, 0.35, 0.0);
    glScalef(0.3, 0.3, 0.0);
        building();
    glLoadIdentity();

    glTranslatef(0.0, 0.35, 0.0);
    glScalef(0.3, 0.3, 0.0);
        building();
    glLoadIdentity();

    glTranslatef(-0.7, 0.35, 0.0);
    glScalef(0.3, 0.3, 0.0);
        building();
    glLoadIdentity();

    glTranslatef(0.975, 0.12, 0.0);
    glScalef(0.2, 0.3, 0.0);
        tree();
    glLoadIdentity();

    glTranslatef(-0.43, 0.12, 0.0);
    glScalef(0.2, 0.3, 0.0);
        tree();
    glLoadIdentity();

    glTranslatef(-0.85, 0.08, 0.0);
    glScalef(0.3, 0.25, 0.0);
        lamppost();
        lamppost_light();
    glLoadIdentity();

    glTranslatef(-0.13, 0.08, 0.0);
    glScalef(0.3, 0.25, 0.0);
        lamppost();
        lamppost_light();
    glLoadIdentity();

    glTranslatef(0.61, 0.08, 0.0);
    glScalef(0.3, 0.25, 0.0);
        lamppost();
        lamppost_light();
    glLoadIdentity();

    glTranslatef(-0.60, 0.00, 0.0);
    glScalef(0.18, 0.18, 0.0);
        bench();
    glLoadIdentity();

    glTranslatef(0.17, 0.00, 0.0);
    glScalef(0.18, 0.18, 0.0);
        bench();
    glLoadIdentity();

    glTranslatef(-0.25, 0.00, 0.0);
    glScalef(0.8, 0.8, 0.0);
    glPushMatrix();
    glTranslatef(-position_car,0.0, 0.0f);
        car(4, 9, 112);
    glPopMatrix();
    glLoadIdentity();


    glTranslatef(0.15, -0.34, 0.0);
    glScalef(0.8, 0.8, 0.0);
    glPushMatrix();
    glTranslatef(-position_car,0.0, 0.0f);
        car(138, 0, 14);
    glPopMatrix();
    glLoadIdentity();

    glTranslatef(0.83, 0.12, 0.0);
    glScalef(0.4, 0.35, 0.0);
        traffic_light();
    glLoadIdentity();

    glutTimerFunc(2000,load_Restart,0);
    position_sun = 0.0f;
	glFlush();
}

void load_Night(int x)
{
    glutDisplayFunc(night_view);
}

void day_view()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Day_Sky();

    grass_day();
    road();
    glEnable(GL_LIGHTING);
    GLfloat sun_shine[] = {77, 77, 0, 7.5};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, sun_shine);
        Sun();
    glDisable(GL_LIGHTING);

    glScalef(0.8,0.8,0.0);
    glTranslatef(0.0,0.3,0.0);
        Cloud();
    glLoadIdentity();

    glScalef(0.8,0.8,0.0);
    glTranslatef(0.0, 0.1, 0.0);
        Bird();
    glLoadIdentity();

    glScalef(0.8,0.8,0.0);
    glTranslatef(0.2, 0.2, 0.0);
        Bird();
    glLoadIdentity();

    glTranslatef(0.7, 0.35, 0.0);
    glScalef(0.3, 0.3, 0.0);
        building();
    glLoadIdentity();

    glTranslatef(0.0, 0.35, 0.0);
    glScalef(0.3, 0.3, 0.0);
        building();
    glLoadIdentity();

    glTranslatef(-0.7, 0.35, 0.0);
    glScalef(0.3, 0.3, 0.0);
        building();
    glLoadIdentity();

    glTranslatef(0.975, 0.12, 0.0);
    glScalef(0.2, 0.3, 0.0);
        tree();
    glLoadIdentity();

    glTranslatef(-0.43, 0.12, 0.0);
    glScalef(0.2, 0.3, 0.0);
        tree();
    glLoadIdentity();

    glTranslatef(-0.85, 0.08, 0.0);
    glScalef(0.3, 0.25, 0.0);
        lamppost();
    glLoadIdentity();

    glTranslatef(-0.13, 0.08, 0.0);
    glScalef(0.3, 0.25, 0.0);
        lamppost();
    glLoadIdentity();

    glTranslatef(0.61, 0.08, 0.0);
    glScalef(0.3, 0.25, 0.0);
        lamppost();
    glLoadIdentity();

    glTranslatef(-0.60, 0.00, 0.0);
    glScalef(0.18, 0.18, 0.0);
        bench();
    glLoadIdentity();

    glTranslatef(0.17, 0.00, 0.0);
    glScalef(0.18, 0.18, 0.0);
        bench();
    glLoadIdentity();

    glTranslatef(-0.25, 0.00, 0.0);
    glScalef(0.8, 0.8, 0.0);
    glPushMatrix();
    glTranslatef(-position_car,0.0, 0.0f);
        car(4, 9, 112);
    glPopMatrix();
    glLoadIdentity();


    glTranslatef(0.15, -0.34, 0.0);
    glScalef(0.8, 0.8, 0.0);
    glPushMatrix();
    glTranslatef(-position_car,0.0, 0.0f);
        car(138, 0, 14);
    glPopMatrix();
    glLoadIdentity();

    glTranslatef(0.83, 0.12, 0.0);
    glScalef(0.4, 0.35, 0.0);
        traffic_light();
    glLoadIdentity();

    glutTimerFunc(2000,load_Night,0);

    position_moon = 0.0f;
	glFlush();
}

void load_Day(int x)
{
    glutDisplayFunc(day_view);
}

void load_Start()
{
    glutDisplayFunc(day_view);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 640);
	glutCreateWindow("City Traffic Scenario (Auto Animation)");
	glutDisplayFunc(load_Start);
	glutTimerFunc(100, update_car, 0);
	glutTimerFunc(100, update_sun, 0);
	glutTimerFunc(100, update_moon, 0);
	glutTimerFunc(100, update_cloud, 0);
	glutTimerFunc(100, update_bird, 0);
	glutIdleFunc(Idle);
	glutMainLoop();
	return 0;
}









