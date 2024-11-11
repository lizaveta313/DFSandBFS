cmake_minimum_required(VERSION 3.10)

# Название проекта
project(GraphProject)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 17)

# Включаем поддержку тестирования
enable_testing()

# Основной исполняемый файл
add_executable(GraphProject main.cpp Graph.cpp)

# Подключаем Google Test как подмодуль
add_subdirectory(external/googletest)

# Создаём исполняемый файл для тестов и подключаем к нему библиотеку Google Test
add_executable(GraphTests test.cpp Graph.cpp)

# Линкуем тесты с Google Test
target_link_libraries(GraphTests gtest gtest_main)

# Регистрируем тесты для автоматического запуска
include(GoogleTest)
gtest_discover_tests(GraphTests)
