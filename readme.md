# FDF

`fdf` is a project that creates a wireframe model of a 3D landscape from a given `.fdf` file, using the MiniLibX library for graphics.

## Objectives

- Create a simple wireframe model of a 3D landscape.
- Render the model in isometric projection.
- Handle basic graphics operations with MiniLibX.

## Features

- **3D Wireframe Model**: Represents landscapes using points and edges.
- **Isometric Projection**: Displays the landscape from a specific viewpoint.
- **Window Management**: Smooth interactions including resizing and closing.

## Usage

1. Compile the project:
    ```sh
    make
    ```

2. Run the program with a `.fdf` file:
    ```sh
    ./fdf example.fdf
    ```

## Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/NuIled/fdf.git
    ```

2. Navigate to the project directory:
    ```sh
    cd fdf
    ```

3. Build the project:
    ```sh
    make
    ```

## Makefile Rules

- `all`: Build the project
- `clean`: Remove object files
- `fclean`: Remove object files and binary
- `re`: Rebuild the project

## External Functions Used

- `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`
- Math library (`-lm`)
- MiniLibX
- Custom `ft_printf` or equivalent

## Example `.fdf` File

```plaintext
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 10 10 0 0 10 10 0 0 0 10 10 10 10 10 0 0 0
0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0
0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0
0 0 10 10 10 10 10 10 0 0 0 0 10 10 10 10 0 0 0
0 0 0 10 10 10 10 10 0 0 0 10 10 0 0 0 0 0 0
0 0 0 0 0 0 10 10 0 0 0 10 10 0 0 0 0 0 0
0 0 0 0 0 0 10 10 0 0 0 10 10 10 10 10 10 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
```
