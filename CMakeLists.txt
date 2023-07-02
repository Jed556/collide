################## HELLO WORLD ##################

# Project configuration
cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_TOOLCHAIN_FILE "../../Managers/vcpkg/scripts/buildsystems/vcpkg.cmake")
project(RPG
    VERSION 1.19.11
    DESCRIPTION "Test game"
    HOMEPAGE_URL "https://github.com/Jed556/game"
    LANGUAGES CXX
)

# Testing
include(CTest)
enable_testing()

# Setup directories
set(FOLDER_NAME ${PROJECT_NAME}-${PROJECT_VERSION}-win64)
set(CMAKE_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FOLDER_NAME}/bin)


################## INCLUDE AND LINK ##################

# Set executable output directory
set(MAIN_CPP ${CMAKE_SOURCE_DIR}/main.cpp)
file(GLOB_RECURSE SOURCE CONFIGURE_DEPENDS "src/*.h" "src/*.cpp")
list(REMOVE_ITEM SOURCE ${REMOVE_CMAKE})
add_executable(${PROJECT_NAME} ${SOURCE})

# Link libraries
find_package(unofficial-sqlite3 CONFIG REQUIRED)
find_package(raylib CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    unofficial::sqlite3::sqlite3
    raylib
    fmt::fmt-header-only
)

# Copy resources to build directory  during the process
add_custom_target(copy_files ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/res ${CMAKE_BINARY_DIR}/${FOLDER_NAME}/res
    COMMENT "Copying files during build"
)

# Add the custom target as a dependency of the main target
add_dependencies(${PROJECT_NAME} copy_files)

# Set the language for the target
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)


################## PACKAGE ##################

# Setup package
set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}-${PROJECT_VERSION}-win64")
set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
set(CPACK_PACKAGE_DIRECTORY ${CMAKE_BINARY_DIR}/package)
include(CPack)

# Package resources and libraries
install(DIRECTORY ${CMAKE_SOURCE_DIR}/res/ DESTINATION ${FOLDER_NAME}/res )
install(TARGETS ${PROJECT_NAME} DESTINATION ${FOLDER_NAME}/bin)
install(FILES
    $<TARGET_FILE:unofficial::sqlite3::sqlite3> 
    $<TARGET_FILE:raylib>
    $<TARGET_FILE:fmt::fmt>
    src/bin/libstdc++-6.dll
    src/bin/libgcc_s_seh-1.dll
    src/bin/freetype.dll
    DESTINATION ${FOLDER_NAME}/bin
)


################## CUSTOM TARGETS ##################

# Custom target for auto packing and running
add_custom_target(PackU
    COMMAND echo "Building the project"
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target package
)