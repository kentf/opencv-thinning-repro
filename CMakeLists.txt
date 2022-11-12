cmake_minimum_required(VERSION 3.23)

project ("OpenCV-thinning-test")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")

file(GLOB SOURCES src/*.cpp)

add_executable(vcpkg-test ${SOURCES})

# Find OpenCV
find_package(OpenCV REQUIRED
	opencv_ximgproc
	)

target_link_libraries(vcpkg-test 
	PUBLIC
		opencv_ximgproc
)

if (UNIX)
	add_definitions(
		-O3
	)
endif()


# Builds two projects, one with OpenCV from vcpkg, and another one from source

# C:/Projects/opencv-thinning-test/opencv-build
