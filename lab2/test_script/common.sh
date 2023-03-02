#Defining colors for output...
RED='\033[0;31m'
LIGHT_RED=\e[91m
GREEN='\033[0;32m'
DARKGREEN='\033[0;32m \e[1m'
YELLOW='\e[33m'
CYAN='\e[36m'
FADEDCYAN='\e[36m'
DARK_LIGHT_BLUE='\e[94m'
LIGHT_BLUE='\e[94m'
NO_COL='\033[0m'

#Declaring some of the global variables 
compiler="compiler"
runningTestCases="ALL"

flag_compile="true"
flag_specificTest="false"
flag_specificCompiler="false"
flag_skipClean="true"
flag_noMenu="false"
flag_fast="false"
flag_onlyTrees="false"
flag_fullPath="false"
flag_onlyErrors="false"
flag_skipSemantic="false"
flag_help="false"
flag_ExtraHelp="false"
flag_RunInterpreter="false"
flag_ForceGenerateJavaOutput="false"

#declare error codes
SUCCESS=0 
LEXICAL_ERROR=1 
SYNTAX_ERROR=2 
AST_ERROR=3 
SEMANTIC_ERROR=4 
SEGMENTATION_FAULT=139 
ASSERT=134

specific_test_case_regex='^-([1-9]+[0-9]*)$'
illegal_case_regex='^-.*$'

#Declaring global variables for paths
test_suit_root="./"
test_valid_path="${test_suit_root}test_files/valid/"
test_syntax_errors_path="${test_suit_root}test_files/syntax_errors/"
test_semantic_errors_path="${test_suit_root}test_files/semantic_errors/"
temp_dotfiles_dir="${test_suit_root}temp_dot_files/"
temp_java_output="${test_suit_root}temp_java_output/"
temp_dotfiles_valid_dir="${temp_dotfiles_dir}valid/"
temp_dotfiles_syntax_dir="${temp_dotfiles_dir}syntax/"
temp_dotfiles_semantic_dir="${temp_dotfiles_dir}semantic/"

#Global variables
tree_dotfile_is_created="true"
CFGs_dotfile_is_created="true"
syntax_test_succeeded="false"
semantic_test_succeeded="true"

declare -a test_to_run_arr
test_counter=0
for arg in "$@"
do
    printf "\"$arg\"\n"

    if [[ "$arg" == "-s" && "$flag_compile" == "true" ]];
    then
        flag_compile="false"

    elif [[ "$arg" == "-c" && "$flag_skipClean" == "true" ]];
    then
        flag_skipClean="false"

    elif [[ "$arg" == "--NOMENU" && "$flag_noMenu" == "false" ]];
    then
        flag_noMenu="true"   

    elif [[ "$arg" == "-f" && "$flag_fast" == "false" ]];
    then
        flag_fast="true"
        flag_noMenu="true"  

    elif [[ "$arg" == "-t" && "$flag_onlyTrees" == "false" ]];
    then
        flag_noMenu="true"
        flag_onlyTrees="true"    
        flag_fast="true"    
        flag_skipSemantic="true"
    
    elif [[ "$arg" == "-p" && "$flag_fullPath" == "false" ]];
    then
        flag_fullPath="true"

    elif [[ "$arg" == "-h" && "$flag_help" == "false" ]];
    then
        flag_help="true"

    elif [[ "$arg" == "-hh" && "$flag_ExtraHelp" == "false" ]];
    then
        flag_ExtraHelp="true"

    elif [[ "$arg" == "-e" && "$flag_onlyErrors" == "false" ]];
    then
        flag_onlyErrors="true"
    
    elif [[ "$arg" == "-ss" && "$flag_skipSemantic" == "false" ]];
    then
        flag_skipSemantic="true"
    
    elif [[ "$arg" == "-r" && "$flag_RunInterpreter" == "false" ]];
    then
        flag_RunInterpreter="true"
        
     
    elif [[ "$arg" == "-j" && "$flag_ForceGenerateJavaOutput" == "false" ]];
    then
        flag_ForceGenerateJavaOutput="true"
        flag_RunInterpreter="true"
    
    elif [[ "$arg" == "-l" ]]; #
    then
        printf "\n\n${NO_COL}Listing all the tests found in the test folders:${NO_COL}\n\n"
        counter=1;
        printf "\nValid Tests :\n" ;
        for file in $test_valid_path*;
        do
            printf "\t[$counter]$file \n";
            ((counter=counter+1))
        done

        printf "\n[$counter]Syntax Error Tests :\n" ;
        for file in $test_syntax_errors_path*;
        do
            printf "\t[$counter]$file \n";
            ((counter=counter+1))
        done
    
        printf "\nSemantic Error Tests :\n" ;
        for file in $test_semantic_errors_path*;
        do
            printf "\t[$counter]:$file \n";
            ((counter=counter+1))
        done

        exit 

    elif [[ $arg =~ $specific_test_case_regex ]]; 
    then
        runningTestCases="${BASH_REMATCH[1]}"
        test_to_run_arr[$test_counter]=$runningTestCases
        ((test_counter=test_counter+1))
        flag_specificTest="true"

    elif [[ $arg =~ $illegal_case_regex ]];
    then
        printf "\n\n${RED}Argument '$arg' is either already used or an undefined flag.${NO_COL}\n\n "
        exit
    elif [[ "$flag_specificCompiler" == "false" ]];
    then
        compiler=$arg 
        flag_specificCompiler="true"
        printf "Using this compiler: \"$compiler\"\n "
    else 
        printf "\n\n${RED}Compiler/executable flag was already defined. Dont send in multiple compilers to be used...${NO_COL}\n\n"
        exit
    fi;

done


get_line_from_file() {
    file_to_get_line_from="$1"
    line=$2

    line_from_file="$(sed "${line}q;d" $file_to_get_line_from | sed -E 's/^\s*(.*)/\1/g')"
    
    echo "Line[$line]: $line_from_file"
}

get_line_from_string() {
    string_to_get_line_from="$1"
    line=$2

    # TODO: prestanda optimera denna... Vi öppnar filen varje gång vi anropar funktionen... 
    #       Bättre att skicka in var="$(cat $file_to_get_line_from )" och sedan utföra 
    #       operationen på strängen var... 

    line_from_file="$(printf "$string_to_get_line_from" | sed "${line}q;d" | sed -E 's/^\s*(.*)/\1/g')"
    
    echo "Line[$line]: $line_from_file"
}

output_recorder () { #arg1:string to print; arg2:string is in optional info view...


    tempOutput="$1"
    #record_output+="$tempOutput"

    if [[ -n "$2" ]];
    then
        if [[ "$2" == "$semantic_output" ]];
        then
            record_output_withExtra_semantic+="$tempOutput"
            #record_output_withExtra_semantic_wlines+="$tempOutput"
        elif [[ "$2" == "$semantic_output_wlines" ]];
        then            
            record_output_withExtra_semantic_wlines+="$tempOutput"
                    
        elif [[ "$2" == "$syntax_output" ]];
        then
            record_output_withExtra_syntax+="$tempOutput"
        elif [[ "$2" == "$valid_output" ]];
        then
            record_output_withExtra_valid+="$tempOutput"
            #record_output_withExtra_valid_wlines+="$tempOutput"

        elif [[ "$2" == "$valid_output_wlines" ]];
        then
            record_output_withExtra_valid_wlines+="$tempOutput"
            
        fi;
        
    else
        
        record_output+="$tempOutput"
        record_output_withExtra_syntax+="$tempOutput"
        record_output_withExtra_semantic+="$tempOutput"
        record_output_withExtra_semantic_wlines+="$tempOutput"
        record_output_withExtra_valid+="$tempOutput"
        record_output_withExtra_valid_wlines+="$tempOutput"        
        printf "$tempOutput";
    fi;
}

menu_system () {

    printf "\nMENU\n==============================================.\n";
    printf "Type ${DARK_LIGHT_BLUE}id${NO_COL} to inspect the output for a given test.\n";
    printf "Type ${DARK_LIGHT_BLUE}m${NO_COL} to show default result screen\n";
    # printf "Type ${DARK_LIGHT_BLUE}A${NO_COL} to show semantic errors for valid tests\n";
    printf "Type ${DARK_LIGHT_BLUE}g${NO_COL} to show syntax error fail test details\n";
    printf "Type ${DARK_LIGHT_BLUE}s${NO_COL} to show semantic fail test details\n";
    printf "Type ${DARK_LIGHT_BLUE}q${NO_COL} to exit \n";

    if [ -n "$1" ];
    then
        printf "Error: $1\n"
    fi;

    read  -p "Output selection: " user_input

    printf "\n==============================================\n";

    if [[ "$user_input" == "q" ]];
    then
        printf "\n";
        exit;
    elif [[ "$user_input" == "m" ]];
    then
        printf "$record_output";
        menu_system
    elif [[ "$user_input" == "s" ]];
    then
        printf "$record_output_withExtra_semantic";
        menu_system
    elif [[ "$user_input" == "ss" ]];
    then
        printf "$record_output_withExtra_semantic_wlines";
        menu_system
    elif [[ "$user_input" == "g" ]];
    then
        printf "$record_output_withExtra_syntax";
        menu_system
    elif [[ "$user_input" == "a" ]];
    then
        printf "$record_output_withExtra_valid";
        menu_system
    elif [[ "$user_input" == "aa" ]];
    then
        printf "$record_output_withExtra_valid_wlines";
        menu_system
    else
        if [ $user_input -gt 0 ];
        then        
            if [ $user_input -lt $((nrOfTests+1)) ];
            then
                printf "\n\nThe file below is: [$user_input]:${outputFileList[$user_input]}\nvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv^\n\n"
                printf "${outputList[$user_input]}"
                printf "\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\nThe above file is: [$user_input]:${outputFileList[$user_input]} \n"
                menu_system
            else
                menu_system "user input: \"$user_input\" <-- is invalid"
            fi;
        else
            menu_system "user input: \"$user_input\" <-- is invalid"
        fi;

    fi;

}