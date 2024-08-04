# Overview

The `cub3D` project is a 3D graphical representation of an environment created from a first-person perspective using ray-casting principles. This project serves as an introduction to graphics programming in C, utilizing the miniLibX library for rendering and user interaction.

## Objectives

The primary goals of the `cub3D` project include:

- Developing a solid understanding of ray-casting algorithms.
- Gaining experience in graphical programming and window management.
- Implementing various wall textures based on their orientation (North, South, East, West).
- Ensuring smooth window management during rendering.

## Features

- **Ray-Casting Engine**: A functional ray-casting engine that simulates a 3D environment.
- **Textured Walls**: Different textures for walls based on their direction, enhancing the visual experience.
- **User Interaction**: Basic controls for navigating through the environment.
- **Configuration File Parsing**: The program parses a configuration file to set up the map and other environment parameters, allowing for flexible scene descriptions.
- **Memory Management**: Proper handling of dynamic memory allocation to prevent leaks and ensure stability.

## Technical Details

- **Language**: C
- **Libraries Used**: miniLibX for graphics rendering.
- **Makefile**: Includes rules for compiling, cleaning, and managing the project.
- **Norm Compliance**: The code adheres to the coding standards and norms specified for the project.

## Installation

To run the `cub3D` project, clone the repository:

```
git clone https://github.com/windchaser-surf/Cub3D.git
cd Cub3D
./cub3D_bonus maps/map1.cub
```

## Conclusion

The `cub3D` project has been a valuable learning experience, allowing me to explore the intersection of mathematics and computer graphics. It has enhanced my programming skills and provided a deeper understanding of how 3D environments are rendered in real-time.
