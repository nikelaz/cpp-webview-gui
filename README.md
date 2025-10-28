# C++ WebView GUI Starter Example

This repository contains the source code for the accompanying YouTube video: **coming soon**. It demonstrates a modern C++ desktop app using [webview/webview](https://github.com/webview/webview) for cross-platform GUI and [nlohmann/json](https://github.com/nlohmann/json) for JSON parsing.

## Features

* Cross-platform desktop GUI using WebView (Windows, macOS, Linux)
* File reading and JSON communication between JS frontend and C++ backend
* Minimal dependencies
* CMake handles fetching required libraries

## Dependencies

### Required

* CMake ≥ 3.16
* C++17 compiler
    * **Windows:** MSVC 2019+
    * **macOS:** Apple Clang
    * **Linux:** GCC ≥ 9 or Clang ≥ 11
* Node.JS (Latest LTS recommended)

### Platform-specific (when building)

| Platform | Dependencies |
|-|-|
| Windows | WebView2 Runtime (included in Windows 11) |
| macOS | WebKit via Cocoa (included in macOS) |
| Linux (GTK) |	GTK 3 or 4 and WebKitGTK development libraries (4 or 6) |

## Build Instructions

1. Clone the repository:

```
git clone https://github.com/nikelaz/cpp-webview-gui.git
cd cpp-webview-gui
```

2. Build the UI
```
cd ui
npm install
npm run build
```

2. Create a build directory in the project root and configure:
```
mkdir build
cd build
cmake ..
```

3. Build the project:
```
cmake --build .
```

The executable will be located in: `build/bin`

## Notes

* The frontend files are embedded as a header (ui/dist/index_html.h) — no external files are required.
* JavaScript communicates with C++ via WebView bindings, using JSON for argument passing.
* The project uses CMake FetchContent to automatically fetch webview and nlohmann/json.
