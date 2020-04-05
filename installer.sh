#!/bin/bash

function main()
{
    clear
    ascii
    ask_user
    if [ $choice = "install" -o $choice = "i" ]; then
        install
    elif [ $choice = "uninstall" -o $choice = "u" ]; then
        uninstall
    fi
}

function ascii()
{
    echo -e "\e[36m"
    cat script/ascii.txt
    echo -e "\e[39m"
}

function ask_user()
{
    echo "Hi gamer ! And welcome to the SFML - Engin installer script "
    echo -n "What would you like to do ? install or uninstall (i or u) : "
    read choice
    if [ $choice != "i" -a $choice != "u" -a $choice != "install" -a $choice != "uninstall" -a $choice != "quit" ]; then
        echo "Sorry I don't understand try again with 'i' to (install) or 'u' to (uninstall)"
        ask_user
    fi

}

function install()
{
    sudo mkdir /bin/SFML-Engine
    sudo cp -r . /bin/SFML-Engine
    sudo cp script/parameter.sh /bin/SFE
    sudo chmod 777 /bin/SFE
    rm -rf *
    rmdir ../SFML-Engine
    echo "Installation completed ! you can now use SFE command to use the engine you can see the documentation online or use SFE --help"
}

function uninstall()
{
    sudo rm -rf /bin/SFML-Engine
    sudo rm /bin/SFE
    echo "Engine removed from computer !"
}

main