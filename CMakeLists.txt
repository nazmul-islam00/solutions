cmake_minimum_required(VERSION 3.10)
project(Solutions)

set(CMAKE_CXX_STANDARD 17)

# Include directories for header resolution
include_directories(
    AtCoder
    CodeForces_ProblemSet
    LeetCode_ProblemSet
    ProjectEuler
)

# Recursively collect all source and header files
file(GLOB_RECURSE SOURCES
    AtCoder/*.cpp
    AtCoder/*.c
    CodeForces_ProblemSet/*.cpp
    CodeForces_ProblemSet/*.c
    LeetCode_ProblemSet/*.cpp
    LeetCode_ProblemSet/*.c
    ProjectEuler/*.cpp
    ProjectEuler/*.c
)

file(GLOB_RECURSE HEADERS
    AtCoder/*.h
    AtCoder/*.hpp
    CodeForces_ProblemSet/*.h
    CodeForces_ProblemSet/*.hpp
    LeetCode_ProblemSet/*.h
    LeetCode_ProblemSet/*.hpp
    ProjectEuler/*.h
    ProjectEuler/*.hpp
)

# Add executable (main.cpp must exist at root level or adjust accordingly)
add_executable(Solutions main.cpp ${SOURCES} ${HEADERS})
