*This project has been created as part of the 42 curriculum by rpinheir.*

## Description

So_long is a small 2D game built in C using the MiniLibX graphical library. The player must collect all collectibles on the map and then reach the exit. The game reads `.ber` map files, validates them, and renders a tile-based 2D view with camera scrolling for large maps.

The map is validated for: rectangular shape, wall enclosure, valid characters (0, 1, C, E, P), exactly 1 player, exactly 1 exit, at least 1 collectible, and a valid path using flood fill.

## Instructions

### Compilation

```bash
make        # Build so_long
make clean  # Remove object files
make fclean # Full clean (objects + binary)
make re     # Rebuild from scratch
```

### Execution

```bash
./so_long maps/map.ber
```

### Controls

| Key | Action |
|-----|--------|
| W / Up | Move up |
| A / Left | Move left |
| S / Down | Move down |
| D / Right | Move right |
| ESC | Quit |

The current number of movements is displayed in the shell at every move.

## Resources

- [MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [42 Docs - so_long](https://harm-smits.github.io/42docs/projects/so_long)
- [X11 events reference](https://tronche.com/gui/x/xlib/events/)

### AI usage

AI tools (Claude Code) were used to assist with the following tasks:
- **Debugging memory leaks**: identifying missing `free()` calls in error paths during map parsing and cleanup


All code was written, understood, and tested manually. AI was used as a support tool for review and debugging, not for code generation.
