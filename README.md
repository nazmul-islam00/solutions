# Solutions Repository

This repository contains solutions to various competitive programming problems from platforms such as AtCoder, CodeForces, LeetCode, and Project Euler.

## Directory Structure

```
solutions/
│-- AtCoder/                # Solutions to AtCoder problems
│-- CodeForces_ProblemSet/  # Solutions to CodeForces problems
│-- LeetCode_ProblemSet/    # Solutions to LeetCode problems
│-- ProjectEuler/           # Solutions to Project Euler problems
│-- CMakeLists.txt          # CMake build configuration
│-- README.md               # Project documentation
```

## Building the Solutions

This repository uses CMake to manage the build process. Follow these steps to build the solutions:

### Prerequisites
- CMake (version 3.10 or higher)
- A C++ compiler (e.g., GCC, Clang, or MSVC)

### Build Instructions

1. Clone the repository:
   ```sh
   git clone https://github.com/nazmul-islam00/solutions.git
   cd solutions
   ```
2. Create a build directory:
   ```sh
   mkdir build && cd build
   ```
3. Run CMake to generate build files:
   ```sh
   cmake ..
   ```
4. Compile the solutions:
   ```sh
   make
   ```

### Running Executables
After building, you can find the compiled executables in the `build` directory. Run them using:
```sh
./build/<executable_name>
```

## Contributing
Feel free to submit pull requests if you have additional solutions or improvements. Make sure your code is well-documented and follows clean coding practices.

## License
This repository is licensed under the MIT License. See the `LICENSE` file for details.


