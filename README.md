
# Bonus (Linke
		- ✅ Render the game with textures
		- ✅ Handle player movement with arrow keys and WASD
		- ✅ Implement collision detection
		- ✅ Validate accessible paths with flood fill algorithm
		- ✅ Display move counter on screen (bonus)
		- ✅ Manage memory properly (no leaks)

### 🎮 Game Rules

		1. **Objective:** Collect all collectibles (C) then reach the exit (E)
		2. **Movement:** Use arrow keys or WASD
		3. **Walls:** Block player movement (1)
		4. **Exit:** Only opens when all collectibles are gathered
		5. **Counter:** Shows number of moves on screen

		---

## 🚀 Installation and Usage

### Prerequisites
- C compiler (cc)
	- Make
	- MiniLibX library
	- X11 (Linux) or XQuartz (macOS)
	- Unix-based system

### Clone the repository
	```bash
	git clone https://github.com/you# 🎮 So_long

> *A 2D game where you collect items and escape through the exit*

**A complete 2D game implementation** featuring map parsing, pathfinding validation (flood fill), texture rendering with MiniLibX, collision detection, and move counting.

Built and maintained by **sriee**.

---

## 🌐 Language / Langue

- [🇬🇧 English](#english)
- [🇫🇷 Français](#français)

---

<a name="english"></a>
# 🇬🇧 English

## 📖 Overview

So_long is a small 2D game project where the player must **collect all items (C)** and **reach the exit (E)** while navigating through a map filled with walls. The project focuses on window management, event handling, and basic gameplay mechanics using the **MiniLibX graphics library**.

### 🎯 Goals
- ✅ Parse and validate `rusername/so_long.git
cd so_long
```

### Compilation

```bash
# Compile so_long
make

# Clean object files
make clean

# Full cleanup
make fclean

# Recompile everything
make re
```

### Running the game

```bash
# Launch with a map file
./so_long maps/valide/map04.ber

# On macOS with Docker/XQuartz
./start-so-long.sh
docker exec -it dev-ubuntu-shared zsh
export DISPLAY=host.docker.internal:0
./so_long maps/valide/map04.ber
```

### Controls

| Key | Action |
|-----|--------|
| `W` or `↑` | Move up |
| `S` or `↓` | Move down |
| `A` or `←` | Move left |
| `D` or `→` | Move right |
| `ESC` | Close game |
| `X` button | Close window |

---

## 🗺️ Map Format

### Valid Map Requirements

Maps must be `.ber` files with these rules:

1. **Rectangular** - All lines same length
2. **Surrounded by walls** (1) on all sides
3. **Contains exactly:**
   - 1 player starting position (P)
   - 1 exit (E)
   - At least 1 collectible (C)
   - Floor tiles (0)
   - Wall tiles (1)
4. **Valid path** - All collectibles and exit must be reachable from player position

### Map Characters

| Character | Meaning |
|-----------|---------|
| `0` | Empty space (floor) |
| `1` | Wall |
| `P` | Player starting position |
| `E` | Exit |
| `C` | Collectible |

### Example Valid Map

```
1111111111
1P00000C01
1000111001
100C00E001
1111111111
```

### Example Invalid Maps

```bash
# Missing wall on top
0000000
1P0C0E1
1111111

# Not rectangular
111111
1P0C1
10001
100E1
1111111

# No valid path (player blocked)
11111111
1P000001
11111111
10C000E1
11111111
```

---

## 🧠 Algorithm Explained

### Map Parsing (`parsing_map.c`)

**Process:**
1. Open and read `.ber` file
2. Use `get_next_line()` to read line by line
3. Store each line in dynamic array
4. Calculate map width and height

```c
// Simplified parsing flow
fd = open(filename, O_RDONLY);
while ((line = get_next_line(fd)) != NULL)
{
    map->grid[y] = line;
    y++;
}
```

---

### Map Validation (`validate_map.c`)

**5 Main Validation Steps:**

#### 1. **Rectangular Check**
```c
int first_width = ft_strlen(map->grid[0]);
for (int i = 1; i < map->height; i++)
{
    if (ft_strlen(map->grid[i]) != first_width)
        → Error: Map not rectangular
}
```

#### 2. **Wall Check**
```c
// Check top and bottom rows (all '1')
// Check first and last column of each row (all '1')
```

#### 3. **Element Count Check**
```c
int player_count = 0;
int exit_count = 0;
int collectible_count = 0;

// Count all elements
// Verify: player == 1, exit == 1, collectibles >= 1
```

#### 4. **Invalid Characters Check**
```c
// Each character must be: '0', '1', 'P', 'E', or 'C'
if (c != '0' && c != '1' && c != 'P' && 
    c != 'E' && c != 'C')
    → Error: Invalid character
