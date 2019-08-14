
#### CMake build for Unix (OSX and Linux)

# Create folder for build
mkdir -p build
cd build

# Generate Unix Makefiles
cmake .. -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles"

# Build project
make
