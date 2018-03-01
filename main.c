#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>

//MV

GLubyte tux[] = {
 0xc3, 0xc3,0x03,  0xc0,
 0xc3, 0xc3,0x03,  0xc0,
 0xc3, 0xc3,0x03,  0xc0,
 0xc7, 0xe3,0x03,  0xc0,
 0xc7, 0xe3,0x07,  0xe0,
 0xc7, 0xe3,0x07,  0xe0,
 0xcf, 0xf3,0x0f,  0xf0,
 0xce, 0x73,0x0e,  0x70,
 0xce, 0x73,0x0e,  0x70,
 0xde, 0x7b,0x1e,  0x78,
 0xde, 0x7b,0x1e,  0x78,
 0xdc, 0x3b,0x1e,  0x78,
 0xfc, 0x3f,0x1c,  0x1c,
 0xfc, 0x3f,0x3c,  0x3c,
 0xfc, 0x3f,0x3c,  0x3c,
 0x0,  0x0,  0x0,   0x0,
 0x0,  0x0,  0x0,   0x0,
 0x0,  0x0,  0x0,   0x0,
 0x0,  0x0,  0x0,   0x0,
 0x0,  0x0,  0x0,   0x0,
 0x0,  0x0,  0x0,   0x0,
 0x0,  0x0,  0x0,   0x0,
 0x0,  0x0,  0x0,   0x0,
 0x0,  0x0,  0x0,   0x0,
 0x0,  0x0,  0x0,   0x0,
 0x0,  0x0,  0x0,   0x0,
 0x0,  0x0,  0x0,   0x0,
 0x0,  0x0,  0x0,   0x0,
 0x0,  0x0,  0x0,   0x0,
 0x0,  0x0,  0x0,   0x0,
 0x0,  0x0,  0x0,   0x0,
 0x0,  0x0,  0x0,   0x0,
 0x0,  0x0,  0x0,   0x0,
};

GLfloat r1 = 0.0, g1 = 0.0, b1 = 0.0;
int flag = -9999;

struct Vertice{
    int x;
    int y;
};

typedef struct Quadrilatero{
    struct Vertice v[4];
}Quadrilatero;

void init(void);
void display1(void);
void display2(void);
void display3Vazado(void);
void display3Solido(void);
void display3Degrade(void);
void display3ComPreenchimento(void);
void display4(void);
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);
void personalizado(void);
void reshape (int w, int h);

Quadrilatero q[4];
int cont = 0;
int cont2 = 0;
int op;

int main(int argc, char** argv){

    srand(time(NULL));
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(360, 360);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Resultado");
    init();

    printf("\tMENU:\n");
    printf("1.Preenchimento personalizado;\n");
    printf("2.Desenhar qualilateros com o mouse ou mudar cor da borda;\n");
    printf("3.Desenhar qualilateros personalizados;\n");
    printf("4.Mudar cor do quadrilatero ou do fundo;\n");
    printf("5.Sair;\n");
    printf("\nOpcao: ");

    scanf("%d", &op);

    switch(op){

        case 1:

            glutDisplayFunc(personalizado);

        break;

        case 2:

            glutDisplayFunc(display1);

        break;

        case 3:

        flag = 1;

        printf("\tEscolha o tipo de preenchimento:\n");
        printf("1.Vazado;\n");
        printf("2.Solido;\n");
        printf("3.Degrade;\n");
        printf("4.Com preenchimento;\n");
        printf("\nOpcao: ");

        scanf("%d", &op);

        if(op==1){

        glutDisplayFunc(display3Vazado);

        }

        if(op==2){

        glutDisplayFunc(display3Solido);

        }

        if(op==3){

        glutDisplayFunc(display3Degrade);

        }

        if(op==4){

        glutDisplayFunc(display3ComPreenchimento);

        }

        break;

        case 4:

        flag = 4;

        glutDisplayFunc(display4);

        break;

        case 5:

        return 0;

        break;
    }

    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}

void init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho (0, 360, 0, 360, -1 ,1);
}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();
}

void display1(void){

    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_POLYGON_STIPPLE);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(r1, g1, b1);
    glBegin(GL_POLYGON);
    glVertex2i(q[0].v[0].x, 360 - q[0].v[0].y);
    glVertex2i(q[0].v[1].x, 360 - q[0].v[1].y);
    glVertex2i(q[0].v[2].x, 360 - q[0].v[2].y);
    glVertex2i(q[0].v[3].x, 360 - q[0].v[3].y);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(r1, g1, b1);
    glBegin(GL_POLYGON);
    glVertex2i(q[1].v[0].x, 360 - q[1].v[0].y);
    glVertex2i(q[1].v[1].x, 360 - q[1].v[1].y);
    glVertex2i(q[1].v[2].x, 360 - q[1].v[2].y);
    glVertex2i(q[1].v[3].x, 360 - q[1].v[3].y);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(r1, g1, b1);
    glBegin(GL_POLYGON);
    glVertex2i(q[2].v[0].x, 360 - q[2].v[0].y);
    glVertex2i(q[2].v[1].x, 360 - q[2].v[1].y);
    glVertex2i(q[2].v[2].x, 360 - q[2].v[2].y);
    glVertex2i(q[2].v[3].x, 360 - q[2].v[3].y);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(r1, g1, b1);
    glBegin(GL_POLYGON);
    glVertex2i(q[3].v[0].x, 360 - q[3].v[0].y);
    glVertex2i(q[3].v[1].x, 360 - q[3].v[1].y);
    glVertex2i(q[3].v[2].x, 360 - q[3].v[2].y);
    glVertex2i(q[3].v[3].x, 360 - q[3].v[3].y);
    glEnd();

    glFlush();
    glutSwapBuffers();
}