```

#### 5. **Path Validation (Flood Fill)**

**Most important check** - ensures all collectibles and exit are reachable.

---

### Flood Fill Algorithm (`pathfinding.c`)

**Concept:** Recursive algorithm that "floods" all accessible tiles from player position.

**How it works:**

```c
void flood_fill(char **grid, int x, int y, int width, int height)
{
    // Stop conditions
    if (x < 0 || x >= width || y < 0 || y >= height)
        return;  // Out of bounds
    
    if (grid[y][x] == '1')
        return;  // Wall
    
    if (grid[y][x] == 'V')
        return;  // Already visited
    
    // Mark as visited
    grid[y][x] = 'V';
    
    // Recursively flood all 4 directions
    flood_fill(grid, x + 1, y, width, height);  // Right
    flood_fill(grid, x - 1, y, width, height);  // Left
    flood_fill(grid, x, y + 1, width, height);  // Down
    flood_fill(grid, x, y - 1, width, height);  // Up
}
```

**Complete Process:**

```c
1. Copy the map grid (don't modify original)
2. Run flood_fill() from player position
3. Check if all 'C' and 'E' are now marked 'V'
4. If any 'C' or 'E' remains → Error: Path invalid
5. Free the grid copy
```

**Visual Example:**

**Original map:**
```
11111
1P0C1
10001
100E1
11111
```

**After flood fill from P:**
```
11111
1VVC1  ← 'C' is reachable!
1VVV1
1VVE1  ← 'E' is reachable!
11111
```

**All collectibles and exit reached → Valid path ✅**

**Invalid example:**
```
Original:
11111
1P001
11111
10C0E1
11111

After flood fill:
11111
1VVV1
11111
10C0E1  ← 'C' and 'E' NOT reached!
11111

→ Error: Path invalid ❌
```

---

### Graphics System (MiniLibX)

#### Initialization (`init_game.c`)

```c
// 1. Initialize MLX connection
game->mlx = mlx_init();

// 2. Create window
int win_width = game->map.width * TILE_SIZE;   // Each tile = 64px
int win_height = game->map.height * TILE_SIZE;

game->window = mlx_new_window(game->mlx, win_width, win_height, "so_long");

// 3. Load textures from .xpm files
game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &w, &h);
game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &w, &h);
game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &w, &h);
game->collectible = mlx_xpm_file_to_image(game->mlx, "textures/collectible.xpm", &w, &h);
game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &w, &h);
```

**Why TILE_SIZE?**
- Grid position (0, 1, 2...) → Pixel position (0, 64, 128...)
- Maps grid coordinates to screen coordinates

---

#### Rendering (`render.c`)

**Two-step rendering process:**

**Step 1: Render individual tile**
```c
static void render_tile(t_game *game, int x, int y)
{
    char tile = game->map.grid[y][x];  // Get tile type
    int px = x * TILE_SIZE;            // Convert to pixels
    int py = y * TILE_SIZE;
    
    if (tile == '1')
        mlx_put_image_to_window(game->mlx, game->window, game->wall, px, py);
    else
    {
        // Always draw floor first
        mlx_put_image_to_window(game->mlx, game->window, game->floor, px, py);
        
        // Then overlay element on top
        if (tile == 'P')
            mlx_put_image_to_window(game->mlx, game->window, game->player, px, py);
        else if (tile == 'C')
            mlx_put_image_to_window(game->mlx, game->window, game->collectible, px, py);
        else if (tile == 'E')
            mlx_put_image_to_window(game->mlx, game->window, game->exit, px, py);
    }
}
```

**Why draw floor first?**
- Player, collectibles, and exit are **on top of** the floor
- Without floor, they'd appear on black background

**Step 2: Render entire map**
```c
void render_map(t_game *game)
{
    int y = -1;
    while (++y < game->map.height)
    {
        int x = -1;
        while (++x < game->map.width)
            render_tile(game, x, y);
    }
}
```

**Traversal order:** Row by row (y), then column by column (x)

---

#### Move Counter Display (Bonus)

```c
void display_moves(t_game *game)
{
    char *msg = ft_itoa(game->moves);  // Convert int to string
    
    // Display "Moves:" at (10, 20)
    mlx_string_put(game->mlx, game->window, 10, 20, 0xFF0000, "Moves:");
    
    // Display number at (70, 20)
    mlx_string_put(game->mlx, game->window, 70, 20, 0xFF0000, msg);
    
    free(msg);  // Important: free allocated memory
}
```

**Color format:** `0xRRGGBB` (hexadecimal RGB)
- `0xFF0000` = Red (255, 0, 0)
- `0xFFFFFF` = White (255, 255, 255)

---

### Event Handling (`events.c`)

#### Movement Logic

```c
void move_player(t_game *game, int new_x, int new_y)
{
    char target = game->map.grid[new_y][new_x];
    
    // 1. Wall → Block movement
    if (target == '1')
        return;
    
    // 2. Collectible → Gather it
    if (target == 'C')
    {
        game->collected++;
        game->map.grid[new_y][new_x] = '0';  // Replace with floor
    }
    
    // 3. Exit + all collectibles → Victory!
    if (target == 'E' && game->collected == game->map.collectibles)
    {
        ft_printf("Bien joue! On a wiiin!\n");
        cleanup_and_exit(game);
        return;
    }
    
    // 4. Exit but missing collectibles → Block
    if (target == 'E')
        return;
    
    // 5. Valid move → Update position
    game->map.grid[game->player.y][game->player.x] = '0';  // Old pos = floor
    game->player.x = new_x;
    game->player.y = new_y;
    game->map.grid[new_y][new_x] = 'P';  // New pos = player
    game->moves++;
    
    // 6. Redraw screen
    render_map(game);
    display_moves(game);
}
```

**Victory condition:** `collected == total_collectibles AND player on exit`

---

### Memory Management

**Principle:** Every `malloc()` must have a corresponding `free()`

#### Map Allocation
```c
// In parsing
game->map.grid = ft_calloc(height + 1, sizeof(char *));
for (int i = 0; i < height; i++)
    game->map.grid[i] = get_next_line(fd);
