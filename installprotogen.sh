#!/bin/sh

# Qt build tools
sudo apt-get install qt5-default

git submodule init && git submodule update

cd ProtoGen
qmake ProtoGen.pro
make