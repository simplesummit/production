#!/bin/bash

cd /home/jetson/production/src/painting/frontend/www
python3 -m http.server 8000 &
cd /home/jetson/production/src/painting/server
python3 /home/jetson/production/src/painting/server/server.py

