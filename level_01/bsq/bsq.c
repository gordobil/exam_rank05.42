
typedef struct	s_map{
	int		_rows;
	int		_cols;
	char	**_map;
	char	_empC;
	char	_obsC;
	char	_fullC;
}				t_map;

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void	freeMap(int r, t_map *m){
	if (!m || !m->_map || r < 0)
		return ;
	
	for (; r >= 0; --r)
		free(m->_map[r]);
	free(m->_map);
}

bool	obstacle(t_map *m, int x, int y, int s){
	for (int i = x; i < (x + s); ++i){
		for (int j = y; j < (y + s); ++j){
			if (m->_map[i][j] == m->_obsC)
				return (true);
		}
	}
	return (false);
}

void	solveMap(t_map *m){
	int	bS = 0, bX = 0, bY = 0;

	for (int x = 0; x < m->_rows; ++x){
		for (int y = 0; y < m->_cols; ++y){
			int	s = 1;
			for (;x + s <= m->_rows && y + s <= m->_cols; ++s){
				if (obstacle(m, x, y, s))
					break ;
				if (s > bS){
					bS = s;
					bX = x;
					bY = y;
				}
			}
		}
	}

	if (bS > 0){
		for (int x = 0; x < bS; ++x){
			for (int y = 0; y < bS; ++y)
				m->_map[bX + x][bY + y] = m->_fullC;
		}
	}

	fputc('\n', stdout);
	for (int i = 0; i < m->_rows; ++i){
		fputs(m->_map[i], stdout);
		fputc('\n', stdout);
	}
	fputc('\n', stdout);
}

int		getMap(FILE *fd, t_map *m){
	m->_map = (char **)calloc(m->_rows + 1, sizeof(char *));
	if (!m->_map)
		return (-1);
	m->_map[m->_rows] = NULL;

	char	*line = NULL;
	size_t	n = 0;
	int		len = 0;

	for (int r = 0; r < m->_rows; ++r){
		len = getline(&line, &n, fd);
		if (len <= 0 || !line || line[len - 1] != '\n')
			return (freeMap(r - 1, m), free(line), -1);
		
		line[len - 1] = '\0';
		len--;
		if (len <= 0)
			return (freeMap(r - 1, m), free(line), -1);

		if (r == 0)
			m->_cols = len;
		else if (len != m->_cols)
			return (freeMap(r - 1, m), free(line), -1);
		
		for (int i = 0; i < m->_cols; ++i){
			if (line[i] != m->_empC && line[i] != m->_obsC)
				return (freeMap(r, m), free(line), -1);
		}

		m->_map[r] = (char *)malloc(m->_cols + 1);
		if (!m->_map[r])
			return (freeMap(r, m), free(line), -1);
		for (int i = 0; i <= m->_cols; ++i)
			m->_map[r][i] = line[i];
	}
	return (free(line), 0);
}

int		checkMap(FILE *fd, t_map *m){
	int		rows = 0;
	char	e = 0, o = 0, f = 0;
	
	int		total = fscanf(fd, " %d %c %c %c \n", &rows, &e, &o, &f);
	if (total != 4 || rows <= 0 || e == o || e == f || o == f)
		return (-1);
	
	m->_rows = rows;
	m->_empC = e;
	m->_obsC = o;
	m->_fullC = f;
	m->_cols = 0;
	m->_map = NULL;

	if (getMap(fd, m) != 0)
		return (-1);
	
	return (0);
}

int		bsq(FILE *fd){
	t_map	m;

	if (checkMap(fd, &m) != 0)
		return (fputs("\nInvalid map.\n", stderr), -1);
	
	solveMap(&m);
	freeMap(m._rows, &m);

	return (0);
}

int		main(int argc, char **argv){
	if (argc <= 1)
		return (bsq(stdin));

	for (int i = 1; i < argc; ++i){
		FILE	*fd = fopen(argv[i], "r");
		if (!fd)
			return (fputs("\nError processing map.\n", stderr), -1);
		bsq(fd);
		fclose(fd);
	}

	return (0);
}
