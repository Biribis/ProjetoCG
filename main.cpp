#include <stdio.h>
#include <glut.h>
#include <math.h>
# define M_PI 3.14159265358979323846

GLfloat angle, fAspect;

//Função auxiliar do Leonardo
float grausParaRadianos(float angulo_graus) {
	return (angulo_graus * 2 * M_PI) / 360.0;
}
void CirculoSimetrico(float raio, float x0, float y0, float z, int definicao) {
	int i;
	float passo = grausParaRadianos(360.0 / definicao);
	float angulo = passo;
	float x = 0.0, y = 0.0;

	glBegin(GL_POLYGON);
	for (i = 0; i < definicao; i++) {
		x = raio * cos(angulo) + x0;
		y = raio * sin(angulo) + y0;
		glVertex3f(x, y, z);
		angulo += passo;
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (i = 0; i < definicao; i++) {
		x = raio * cos(angulo) + x0;
		y = raio * sin(angulo) + y0;
		glVertex3f(-x, y, z);
		angulo += passo;
	}
	glEnd();
}

//Rotação em progresso
/*
void MultiplyWithOutAMP() {
	int aMatrix[3][1] = { {1, 4}, {2, 5}, {3, 6} };
	int bMatrix[2][3] = { {7, 8, 9}, {10, 11, 12} };

	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			// Multiply the row of A by the column of B to get the row, column of product.
			for (int inner = 0; inner < 2; inner++) {
				product[row][col] += aMatrix[row][inner] * bMatrix[inner][col];
			}
			std::cout << product[row][col] << "  ";
		}
		std::cout << "\n";
	}
}
*/

void Asa() {

	glBegin(GL_POLYGON);
	glColor3ub(250, 219, 117);
	CirculoSimetrico(5, -2, 5.5, -1, 32);
	glEnd();

	//recorte de seções
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	CirculoSimetrico(4.5, -3, 8.5, -.5, 60);
	glEnd();
	glBegin(GL_POLYGON);
	CirculoSimetrico(2, 0, 4.5, -.5, 60);
	glEnd();
	glBegin(GL_POLYGON);
	CirculoSimetrico(2, 0, 0, -.5, 60);
	glEnd();
}
void Haste() {

	//Encaixe Crystal
	glBegin(GL_POLYGON);
	//Duplas de Vertex e coloração para formar gradiente
	glColor3ub(33, 18, 1);
	glVertex2f(-1, 4.2);
	glColor3ub(66, 36, 3);
	glVertex2f(-1.2, 3.8);
	glColor3ub(105, 57, 3);
	glVertex2f(1.2, 3.8);
	glColor3ub(94, 51, 3);
	glVertex2f(1, 4.2);
	glEnd();

	glColor3ub(105, 57, 3);
	//Trapezio Superior
	glBegin(GL_POLYGON);
	glColor3ub(66, 36, 3);
	glVertex2f(-1.2, 3.8);
	glColor3ub(66, 36, 3);
	glVertex2f(-1, 0.5);
	glColor3ub(105, 57, 3);
	glVertex2f(1, 0.5);
	glColor3ub(105, 57, 3);
	glVertex2f(1.2, 3.8);
	glEnd();

	//Trapezio Inferior
	glBegin(GL_POLYGON);
	glColor3ub(105, 57, 3);
	glVertex2f(1.5, -2);
	glColor3ub(105, 57, 3);
	glVertex2f(1, 0.5);
	glColor3ub(66, 36, 3);
	glVertex2f(-1, 0.5);
	glColor3ub(94, 51, 3);
	glVertex2f(-1.5, -2);
	glEnd();


}

void Crystal() {

	//superior

	glColor3ub(201, 60, 166);

	glBegin(GL_POLYGON);//trapezio meio esquerdo
	glVertex2f(0, 6);
	glVertex2f(-2, 6);
	glVertex2f(-0.7, 8.5);
	glVertex2f(0, 8);
	glEnd();


	glColor3ub(227, 66, 187);

	glBegin(GL_POLYGON);//trapezio meio direito
	glVertex2f(0, 6);
	glVertex2f(2, 6);
	glVertex2f(1.1, 7.7);
	glVertex2f(0, 8);
	glEnd();


	glColor3ub(168, 50, 139);

	glBegin(GL_POLYGON);//trapezio exterior esquerdo
	glVertex2f(-2, 6);
	glVertex2f(-3, 6);
	glVertex2f(-0.8, 8.8);
	glVertex2f(-0.7, 8.5);
	glEnd();


	glColor3ub(242, 75, 201);

	glBegin(GL_POLYGON);//trapezio exterior direito
	glVertex2f(2, 6);
	glVertex2f(3, 6);
	glVertex2f(1.4, 8);
	glVertex2f(1.1, 7.7);
	glEnd();

	//inferior

	glColor3ub(168, 50, 139);

	glBegin(GL_POLYGON);//trapezio meio esquerdo
	glVertex2f(0, 6);
	glVertex2f(-2, 6);
	glVertex2f(-0.7, 4.2);
	glVertex2f(0, 4.2);
	glEnd();


	glColor3ub(201, 60, 166);

	glBegin(GL_POLYGON);//trapezio meio direito
	glVertex2f(0, 6);
	glVertex2f(2, 6);
	glVertex2f(0.7, 4.2);
	glVertex2f(0, 4.2);
	glEnd();


	glColor3ub(140, 28, 113);

	glBegin(GL_POLYGON);//trapezio exterior esquerdo
	glVertex2f(-2, 6);
	glVertex2f(-3, 6);
	glVertex2f(-1, 4.2);
	glVertex2f(0, 4.2);
	glEnd();


	glColor3ub(227, 66, 187);

	glBegin(GL_POLYGON);//trapezio exterior direito
	glVertex2f(2, 6);
	glVertex2f(3, 6);
	glVertex2f(1, 4.2);
	glVertex2f(0, 4.2);
	glEnd();

	//topo

	glColor3ub(227, 66, 187);

	glBegin(GL_POLYGON);
	glVertex2f(-0.8, 8.8);
	glVertex2f(-0.7, 8.5);
	glVertex2f(0, 8);
	glVertex2f(1.1, 7.7);
	glVertex2f(1.4, 8);
	glVertex2f(0.7, 8.5);
	glVertex2f(0, 8.8);

	glEnd();
}

float anguloR = 0;
// Função callback chamada para fazer o desenho
void Desenha(void)
{
	// Limpa a janela e o depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Rotaciona com base no angulo definido na função timer que varia conforme passam os frames
	glRotatef(60, 1.0, 1.0, 14.0);
	
	// Desenha as Asas
	Asa();
	// Desenha a Haste
	Haste();
	// Desenha o Crystal
	Crystal();

	glutSwapBuffers();
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

// Função callback chamada pela GLUT a cada intervalo de tempo
// (a window não está sendo redimensionada ou movida)
void Timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(33, Timer, 1);
	anguloR += 0.001;
	if (anguloR > 360.0) {
		anguloR -= 360.0;
	}
}
// Programa Principal
int main(void)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	glutTimerFunc(33, Timer, 1);
	Inicializa();
	glutMainLoop();
}