```

#### Map Cleanup
```c
void ft_free_map(t_game *game)
{
    if (!game->map.grid)
        return;
    
    for (int i = 0; i < game->map.height; i++)
    {
        if (game->map.grid[i])
            free(game->map.grid[i]);
    }
    free(game->map.grid);
    game->map.grid = NULL;
}
```

#### Complete Cleanup
```c
void cleanup_and_exit(t_game *game)
{
    // 1. Destroy textures
    if (game->wall)
        mlx_destroy_image(game->mlx, game->wall);
    // ... all other textures
    
    // 2. Destroy window
    if (game->window)
        mlx_destroy_window(game->mlx, game->window);
    
    // 3. Destroy MLX connection
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
    
    // 4. Free map
    ft_free_map(game);
    
    // 5. Exit
    exit(0);
}
```

---

## 📁 Project Structure

```
so_long/
├── Makefile
├── README.md
├── .gitignore
├── so_long.h                    # Main header
├── start-so-long.sh             # Docker/XQuartz setup script
│
├── src/
│   ├── init/
│   │   ├── main.c               # Entry point + argument validation
│   │   └── init_game.c          # MLX + texture initialization
│   │
│   ├── parsing/
│   │   └── parsing_map.c        # Read .ber file with GNL
│   │
│   ├── validation/
│   │   └── validate_map.c       # All map validation checks
│   │
│   ├── pathfinding/
│   │   └── pathfinding.c        # Flood fill algorithm
│   │
│   ├── render/
│   │   └── render.c             # Graphics rendering
│   │
│   ├── events/
│   │   └── events.c             # Keyboard + movement handling
│   │
│   └── utils/
│       ├── utils.c              # General utilities
│       └── utils-maps.c         # Map-specific utilities
│
├── Libft/                       # Custom C library
│   ├── libft.h
│   ├── Makefile
│   └── *.c
│
├── Printf/                      # Custom ft_printf
│   ├── ft_printf.h
│   ├── Makefile
│   └── *.c
│
├── GetNextLine/                 # Line reading function
│   ├── get_next_line.h
│   ├── Makefile
│   └── *.c
│
├── minilibx-linux/              # Graphics library
│   └── (MiniLibX files)
│
├── textures/                    # 64x64 .xpm images
│   ├── wall.xpm
│   ├── floor.xpm
│   ├── player.xpm
│   ├── collectible.xpm
│   └── exit.xpm
│
└── maps/
    ├── valide/
    │   ├── map01.ber
    │   ├── map02.ber
    │   └── ...
    └── invalide/
        ├── no_walls.ber
        ├── no_path.ber
        └── ...
```

---

## ⚠️ Error Handling

The program displays **"Error"** followed by an explicit message for:

- ❌ **No arguments:** `Error\nUsage: ./so_long <map.ber>`
- ❌ **Too many arguments:** `Error\nUsage: ./so_long <map.ber>`
- ❌ **Bad extension:** `Error\nLe fichier n'a pas l'extension .ber.`
- ❌ **File not found:** `Error\nImpossible d'ouvrir le fichier.`
- ❌ **Empty map:** `Error\nLa carte est vide.`
- ❌ **Not rectangular:** `Error\nLa carte n'est pas rectangulaire.`
- ❌ **Missing walls:** `Error\nLa carte n'est pas entouree de murs.`
- ❌ **Invalid elements:** `Error\nElements invalides (P, E, C).`
- ❌ **Invalid path:** `Error\nLe chemin n'est pas valide.`

### Examples

```bash
./so_long                       # Error + Usage
./so_long map.txt               # Error + Bad extension
./so_long nonexistent.ber       # Error + Cannot open
./so_long maps/invalide/no_path.ber  # Error + Invalid path
```

---

## 🧪 Testing

### Basic Tests

```bash
# 1. Compilation test
make
# Should compile without errors

# 2. No relink test
make
# Should display "make: 'so_long' is up to date."

# 3. Norminette check
norminette src/**/*.c *.h
# Should have no errors
```

### Argument Tests

```bash
# No arguments
./so_long
# Expected: Error + Usage

# Too many arguments
./so_long map1.ber map2.ber
# Expected: Error + Usage

# Bad extension
./so_long test.txt
# Expected: Error + Bad extension

# File not found
./so_long nonexistent.ber
# Expected: Error + Cannot open
```

### Invalid Map Tests

```bash
# Empty map
echo "" > empty.ber
./so_long empty.ber
# Expected: Error + Empty map

# Not rectangular
./so_long maps/invalide/not_rectangular.ber
# Expected: Error + Not rectangular

# Missing walls
./so_long maps/invalide/no_walls.ber
# Expected: Error + Not surrounded by walls

# Invalid characters
./so_long maps/invalide/wrong_chars.ber
# Expected: Error + Invalid elements

# No valid path
./so_long maps/invalide/no_path.ber
# Expected: Error + Path invalid
```

