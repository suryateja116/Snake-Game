# Snake Game with Console Graphics (C++)

This project is a "Snake Game with Console Graphics", developed in C++ using `windows.h` and `conio.h`.  
It recreates the classic Snake Game in a terminal environment, featuring color-based visuals, menu options, adjustable speed levels, and smooth real-time movement.

---

## Project Overview

The program simulates the popular Snake Game on a 20x20 grid.  
The player controls a snake that moves continuously in one direction, consumes food to grow longer, and must avoid colliding with itself.  
Each time the snake eats food, the score increases, and the game continues until the player collides or exits manually.

---

## How It Works

### 1. Game Initialization
- The game initializes by setting the snake at the center of the grid.  
- Food is randomly placed on the grid at coordinates that do not overlap with the snake.  
- Variables such as position, direction, score, and tail length are initialized.

### 2. Grid Display
- The game grid is drawn using console characters.  
- Borders are represented with `#`.  
- The snake’s head (`@`) and body (`O`) are displayed in color using the `setColor()` function.  
- The food is represented by `*`.  
- The current score and selected difficulty are shown below the grid.

### 3. Input Handling
- User input is captured using `_kbhit()` and `_getch()`.  
- Movement keys:
  - **W**: Move Up  
  - **S**: Move Down  
  - **A**: Move Left  
  - **D**: Move Right  
- Press **X** to exit the game anytime.

### 4. Game Logic
- The snake moves in the current direction until new input is given.  
- When food is eaten:
  - The score increases by 10.  
  - The snake length increases by one segment.  
  - New food coordinates are generated randomly.  
- The snake wraps around edges (no hard wall boundaries).  
- The game ends if the snake collides with itself.

### 5. Difficulty Levels
Before starting, the user can choose one of four speed levels:
- Easy (Slow speed)  
- Medium (Normal speed)  
- Hard (Fast speed)  
- Extreme (Very fast speed)

The speed determines the delay between movement updates.

### 6. Game Loop
The main loop continuously performs:
until the `gameover` flag becomes `true`.

### 7. Game Over
When the snake collides with its body or the player presses 'X',  
the game stops, clears the screen, and displays the final score.

---

## Explanation of Output

1. **Setup Phase**  
   - The 20x20 grid is displayed with borders.  
   - The snake starts at the center, and a food item appears at a random position.

2. **Gameplay Display**  
   - The snake’s head and body move smoothly as the player gives inputs.  
   - Food reappears in new random positions after being eaten.  
   - The score updates in real-time.

3. **Collision Handling**  
   - If the snake eats food, its length increases.  
   - If it collides with its own body, the game ends and displays "Game Over" with the final score.

---

## Algorithm Steps

1. **Initialize Game Variables**  
   - Set `gameover = false`, initial snake position, and random food coordinates.

2. **Draw the Grid**  
   - Render the boundaries, snake, food, and display the score.

3. **Handle Input**  
   - Detect key presses (`w`, `a`, `s`, `d`, `x`) to control direction or exit.

4. **Update Logic**  
   - Move the snake head and shift each tail segment to the previous one’s position.  
   - Detect food collision, increase score and tail length, and respawn food.

5. **Repeat**  
   - Continue drawing, receiving input, and updating logic until `gameover` is `true`.

6. **End Game**  
   - Display "Game Over" and the final score.

---

## Time Complexity Analysis

| Function | Description | Time Complexity |
|-----------|--------------|----------------|
| `Setup()` | Initializes variables and positions | O(1) |
| `Draw()` | Displays the grid and checks for collisions | O(Tail) |
| `Input()` | Captures user key press | O(1) |
| `Logic()` | Updates positions, checks for food and self-collision | O(Tail) |
| **Overall Loop** | Runs until game over | O(n × Tail) |

As the game progresses and the snake grows longer, the time required per iteration increases linearly with the tail length.

---

## Requirements
- Windows operating system  
- Any C++ compiler that supports `conio.h` and `windows.h` (e.g., MinGW, Visual Studio, Code::Blocks)  
- Command Prompt or Terminal for execution

---

## How to Run
1. Open Command Prompt in the project directory.  
2. Compile the code:
   ```bash
   g++ "snake game graphics.cpp" -o snake

