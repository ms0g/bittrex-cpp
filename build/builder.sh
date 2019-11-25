CMAKE_PARAMS="-DCMAKE_BUILD_TYPE=RelWithDebInfo"

BUILDROOT=$(pwd)

mkdir -p build_temp
cd build_temp || { echo "Failure:Wrong path"; exit 1; }

NUMPROC=$(nproc)

echo "Build root: $BUILDROOT"
echo "Cores:      $NUMPROC "

cmake $CMAKE_PARAMS "$BUILDROOT/.." && cmake --build . -- -j"$NUMPROC"

