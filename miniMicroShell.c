//Saúl Enrique Labra Cruz A01020725
//Sistemas Operativos
//Karen Azurim García
//28 de agosto 2018

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define inLength 150

int main()
{
	pid_t p;

	char input[inLength];
	char comando[20];
	char argumento[2][100];

	while(strcmp(comando, "salir") != 0)
	{
		fflush(stdin);//limpia buffer de entrada
		memset(argumento[0], 0, sizeof(argumento[0]));//limpia array de argumento
		memset(argumento[1], 0, sizeof(argumento[1]));//limpia array de argumento
		printf("SHELL_SO>$");
		fgets(input, inLength, stdin);//se lee toda la línea
		sscanf(input, "%s %s %s", comando, argumento[0], argumento[1]); //se aplica scanf() desde el string general

		if(strcmp(comando, "listar") == 0)
		{
			p = fork();
			if(p == 0)
			{
				if(strcmp(argumento[0], "\0") == 0)
				{
					execl("/bin/ls", "/bin/ls", (char *)0);
				}else{
					execl("/bin/ls", "/bin/ls", argumento[0], (char *)0);
				}
				exit(0);
			}else{
				wait(NULL);
			}
		}else{
			if(strcmp(comando, "fecha") == 0)
			{
				p = fork();
				if(p == 0)
				{
					if(strcmp(argumento[0], "\0") == 0)
					{
						execl("/bin/date", "/bin/date", (char *)0);
					}else{
						execl("/bin/date", "/bin/date", argumento[0], (char *)0);
					}
					exit(0);
				}else{
					wait(NULL);
				}
			}else{
				if(strcmp(comando, "renombrar") == 0)
				{
					p = fork();
					if(p == 0)
					{
						if(strcmp(argumento[0], "\0") == 0)
						{
							execl("/bin/mv", "/bin/mv", (char *)0);
						}else{
							execl("/bin/mv", "/bin/mv", argumento[0], argumento[1], (char *)0);
						}
						exit(0);
					}else{
						wait(NULL);
					}
				}else{
					if(strcmp(comando, "borrar") == 0)
					{
						p = fork();
						if(p == 0)
						{
							if(strcmp(argumento[0], "\0") == 0)
							{
								execl("/bin/rm", "/bin/rm", (char *)0);
							}else{
								execl("/bin/rm", "/bin/rm", argumento[0], (char *)0);
							}
							exit(0);
						}else{
							wait(NULL);
						}
					}
				}
			}
		}
	}

	return 0;
}
