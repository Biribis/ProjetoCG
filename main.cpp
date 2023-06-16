#include<windows.h>
#include <glut.h>
#include <math.h>
# define M_PI 3.14159265358979323846

GLfloat angle, fAspect;

bool rotateD = false;
bool even = true;
int anglePeca = 0; // angulo que a peca forma com o eixo z
int i = 0;

//Função auxiliar do Leonardo
float grausParaRadianos(float angulo_graus) {
	return (angulo_graus * 2 * M_PI) / 360.0;
}

//Funcao cria circulos simetricos no eixo y
void CirculoSimetrico(float raio, float x0, float y0, float z, int definicao, float grad) {
	int i;
	float passo = grausParaRadianos(360.0 / definicao);
	float angulo = passo;
	float x = 0.0, y = 0.0;

	glBegin(GL_POLYGON);
	for (i = 0; i < definicao; i++) {
		x = raio * cos(angulo) + x0;
		y = raio * sin(angulo) + y0;
		if (grad) {
			glColor3ub(187 - (50 / y), 187 - (50 / y), 189 - (50 / y));
		}
		glVertex3f(x, y, (z - (angulo / 360)));
		angulo += passo;
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (i = 0; i < definicao; i++) {
		x = raio * cos(angulo) + x0;
		y = raio * sin(angulo) + y0;
		if (grad) {
			glColor3ub(187 - (50 / y), 187 - (50 / y), 189 - (50 / y));
		}
		glVertex3f(-x, y, (z - (angulo / 360)));
		angulo += passo;
	}
	glEnd();
}

//Cria as asas da ward
void Asa() {

	//Circulo maior
	glBegin(GL_POLYGON);
	glColor3ub(187, 187, 189);
	CirculoSimetrico(5, -2, 5.5, -1, 100, true);
	glEnd();

	//recorte de seções
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	CirculoSimetrico(4.5, -3, 8.5, -.5, 100, false);
	glEnd();
	glBegin(GL_POLYGON);
	CirculoSimetrico(2, 0, 4.5, -.5, 100, false);
	glEnd();
	glBegin(GL_POLYGON);
	CirculoSimetrico(2, 0, 0, -.5, 100, false);
	glEnd();
}

//Cria o cabo de madeira da ward
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

//Cria o crystal da ward
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


// Função callback chamada para fazer o desenho
void Desenha(void)
{
	// Limpa a janela e o depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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
	GLfloat luzDifusa[4] = { 1.0,1.0,1.0,1.0 };	   // "cor" 
	GLfloat luzEspecular[4] = { 1.0, 1.0, 1.0, 1.0 };// "brilho" 
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

	angle = 5;
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
	gluLookAt(0, 80, 200, 0, 3, 0, 0, 1, 0);
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
			if (angle >= 2) angle -= 1;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			if (angle <= 6) angle += 1;
		}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

//Roda o objeto em idle
void Rotate() {
	glRotatef(5, 0, 0, 1);
	glutPostRedisplay();
	i += 5;
	rotateD = false;
}

//Para a rotação
void Para() {
	glutPostRedisplay();
}

// Função callback chamada para gerenciar eventos de teclado
void GerenciaTeclado(unsigned char key, int x, int y)
{
	switch (key) {
	case 'r':// gira
	case 'R':
		rotateD =  true;
		glutIdleFunc(rotateD ? Rotate : NULL);
		break;
	case 'p'://para de girar
		glutIdleFunc(rotateD ? Para : NULL);
		break;
	case 'S':
	case 's':// decresce o eixo y em 1 unidade
		glTranslatef(0, -1, 0);
		glutPostRedisplay();
		break;
	case 'w':// acresce o eixo y de 1 unidade
		glTranslatef(0, 1, 0);
		glutPostRedisplay();
		break;
	case 'a':// decresce o eixo x em 1 unidade
		glTranslatef(-1, 0, 0);
		glutPostRedisplay();
		break;
	case 'd':// acresce o eixo x de 1 unidade
		glTranslatef(1, 0, 0);
		glutPostRedisplay();
		break;
	case 'i'://gira no eixo y
		if (anglePeca <= 90) {
			glRotatef(5, 0, 1, 0);
			glutPostRedisplay();
			anglePeca += 5;
		}
		if (anglePeca >= 90) {
			if (even) {
				glRotatef(-180, 0, 1, 0);
				glutPostRedisplay();
				anglePeca = 0;
				even = false;
			}
			else {
				anglePeca = 0;
				even = true;
				Sleep(1000);
			}
		}
	}
}

// Programa Principal
int main(void)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1920, 1080);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutKeyboardFunc(GerenciaTeclado);
	glutMouseFunc(GerenciaMouse);
	Inicializa();
	glutMainLoop();
}
