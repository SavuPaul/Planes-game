# Plane Data Processing Program

This program processes data for a list of planes based on specific requirements, displaying information, drawing planes on a matrix, and sorting them by various attributes. It consists of four main tasks:

## Table of Contents
1. [Task 1: Display Plane Details](#task-1-display-plane-details)
2. [Task 2: Draw Planes in Matrix](#task-2-draw-planes-in-matrix)
3. [Task 3: Sort Planes by Type, Code, and Speed](#task-3-sort-planes-by-type-code-and-speed)
4. [Task 4: Obstacle Detection](#task-4-obstacle-detection)

---

### Task 1: Display Plane Details

To display details for each plane, the program extracts specific data fields from a given vector according to data types:
- **Coordinates**: The coordinates of the plane’s tip are of type `unsigned short` and occupy 2 bytes each. 
    - First coordinate: `*((unsigned short*)(info + 0))`
    - Second coordinate: `*((unsigned short*)(info + 2))`
- **Direction**: The direction is a `char` (1 byte): `*((char*)(info + 4))`
- **Code**: The code is composed of 4 characters.
- **Speed**: Speed is of type `unsigned int` and occupies 4 bytes: `*((unsigned int*)(info + 9))`

This process is iterated within a `for` loop to display each plane’s information sequentially.

### Task 2: Draw Planes in Matrix

For each plane, based on its coordinates, direction, and type, the program "draws" the plane differently within a matrix. The directions vary as follows:
- **Type 1**: Directions include North (N), South (S), East (E), and West (W).
- **Type 2**: The directions follow the same pattern as Type 1.

Each plane type has a unique drawing style based on its direction within the matrix.

### Task 3: Sort Planes by Type, Code, and Speed

To sort planes, the program uses the `qsort` function with custom comparison functions:
1. **Sort by Type (Ascending)**:
    - If the type of the first plane is greater than the second, their positions are swapped.
    - Function call: `qsort(info, nr_avioane, plane_size, tip_asc);`
2. **Sort by Code (Descending)**:
    - If types are equal, planes are sorted by code in descending order using `code_desc`.
    - This is done by comparing each of the 4 characters lexicographically between two codes.
    - Function call: `qsort(info, nr_avioane, plane_size, code_desc);`
3. **Sort by Speed (Ascending)**:
    - For planes with equal types and codes, sorting by speed is performed using `speed_asc`.
    - Function call: `qsort(info, nr_avioane, plane_size, speed_asc);`

Constants direct the program to interpret memory addresses as specific data types, ensuring correct extraction and sorting of plane attributes. The display format for sorted data mirrors that of Task 1.

### Task 4: Obstacle Detection

This task checks if planes will encounter obstacles along their path. Using the coordinates of the plane's tail, wing edges, type, and direction:
- **Obstacle Check**: For each plane, the program verifies that obstacles are not within the path of the plane’s direction, based on its wingspan and the tail’s position.
- **Result Tracking**: The `ok` variable counts obstacles that do not intersect with the plane’s path. If `ok` equals `nr_obstacole` (total obstacles), the plane can move without collision.

This obstacle detection is repeated for each plane individually.

---

This program effectively manages and processes plane data, from display to sorting and obstacle assessment, with structured handling for each task.

