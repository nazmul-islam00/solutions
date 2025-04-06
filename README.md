# Solutions Repository

This repository contains a collection of competitive programming solutions across various online judges and problem-solving platforms, including:

- 🧩 [AtCoder](https://atcoder.jp)
- 🏆 [CodeForces](https://codeforces.com)
- 💡 [LeetCode](https://leetcode.com)
- 🧮 [Project Euler](https://projecteuler.net)

  
The solutions are written in **C++**, **C**, **Python**, **Go**, **Java**, and **Rust**, depending on the nature of the problem and the platform.


## Directory Structure

```
solutions/
├── AtCoder/ # AtCoder problem solutions
├── CodeForces_ProblemSet/ # CodeForces problem solutions
├── LeetCode_ProblemSet/ # LeetCode problem solutions
├── ProjectEuler/ # Project Euler solutions
├── main.cpp # (Optional) main driver for C++ builds
├── CMakeLists.txt # CMake configuration for C/C++ code
└── README.md
```


## ⚙️ Build Instructions (C/C++)

If you want to compile and run the C/C++ solutions, a `CMakeLists.txt` is provided to make the process easier.

### Requirements
- CMake ≥ 3.10
- A C++ compiler (GCC, Clang, MSVC, etc.)

### Steps

```bash
# Clone the repository
git clone https://github.com/nazmul-islam00/solutions.git
cd solutions

# Create and enter build directory
mkdir build && cd build

# Generate and build
cmake ..
make

# Run the executable
./Solutions
```

``main.cpp`` is a customizable entry point for testing your own C++ solutions.


## 🌐 Multi-Language Solutions
This repository also contains solutions in other languages. Each language uses its standard toolchain:

### 🐍 Python
Run directly using:

```bash
python3 solution.py
```

### 🦫 Go
Use the Go toolchain:

```bash
go run solution.go
```

### 🦀 Rust
Use Cargo:

```bash
cargo run
```

### ☕ Java
Compile and run:

```bash
javac Solution.java
java Solution
```


## 📌 Notes

- This repo is primarily for learning and practicing algorithms and data structures.
- File naming conventions may vary by platform or user preference.
- Pull requests are welcome for enhancements, fixes, or new solutions.


## Contributing
Feel free to submit pull requests if you have additional solutions or improvements. Make sure your code is well-documented and follows clean coding practices.


## 📜 License
This repository is licensed under the [MIT License](LICENSE).


