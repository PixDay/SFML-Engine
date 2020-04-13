#!/bin/bash

function main()
{
    if [[ $1 = "update" ]]; then
        update
    elif [[ $1 = "--help" ]]; then
        help
    elif [[ $1 = "create" ]]; then
        create_project $2
    elif [[ $1 = "uninstall" ]]; then
        sudo /bin/SFML-Engine/installer.sh
    fi
}

function update()
{
    cd /bin/SFML-Engine
    sudo git pull
    echo "Engine updated"
    cp script/parameter.sh /bin/SFE
    sudo chmod 777 /bin/SFE
    echo "SFE updated"
    cd
}

function help()
{
    echo "SFE command :"
    echo "    --help : show you the different available commands"
    echo "    update : updating the SFML-Engine and the SFE commands (can ask for password)"
    echo "    create [name] : create a directory with the given name that will contain the default file project for the SFML-Engine"
    echo "    uninstall : will execute the first installer programe used to install this command so you can uninstall the engine"
}

function create_project()
{
    mkdir $1
    cd $1
    cp -r /bin/SFML-Engine/* .
    rm installer.sh
    rm -rf script
    rm LICENSE
    rm README.md
    cd ..
    echo "SFML-Engine project created !"
}

main $1 $2