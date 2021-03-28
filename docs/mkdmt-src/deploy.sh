#!/bin/bash

rsync --exclude src/ --delete -ncav docs/ ../
echo ""
echo "** Now run 'rsync --exclude src/ --delete -cav docs/ ../'"
echo ""
