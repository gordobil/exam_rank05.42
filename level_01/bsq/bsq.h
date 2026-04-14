
#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_map {
	size_t	_rows;
	size_t	_cols;
	char	**_map;
	char	_empC;
	char	_obsC;
	char	_fullC;
} t_map;


#endif