*This project has been created as part of the 42 curriculum by rpinheir.*

## Description

So_long is a small 2D game built in C using MiniLibX. The player navigates a map, collects items, and reaches the exit. The game reads `.ber` map files, validates them (rectangular, walled, valid path via flood fill), and renders a tile-based view with camera scrolling.

The mandatory part handles basic gameplay with WASD movement and a move counter in the terminal.

The bonus part adds:
- **Enemy patrols**: enemies move horizontally and kill the player on contact
- **Sprite animation**: 4-frame animations for player and enemies
- **On-screen move counter**: displayed directly on the game window

## Instructions

### Compilation

```bash
make        # Build mandatory version
make bonus  # Build bonus version (enemies + animation)
make clean  # Remove object files
make fclean # Full clean (objects + binaries)
make re     # Rebuild from scratch
```

### Execution

**Mandatory:**
```bash
./so_long maps/map.ber
```

**Bonus:**
```bash
./so_long_bonus maps/bonus.ber
```

### Controls

| Key | Action |
|-----|--------|
| W / Up | Move up |
| A / Left | Move left |
| S / Down | Move down |
| D / Right | Move right |
| ESC | Quit |

## Map Format

Maps use `.ber` files with these characters:

| Char | Meaning |
|------|---------|
| 1 | Wall |
| 0 | Empty space |
| P | Player start (exactly 1) |
| E | Exit (exactly 1) |
| C | Collectible (at least 1) |
| X | Enemy (bonus only) |

## Resources

- [MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [pipe(2) - Linux man page](https://man7.org/linux/man-pages/man2/pipe.2.html)
- [dup2(2) - Linux man page](https://man7.org/linux/man-pages/man2/dup2.2.html)

### AI usage

AI tools (Claude Code) were used to assist with debugging enemy collision logic and fixing memory leaks in error paths. All code was reviewed and tested manually.
