# Cub3D - My First RayCaster with miniLibX

![Score: 100/100](https://img.shields.io/badge/Score-100%2F100-success?style=for-the-badge)
![Language: C](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)
![Graphics: miniLibX](https://img.shields.io/badge/Graphics-miniLibX-orange?style=for-the-badge)

## 📖 Overview

**Cub3D** is a 3D graphical representation of the inside of a maze from a first-person perspective, created using ray-casting principles. This project is inspired by the world-famous **Wolfenstein 3D** game (1992), which was the first FPS (First Person Shooter) ever created.

The project explores the mathematical concepts behind 3D graphics rendering and provides hands-on experience with:

- **Ray-casting algorithms**
- **3D graphics programming**
- **Event handling and user interaction**
- **Texture mapping and rendering**

## 👥 Authors

This project was developed as a collaborative effort by two students from **42 Wolfsburg**:

- **Igors Oleinikovs** (ioleinik) - [42 Wolfsburg]
- **Khanak Gulati** (khanakgulat) - [42 Wolfsburg]

## 🎯 Project Objectives

- Implement a realistic 3D maze representation using ray-casting
- Handle window management and user interactions
- Parse and validate map configuration files
- Apply mathematical concepts in practical programming
- Develop skills in graphics programming and event handling

## ✨ Features

### Mandatory Features

- ✅ **3D Ray-casting Engine**: Real-time rendering of 3D maze environment
- ✅ **Texture Mapping**: Different wall textures based on direction (North, South, East, West)
- ✅ **Player Movement**: Smooth movement with WASD keys
- ✅ **Camera Control**: Look left/right with arrow keys
- ✅ **Color Management**: Customizable floor and ceiling colors
- ✅ **Map Parsing**: Support for .cub configuration files
- ✅ **Input Validation**: Comprehensive error handling and validation
- ✅ **Cross-platform**: Works on both macOS and Linux

### Controls

- `W` `A` `S` `D` - Move through the maze
- `←` `→` - Look left and right
- `ESC` - Exit the program
- `❌` (window close button) - Exit the program

## 🏗️ Project Structure

```text
42-Cub3d/
├── src/                    # Main source code (Linux compatible)
│   ├── *.c                # Source files
│   ├── *.h                # Header files  
│   ├── libft/             # Custom C library
│   ├── mlx-linux/         # MLX library for Linux
│   ├── textures/          # Wall texture files
│   ├── *.cub              # Map configuration files
│   └── Makefile           # Cross-platform build system
├── macos/                 # Original macOS version
├── cub3d-subject.pdf      # Project subject
└── README.md              # This file
```

## 🛠️ Installation & Usage

### Prerequisites

**Linux:**

```bash
sudo apt update
sudo apt install gcc make libxext-dev libxrandr-dev libx11-dev libbsd-dev
```

**macOS:**

```bash
# Xcode command line tools required
xcode-select --install
```

### Building the Project

```bash
# Clone the repository
git clone [repository-url]
cd 42-Cub3d

# Build the project (recommended - auto-cleans object files)
cd src
make build

# Alternative: Standard build (leaves object files)
make

# Clean build (removes all artifacts and rebuilds with cleanup)
make rebuild

# Run with a map file
./cub3D test.cub
```

#### Available Make Targets

- `make` or `make all` - Standard build (leaves object files)
- `make build` - Build and automatically clean object files after success
- `make rebuild` - Full clean and build with automatic object cleanup  
- `make clean` - Remove all build artifacts except executable
- `make clean-obj` - Remove only object files (keeps libraries and executable)
- `make fclean` - Remove all build artifacts including executable
- `make re` - Full rebuild (equivalent to `make fclean all`)
- `make norme` - Run norminette style checker
- `make valgrind` - Build with cleanup and run memory leak detection

### Map File Format (.cub)

Map files must follow this specific format:

```text
NO ./textures/north_texture.xpm
SO ./textures/south_texture.xpm  
WE ./textures/west_texture.xpm
EA ./textures/east_texture.xpm

F 220,100,0    # Floor color (R,G,B)
C 225,30,0     # Ceiling color (R,G,B)

111111111111
100000000001
101010001001
100000000001
101010001001
100000N00001
111111111111
```

#### Map Rules

- `0` - Empty space
- `1` - Wall
- `N`, `S`, `E`, `W` - Player start position and orientation
- Map must be surrounded by walls
- Only one player position allowed

### Memory Testing

For comprehensive memory leak detection, the project includes Valgrind integration:

```bash
# Run automatic memory leak testing
make valgrind

# Manual Valgrind testing with custom maps
valgrind --leak-check=full --suppressions=valgrind_x11.supp ./cub3D test.cub
```

**Memory Safety Results**: ✅ **100% Leak-Free**

- Zero definite memory leaks
- Zero indirect memory leaks
- Zero possible memory leaks
- Professional-grade memory management

## 🔧 Technical Implementation

### Ray-Casting Algorithm

The project implements a grid-based ray-casting engine that:

1. Casts rays from the player position for each screen column
2. Calculates wall distances using DDA (Digital Differential Analyzer)
3. Determines wall height based on distance (perspective projection)
4. Maps appropriate textures based on wall orientation
5. Renders floor and ceiling with specified colors

### Key Components

- **Parsing Engine**: Validates and processes .cub files
- **Graphics Engine**: MLX-based rendering system
- **Math Library**: Vector operations and trigonometric calculations
- **Event Handler**: Keyboard and window event management
- **Memory Management**: Proper allocation and cleanup

## 🚀 Recent Improvements

### Code Quality Enhancements

- ✅ **Cross-platform Makefile**: Automatic OS detection and appropriate compilation flags
- ✅ **Linux Compatibility**: Full MLX-Linux integration
- ✅ **Memory Safety**: Comprehensive cleanup and error handling
- ✅ **Code Organization**: Clear separation of concerns
- 🔄 **Constants Definition**: Replacing magic numbers with named constants
- 🔄 **Function Modularization**: Breaking down complex functions
- 🔄 **Documentation**: Adding comprehensive code comments

### Performance Optimizations

- Efficient ray-casting algorithms
- Optimized texture mapping
- Minimal memory footprint

## 📚 Learning Outcomes

This project provided hands-on experience with:

- **Computer Graphics**: Understanding 3D rendering principles
- **Mathematics**: Practical application of trigonometry and linear algebra
- **Algorithm Design**: Implementing efficient ray-casting algorithms
- **System Programming**: Cross-platform development and library integration
- **Software Architecture**: Designing modular and maintainable code

## 🎮 Inspiration

This project draws inspiration from classic games that pioneered 3D graphics:

- **Wolfenstein 3D** (1992) - Id Software
- **Doom** (1993) - Id Software  
- **Duke Nukem 3D** (1996) - 3D Realms
- **Quake** (1996) - Id Software

## 📝 License

This project was created as part of the 42 School curriculum. Feel free to explore and learn from the code, but please respect academic integrity policies if you're a current 42 student.

## 🔗 Resources

- [42 School](https://42.fr/)
- [Wolfenstein 3D Original Game](http://users.atw.hu/wolf3d/)
- [Ray-Casting Tutorial](https://lodev.org/cgtutor/raycasting.html)
- [miniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)

---

*"Now, it's your turn to relive History..."* - From the Cub3D subject
