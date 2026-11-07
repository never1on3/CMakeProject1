cmake_minimum_required(VERSION 3.10)
project(CMakeProjectMain CXX)

# Собираем файлы из текущей папки
add_executable(CMakeProject1 "CMakeProject1.cpp" "CMakeProject1.h" "culc.h" "math.h")

# Выходим на уровень вверх и заходим в соседнюю папку Hospital-lab
add_subdirectory("../Hospital-lab" "Hospital-lab_build")
