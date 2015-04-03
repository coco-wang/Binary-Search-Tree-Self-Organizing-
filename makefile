proj4.x: proj4_driver.o
        g++47 -std=c++11 -o proj4.x proj4_driver.o
proj4_driver.o: proj4_driver.cpp
        g++47 -std=c++11 -c proj4_driver.cpp
clean:
        rm *.o proj4.x
