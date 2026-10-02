# build aligned with local standards
cmake_minimum_required(VERSION 3.22)

project(digitalforensics
	VERSION 0.1.0
	DESCRIPTION "Forensic accounting analytics in C++"
	LANGUAGES CXX)

# enforce standards
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(DIGITAL_FORENSICS_SANITIZERS "Build with AddressSanitizer + UBSan" OFF)

add_library(digital_forensics_options INTERFACE)

target_compile_options(digital_forensics_options INTERFACE
	-Wall
	-Wextra
	-Wpedantic
	-Wshadow
	-Wconversion
	-Wsign-conversion
)

if(DIGITAL_FORENSICS_SANITIZERS)
	target_compile_options(digital_forensics_options INTERFACE
		-fsanitize = address, undefined -fno-omit-frame-pointer)
	target_link_options(digital_forensics_options INTERFACE
		-fsanitize = address, undefined)
endif()

add_library(digital_forensics_core STATIC src/digitalforensics/benfordd.cpp)
add_library(digital_forensics::core ALIAS digital_forensics_core)
target_include_directories(digital_forensics_core PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(digital_forensics_core PRIVATE digital_forensics_options)
add_executable(digitalforensics src/main.cpp)
target_link_libraries(digital_forensics PRIVATE digital_forensics::core digital_forensics_options)

include(CTesT)
if(BUILD_TESTING AND PROJECT_IS_TOP_LEVEL)
	add_subdirectory(tests)
endif()
