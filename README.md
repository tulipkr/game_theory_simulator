# Game Theory Simulator (C++)

A menu-driven C++ console application implementing several classic puzzle and strategy games using object-oriented programming concepts.

**Main file:** `cpp_game.cpp`

## Overview

This project combines multiple classic logic and puzzle problems into a single interactive console application.  
Each game is implemented as a derived class from an abstract base class using **runtime polymorphism**.

The program allows the user to select a game, choose difficulty levels where applicable, and interact through a menu-driven interface.

---

## Games Implemented

### Tic Tac Toe
- Supports multiple board sizes (3×3, 4×4, 5×5)
- Two-player gameplay
- Automatic win detection

### Water Jug Problem
- Classic puzzle involving two jugs with different capacities
- Interactive actions for pouring and transferring water
- Multiple difficulty levels

### Missionaries and Cannibals
- River-crossing puzzle
- Boat capacity constraints
- Game-over condition if missionaries are outnumbered

### N-Queens Problem
- Backtracking-based solution
- Supports both **4-Queens** and **8-Queens**

### Tower of Hanoi
- Recursive algorithm implementation
- Demonstrates disk movement between rods

---

## Programming Concepts Used

- Object-Oriented Programming
- Abstract Base Classes
- Runtime Polymorphism
- Inheritance
- Friend Functions
- Recursion
- Backtracking
- Dynamic Memory Allocation
- Menu-Driven Program Design

---

## Technologies Used

- C++
- Standard Library

---

## How to Run

### Method 1: Using Dev C++ / CodeBlocks / any IDE

1. Open the `.cpp` file in your C++ IDE.
2. Compile the program.
3. Run the program.

---

### Method 2: Using Terminal (g++ compiler)

Compile the program:

```
g++ cpp_game.cpp -o game
```

Run the program:

```
./game
```
---

## Learning Outcomes

- Implementing polymorphism through abstract classes
- Structuring modular console applications
- Solving classical algorithmic problems using recursion
- Designing interactive menu-driven programs
