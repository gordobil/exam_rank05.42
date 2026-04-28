
typedef struct	s_map{
	int		_rows;
	int		_cols;
	char	**_map;
	char	_eC;
	char	_oC;
	char	_fC;
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
			if (m->_map[i][j] == m->_oC)
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
				m->_map[bX + x][bY + y] = m->_fC;
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
		return (fputs("\nError reserving map memory.\n", stderr), -1);
	m->_map[m->_rows] = NULL;

	char	*line = NULL;
	size_t	n = 0;
	int		len = 0;

	for (int r = 0; r < m->_rows; ++r){
		len = getline(&line, &n, fd);
		if (len <= 1 || !line || line[len - 1] != '\n')
			return (fputs("\nError getting line\n", stderr), freeMap(r - 1, m), free(line), -1);
		
		line[len - 1] = '\0';
		len--;

		if (r == 0)
			m->_cols = len;
		else if (r > 0 && len != m->_cols)
			return (fputs("\nInvalid line length.\n", stderr), freeMap(r - 1, m), free(line), -1);
		
		for (int i = 0; i < m->_cols; ++i){
			if (line[i] != m->_eC && line[i] != m->_oC)
				return (fputs("\nInvalid character.\n", stderr), freeMap(r, m), free(line), -1);
		}

		m->_map[r] = (char *)malloc(m->_cols + 1);
		if (!m->_map[r])
			return (fputs("\nError reserving line memory.\n", stderr), freeMap(r, m), free(line), -1);
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
		return (fputs("\nInvalid header.\n", stderr), -1);
	
	m->_rows = rows;
	m->_eC = e;
	m->_oC = o;
	m->_fC = f;
	m->_cols = 0;
	m->_map = NULL;

	if (getMap(fd, m) != 0)
		return (-1);
	
	return (0);
}

int		bsq(FILE *fd){
	t_map	m;

	if (checkMap(fd, &m) != 0)
		return (-1);
	
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
