# So_Long - A 2D Game

## 📝 Project Description
**So_Long** is a simple 2D game created using **C** and the **MiniLibX** graphics library. The objective of the game is to collect all collectibles on the map and reach the exit while avoiding enemies. This project helped in understanding window management, event handling, and texture rendering.

## 🎮 Features
- **2D Top-Down Gameplay**
- **Custom Textures & Sprites**
- **Smooth Player Movement (W, A, S, D Keys)**
- **Collision Detection with Walls**
- **Collectibles System**
- **Exit to Complete the Level**
- **Enemy Mechanics (Player Loses on Contact)** *(Bonus)*
- **Sprite Animation for Player & Enemy** *(Bonus)*
- **Move Counter Displayed on Screen** *(Bonus)*
- **Error Handling for Invalid Maps**

## 🖥️ Installation & Usage
### 1️⃣ Clone the Repository
```sh
git clone https://github.com/radouani-md/so_long.git
cd so_long
```
### 2️⃣ Compile the Game
```sh
make
make bonus
```
### 3️⃣ Run the Game with a Map
```sh
./so_long maps/map_level_1.ber
map_level_1
map_level_2
map_level_3
map_level_4
map_level_5 
```

## 🎮 Controls
| Key | Action |
|------|--------|
| W    | Move Up |
| A    | Move Left |
| S    | Move Down |
| D    | Move Right |
| ESC  | Quit the Game |

## 🗺️ Map Rules
The map must be a **.ber** file and follow these rules:
- It must be **rectangular**.
- It must be **surrounded by walls (1)**.
- It must contain:
  - **1 Player (P)**
  - **1 Exit (E)**
  - **At least 1 Collectible (C)**
  - **Walls (1) and Free Space (0)**
- There must be a valid path to collect all collectibles and reach the exit.

### Example of a Valid Map
```
111111
1P0C01
101001
1C00E1
111111
```

## 🚀 Bonus Features
- Animated player and enemy sprites.
- Enemy patrols that cause the player to lose on contact.
- Move counter displayed directly in the game window.

## ⚠️ Errors & Debugging
- If the map is **invalid**, an error message will be displayed.
- If any **texture fails to load**, the game will exit safely.
- Memory leaks are avoided with proper **freeing of resources**.

## 🛠️ Requirements
- **GNU/Linux or macOS**
- **Make & GCC**
- **MiniLibX Library**

## 📜 License
This project is for learning purposes and follows the **42 School Norms**.

## 🙌 Acknowledgments
Special thanks to **42 Network** for this project and the **MiniLibX** creators for providing the graphics library.

---
_"So Long, and Thanks for All the Fish!" 🐬🐟🌍_