### Valid Map Tests

```bash
# Minimal map
./so_long maps/valide/map01.ber
# Expected: Window opens, game playable

# Regular map
./so_long maps/valide/map04.ber
# Expected: All features work (movement, collection, victory)
```

### Memory Tests

```bash
# Test invalid map (should exit cleanly)
valgrind --leak-check=full ./so_long maps/invalide/no_path.ber
# Expected: definitely lost: 0 bytes

# Test valid map (play and press ESC)
valgrind --leak-check=full ./so_long maps/valide/map04.ber
# Expected: All heap blocks were freed
```

### Gameplay Tests

**Manual checklist:**
- [ ] Arrow keys and WASD work
- [ ] Walls block movement
- [ ] Move counter increments
- [ ] Collectibles disappear when gathered
- [ ] Exit blocks until all collectibles gathered
- [ ] Victory message displays
- [ ] ESC key closes window
- [ ] X button closes window
- [ ] No visual glitches

---

## 🎯 Bonus Features

### ✅ Implemented
- **On-screen move counter** - Displays current move count using `mlx_string_put`

### 💡 Possible Extensions (not required)
- Enemy patrols
- Sprite animations
- Multiple levels
- Collectible counter display
- Timer

---

## 🔧 Technical Challenges & Solutions

### Challenge 1: Grid Indexing
**Problem:** Confusion between `grid[x][y]` vs `grid[y][x]`

**Solution:** 
- Maps are stored **row by row**
- Always use `grid[y][x]` where y = row, x = column

---

### Challenge 2: C Structure Syntax
**Problem:** When to use `.` vs `->`

**Solution:**
- `.` for normal structures: `game.player.x`
- `->` for pointers to structures: `game->player.x`
- Mixed: `game->player.x` (pointer to struct, member is normal)

---

### Challenge 3: Multiple Definition Errors
**Problem:** `get_next_line` and `libft` both had `ft_strlen`, `ft_strdup`

**Solution:**
- Removed duplicates from `get_next_line_utils.c`
- Added `#include "../Libft/libft.h"` in `get_next_line.h`
- Kept only `ft_strchr` in GNL (not in libft)

---

### Challenge 4: Makefile Organization
**Problem:** Compiling multiple libraries + MLX

**Solution:**
```makefile
# Compile each library separately
$(LIBFT):
	make -C Libft

$(LIBFTPRINTF):
	make -C Printf

$(LIBGNL):
	make -C GetNextLine

$(LIBMLX):
	make -C minilibx-linux

# Link everything together
$(NAME): $(OBJS) $(LIBFT) $(LIBFTPRINTF) $(LIBGNL) $(LIBMLX)
	$(CC) $(OBJS) $(LIBFT) $(LIBFTPRINTF) $(LIBGNL) $(LIBMLX) \
	-L/usr/lib -lXext -lX11 -lm -o $(NAME)
```

---

## 💡 Why This Implementation is Good

✅ **Clean separation of concerns** - Each file handles one responsibility  
✅ **Robust validation** - Flood fill ensures playable maps  
✅ **Memory safety** - Zero leaks confirmed with Valgrind  
✅ **Error handling** - Explicit messages for every error case  
✅ **Norminette compliant** - Strict adherence to coding standards  
✅ **Professional structure** - Easy to maintain and extend  

**Code quality principles:**
- Functions under 25 lines
- Maximum 4 parameters per function
- Maximum 80 characters per line
- Meaningful variable names
- No global variables

---

## 📚 Key Learnings

### 1. Graphics Programming
- Window management with MiniLibX
- Texture loading from XPM files
- Rendering pipeline (clear → draw → display)
- Event loop and callbacks

### 2. Algorithm Design
- Recursive flood fill for path validation
- Coordinate system conversions (grid ↔ pixels)
- Collision detection

### 3. Memory Management
- Dynamic allocation for unknown map sizes
- Proper cleanup in all exit paths
- Avoiding memory leaks in error cases

### 4. File Parsing
- Reading files with `get_next_line`
- Validating file format
- Handling edge cases (empty files, permissions, etc.)

---

## 👤 Author

