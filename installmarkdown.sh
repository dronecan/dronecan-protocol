#!/bin/sh

# Script for installing the MultiMarkdown tool (required by Protogen)

# First install multimarkdown-5
git clone https://github.com/fletcher/MultiMarkdown-5 markdown
cd markdown
git submodule init
git submodule update
make
cd build
sudo make install
