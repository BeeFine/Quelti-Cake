# CMakeList.txt: проект CMake для QueltiLock; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("QueltiLock")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (QueltiLock "QueltiLock.cpp"  "GUI.h" "GUI.cpp"  "Languages/languages.h" "Languages/languages.cpp" "hash-library-master/sha3.h" "hash-library-master/sha3.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET QueltiLock PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
