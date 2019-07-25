#!/bin/bash

#Requires node version 8, ionic version 3, and cordova version 8.0.1

#Uninstall to avoid conflicts
npm uninstall -g cordova
npm uninstall -g ionic

#Install correct versions
npm install -g ionic@3.9.2
npm install -g cordova@8

#Install project dependencies
cd neuralpaint/frontend
npm install
