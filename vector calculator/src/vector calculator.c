/*
 ============================================================================
 Name        : calculator.c
 Author      : Добрыдень Яна
 License     : GNU GPL
 Description : Программа калькулятор поддерживает работу с вещественными числами,
 обработку ошибок в арифметических выражениях.
 Поддерживаемые операции - сложение, вычитание, умножение, деление, факториал, возведение в степень
 и работа с векторами. При работе с векторами возможно сложение, вычитание и их скалярное произведение.
 (+ - * / ! ^ v).
 После выполнения одной операции программа выводит запрос на повторение работы, при положительном
 ответе она запускается сначала.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Присваиваем переменной r временное значение, для работы цикла while

int main(int argc, char *argv[])
{
	char r;
	do
	{
		//*A и *B - первый и второй вектор
		double a,b, d, f, *A, *B;
		char c;
		int size;
		float *res;
		//Выводим подсказку
		printf ("Введите операцию (+ - * / ! ^ v):");
		//Вводим операцию
		scanf ("\n%c", &c);
		//Создаем блок функций, которые будут выполняться в зависимости от введенной операции
		switch (c)
		{
			//Блок сложения
			case '+':
				printf ("Введите первое число:");
				scanf (" %lg", &a);
				printf ("Введите второе число:");
				scanf (" %lg", &b);
				printf ("%lg", a+b);
				break;
			//Блок вычитания
			case '-':
				printf ("Введите первое число:");
				scanf (" %lg", &a);
				printf ("Введите второе число:");
				scanf (" %lg", &b);
				printf ("%lg", a-b);
 		    	break;
 		    //Блок умножения
			case '*':
				printf ("Введите первое число:");
				scanf (" %lg", &a);
				printf ("Введите второе число:");
				scanf (" %lg", &b);
				printf ("%lg", a*b);
				break;
			//Блок деления
			case '/':
				printf ("Введите первое число:");
				scanf ("%lg", &a);
				printf ("Введите второе число:");
				scanf ("%lg", &b);
				if (b==0) printf ("Ошибка");
				else printf ("%lg", a/b);
				break;
			//Блок факториала
			case '!':
				f=1;
				scanf ("%lf", &a);
				if (a>0)
				{
			    	for (int i=1; i<=a; i++)
			    	{
			        	f=f*i;
			    	}
			    	printf("%.0lf\n", f);
				}
				else if (a<0)
				{
			    	printf ("Ошибка");
				}
				else printf ("1");
				break;
			//Блок возведения в степень реализован с помощью библиотеки <math.h>
			case '^':
				printf ("Введите число:");
				scanf ("%lf", &a);
				printf ("Введите степень:");
				scanf ("%lf",&b);
				d = pow (a, b);
				printf( " %.1f", d);
				break;
			//Блок работы с векторами
			case 'v':
				printf ("Введите размер векторов: ");
				scanf ("%i", &size);
				A = malloc(size*sizeof(int));
				B = malloc(size*sizeof(int));
				res = malloc(size*sizeof(int));
				printf ("Введите координаты первого вектора: ");
				for(int i=0;i<size;i++) scanf("%lf",&A[i]);
				printf ("Введите координаты второго вектора: ");
				for(int i=0;i<size;i++) scanf("%lf",&B[i]);
				printf ("Введите операцию (+ - *): ");
				scanf(" %c",&c);
				if (c == '+')
				{
					 printf("Результат сложения векторов: ");
					 for(int i=0;i<size;i++) printf("%lf ",A[i]+B[i]);
					 printf("\n");
				}
				else if (c == '-')
				{
					printf("Результат вычитания векторов: ");
					for(int i=0;i<size;i++) printf("%lf ",A[i]-B[i]);
					printf("\n");
				}
				else if (c == '*')
				{
					printf("Результат скалярного произведения векторов: ");
					for(int i=0;i<size;i++) printf("%lf ",A[i]*B[i]);
					printf("\n");
				}
				else printf("Такой операции нет, попробуйте снова");
				free(A);
				free(B);
				free(res);
				break;
			default:
				printf ("Ошибка");
		}
		printf ("\nЧтобы продолжить программу нажмите 1\nДля выхода нажмите любой другой символ\n");
		scanf (" %c", &r);
	}
	while (r == '1');
	return 0;
}
