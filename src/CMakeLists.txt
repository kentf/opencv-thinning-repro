cmake_minimum_required(VERSION 3.23)

project ("OpenCV-thinning-test-github")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OpenCV_DIR "${CMAKE_SOURCE_DIR}/../opencv-build/install")

if (UNIX)
	set(OpenCV_DIR "${CMAKE_SOURCE_DIR}/../opencv-build-gcc/install/lib64/cmake/opencv4")
endif()


set(OpenCV_STATIC TRUE)

# Find OpenCV

file(GLOB SOURCES *)

add_executable(github-test ${SOURCES})

# Find OpenCV
find_package(OpenCV REQUIRED
	# core opencv_core opencv_imgcodecs opencv_imgproc 
	#opencv_calib3d
	opencv_ximgproc
	)

target_link_libraries(github-test
	PUBLIC
		opencv_ximgproc
)

if (UNIX)
	add_definitions(
		-O3
	)
endif()