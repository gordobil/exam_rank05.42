
#include "bsq.h"

int	checkMap(FILE *fd, t_map *m){
	
}

int	bsq(FILE *fd){
	t_map	m;

	if (checkMap(fd, &m) != 0)
		return (fputs("\nInvalid map.\n", stderr), -1);
}

int	main(int argc, char **argv){
	if (argc <= 1)
		return (bsq(stdin));
	
	for (int i = 1; i < argc; ++i){
		FILE	*fd = fopen(argv[i], "r");
		if (!fd)
			return (fputs("\n Error processing map.\n", stderr), -1);
		bsq(fd);
		fclose(fd);
	}

	return (0);
}