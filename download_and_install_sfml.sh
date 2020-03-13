#!/bin/bash

# A script to download and "install" SFML 2.5.1
# By Thiago de Mendonça Mildemberger

# from https://superuser.com/questions/39751/add-directory-to-path-if-its-not-already-there
pathadd() {
    if [ -d "$1" ] && [[ ":$PATH:" != *":$1:"* ]]; then
        PATH="${PATH:+"$PATH:"}$1"
    fi
}

# based on the above function
pkgconfigpathadd() {
    if [ -d "$1" ] && [[ ":$PKG_CONFIG_PATH:" != *":$1:"* ]]; then
        export PKG_CONFIG_PATH="${PKG_CONFIG_PATH:+"$PKG_CONFIG_PATH:"}$1"
    fi
}

# if there is no wget, we could try curl, like:
# curl -s --output sfml.tar.gz https://www.sfml-dev.org/files/SFML-2.5.1-linux-gcc-64-bit.tar.gz

# Download and unpack SFML-2.5.1-linux-gcc-64-bit.tar.gz from the sfml website
wget -q -O sfml.tar.gz https://www.sfml-dev.org/files/SFML-2.5.1-linux-gcc-64-bit.tar.gz
tar -xzf sfml.tar.gz 

# Don't need it anymore
rm sfml.tar.gz 

# Temporarially jump to the newly extracted directory
pushd SFML-2.5.1/ > /dev/null

# Now we download some pkg-config files from the sfml github repo
wget -q https://raw.githubusercontent.com/SFML/SFML/2.5.1/tools/pkg-config/sfml-{all,audio,graphics,network,system,window}.pc.in

# Substitute @CMAKE_INSTALL_PREFIX@ to our current path
sed -i -- "s:@CMAKE_INSTALL_PREFIX@:$(pwd):g" sfml-*

# Remove all appaerances of @LIB_SUFFIX@
sed -i -- "s:@LIB_SUFFIX@::g" sfml-*

# Our version is 2.5.1
sed -i -- "s:@VERSION_MAJOR@:2:g" sfml-*
sed -i -- "s:@VERSION_MINOR@:5:g" sfml-*
sed -i -- "s:@VERSION_PATCH@:1:g" sfml-*

# Remove some trouble
sed -i -- "\:private:d" sfml-*
sed -i -- "\:\#.*:d" sfml-*

# Remove the .in from the filenames
for file in sfml-*
do
    mv $file $(basename -s .in $file)
done

# Add this place to the pkg-config path
sfml_dir=$(pwd)
pkgconfigpathadd $sfml_dir

# Return to where we started
popd > /dev/null

# We're done! Let's just check if pkg-config now knows where sfml lives
# pkg-config --exists sfml-all
# if [ $? -eq 0 ]; then
#     echo '----------------------------------------------------'
#     echo '         SFML was successfully installed!'
#     echo ' Now add the two following lines to your ~/.bashrc:'
#     echo '----------------------------------------------------'
#     echo 'PATH=$PATH:'"${sfml_dir}/lib/SFML"
#     echo 'export PKG_CONFIG_PATH="${PKG_CONFIG_PATH:+"$PKG_CONFIG_PATH:"}'"${sfml_dir}\"" 
#     echo '----------------------------------------------------'
#     echo '                  And then run:'
#     echo '----------------------------------------------------'
#     echo 'source ~/.bashrc'
#     echo '----------------------------------------------------'
#     echo '        After that, SFML is ready for use!'
#     echo '----------------------------------------------------'
# else
#    echo 'Something went wrong'
# fi

echo 'PATH=$PATH:'"${sfml_dir}/lib" >> "$HOME/.bashrc"
echo 'export PKG_CONFIG_PATH="${PKG_CONFIG_PATH:+"$PKG_CONFIG_PATH:"}'"${sfml_dir}\""  >> "$HOME/.bashrc"
echo 'export LD_LIBRARY_PATH="$HOME/SFML-2.5.1/lib:$LD_LIBRARY_PATH"' >> "$HOME/.bashrc"

source ~/.bashrc
