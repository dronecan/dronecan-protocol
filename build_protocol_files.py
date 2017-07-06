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
    PROTOGEN_ARGS = ["--no-doxygen", "--no-markdown", '--license', 'licensetemplate']

    Call(['protogen', xml_file, OUTPUT_DIR] + PROTOGEN_ARGS)

# Create output directory if needed
if not os.path.exists(OUTPUT_DIR):
    os.mkdir(OUTPUT_DIR)
    print("Created dir '{d}'".format(d=OUTPUT_DIR))

# Clean the output directory
for f in os.listdir(OUTPUT_DIR):
    x = os.path.join(OUTPUT_DIR, f)
    os.remove(x)

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
