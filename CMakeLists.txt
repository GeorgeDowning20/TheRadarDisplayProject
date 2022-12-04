cmake_minimum_required(VERSION 3.10)
project(Radar-project)

find_package(X11)

add_executable(Radar 	src/main.cpp 
						Radar/Aircraft/Aircraft.cpp
						Radar/Airspace/Airspace.cpp
						Radar/RadarDisplay/RadarDisplay.cpp
						Radar/Pixel/Pixel.cpp
						Radar/Icon/Icon.cpp
						Radar/Radar.cpp
						 )


target_link_libraries(Radar
	${X11_LIBRARIES}
	)