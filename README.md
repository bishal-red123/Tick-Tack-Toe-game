# Tic-Tac-Toe Game (SFML)

A modern, interactive Tic-Tac-Toe game built using **C++** and **SFML**. This project showcases game development concepts such as event handling, rendering, and user interaction.

---

## 📌 Features
✅ Two-player mode  
✅ Graphical UI using SFML  
✅ Mouse-based input handling  
✅ Real-time board updates  
✅ Win detection & game-over screen  

---

## 🛠️ Tech Stack
- **Language**: C++
- **Framework**: SFML (Simple and Fast Multimedia Library)
- **Tools**: GCC/MSVC, Visual Studio Code, Makefile

---

## 🚀 Installation & Usage
### **1️⃣ Clone the Repository**
```sh
git clone https://github.com/YOUR_USERNAME/Tic-Tac-Toe-SFML.git
cd Tic-Tac-Toe-SFML
```

### **2️⃣ Install SFML**
#### **Windows (Using vcpkg)**
```sh
vcpkg install sfml
```

#### **Linux**
```sh
sudo apt-get install libsfml-dev
```

### **3️⃣ Compile & Run**
#### **Using g++ (Linux/macOS)**
```sh
g++ src/*.cpp -o tic-tac-toe -Iinclude -Llib -lsfml-graphics -lsfml-window -lsfml-system
./tic-tac-toe
```

#### **Using Visual Studio (Windows)**
- Open the project folder in **VS Code**
- Configure the **include & library paths** for SFML
- Build & run the project

---

## 🎮 How to Play
1️⃣ Launch the game.  
2️⃣ Click on a grid cell to place your mark (`X` or `O`).  
3️⃣ Players take turns until a player wins or the game ends in a tie.  
4️⃣ The winner or tie result is displayed at the end.  

---

## 📌 Future Enhancements
🔹 AI-based opponent (Minimax Algorithm)  
🔹 Online Multiplayer with Networking  
🔹 Score Tracking & Game History  
🔹 Animated UI with Sound Effects  
