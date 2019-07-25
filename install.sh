#!/bin/bash

USER=jetson
SDNAME=PRODSD
PROJECTNAME=production
SOURCE=/home/$USER/media/$USER/$SDNAME/$PROJECTNAME/src
HOME=/home/$USER/media/$USER/$SDNAME/$PROJECTNAME

#Dependencies
sudo apt-get install -y libblas-dev liblapack-dev libatlas-base-dev gfortran libjpeg-dev zlib1g-dev libfreetype6-dev
sudo apt-get install -y qt5-default wmctrl
sudo apt-get install -y qtbase5-private-dev qtdeclarative5-private-dev


#Install Node 8
curl -sL https://deb.nodesource.com/setup_8.x | sudo -E bash -
sudo apt-get install -y nodejs
sudo apt-get install -y npm

#Install Ionic 3
sudo npm install -g ionic@3

#Install Cordova 8
sudo npm install -g cordova@8.1.1

#Install frontend packages
cd $SOURCE/painting/frontend
sudo rm -rf node_modules
npm install


#Get Server Checkpoints (SPADE)
cd $SOURCE/painting/server/checkpoints
ggID='12gvlTbMvUcJewQlSEaZdeb2CdOB-b8kQ'
ggURL='https://drive.google.com/uc?export=download'
filename="$(curl -sc /tmp/gcokie "${ggURL}&id=${ggID}" | grep -o '="uc-name.*</span>' | sed 's/.*">//;s/<.a> .*//')"
getcode="$(awk '/_warning_/ {print $NF}' /tmp/gcokie)"
curl -Lb /tmp/gcokie "${ggURL}&confirm=${getcode}&id=${ggID}" -o "${filename}"
tar xvf checkpoints.tar.gz

#GUI

cd $SOURCE/libs
git clone https://github.com/qt/qtgamepad.git
cd qtgamepad
sudo qmake
sudo make
sudo make install

#BUILD ALL APPS
cd $SOURCE/painting/frontend
ionic cordova build browser --prod --release

cd $SOURCE/GUI
sudo qmake
sudo make
sudo make install

cd $SOURCE/smoke
sudo make clean
sudo make

cd $SOURCE/particles
sudo make clean
sudo make

#Install and Compile PyTorch (takes a long time)
cd $SOURCE/libs
git clone --recursive http://github.com/pytorch/pytorch
cd pytorch
export USE_NCCL=0
export USE_DISTRIBUTED=0
export TORCH_CUDA_ARCH_LIST="5.3;6.2;7.2"
sudo apt-get install python-pip cmake
sudo python3 -m pip install -U pip
sudo python3 -m install -U setuptools
sudo python3 -m install -r requirements.txt
sudo python3 -m pip install scikit-build --user
sudo python3 -m pip install ninja --user
python3 setup.py bdist_wheel
sudo python3 setup.py install --user

#Install Pillow Library
cd $SOURCE/libs
git clone https://github.com/python-pillow/Pillow.git
cd Pillow
sudo python3 setup.py install

#Install server dependencies
cd $SOURCE/painting/server
sudo python3 -m pip install -r requirements.txt

echo 'Install Finished!'
