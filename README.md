# GamePart2
This project is a simple 3D maze game inspired by the classic Wolfenstein 3D game. It is written in C and uses the MinilibX library for graphical rendering.

## Features

- Simple 3D maze rendering
- Textured walls
- Player movement
- Minimap display
- Basic enemy(if implemented)

## Prerequisites

- C compiler (gcc or clang)
- MinilibX library
- macOS or Linux (Windows support may require additional setup)

## how to compile

```bash
gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit libft/src/*.c src/*.c -o output
./output map/1.cub
