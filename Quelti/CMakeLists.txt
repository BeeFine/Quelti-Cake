﻿# CMakeList.txt: проект CMake для QueltiLock; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("QueltiLock")

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set(CMAKE_MFC_FLAG 1)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (QueltiLock "QueltiLock.cpp"  "GUI.h" "GUI.cpp"  "Languages/languages.h" "Languages/languages.cpp" "EncryptionMethod/encryption.h" "EncryptionMethod/encryption.cpp" "EncryptionMethod/Colors/colors.h" "Colors/colors.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET QueltiLock PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.