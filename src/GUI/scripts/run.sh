cd ..

qmake /home/node-8/test2/test2.pro -spec linux-g++ CONFIG+=qml_debug CONFIG+=force_debug_info CONFIG+=separate_debug_info && /usr/bin/make qmake_all

/usr/bin/make


