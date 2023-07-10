
cmake_minimum_required(VERSION 3.19)
set(GOOGLETEST_VERSION 1.11.0)
project(LP_esame_ls)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Test)
set(SOURCE_FILES ShoppingList.cpp ShoppingList.h Observer.h User.cpp User.h Subject.h Item.cpp Item.h)

add_executable(LP_esame_ls main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(LP_esame_ls core)