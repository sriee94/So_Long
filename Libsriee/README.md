# 📚 libsriee

**A comprehensive C library** featuring standard functions, string manipulation, memory management, linked lists, get_next_line, and ft_printf.

**Une bibliothèque C complète** comprenant des fonctions standard, manipulation de chaînes, gestion de mémoire, listes chaînées, get_next_line et ft_printf.

Built and maintained by **sriee** as an evolution of the 42 libft project.

Construite et maintenue par **sriee** comme évolution du projet libft de 42.

---

## 🌐 Language / Langue

- [🇬🇧 English](#english)
- [🇫🇷 Français](#français)

---

<a name="english"></a>
# 🇬🇧 English

## 🎯 Features

### Core Functions (libft base)
- **Character checks**: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- **String manipulation**: `ft_strlen`, `ft_strchr`, `ft_strjoin`, `ft_split`, `ft_substr`, `ft_strtrim`, and more
- **Memory management**: `ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_calloc`, and more
- **Conversions**: `ft_atoi`, `ft_itoa`, `ft_toupper`, `ft_tolower`
- **Output functions**: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
- **Linked lists**: Complete set of list manipulation functions (`ft_lstnew`, `ft_lstadd_back`, `ft_lstmap`, etc.)

### Advanced Features
- **get_next_line**: Read from file descriptors line by line with configurable buffer size
- **ft_printf**: Custom implementation of printf supporting `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%p`, `%%`

---

## 📁 Project Structure
```
libsriee/
├── Makefile
├── README.md
├── Include/
│   └── libsriee.h       # Main header file
├── Src/
│   ├── String/          # String manipulation functions
│   ├── Memory/          # Memory operations
│   ├── Convert/         # Type conversions
│   ├── Check/           # Character validation
│   ├── Output/          # File descriptor output
│   ├── List/            # Linked list functions
│   ├── Gnl/             # get_next_line
│   └── Printf/          # ft_printf implementation
└── Objs/                # Compiled objects (auto-generated)
```

---

## 🚀 Installation

### Clone the repository
```bash
git clone https://github.com/sriee94/libsriee.git
cd libsriee
```

### Compile the library
```bash
make
```

This creates `libsriee.a` in the root directory.

### Clean up
```bash
make clean   # Remove object files
make fclean  # Remove everything (including libsriee.a)
make re      # Recompile from scratch
```

---

## 💻 Usage

### In your project

1. **Copy the library** to your project:
```bash
cp libsriee.a /path/to/your/project/
cp Include/libsriee.h /path/to/your/project/
```

2. **Include the header** in your C files:
```c
#include "libsriee.h"
```

3. **Compile with the library**:
```bash
cc -Wall -Wextra -Werror your_file.c -L. -lsriee -o your_program
```

### Example
```c
#include "libsriee.h"
#include <fcntl.h>

int main(void)
{
    char *str;
    int fd;

    // Using ft_printf
    ft_printf("Hello %s!\n", "World");
    
    // Using get_next_line
    fd = open("file.txt", O_RDONLY);
    while ((str = get_next_line(fd)))
    {
        ft_printf("%s", str);
        free(str);
    }
    close(fd);
    
    // Using string functions
    char *joined = ft_strjoin("Hello ", "42!");
    ft_printf("%s\n", joined);
    free(joined);
    
    return (0);
}
```

---

## 🛠️ Customization

### Modify BUFFER_SIZE for get_next_line

Edit `Include/libsriee.h` or compile with:
```bash
cc -D BUFFER_SIZE=1024 your_file.c -L. -lsriee
```

Default is 42, maximum is 8,000,000.

---

## 📖 Function Reference

### String Functions
| Function | Description |
|----------|-------------|
| `ft_strlen` | Calculate string length |
| `ft_strdup` | Duplicate a string |
| `ft_strjoin` | Concatenate two strings |
| `ft_split` | Split string by delimiter |
| `ft_substr` | Extract substring |
| `ft_strtrim` | Trim characters from string |
| `ft_strchr` | Locate character in string |
| `ft_strrchr` | Locate character from end |
| `ft_strncmp` | Compare strings (n bytes) |
| `ft_strnstr` | Locate substring (n bytes) |
| `ft_strlcpy` | Size-bounded string copy |
| `ft_strlcat` | Size-bounded string concatenation |
| `ft_strmapi` | Apply function to string |
| `ft_striteri` | Iterate over string with function |

### Memory Functions
| Function | Description |
|----------|-------------|
| `ft_memset` | Fill memory with constant byte |
| `ft_bzero` | Zero a byte string |
| `ft_memcpy` | Copy memory area |
| `ft_memmove` | Copy memory (handles overlap) |
| `ft_memchr` | Scan memory for character |
| `ft_memcmp` | Compare memory areas |
| `ft_calloc` | Allocate and zero memory |

### Conversion Functions
| Function | Description |
|----------|-------------|
| `ft_atoi` | Convert string to integer |
| `ft_itoa` | Convert integer to string |
| `ft_toupper` | Convert to uppercase |
| `ft_tolower` | Convert to lowercase |

### Character Check Functions
| Function | Description |
|----------|-------------|
| `ft_isalpha` | Check if alphabetic |
| `ft_isdigit` | Check if digit |
| `ft_isalnum` | Check if alphanumeric |
| `ft_isascii` | Check if ASCII |
| `ft_isprint` | Check if printable |

### Output Functions
| Function | Description |
|----------|-------------|
| `ft_printf` | Formatted output to stdout |
| `get_next_line` | Read line from file descriptor |
| `ft_putchar_fd` | Output character to fd |
| `ft_putstr_fd` | Output string to fd |
| `ft_putendl_fd` | Output string + newline to fd |
| `ft_putnbr_fd` | Output number to fd |

### Linked List Functions
| Function | Description |
|----------|-------------|
| `ft_lstnew` | Create new list element |
| `ft_lstadd_front` | Add element at beginning |
| `ft_lstadd_back` | Add element at end |
| `ft_lstsize` | Count list elements |
| `ft_lstlast` | Get last element |
| `ft_lstdelone` | Delete one element |
| `ft_lstclear` | Delete all elements |
| `ft_lstiter` | Iterate with function |
| `ft_lstmap` | Map function to new list |

*See `Include/libsriee.h` for complete function list and prototypes.*

---

## 🎓 About

This library started as the **42 libft project** and has evolved into a comprehensive toolkit used across multiple projects including:
- **get_next_line**
- **ft_printf**
- **pipex**
- **minishell**
- **push_swap**
- And more to come...

Built with **clean code principles**, **Norminette compliance**, and **optimization** in mind.

---

## 📜 License

This project is part of the 42 curriculum. Feel free to use and modify for educational purposes.

---

## 👤 Author

**sriee** - [GitHub](https://github.com/sriee94)

*42 Belgium - 2025*

---

## 🔗 Related Projects

- [get_next_line](https://github.com/sriee94/get_next_line)
- [ft_printf](https://github.com/sriee94/ft_printf)
- [push_swap](https://github.com/sriee94/push_swap)
- [pipex](https://github.com/sriee94/pipex)

---

**⭐ If you find this useful, consider giving it a star!**

---
---

<a name="français"></a>
# 🇫🇷 Français

## 🎯 Fonctionnalités

### Fonctions de base (libft)
- **Vérification de caractères**: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- **Manipulation de chaînes**: `ft_strlen`, `ft_strchr`, `ft_strjoin`, `ft_split`, `ft_substr`, `ft_strtrim`, et plus
- **Gestion de mémoire**: `ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_calloc`, et plus
- **Conversions**: `ft_atoi`, `ft_itoa`, `ft_toupper`, `ft_tolower`
- **Fonctions de sortie**: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
- **Listes chaînées**: Ensemble complet de fonctions (`ft_lstnew`, `ft_lstadd_back`, `ft_lstmap`, etc.)

### Fonctionnalités avancées
- **get_next_line**: Lecture ligne par ligne depuis des descripteurs de fichiers avec taille de buffer configurable
- **ft_printf**: Implémentation personnalisée de printf supportant `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%p`, `%%`

---

## 📁 Structure du projet
```
libsriee/
├── Makefile
├── README.md
├── Include/
│   └── libsriee.h       # Fichier d'en-tête principal
├── Src/
│   ├── String/          # Fonctions de manipulation de chaînes
│   ├── Memory/          # Opérations mémoire
│   ├── Convert/         # Conversions de types
│   ├── Check/           # Validation de caractères
│   ├── Output/          # Sortie sur descripteur de fichier
│   ├── List/            # Fonctions de listes chaînées
│   ├── Gnl/             # get_next_line
│   └── Printf/          # Implémentation de ft_printf
└── Objs/                # Objets compilés (auto-généré)
```

---

## 🚀 Installation

### Cloner le dépôt
```bash
git clone https://github.com/sriee94/libsriee.git
cd libsriee
```

### Compiler la bibliothèque
```bash
make
```

Cela crée `libsriee.a` dans le répertoire racine.

### Nettoyage
```bash
make clean   # Supprimer les fichiers objets
make fclean  # Tout supprimer (y compris libsriee.a)
make re      # Recompiler depuis zéro
```

---

## 💻 Utilisation

### Dans votre projet

1. **Copier la bibliothèque** dans votre projet:
```bash
cp libsriee.a /chemin/vers/votre/projet/
cp Include/libsriee.h /chemin/vers/votre/projet/
```

2. **Inclure le header** dans vos fichiers C:
```c
#include "libsriee.h"
```

3. **Compiler avec la bibliothèque**:
```bash
cc -Wall -Wextra -Werror votre_fichier.c -L. -lsriee -o votre_programme
```

### Exemple
```c
#include "libsriee.h"
#include <fcntl.h>

int main(void)
{
    char *str;
    int fd;

    // Utilisation de ft_printf
    ft_printf("Bonjour %s!\n", "Monde");
    
    // Utilisation de get_next_line
    fd = open("fichier.txt", O_RDONLY);
    while ((str = get_next_line(fd)))
    {
        ft_printf("%s", str);
        free(str);
    }
    close(fd);
    
    // Utilisation des fonctions de chaînes
    char *joined = ft_strjoin("Bonjour ", "42!");
    ft_printf("%s\n", joined);
    free(joined);
    
    return (0);
}
```

---

## 🛠️ Personnalisation

### Modifier BUFFER_SIZE pour get_next_line

Éditez `Include/libsriee.h` ou compilez avec:
```bash
cc -D BUFFER_SIZE=1024 votre_fichier.c -L. -lsriee
```

Par défaut: 42, maximum: 8 000 000.

---

## 📖 Référence des fonctions

### Fonctions de chaînes
| Fonction | Description |
|----------|-------------|
| `ft_strlen` | Calculer la longueur d'une chaîne |
| `ft_strdup` | Dupliquer une chaîne |
| `ft_strjoin` | Concaténer deux chaînes |
| `ft_split` | Diviser une chaîne par délimiteur |
| `ft_substr` | Extraire une sous-chaîne |
| `ft_strtrim` | Enlever des caractères d'une chaîne |
| `ft_strchr` | Localiser un caractère dans une chaîne |
| `ft_strrchr` | Localiser un caractère depuis la fin |
| `ft_strncmp` | Comparer des chaînes (n octets) |
| `ft_strnstr` | Localiser une sous-chaîne (n octets) |
| `ft_strlcpy` | Copie de chaîne limitée en taille |
| `ft_strlcat` | Concaténation limitée en taille |
| `ft_strmapi` | Appliquer une fonction à une chaîne |
| `ft_striteri` | Itérer sur une chaîne avec fonction |

### Fonctions mémoire
| Fonction | Description |
|----------|-------------|
| `ft_memset` | Remplir la mémoire avec un octet constant |
| `ft_bzero` | Mettre à zéro une chaîne d'octets |
| `ft_memcpy` | Copier une zone mémoire |
| `ft_memmove` | Copier la mémoire (gère les chevauchements) |
| `ft_memchr` | Rechercher un caractère en mémoire |
| `ft_memcmp` | Comparer des zones mémoire |
| `ft_calloc` | Allouer et mettre à zéro la mémoire |

### Fonctions de conversion
| Fonction | Description |
|----------|-------------|
| `ft_atoi` | Convertir chaîne en entier |
| `ft_itoa` | Convertir entier en chaîne |
| `ft_toupper` | Convertir en majuscule |
| `ft_tolower` | Convertir en minuscule |

### Fonctions de vérification
| Fonction | Description |
|----------|-------------|
| `ft_isalpha` | Vérifier si alphabétique |
| `ft_isdigit` | Vérifier si chiffre |
| `ft_isalnum` | Vérifier si alphanumérique |
| `ft_isascii` | Vérifier si ASCII |
| `ft_isprint` | Vérifier si imprimable |

### Fonctions de sortie
| Fonction | Description |
|----------|-------------|
| `ft_printf` | Sortie formatée vers stdout |
| `get_next_line` | Lire une ligne depuis un descripteur |
| `ft_putchar_fd` | Afficher un caractère sur fd |
| `ft_putstr_fd` | Afficher une chaîne sur fd |
| `ft_putendl_fd` | Afficher chaîne + retour ligne sur fd |
| `ft_putnbr_fd` | Afficher un nombre sur fd |

### Fonctions de listes chaînées
| Fonction | Description |
|----------|-------------|
| `ft_lstnew` | Créer un nouvel élément |
| `ft_lstadd_front` | Ajouter en début |
| `ft_lstadd_back` | Ajouter en fin |
| `ft_lstsize` | Compter les éléments |
| `ft_lstlast` | Obtenir le dernier élément |
| `ft_lstdelone` | Supprimer un élément |
| `ft_lstclear` | Supprimer tous les éléments |
| `ft_lstiter` | Itérer avec fonction |
| `ft_lstmap` | Mapper fonction vers nouvelle liste |

*Voir `Include/libsriee.h` pour la liste complète des fonctions et prototypes.*

---

## 🎓 À propos

Cette bibliothèque a commencé comme le **projet libft de 42** et a évolué en une boîte à outils complète utilisée dans plusieurs projets:
- **get_next_line**
- **ft_printf**
- **pipex**
- **minishell**
- **push_swap**
- Et d'autres à venir...

Construite avec les principes du **code propre**, la **conformité Norminette** et l'**optimisation** à l'esprit.

---

## 📜 Licence

Ce projet fait partie du cursus 42. N'hésitez pas à l'utiliser et le modifier à des fins éducatives.

---

## 👤 Auteur

**sriee** - [GitHub](https://github.com/sriee94)

*42 Belgium - 2025*

---

## 🔗 Projets liés

- [get_next_line](https://github.com/sriee94/get_next_line)
- [ft_printf](https://github.com/sriee94/ft_printf)
- [push_swap](https://github.com/sriee94/push_swap)
- [pipex](https://github.com/sriee94/pipex)

---

**⭐ Si vous trouvez cela utile, pensez à mettre une étoile!**
