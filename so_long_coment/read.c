/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:48:02 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/03/01 11:32:02 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**make_map(char *map, int ck_line)
{
	char	**temp;

	temp = NULL;
	if (ck_line >= 3)// verifco se o meu ck_line é maior ou igual a 3.
		temp = ft_split(map, '\n');// minha variavel temporaria, recebe as substrings da string map, separdas por \n.
	free(map); // limpo a minha variavel map.
	return (temp);// retorno as substrings.
}

char	**read_maps(char **argv)
{
	int		fd;
	int		ck_line;
	char	*gnl_line;
	char	*map;

	fd = open (argv[1], O_RDONLY); // abre o arquivo passado como parametro
	if (fd < 0) //verifica se o arquivo esta vazio.
		return (NULL);
	gnl_line = get_next_line(fd); // a gnl_line recebe a primeira linha do arquivo.
	map = ft_strdup(""); // variavel map recebe uma string vazia.
	ck_line = ft_strlen(gnl_line); // variavel ck_line recebe o tamanho da string gnl_line.
	while (gnl_line)
	{
		map = ft_strjoin(map, gnl_line); // map recebe o retorno da concatenação de map com gnl_line
		free (gnl_line); // libero a memoria alocada
		gnl_line = get_next_line(fd); //gnl_line recebe a proxima linha 
		if ((ck_line < 3 && gnl_line != NULL) || gnl_line == NULL )// Verifica se a linha lida é menor que 3 caracteres e continua o loop sem armazenar a linha se for o caso.
			continue ;
		ck_line = ft_strlen(gnl_line);//Armazena o comprimento da última linha lida em ck_line.
	}
	close(fd); // fecha o arquivo
	return (make_map(map, ck_line));// retorna um array de strings.
}
