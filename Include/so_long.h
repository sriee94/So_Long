/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:38:21 by sariee            #+#    #+#             */
/*   Updated: 2026/01/02 18:13:29 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../Libsriee/Include/libsriee.h"
# include <stdlib.h>
# include <fcntl.h>

# define TILE_SIZE 64
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_counts
{
	int	p;
	int	e;
	int	c;
}	t_counts;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		pos_player_x;
	int		pos_player_y;
	int		pos_exit_x;
	int		pos_exit_y;
	int		collectible;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
	int		moves;
	int		collected_c;
	t_map	map;
}	t_game;

// Initialisation + le graphique
void	init_mlx(t_game *game);
void	load_textures(t_game *game);

// Events
int		close_game(t_game *game);
int		handle_keypress(int keycode, void *param);

// Flood Fill
int		check_path(t_game *game);

// Utils
void	ft_error_exit(char *message, t_game *game);
void	ft_init_game(t_game *game);
void	ft_free_map(t_game *game);
void	check_file_extension(char *filename);

// Utils-maps
int		is_valid_char(char c);
void	process_char(char c, t_counts *counts);
int		validate_counts(t_counts *counts, t_game *game);

// Render
void	render_map(t_game *game);
void	display_moves(t_game *game);

// Parsing
void	ft_read_map_file(char *filename, t_game *game);

// Map valide
int		validate_map(t_game *game);

#endif