void display2(void){

    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_POLYGON_STIPPLE);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(r1, g1, b1);
    glBegin(GL_POLYGON);
    glVertex2i(q[0].v[0].x, 360 - q[0].v[0].y);
    glVertex2i(q[0].v[1].x, 360 - q[0].v[1].y);
    glVertex2i(q[0].v[2].x, 360 - q[0].v[2].y);
    glVertex2i(q[0].v[3].x, 360 - q[0].v[3].y);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(r1, g1, b1);
    glBegin(GL_POLYGON);
    glVertex2i(q[1].v[0].x, 360 - q[1].v[0].y);
    glVertex2i(q[1].v[1].x, 360 - q[1].v[1].y);
    glVertex2i(q[1].v[2].x, 360 - q[1].v[2].y);
    glVertex2i(q[1].v[3].x, 360 - q[1].v[3].y);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(r1, g1, b1);
    glBegin(GL_POLYGON);
    glVertex2i(q[2].v[0].x, 360 - q[2].v[0].y);
    glVertex2i(q[2].v[1].x, 360 - q[2].v[1].y);
    glVertex2i(q[2].v[2].x, 360 - q[2].v[2].y);
    glVertex2i(q[2].v[3].x, 360 - q[2].v[3].y);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(r1, g1, b1);
    glBegin(GL_POLYGON);
    glVertex2i(q[3].v[0].x, 360 - q[3].v[0].y);
    glVertex2i(q[3].v[1].x, 360 - q[3].v[1].y);
    glVertex2i(q[3].v[2].x, 360 - q[3].v[2].y);
    glVertex2i(q[3].v[3].x, 360 - q[3].v[3].y);
    glEnd();

    glFlush();
    glutSwapBuffers();
}

void display3Vazado(void){

    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_POLYGON_STIPPLE);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(r1, g1, b1);
    glBegin(GL_POLYGON);
    glVertex2i(q[0].v[0].x, 360 - q[0].v[0].y);
    glVertex2i(q[0].v[1].x, 360 - q[0].v[1].y);
    glVertex2i(q[0].v[2].x, 360 - q[0].v[2].y);
    glVertex2i(q[0].v[3].x, 360 - q[0].v[3].y);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(r1, g1, b1);
    glBegin(GL_POLYGON);
    glVertex2i(q[1].v[0].x, 360 - q[1].v[0].y);
    glVertex2i(q[1].v[1].x, 360 - q[1].v[1].y);
    glVertex2i(q[1].v[2].x, 360 - q[1].v[2].y);
    glVertex2i(q[1].v[3].x, 360 - q[1].v[3].y);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(r1, g1, b1);
    glBegin(GL_POLYGON);
    glVertex2i(q[2].v[0].x, 360 - q[2].v[0].y);
    glVertex2i(q[2].v[1].x, 360 - q[2].v[1].y);
    glVertex2i(q[2].v[2].x, 360 - q[2].v[2].y);
    glVertex2i(q[2].v[3].x, 360 - q[2].v[3].y);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(r1, g1, b1);
    glBegin(GL_POLYGON);
    glVertex2i(q[3].v[0].x, 360 - q[3].v[0].y);
    glVertex2i(q[3].v[1].x, 360 - q[3].v[1].y);
    glVertex2i(q[3].v[2].x, 360 - q[3].v[2].y);
    glVertex2i(q[3].v[3].x, 360 - q[3].v[3].y);
    glEnd();

    glFlush();
    glutSwapBuffers();
}

