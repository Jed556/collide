<div align="center">
  <a href="#"><img src="src/res/images/title.png?raw=true"></a>
  <br>
  <a href="https://github.com/Jed556/collide/releases"><img alt="GitHub release (latest, including pre-releases)" src="https://img.shields.io/github/v/release/Jed556/collide?include_prereleases&color=4686ff&logo=github&logoColor=white&label=latest"></a>
  <a href="https://github.com/Jed556/collide/releases"><img alt="GitHub downloads" src="https://img.shields.io/github/downloads/Jed556/collide/total?label=downloads&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABAAAAAQCAYAAAAf8/9hAAAACXBIWXMAAA7EAAAOxAGVKw4bAAAA2klEQVQ4jZ2SMWpCQRCGv5WHWKQIHsAj5Ah2IR7ByhvYpUiVxkqipPCE5gKKBB5Y+KXIIzzXWX3mh2FhZ/5vZ3YXAqkzdavumtiqs6g2MvfV2kvVaj+v7wWMChgE+4MmdxMQ7RVz14r/Dbirg7+Z1BHw2ERJT+oe2KeUvs4y6ntw8yUtLtAq6rqDeaPG/XWAlM0Z5KOzWZ2owwCybJk/c7M6VCf4+0XHhU5e1bfoZHWs1hVwInjflBLA6vrAnCrgADyrxwZGa83Va60vwCGpU2ADPNw4Ldc3MP8Bk60okvXOxJoAAAAASUVORK5CYII="></a>
</div>
</h1>

<p align="center">
  Random open-world RPG game and game engine test with Raylib and C++
</p>

<details open>
  <summary><h2>Installation</h2></summary>

### Dependencies
Dependencies needed for building from source:
- [Visual Studio Code](https://code.visualstudio.com)
- [Msys2](https://www.msys2.org)
- [Git](https://git-scm.com)
- [CMake](https://cmake.org)
- [vcpkg](https://vcpkg.io) (installed in [setup](#setup))

### Setup
The following instructions are for Windows with Visual Studio Code and CMake Tools extension. Other IDEs and platforms may require different steps.
1. Clone the following repositories to your local machine
```bash
git clone https://github.com/Jed556/collide.git
```
```bash
git clone https://github.com/Microsoft/vcpkg.git
```
2. Open the `vcpkg` folder in Visual Studio Code and install the extensions `ms-vscode.cpptools`, `twxs.cmake`, and `ms-vscode.cmake-tools`.
3. In the `vcpkg` folder, run the following command to build vcpkg.
```bash
.\bootstrap-vcpkg.bat
```
4. In the `vcpkg` folder, run the following command to install the required packages.
```bash
./vcpkg install fmt:x64-windows raylib:x64-windows
```
> **Note**<br>
> Please refer to the [vcpkg documentation](https://vcpkg.io/en/getting-started.html) for more information on how to setup vcpkg and install packages.

### Build
1. Open the `collide` folder in Visual Studio Code.
2. Allow the **CMake Tools** extension to configure the project. CMake Tools will automatically include the required dependencies through vcpkg.
3. Select the **CMake: Build** command from the command palette. With the target `PackU` selected, this will build the project and pack the program inside `build/package`.

</details>

## Download
Check [**Releases**](https://github.com/Jed556/collide/releases) page and install the latest [**Collide.zip**](https://github.com/Jed556/collide/releases) release.


## Controls
- **W**: Move up
- **A**: Move left
- **S**: Move down
- **D**: Move right
- **Q**: Previous character
- **E**: Next character
- **F1**: Toggle debug mode