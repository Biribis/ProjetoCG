#include <glut.h>
#include <math.h>
# define M_PI 3.14159265358979323846


GLfloat angle, fAspect;

void Crystal() {

	glColor3ub(185, 99, 235);

	glBegin(GL_POLYGON);//trapezio meio esquerdo
	glVertex2f(0, 6);
	glVertex2f(-2, 6);
	glVertex2f(-0.7, 8.5);
	glVertex2f(0, 8);
	glEnd();


	glColor3ub(185, 99, 0);

	glBegin(GL_POLYGON);//trapezio meio direito
	glVertex2f(0, 6);
	glVertex2f(2, 6);
	glVertex2f(1.1, 7.7);
	glVertex2f(0, 8);
	glEnd();


	glColor3ub(185, 0, 235);

	glBegin(GL_POLYGON);//trapezio exterior esquerdo
	glVertex2f(-2, 6);
	glVertex2f(-3, 6);
	glVertex2f(-0.8, 8.8);
	glVertex2f(-0.7, 8.5);
	glEnd();


	glColor3ub(0, 99, 235);

	glBegin(GL_POLYGON);//trapezio exterior direito
	glVertex2f(2, 6);
	glVertex2f(3, 6);
	glVertex2f(1.4, 8);
	glVertex2f(1.1, 7.7);
	glEnd();
}

// Função callback chamada para fazer o desenho
void Desenha(void)
{
	// Limpa a janela e o depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Desenha o Crystal com a cor corrente (solid)
	Crystal();

	glutSwapBuffers();
}

void Gema(void) {

}

// Inicializa parâmetros de rendering
void Inicializa(void)
{
	GLfloat luzAmbiente[4] = { 0.2,0.2,0.2,1.0 };
	GLfloat luzDifusa[4] = { 0.7,0.1,0.7,1.0 };	   // "cor" 
	GLfloat luzEspecular[4] = { 1.0, 0.5, 1.0, 1.0 };// "brilho" 
	GLfloat posicaoLuz[4] = { 100.0, 50.0, 50.0, 1.0 };

	// Capacidade de brilho do material
	GLfloat especularidade[4] = { 1.0,1.0,1.0,1.0 };
	GLint especMaterial = 60;

	// Especifica que a cor de fundo da janela será preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a refletância do material 
	glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT, GL_SHININESS, especMaterial);

	// Ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

	angle = 45;
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva
	gluPerspective(angle, fAspect, 0.4, 500);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posição do observador e do alvo
	gluLookAt(0, 80, 200, 0, 0, 0, 0, 1, 0);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if (h == 0) h = 1;

	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);

	// Calcula a correção de aspecto
	fAspect = (GLfloat)w / (GLfloat)h;

	EspecificaParametrosVisualizacao();
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			if (angle >= 10) angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			if (angle <= 130) angle += 5;
		}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

// Programa Principal
int main(void)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 350);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	Inicializa();
	glutMainLoop();
}
