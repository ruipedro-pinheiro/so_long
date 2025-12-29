<p align="center">
  <img src="assets/banner.png" alt="so_long banner" width="800"/>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/42-project-000000?style=for-the-badge&logo=42&logoColor=white" alt="42 Project"/>
  <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C"/>
  <img src="https://img.shields.io/badge/Graphics-MiniLibX-purple?style=for-the-badge" alt="MiniLibX"/>
  <img src="https://img.shields.io/badge/Style-Stardew%20Valley-7CB342?style=for-the-badge" alt="Stardew Valley"/>
</p>

<p align="center">
  <i>A Stardew Valley inspired 2D game built with MiniLibX</i>
</p>

---

## About

**so_long** is a simple 2D game where the player must collect all items and reach the exit using the shortest path possible. This implementation features pixel art graphics inspired by Stardew Valley.

## Features

| Mandatory | Bonus | Status |
|-----------|-------|--------|
| Map parsing & validation | Enemy patrols | |
| Player movement (WASD) | Sprite animations | |
| Collectibles system | On-screen move counter | |
| Win condition | | |
| Clean exit (ESC/window close) | | |

## Controls

| Key | Action |
|-----|--------|
| `W` | Move up |
| `A` | Move left |
| `S` | Move down |
| `D` | Move right |
| `ESC` | Exit game |

## Map Format

Maps use the `.ber` extension with the following characters:

```
1 - Wall
0 - Empty space
C - Collectible
E - Exit
P - Player start position
```

Example:
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

## Installation

```bash
# Clone the repository
git clone <repo-url> so_long
cd so_long

# Compile
make

# Run with a map
./so_long maps/level.ber
```

## Requirements

- MiniLibX
- libft
- GCC with `-Wall -Wextra -Werror`

## Author

**rpinheir** - 42 Lausanne

---

<p align="center">
  <i>"And thanks for all the fish!"</i>
</p>
