#!/bin/bash

###################################################
#  Usage : ./common_installation_commands.sh $inputFilePathList
#       
#  Example: ./common_installation_commands.sh "/home/lenovo/Installers/common_libs_installer_script/list_of_installer_txt_files.txt"
###################################################

TOTAL_NUM_OF_ARGS=0

installationRunLogFile="$0_logFile.log"

echo -e "\n Script name : $0 \n"

# src path
if [ -e "$1" ]
then 
        echo -e "\n File with Input file paths with list of apt packages in ubuntu - $1 \n"
        TOTAL_NUM_OF_ARGS=$(($TOTAL_NUM_OF_ARGS + 1))
        inputFilePathList=$1
else
        echo -e "\n First argument is Input file paths with list of apt packages in ubuntu, which is not a valid file = $1 \n"
		exit 1
fi

# number of input arguments
if [ -n $2 ] && [ $2 -eq $TOTAL_NUM_OF_ARGS ] && [ $2 -eq $(($# - 1)) ]
then 
        echo -e "\n Total number of input arguments for the script - $2 \n"
else
        echo -e "\n Second argument is number of input arguments, which is not equal to number of input arguments = $2 --- $# \n "
        exit 1
fi

inputFileIdx=1
totalNumOfPackagesInstalled=0

# scale in terms of input files for packages installation, all in txt format
while read pathOfPackageFile;
do

	if [ -e  "$pathOfPackageFile" ]
	then
			echo -e "\n Installing listed packages in the file ===> $inputFileIdx : $pathOfPackageFile \n"
	else
			echo -e "\n File "$pathOfPackageFile" does not exits, failed to install \n ">>$installationRunLogFile
	fi

	packageCountVar=1
	while read installPackageName;
	do 
		echo -e "\n Installing .... package number $packageCountVar : $installPackageName \n"

		sudo apt-get install -y $installPackageName
		
		packageCountVar=$(($packageCountVar + 1))
		
		totalNumOfPackagesInstalled=$(($totalNumOfPackagesInstalled + 1))

	done<$pathOfPackageFile

	inputFileIdx=$(($inputFileIdx + 1))

done<$inputFilePathList

echo -e "\n Update in progress ..............\n"

sudo apt-get dist-upgrade

sudo apt-get update

echo -e "\n Total $totalNumOfPackagesInstalled number of linux packages installed !!! \n"