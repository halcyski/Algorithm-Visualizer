cmake_minimum_required(VERSION 3.10)

project(SortingVisualizer VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SFML_DIR "C:/Libraries/SFML-2.6.1/lib/cmake/SFML")
set(TGUI_DIR "C:/Libraries/TGUI-1.6/lib/cmake/TGUI")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
find_package(TGUI REQUIRED)

