# Organized

A C program that implements a workshop management system for organizing different types of hardware materials using linked lists and sorting algorithms.

## Overview

This program provides a shell interface to manage and organize workshop materials. Users can add, delete, display, and sort hardware materials through a command-line interface. The project focuses on efficient data storage and sorting of materials based on different criteria.

## Features

- **Material Management**: Add and delete hardware materials with unique IDs
- **Display Functionality**: View the current state of your workshop
- **Advanced Sorting**: Sort materials based on different criteria (TYPE, NAME, ID)
  - Support for reverse sorting with the `-r` flag
  - Multi-criteria sorting (e.g., sort by TYPE, then by NAME)

## Hardware Categories

The program organizes materials into 5 categories:
- Actuators: buttons, levers, etc.
- Devices: radios, watches, recorders, etc.
- Processors: intel, amd, etc.
- Sensors: movement sensors, sound sensors, thermal sensors, etc.
- Wires: type-c, hdmi, jack, etc.

## Technical Details

- **Language**: C
- **Compilation**: Via Makefile, including re, clean, and fclean rules
- **Authorized Functions**: open, read, write, close, malloc, free
- **Error Handling**: Error messages are written to the error output, with exit code 84 for errors

## Usage

### Compilation

```bash
make
```

### Running the Program

```bash
./organized
```

### Available Commands

- **add**: Add new hardware
  ```
  add WIRE usb
  add ACTUATOR button, DEVICE recorder
  ```

- **del**: Delete hardware by ID
  ```
  del 1
  del 0, 2
  ```

- **disp**: Display workshop contents
  ```
  disp
  ```

- **sort**: Sort materials according to specified tags
  ```
  sort NAME
  sort NAME -r
  sort TYPE -r NAME ID -r
  ```

- **exit**: Exit the program

### Batch Testing

You can also run commands from a file:

```bash
cat commands_file | ./organized
```

Example commands file:
```
add WIRE a, WIRE b, WIRE c, WIRE d, SENSOR e, SENSOR f, WIRE a
disp
sort TYPE -r
disp
exit
```

## Implementation Notes

- Materials are stored in a linked list
- New materials are added in reverse order
- Materials are assigned unique IDs starting from 0
- The program uses the provided shell interface (libshell.a and shell.h)
