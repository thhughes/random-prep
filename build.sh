
echo "Cleaning Old build..." 
rm -r build
mkdir build 
echo "Begining build..."
pushd build
cmake ..
cmake --build . 
ctest --output-on-failure
popd
echo "fin"
