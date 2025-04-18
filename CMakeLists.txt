# CMakeLists.txt
cmake_minimum_required(VERSION 3.15)
project(IBSOM_DayCount LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Boost
find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS} include)

# Library
file(GLOB LIB_SRC src/*.cpp)
add_library(daycount STATIC ${LIB_SRC})

# Tests
enable_testing()
file(GLOB TEST_SRC tests/*.cpp)
add_executable(daycount_tests ${TEST_SRC})
target_link_libraries(daycount_tests daycount Boost::boost)
add_test(NAME DayCountTest COMMAND daycount_tests)
