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