void display3Solido(void){

    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_POLYGON_STIPPLE);

    glPolygonMode(GL_BACK, GL_FILL);
    glColor3f(1, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2i(q[0].v[0].x, 360 - q[0].v[0].y);
    glVertex2i(q[0].v[1].x, 360 - q[0].v[1].y);
    glVertex2i(q[0].v[2].x, 360 - q[0].v[2].y);
    glVertex2i(q[0].v[3].x, 360 - q[0].v[3].y);
    glEnd();

    glPolygonMode(GL_BACK, GL_FILL);
    glColor3f(1, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2i(q[1].v[0].x, 360 - q[1].v[0].y);
    glVertex2i(q[1].v[1].x, 360 - q[1].v[1].y);
    glVertex2i(q[1].v[2].x, 360 - q[1].v[2].y);
    glVertex2i(q[1].v[3].x, 360 - q[1].v[3].y);
    glEnd();

    glPolygonMode(GL_BACK, GL_FILL);
    glColor3f(1, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2i(q[2].v[0].x, 360 - q[2].v[0].y);
    glVertex2i(q[2].v[1].x, 360 - q[2].v[1].y);
    glVertex2i(q[2].v[2].x, 360 - q[2].v[2].y);
    glVertex2i(q[2].v[3].x, 360 - q[2].v[3].y);
    glEnd();

    glPolygonMode(GL_BACK, GL_FILL);
    glColor3f(1, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2i(q[3].v[0].x, 360 - q[3].v[0].y);
    glVertex2i(q[3].v[1].x, 360 - q[3].v[1].y);
    glVertex2i(q[3].v[2].x, 360 - q[3].v[2].y);
    glVertex2i(q[3].v[3].x, 360 - q[3].v[3].y);
    glEnd();

    glFlush();
    glutSwapBuffers();
}

void display3Degrade(void){

    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_POLYGON_STIPPLE);

    glPolygonMode(GL_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);  glVertex2i(q[0].v[0].x, 360 - q[0].v[0].y);
    glColor3f(0.0, 1.0, 0.0);  glVertex2i(q[0].v[1].x, 360 - q[0].v[1].y);
    glColor3f(0.0, 0.0, 1.0);  glVertex2i(q[0].v[2].x, 360 - q[0].v[2].y);
    glColor3f(1.0, 1.0, 0.0);  glVertex2i(q[0].v[3].x, 360 - q[0].v[3].y);
    glEnd();

    glFlush();
    glutSwapBuffers();
}

void display3ComPreenchimento(void){

    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_POLYGON_STIPPLE);

    glEnable(GL_POLYGON_STIPPLE);
    glColor3f(0.0, 0.0, 1.0);
    glPolygonStipple(tux);
    glBegin(GL_POLYGON);
    glVertex2i(q[0].v[0].x, 360 - q[0].v[0].y);
    glVertex2i(q[0].v[1].x, 360 - q[0].v[1].y);
    glVertex2i(q[0].v[2].x, 360 - q[0].v[2].y);
    glVertex2i(q[0].v[3].x, 360 - q[0].v[3].y);
    glEnd();

    glFlush();
    glutSwapBuffers();

}

void display4(void){

    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_POLYGON_STIPPLE);

    glPolygonMode(GL_BACK, GL_LINE);
    glColor3f(r1, g1, b1);
    glBegin(GL_POLYGON);
    glVertex2i(30,226);  glVertex2i(113,226);
    glVertex2i(113,143); glVertex2i(30,143);
    glEnd();

    glFlush();
    glutSwapBuffers();

}

void keyboard(unsigned char key, int x, int y){
    key = toupper(key);
    switch (key) {
        case 27:
            exit(0);
        break;
        case 'B':
            if(flag==-9999){
            r1 = (float)rand()/(float)RAND_MAX;
            g1 = (float)rand()/(float)RAND_MAX;
            b1 = (float)rand()/(float)RAND_MAX;
            glutPostRedisplay();
            }
        break;
        case 'F':
            if(flag==-9999){
            glutDisplayFunc(display2);
            }
        break;
    }
}

void mouse(int button, int state, int x, int y){
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN){
                if(cont <= 3){
                    q[cont].v[cont2].x = x;
                    q[cont].v[cont2].y = y;
                    cont2++;
                    if(cont2 == 4){
                         cont++;
                         cont2 = 0;
                         glutPostRedisplay();
                    }
                }

                if(113>=x && x>=30 && y>=143 && 226>= y  && flag==4){
                  r1=(GLfloat)rand()/(RAND_MAX+1.0);
                  g1=(GLfloat)rand()/(RAND_MAX+1.0);
                  b1=(GLfloat)rand()/(RAND_MAX+1.0);
                  glutPostRedisplay();
               }
               if(((143<x || x<30) && (y>226 || y<143)) && flag==4){
                  r1=(GLfloat)rand()/(RAND_MAX+1.0);
                  g1=(GLfloat)rand()/(RAND_MAX+1.0);
                  b1=(GLfloat)rand()/(RAND_MAX+1.0);
                  glClearColor(r1, g1, b1, 1.0);
                  glOrtho (0, 360, 0, 360, -1 ,1);
                  glutPostRedisplay();
               }
            }
        break;

    }
}

void personalizado(void){

    glEnable(GL_POLYGON_STIPPLE);

    glColor3f(0.0, 0.0, 1.0);
    glPolygonStipple(tux);
    glBegin(GL_POLYGON);
    glVertex2i(143,113);
    glVertex2i(226,113);
    glVertex2i(226,30);
    glVertex2i(143,30);
    glEnd();

    glFlush();
    glutSwapBuffers();
}
