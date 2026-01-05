#include "so_long.h"

static int	can_move(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map.width || y >= game->map.height)
		return (0);
	if (game->map.grid[y][x] == '1')
		return (0);
	if (game->map.grid[y][x] == 'E' && game->map.collected < game->map.collectibles)
		return (0);
	return (1);
}

static void	move_player(t_game *game, int dx, int dy, int dir)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x + dx;
	new_y = game->player.y + dy;
	game->player.dir = dir;
	if (!can_move(game, new_x, new_y))
		return ;
	game->player.x = new_x;
	game->player.y = new_y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	game->player.frame = (game->player.frame + 1) % 4;
	if (game->map.grid[new_y][new_x] == 'C')
	{
		game->map.grid[new_y][new_x] = '0';
		game->map.collected++;
	}
	if (game->map.grid[new_y][new_x] == 'E'
		&& game->map.collected == game->map.collectibles)
	{
		ft_printf("You win in %d moves!\n", game->moves);
		game->win_state = 1;
		close_game(game);
	}
	render(game);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, 0, -1, 2);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, 0, 1, 0);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, -1, 0, 3);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, 1, 0, 1);
	return (0);
}
