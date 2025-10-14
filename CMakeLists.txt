cmake_minimum_required(VERSION 3.16)
project(app LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(WEBVIEW_WEBKITGTK_API 6.0)	

include(FetchContent)

FetchContent_Declare(
    webview
    GIT_REPOSITORY https://github.com/webview/webview
    GIT_TAG 0.12.0)
FetchContent_MakeAvailable(webview)

add_executable(app WIN32)

target_sources(app PRIVATE src/main.cpp ui/dist/index_html.h)
target_include_directories(app PRIVATE ui/dist)
target_link_libraries(app PRIVATE webview::core)
