#include <glut.h>
 
void changeSize(int w, int h)
{
	// предупредим деление на ноль
	// если окно сильно перетянуто будет
	if(h == 0)
		h = 1;
	float ratio = 1.0* w / h;
 
	// используем матрицу проекции
	glMatrixMode(GL_PROJECTION);
 
        // Reset матрицы
	glLoadIdentity();
 
	// определяем окно просмотра
	glViewport(0, 0, w, h);
 
	// установить корректную перспективу.
	gluPerspective(45,ratio,1,1000);
 
	// вернуться к модели
	glMatrixMode(GL_MODELVIEW);
}
 
void renderScene(void) {
	glBegin(GL_TRIANGLES);
		glVertex3f(-1.5,-1.5,-5.0);
		glVertex3f(0.0,1.5,-5.0);
		glVertex3f(1.5,-1.5,-5.0);
	glEnd();
	glutSwapBuffers();
}
 
int main(int argc, char **argv) 
{
 
	// инициализация
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(400,400);
	glutCreateWindow("Урок 2");
 
        // регистрация
	glutDisplayFunc(renderScene);
 
	// Новая функция изменения размеров окна
	glutReshapeFunc(changeSize);
 
	// основной цикл
	glutMainLoop();
}
