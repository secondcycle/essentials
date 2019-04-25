#!/bin/bash
###################################################
#  Usage : ./close_running_program.sh $inputPathWithListOfLinuxProgramsFile
#       
#  Example: ./close_running_program.sh "sl"
###################################################

TOTAL_NUM_OF_ARGS=1

logFile="$0_Logger.log"

echo -e "\n Script name : $0 \n"

#  inputPathWithListOfLinuxProgramsFile
if [ -e "$1" ]
then 
	echo -e "\n File Path With List of Linux Programs which needs to be closed - $1 \n"
	TOTAL_NUM_OF_ARGS=$(($TOTAL_NUM_OF_ARGS + 1))
	inputPathWithListOfLinuxProgramsFile=$1
else
	echo -e "\n  = $1 \n"
	exit 1
fi

echo -e "Debug: \n Total number of input arguments for the script - $2, $(($TOTAL_NUM_OF_ARGS -1)), $(($# - 1))"

# number of input arguments
if [ -n $2 ] && [ $2 -eq $(($TOTAL_NUM_OF_ARGS -1)) ] && [ $2 -eq $(($# - 1)) ]
then 
    echo -e "\n Total number of input arguments for the script - $2 \n"
else
	echo -e "\n Second argument is number of input arguments, which is not equal to number of input arguments = $2 --- $# \n "
	exit 1
fi


if [ -e  "$inputPathWithListOfLinuxProgramsFile" ]
then
	echo -e "\n FilePath with list of linux programs/processes to be closed ===> $inputPathWithListOfLinuxProgramsFile \n"
else
	echo -e "\n File "$inputPathWithListOfLinuxProgramsFile" does not exits, failed to further run the script \n "
	exit 1
fi


createFileFunc () {
	local inputFileArr=($@)
	local numOfArgs1=$2
	local totalNumberOfInputArgs=$3

	for (( i = 0; i < $numOfArgs1; i++ ));
	do
		echo -e " Create file $i of ${#inputFileArr[@]} => ${inputFileArr[$i]} "
		touch ${inputFileArr[$i]}
	done
}

deleteFileFunc () {
	local inputFileArr=($@)
	local numOfArgs1=$2
	local totalNumberOfInputArgs=$3

	for (( i = 0; i < $numOfArgs1; i++ ));
	do
		echo -e " Delete file $i of ${#inputFileArr[@]} => ${inputFileArr[$i]} "
		rm -rf ${inputFileArr[$i]}
	done
}

#local vars
inputProgramIdx=0
totalNumOfClosedLinuxProgram=0

#local files
tempAllRunningProgramInstanceFile="localProgramInstanceFile.txt"
tempPIDFile="localPIDFile.txt"
tempMatchedInstanceFile="localTempMatchedInstanceFile.txt"
tempLocalFile="localTempLocalFile.txt"

emptyFilesArr=($tempAllRunningProgramInstanceFile $tempPIDFile $tempLocalFile $tempMatchedInstanceFile)

totalNumberOfInputArgs=3
numOfArgs1=${#emptyFilesArr[@]}
createFileFunc "${emptyFilesArr[*]}" $numOfArgs1 $totalNumberOfInputArgs

ps -aux > "$tempAllRunningProgramInstanceFile"

# scale in terms of input files for packages installation, all in txt format
while read inputNameOfTheLinuxProgram
do
	echo "Within the loop $inputNameOfTheLinuxProgram search using grep ";

	grep -i "$inputNameOfTheLinuxProgram" "$tempAllRunningProgramInstanceFile" > "$tempMatchedInstanceFile";

	echo -e "GREP Success $?";

	linuxProgramInstanceCountVar=0

	echo -e "Before the loop = $inputNameOfTheLinuxProgram "

	while read linuxProgramLineInfo
	do
		echo -e "$linuxProgramLineInfo" > "$tempLocalFile"

		# get PID from awk
 		awk '{ print $2 }' "$tempLocalFile" > "$tempPIDFile"

		# redirect to a file
		# read from file to PID
		PID=''
		while read readPID;
		do
			PID=$readPID
			echo "Process ID $PID"
			kill -9 "$PID"
			echo -e "\n Closing Linux program $inputProgramIdx: \" $inputNameOfTheLinuxProgram \" With instance && PID = $PID : $linuxProgramInstanceCountVar \n"
			inputProgramIdx=$(($inputProgramIdx + 1))
			linuxProgramInstanceCountVar=$(($linuxProgramInstanceCountVar + 1))
			totalNumOfClosedLinuxProgram=$(($totalNumOfClosedLinuxProgram + 1))
		done<"$tempPIDFile"

	done<"$tempMatchedInstanceFile"

	echo -e "Outside the loop "

done<"$inputPathWithListOfLinuxProgramsFile"


filesToDeleteArr=($tempAllRunningProgramInstanceFile $tempPIDFile $tempMatchedInstanceFile $tempLocalFile)
totalNumberOfInputArgs=3
numOfArgs1=${#filesToDeleteArr[@]}
deleteFileFunc "${emptyFilesArr[*]}" $numOfArgs1 $totalNumberOfInputArgs

echo -e "\n Total number of closed linux program = $totalNumOfClosedLinuxProgram  !!! \n"