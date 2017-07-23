/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:46:33 by mpotapov          #+#    #+#             */
/*   Updated: 2017/05/18 11:47:11 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"

# define BUFF_SIZE 1
# define BLUE "\033[22;34m"
# define YELLOW "\033[01;33m"
# define RED "\033[22;31m"
# define GREY "\033[22;37m"
# define NO_COLOR "\033[0m"

typedef struct		s_go
{
	int				ant_ind;
	int				room_ind;
	struct s_go		*next;
}					t_go;

typedef struct		s_node
{
	struct s_node	*next;
	int				data;
	int				ind_to_go;
	int				prev_ind;
	char			*name;
}					t_node;

typedef struct		s_lst
{
	struct s_node	*head;
	int				number_ways;
}					t_lst;

typedef struct		s_str
{
	int				ant;
	int				num_ants;
	int				ants_in_end;
	char			*room_name;
	char			*room_name_start;
	char			*room_name_end;
	int				is_links;
	int				is_start;
	int				is_end;
	char			**rooms;
	int				**matrix;
	int				**matrix1;
	int				is_matrix;
	char			*name_link1;
	char			*name_link2;
	int				count_rooms;
	int				*cords;
	long int		x_cord;
	long int		y_cord;
	int				num_of_ways;
	int				ind_end;
	int				ind_st;
	int				*queue;
	int				*stack;
	int				*path;
	int				**ways;
	int				num_way;
	t_lst			*array;
	int				s;
	int				s1;
	int				q;
	char			*line_print;
	int				end_read;
	int				print_ways;
	int				num_print_ways;
}					t_str;

int					get_next_line(int fd, char **line);
void				alg(t_str *strct);
void				run_ants(t_str *strct);
void				print_ants(t_str *strct);
char				*check_room(char *s, t_str *strct, int fd);
char				*comment_comand(char *s, t_str *strct, int fd);
void				check_link(char *line, t_str *strct);
void				to_big_first_room(t_str *strct);
int					bfs(t_str *strct);
void				make_mass_to_bfs(t_str *strct);
void				norme_mtx(t_str *strct);
void				find_way(t_str *strct);
void				find_num_of_ways(t_str *strct);
t_go				*add_to_go(int ant, int room, t_go *go);
t_go				*go_for_one_step(t_str *strct, t_go *go);
void				write_line(char *line, t_str *strct);
void				ft_exit(t_str *strct);
void				to_big(t_str *strct);
void				er(void);
void				input(void);

#endif
