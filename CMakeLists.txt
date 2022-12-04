#cmake file to build the project. The CMakeLists.txt file is a text file that contains a set of commands that instruct CMake how to build the project. 
cmake_minimum_required(VERSION 3.10)

#set the project name
project(Radar-project)

#Load the x11 package
find_package(X11)

#add directorys of the files to be compiled
add_executable(Radar 	src/main.cpp 
						Radar/Aircraft/Aircraft.cpp
						Radar/Airspace/Airspace.cpp
						Radar/RadarDisplay/RadarDisplay.cpp
						Radar/Pixel/Pixel.cpp
						Radar/Icon/Icon.cpp
						Radar/Radar.cpp
						 )


#add the include directories
target_link_libraries(Radar
	${X11_LIBRARIES}
	)