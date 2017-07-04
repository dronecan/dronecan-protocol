#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function

import argparse
import sys
import os, glob, shutil
import platform
import subprocess
import shutil

# 'Here'
BASE_PATH = os.path.join(os.path.abspath(os.path.dirname(sys.argv[0])), '..')

OUTPUT_DIR = "src"

def Call(cmd):
    # Windows requires that commands are piped through cmd.exe
    if platform.platform().lower().count('windows') > 0:
        cmd = ["cmd", "/c"] + cmd

    pipe = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)

    # Print output of commmand
    for line in iter(pipe.stdout.readline, b''):
        line = line.decode('utf-8')
        print(line.rstrip())

# Build a single protocol file
def BuildFile(xml_file):

    # Arguments to reduce noise of protogen output
    PROTOGEN_ARGS = ["--no-doxygen", "--no-markdown"]

    Call(['protogen', xml_file, OUTPUT_DIR] + PROTOGEN_ARGS)

# Clean the output directory
shutil.rmtree(OUTPUT_DIR)

# List of message classes to build
PROTOCOL_FILES = [
    "autopilot",
    "block",
    "command",
    "system",
    "telemetry"
]

for pf in PROTOCOL_FILES:
    fn = "class_" + pf + ".xml"

    fn = os.path.join("xml_src", fn)

    BuildFile(fn)
