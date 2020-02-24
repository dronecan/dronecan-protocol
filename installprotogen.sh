#!/bin/sh

# Qt build tools
sudo apt-get install qt5-default

git clone https://github.com/billvaglienti/ProtoGen

cd ProtoGen
qmake ProtoGen.pro
make