**sriee** - [GitHub](https://github.com/sriee94)

*Built with clean code principles and optimization in mind - 2025*

---

## 🔗 Related Projects

- [push_swap](https://github.com/sriee94/push_swap) - Sorting algorithm with two stacks
- [get_next_line](https://github.com/yourusername/get_next_line) - Line reading function
- [ft_printf](https://github.com/yourusername/ft_printf) - Custom printf implementation
- [libft](https://github.com/yourusername/libft) - Custom C library

---

**⭐ If you find this useful, consider giving it a star!**

---
---

<a name="français"></a>
# 🇫🇷 Français

## 📖 Aperçu

So_long est un petit projet de jeu 2D où le joueur doit **collecter tous les objets (C)** et **atteindre la sortie (E)** tout en naviguant dans une carte remplie de murs. Le projet se concentre sur la gestion de fenêtre, la gestion d'événements et les mécaniques de jeu de base en utilisant la **bibliothèque graphique MiniLibX**.

### 🎯 Objectifs
- ✅ Parser et valider les fichiers de carte `.ber`
- ✅ Afficher le jeu avec des textures
- ✅ Gérer les mouvements du joueur avec les flèches et WASD
- ✅ Implémenter la détection de collision
- ✅ Valider les chemins accessibles avec l'algorithme flood fill
- ✅ Afficher le compteur de mouvements à l'écran (bonus)
- ✅ Gérer la mémoire correctement (pas de fuites)

### 🎮 Règles du Jeu

1. **Objectif :** Collecter tous les collectibles (C) puis atteindre la sortie (E)
2. **Mouvement :** Utiliser les flèches ou WASD
3. **Murs :** Bloquent le mouvement du joueur (1)
4. **Sortie :** S'ouvre uniquement quand tous les collectibles sont ramassés
5. **Compteur :** Affiche le nombre de mouvements à l'écran

---

## 🚀 Installation et Utilisation

### Prérequis
- Compilateur C (cc)
- Make
- Bibliothèque MiniLibX
- X11 (Linux) ou XQuartz (macOS)
- Système Unix

### Cloner le dépôt
```bash
git clone https://github.com/votreusername/so_long.git
cd so_long
```

### Compilation

```bash
# Compiler so_long
make

# Nettoyer les fichiers objets
make clean

# Nettoyage complet
make fclean

# Recompiler tout
make re
```

### Lancer le jeu

```bash
# Lancer avec un fichier de carte
./so_long maps/valide/map04.ber

# Sur macOS avec Docker/XQuartz
./start-so-long.sh
docker exec -it dev-ubuntu-shared zsh
export DISPLAY=host.docker.internal:0
./so_long maps/valide/map04.ber
```

### Contrôles

| Touche | Action |
|--------|--------|
| `W` ou `↑` | Aller en haut |
| `S` ou `↓` | Aller en bas |
| `A` ou `←` | Aller à gauche |
| `D` ou `→` | Aller à droite |
| `ESC` | Fermer le jeu |
| Bouton `X` | Fermer la fenêtre |

---

## 🗺️ Format de Carte

### Exigences d'une Carte Valide

Les cartes doivent être des fichiers `.ber` avec ces règles :

1. **Rectangulaire** - Toutes les lignes de même longueur
2. **Entourée de murs** (1) sur tous les côtés
3. **Contient exactement :**
   - 1 position de départ du joueur (P)
   - 1 sortie (E)
   - Au moins 1 collectible (C)
   - Cases de sol (0)
   - Cases de mur (1)
4. **Chemin valide** - Tous les collectibles et la sortie doivent être accessibles depuis la position du joueur

### Caractères de Carte

| Caractère | Signification |
|-----------|---------------|
| `0` | Espace vide (sol) |
| `1` | Mur |
| `P` | Position de départ du joueur |
| `E` | Sortie |
| `C` | Collectible |

### Exemple de Carte Valide

```
1111111111
1P00000C01
1000111001
100C00E001
1111111111
```

### Exemples de Cartes Invalides

```bash
# Mur manquant en haut
0000000
1P0C0E1
1111111

# Pas rectangulaire
111111
1P0C1
10001
100E1
1111111

# Pas de chemin valide (joueur bloqué)
11111111
1P000001
11111111
10C000E1
11111111
```

---

## 🧠 Explication de l'Algorithme

### Parsing de Carte (`parsing_map.c`)

**Processus :**
1. Ouvrir et lire le fichier `.ber`
2. Utiliser `get_next_line()` pour lire ligne par ligne
3. Stocker chaque ligne dans un tableau dynamique
4. Calculer la largeur et hauteur de la carte

```c
// Flux de parsing simplifié
fd = open(filename, O_RDONLY);
while ((line = get_next_line(fd)) != NULL)
{
    map->grid[y] = line;
    y++;
}
```

---

### Validation de Carte (`validate_map.c`)

**5 Étapes Principales de Validation :**

#### 1. **Vérification Rectangulaire**
```c
int first_width = ft_strlen(map->grid[0]);
for (int i = 1; i < map->height; i++)
{
    if (ft_strlen(map->grid[i]) != first_width)
        → Erreur : Carte non rectangulaire
}
```

#### 2. **Vérification des Murs**
```c
// Vérifier lignes du haut et du bas (tous '1')
// Vérifier première et dernière colonne de chaque ligne (tous '1')
```

#### 3. **Vérification du Compte d'Éléments**
```c
int player_count = 0;
int exit_count = 0;
int collectible_count = 0;

// Compter tous les éléments
// Vérifier : player == 1, exit == 1, collectibles >= 1
```

#### 4. **Vérification des Caractères Invalides**
```c
// Chaque caractère doit être : '0', '1', 'P', 'E', ou 'C'
if (c != '0' && c != '1' && c != 'P' && 
    c != 'E' && c != 'C')
    → Erreur : Caractère invalide
```

#### 5. **Validation de Chemin (Flood Fill)**

**Vérification la plus importante** - assure que tous les collectibles et la sortie sont accessibles.

---

### Algorithme Flood Fill (`pathfinding.c`)

**Concept :** Algorithme récursif qui "inonde" toutes les cases accessibles depuis la position du joueur.

**Fonctionnement :**

```c
void flood_fill(char **grid, int x, int y, int width, int height)
{
    // Conditions d'arrêt
    if (x < 0 || x >= width || y < 0 || y >= height)
        return;  // Hors limites
    
    if (grid[y][x] == '1')
        return;  // Mur
    
    if (grid[y][x] == 'V')
        return;  // Déjà visité
    
    // Marquer comme visité
    grid[y][x] = 'V';
    
    // Inonder récursivement les 4 directions
    flood_fill(grid, x + 1, y, width, height);  // Droite
    flood_fill(grid, x - 1, y, width, height);  // Gauche
    flood_fill(grid, x, y + 1, width, height);  // Bas
    flood_fill(grid, x, y - 1, width, height);  // Haut
}
```

**Processus Complet :**

```c
1. Copier la grille de carte (ne pas modifier l'originale)
2. Lancer flood_fill() depuis la position du joueur
3. Vérifier si tous les 'C' et 'E' sont maintenant marqués 'V'
4. Si un 'C' ou 'E' reste → Erreur : Chemin invalide
5. Libérer la copie de la grille
```

**Exemple Visuel :**

**Carte originale :**
```
11111
1P0C1
10001
100E1
11111
```

**Après flood fill depuis P :**
```
11111
1VVC1  ← 'C' est accessible !
1VVV1
1VVE1  ← 'E' est accessible !
11111
```

**Tous les collectibles et la sortie atteints → Chemin valide ✅**

**Exemple invalide :**
```
Original :
11111
1P001
11111
10C0E1
11111

Après flood fill :
11111
1VVV1
11111
10C0E1  ← 'C' et 'E' NON atteints !
11111

→ Erreur : Chemin invalide ❌
```

---

### Système Graphique (MiniLibX)

#### Initialisation (`init_game.c`)

```c
// 1. Initialiser la connexion MLX
game->mlx = mlx_init();

// 2. Créer la fenêtre
int win_width = game->map.width * TILE_SIZE;   // Chaque tuile = 64px
int win_height = game->map.height * TILE_SIZE;

game->window = mlx_new_window(game->mlx, win_width, win_height, "so_long");

// 3. Charger les textures depuis les fichiers .xpm
game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &w, &h);
game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &w, &h);
game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &w, &h);
game->collectible = mlx_xpm_file_to_image(game->mlx, "textures/collectible.xpm", &w, &h);
game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &w, &h);
```

**Pourquoi TILE_SIZE ?**
- Position grille (0, 1, 2...) → Position pixels (0, 64, 128...)
- Mappe les coordonnées de la grille aux coordonnées écran

---

#### Rendu (`render.c`)

**Processus de rendu en deux étapes :**

**Étape 1 : Rendre une tuile individuelle**
```c
static void render_tile(t_game *game, int x, int y)
{
    char tile = game->map.grid[y][x];  // Obtenir le type de tuile
    int px = x * TILE_SIZE;            // Convertir en pixels
    int py = y * TILE_SIZE;
    
    if (tile == '1')
        mlx_put_image_to_window(game->mlx, game->window, game->wall, px, py);
    else
    {
        // Toujours dessiner le sol en premier
        mlx_put_image_to_window(game->mlx, game->window, game->floor, px, py);
        
        // Puis superposer l'élément par-dessus
        if (tile == 'P')
            mlx_put_image_to_window(game->mlx, game->window, game->player, px, py);
        else if (tile == 'C')
            mlx_put_image_to_window(game->mlx, game->window, game->collectible, px, py);
        else if (tile == 'E')
            mlx_put_image_to_window(game->mlx, game->window, game->exit, px, py);
    }
}
```

**Pourquoi dessiner le sol en premier ?**
- Le joueur, les collectibles et la sortie sont **par-dessus** le sol
- Sans le sol, ils apparaîtraient sur fond noir

**Étape 2 : Rendre toute la carte**
```c
void render_map(t_game *game)
{
    int y = -1;
    while (++y < game->map.height)
    {
        int x = -1;
        while (++x < game->map.width)
            render_tile(game, x, y);
    }
}
```

**Ordre de parcours :** Ligne par ligne (y), puis colonne par colonne (x)

---

#### Affichage du Compteur de Mouvements (Bonus)

```c
void display_moves(t_game *game)
{
    char *msg = ft_itoa(game->moves);  // Convertir int en string
    
    // Afficher "Moves:" à (10, 20)
    mlx_string_put(game->mlx, game->window, 10, 20, 0xFF0000, "Moves:");
    
    // Afficher le nombre à (70, 20)
    mlx_string_put(game->mlx, game->window, 70, 20, 0xFF0000, msg);
    
    free(msg);  // Important : libérer la mémoire allouée
}
```

**Format de couleur :** `0xRRVVBB` (RGB hexadécimal)
- `0xFF0000` = Rouge (255, 0, 0)
- `0xFFFFFF` = Blanc (255, 255, 255)

---

### Gestion d'Événements (`events.c`)

#### Logique de Mouvement

```c
void move_player(t_game *game, int new_x, int new_y)
{
    char target = game->map.grid[new_y][new_x];
    
    // 1. Mur → Bloquer le mouvement
    if (target == '1')
        return;
    
    // 2. Collectible → Le ramasser
    if (target == 'C')
    {
        game->collected++;
        game->map.grid[new_y][new_x] = '0';  // Remplacer par du sol
    }
    
    // 3. Sortie + tous les collectibles → Victoire !
    if (target == 'E' && game->collected == game->map.collectibles)
    {
        ft_printf("Bien joue! On a wiiin!\n");
        cleanup_and_exit(game);
        return;
    }
    
    // 4. Sortie mais collectibles manquants → Bloquer
    if (target == 'E')
        return;
    
    // 5. Mouvement valide → Mettre à jour la position
    game->map.grid[game->player.y][game->player.x] = '0';  // Ancienne pos = sol
    game->player.x = new_x;
    game->player.y = new_y;
    game->map.grid[new_y][new_x] = 'P';  // Nouvelle pos = joueur
    game->moves++;
    
    // 6. Redessiner l'écran
    render_map(game);
    display_moves(game);
}
```

**Condition de victoire :** `collected == total_collectibles ET joueur sur sortie`

---

### Gestion de Mémoire

**Principe :** Chaque `malloc()` doit avoir un `free()` correspondant

#### Allocation de Carte
```c
// Dans le parsing
game->map.grid = ft_calloc(height + 1, sizeof(char *));
for (int i = 0; i < height; i++)
    game->map.grid[i] = get_next_line(fd);
```

#### Nettoyage de Carte
```c
void ft_free_map(t_game *game)
{
    if (!game->map.grid)
        return;
    
    for (int i = 0; i < game->map.height; i++)
    {
        if (game->map.grid[i])
            free(game->map.grid[i]);
    }
    free(game->map.grid);
    game->map.grid = NULL;
}
```

#### Nettoyage Complet
```c
void cleanup_and_exit(t_game *game)
{
    // 1. Détruire les textures
    if (game->wall)
        mlx_destroy_image(game->mlx, game->wall);
    // ... toutes les autres textures
    
    // 2. Détruire la fenêtre
    if (game->window)
        mlx_destroy_window(game->mlx, game->window);
    
    // 3. Détruire la connexion MLX
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
    
    // 4. Libérer la carte
    ft_free_map(game);
    
    // 5. Quitter
    exit(0);
}
```

---

## ⚠️ Gestion d'Erreurs

Le programme affiche **"Error"** suivi d'un message explicite pour :

- ❌ **Pas d'arguments :** `Error\nUsage: ./so_long <map.ber>`
- ❌ **Trop d'arguments :** `Error\nUsage: ./so_long <map.ber>`
- ❌ **Mauvaise extension :** `Error\nLe fichier n'a pas l'extension .ber.`
- ❌ **Fichier non trouvé :** `Error\nImpossible d'ouvrir le fichier.`
- ❌ **Carte vide :** `Error\nLa carte est vide.`
- ❌ **Pas rectangulaire :** `Error\nLa carte n'est pas rectangulaire.`
- ❌ **Murs manquants :** `Error\nLa carte n'est pas entouree de murs.`
- ❌ **Éléments invalides :** `Error\nElements invalides (P, E, C).`
- ❌ **Chemin invalide :** `Error\nLe chemin n'est pas valide.`

### Exemples

```bash
./so_long                       # Error + Usage
./so_long map.txt               # Error + Mauvaise extension
./so_long nonexistent.ber       # Error + Impossible d'ouvrir
./so_long maps/invalide/no_path.ber  # Error + Chemin invalide
```

---

## 🧪 Tests

### Tests de Base

```bash
# 1. Test de compilation
make
# Devrait compiler sans erreurs

# 2. Test de non-relink
make
# Devrait afficher "make: 'so_long' is up to date."

# 3. Vérification Norminette
norminette src/**/*.c *.h
# Devrait n'avoir aucune erreur
```

### Tests d'Arguments

```bash
# Pas d'arguments
./so_long
# Attendu : Error + Usage

# Trop d'arguments
./so_long map1.ber map2.ber
# Attendu : Error + Usage

# Mauvaise extension
./so_long test.txt
# Attendu : Error + Mauvaise extension

# Fichier non trouvé
./so_long nonexistent.ber
# Attendu : Error + Impossible d'ouvrir
```

### Tests de Cartes Invalides

```bash
# Carte vide
echo "" > empty.ber
./so_long empty.ber
# Attendu : Error + Carte vide

# Pas rectangulaire
./so_long maps/invalide/not_rectangular.ber
# Attendu : Error + Pas rectangulaire

# Murs manquants
./so_long maps/invalide/no_walls.ber
# Attendu : Error + Pas entourée de murs

# Caractères invalides
./so_long maps/invalide/wrong_chars.ber
# Attendu : Error + Éléments invalides

# Pas de chemin valide
./so_long maps/invalide/no_path.ber
# Attendu : Error + Chemin invalide
```

### Tests de Cartes Valides

```bash
# Carte minimale
./so_long maps/valide/map01.ber
# Attendu : Fenêtre s'ouvre, jeu jouable

# Carte normale
./so_long maps/valide/map04.ber
# Attendu : Toutes les fonctionnalités marchent (mouvement, collection, victoire)
```

### Tests Mémoire

```bash
# Test carte invalide (devrait quitter proprement)
valgrind --leak-check=full ./so_long maps/invalide/no_path.ber
# Attendu : definitely lost: 0 bytes

# Test carte valide (jouer et appuyer sur ESC)
valgrind --leak-check=full ./so_long maps/valide/map04.ber
# Attendu : All heap blocks were freed
```

### Tests de Gameplay

**Checklist manuelle :**
- [ ] Les flèches et WASD fonctionnent
- [ ] Les murs bloquent le mouvement
- [ ] Le compteur de mouvements s'incrémente
- [ ] Les collectibles disparaissent quand ramassés
- [ ] La sortie bloque jusqu'à tous les collectibles ramassés
- [ ] Le message de victoire s'affiche
- [ ] La touche ESC ferme la fenêtre
- [ ] Le bouton X ferme la fenêtre
- [ ] Pas de bugs visuels

---

## 🎯 Fonctionnalités Bonus

### ✅ Implémentées
- **Compteur de mouvements à l'écran** - Affiche le nombre de mouvements en utilisant `mlx_string_put`

### 💡 Extensions Possibles (non requises)
- Patrouilles d'ennemis
- Animations de sprites
- Niveaux multiples
- Affichage du compteur de collectibles
- Chronomètre

---

## 🔧 Défis Techniques & Solutions

### Défi 1 : Indexation de Grille
**Problème :** Confusion entre `grid[x][y]` vs `grid[y][x]`

**Solution :** 
- Les cartes sont stockées **ligne par ligne**
- Toujours utiliser `grid[y][x]` où y = ligne, x = colonne

---

### Défi 2 : Syntaxe des Structures C
**Problème :** Quand utiliser `.` vs `->`

**Solution :**
- `.` pour structures normales : `game.player.x`
- `->` pour pointeurs vers structures : `game->player.x`
- Mixte : `game->player.x` (pointeur vers struct, membre normal)

---

### Défi 3 : Erreurs de Définition Multiple
**Problème :** `get_next_line` et `libft` avaient tous deux `ft_strlen`, `ft_strdup`

**Solution :**
- Supprimé les doublons de `get_next_line_utils.c`
- Ajouté `#include "../Libft/libft.h"` dans `get_next_line.h`
- Gardé seulement `ft_strchr` dans GNL (pas dans libft)

---

### Défi 4 : Organisation du Makefile
**Problème :** Compiler plusieurs bibliothèques + MLX

**Solution :**
```makefile
# Compiler chaque bibliothèque séparément
$(LIBFT):
	make -C Libft

$(LIBFTPRINTF):
	make -C Printf

$(LIBGNL):
	make -C GetNextLine

$(LIBMLX):
	make -C minilibx-linux

# Tout linker ensemble
$(NAME): $(OBJS) $(LIBFT) $(LIBFTPRINTF) $(LIBGNL) $(LIBMLX)
	$(CC) $(OBJS) $(LIBFT) $(LIBFTPRINTF) $(LIBGNL) $(LIBMLX) \
	-L/usr/lib -lXext -lX11 -lm -o $(NAME)
```

---

## 💡 Pourquoi Cette Implémentation est Bonne

✅ **Séparation claire des responsabilités** - Chaque fichier gère une responsabilité  
✅ **Validation robuste** - Flood fill assure des cartes jouables  
✅ **Sécurité mémoire** - Zéro fuite confirmé avec Valgrind  
✅ **Gestion d'erreurs** - Messages explicites pour chaque cas d'erreur  
✅ **Conforme Norminette** - Respect strict des standards de codage  
✅ **Structure professionnelle** - Facile à maintenir et étendre  

**Principes de qualité de code :**
- Fonctions de moins de 25 lignes
- Maximum 4 paramètres par fonction
- Maximum 80 caractères par ligne
- Noms de variables significatifs
- Pas de variables globales

---

## 📚 Apprentissages Clés

### 1. Programmation Graphique
- Gestion de fenêtre avec MiniLibX
- Chargement de textures depuis fichiers XPM
- Pipeline de rendu (effacer → dessiner → afficher)
- Boucle d'événements et callbacks

### 2. Conception d'Algorithme
- Flood fill récursif pour validation de chemin
- Conversions de systèmes de coordonnées (grille ↔ pixels)
- Détection de collision

### 3. Gestion de Mémoire
- Allocation dynamique pour tailles de cartes inconnues
- Nettoyage approprié dans tous les chemins de sortie
- Éviter les fuites mémoire dans les cas d'erreur

### 4. Parsing de Fichier
- Lecture de fichiers avec `get_next_line`
- Validation de format de fichier
- Gestion de cas limites (fichiers vides, permissions, etc.)

---

## 👤 Auteur

**sriee** - [GitHub](https://github.com/sriee94)

*Construit avec des principes de code propre et d'optimisation à l'esprit - 2025*

---

## 🔗 Projets Liés

- [push_swap](https://github.com/sriee94/push_swap) - Algorithme de tri avec deux piles
- [get_next_line](https://github.com/votreusername/get_next_line) - Fonction de lecture de ligne
- [ft_printf](https://github.com/votreusername/ft_printf) - Implémentation personnalisée de printf
- [libft](https://github.com/votreusername/libft) - Bibliothèque C personnalisée

---

**⭐ Si vous trouvez cela utile, pensez à mettre une étoile !**list
