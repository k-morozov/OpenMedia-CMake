#!/bin/bash

pip install conan
source ~/.profile

# conan profile new default --detect  # Generates default profile detecting GCC and sets old ABI
# conan profile update settings.compiler.libcxx=libstdc++11 default  # Sets libcxx to C++11 ABI

# conan install -s build_type=Release .. --build=missing