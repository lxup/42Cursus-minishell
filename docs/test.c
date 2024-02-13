verifie si la string a un sens
	elle a pas de sens si
		apres une redirection ya rien
		si ca commence ou fini par un pipe
		deux redirections se suivent
		si ya un pipe qui se suit
	
	il fait process par process
	"ls < A > b | < Makefile > c > d | >> a"
		redirige les pipes
		ouvrir les fichiers
		il guette la commande
		execute
// #include <fcntl.h> 
// #include <errno.h>
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int main()
// {
// 	// int fd = open("moha", O_RDONLY);
// 	char *str = malloc(1000000000);
// 	for (int i = 0; i < 134; i++)
// 	{
// 		printf("{%i}%s\n", i, strerror(i));
// 	}
// 	free(str);
// 	// printf("%d\n", fd);
// 	// printf("[%i] {%s}\n", errno, strerror(errno));
// 	// perror("moha");
// }
>> a
< Makefile > c > d

{ls}{<}{A}{-R}{>}{b}

while (tab[i])
{
	if (isaredirection(tab[i]))
	{
		type[f] = isaredirection(tab[i]);
		filename[f++] = tab[++i];
	}
	else
		arg[c++] = tab[i];
	i++;
}
cmd = arg[0];

{<}{Makefile}{>}{c}{>}{d}

{>>}{a}

