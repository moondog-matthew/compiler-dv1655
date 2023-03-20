#!/bin/bash

# Originally developed by Lowe Raivio

# PATH="/usr/local/opt/grep/libexec/gnubin:$PATH" 
source test_script/common.sh
source test_script/valid.sh
source test_script/syntax.sh
source test_script/semantic.sh

main() {

DESC_FLAG_H="Shows information on how to use the test script, without runing it...\n"
DESC_FLAG_H_H="Shows detailed information on how to use the tes script, without running it...\n"
DESC_FLAG_T_ESTCASE="Run the script for any number of given tests.\n"
DESC_FLAG_L_IST="List all tests in the test folders.\n"
DESC_FLAG_FAST="Quickly run all tests. It skips menu interaction and it does not print line errors.\n"
DESC_FLAG_SKIP_SEMANTIC="Disables the semantic checking. Semantic check is slow, so you might want to skip.\n"
DESC_FLAG_E_RRORS_ONLY="Show only tests that fail.\n"
DESC_FLAG_P_ATHS="Show full paths to test-files.\n"
DESC_FLAG_MENU="Run program once without prompting the menu.\n"

    if [[ "$flag_ExtraHelp" == "true" ]]; then
        printf "\nInstructions:  ./run_tests.sh [OPTIONS]\n\
DESCRIPTION: \n\
        ${DARKGREEN}Overview:${NO_COL}\n\
            This script will use the makefile to compile (if not telled otherwise)\n\
            the compiler and then use the compiler to compile a set of given\n\
            .java-files. The first time the script is run it will generate a\n\
            required folder struture that will be used to store the java test files,\n\
            the AST and CFG .pdf-files and their respective dot-files.\n\
            In order for the script to successfully generate the folder structure\n\
            make sure that there is no folder in the project root named any of \n\
            the following before running the script: \n\
                tests\n\
                trees\n\
                temp_dot_files\n\n\
            Note that it is up to the user to fill the test folders with test-files.\n\
            For all Java-files in the test folders a indication for wether\n\
            the test FAILED or SUCCEEDED will be reported next to the test-file\n\
            name in the script output. This script checks three types of tests;\n\
            Valid tests, Syntax tests and Semantic tests. \n\
            Any valid test will be reported as FAILED if it contains a syntax\n\
            or semantic error.\n\
            Syntax tests will be reported as FAILED if it is does not report any syntax error\n\
            Semantic tests will be reported as FAILED if it does not contain any \n\
            semantic errors. \n\n\
            The folders: \n\
                tests:  \n\
                    Contains subfolders where the the user can store any \n\
                    number of test in order to quickly validated them. \n\n\
                tests/valid:\n\
                        Any Test in this folder will result in FAILURE if \n\
                        it contains either syntax and/or semantic errors.\n\n\
                tests/syntax_error:        \n\
                        Any Test in this folder will result in FAILURE if \n\
                        it does not trigger a syntax error.\n\n\
                tests/semantic_error:        \n\
                        Any Test in this folder will result in FAILURE if \n\
                        it does not trigger a Semantic error.\n\n\
                trees:\n\
                    Will store the AST and CFG trees generated as .pdf-files. \n\n\
                temp_dot_files:\n\
                    Will store AST and CFG as .dot-files. Main purpouse for \n\
                    storing the .dot-files is to improve script performance.\n\n\
        ${DARKGREEN}What is semantic/syntax errors?${NO_COL}\n\
            syntax errors refers to the errors caused by invalid syntax, i.e.\n\
            all errors triggered by the syntax and lexical analysis.\n\
            semantic errors refers to the errors found during semantic analysis.\n\n\
        ${DARKGREEN}How to check if the semantic error is what you expect it to be?${NO_COL}\n\
            When you run a invalid semantic .java-testfile the script will notify \n\
            you wether or not the script triggered a semantic error or not. \n\
            This is useful if you have alot of java-test files where each test\n\
            only contain one semantic error. However in that scenario you must manually\n\
            check that  the error your compiler detects also is the error that should\n\
            be triggered. Instead of checking this manually you can let the script \n\
            do it for you! Simply add a special comment that start with the keyword \n\
            'fail' after the line in the java testfile that contains the semantic \n\
            rule break. Here's a demonstration of how such line in your java test\n\
            file could look like: \n\
                ${GREEN}...//some code here\n\
                ${DARK_LIGHT_BLUE}int ${LIGHT_BLUE}a;\n\
                ${DARK_LIGHT_BLUE}int ${LIGHT_BLUE}a;${GREEN}//fail Already Declared variable: a\n\
                ${GREEN}...//some code here${NO_COL}\n\
            In the example above the semantic error generated by our compiler would\n\
            be 'Already Declared variable: a', unless our compiler prints this error\n\
            for this line the script will assume that your compiler doesnt work as\n\
            you intended and it will now notify you that this testfile failed.\n\
            If you have a line in your testfile that contains multiple errors you can\n\
            include them by adding several '//fail' comments on the same line, \n\
            this is demonstrated below: \n\
                ${GREEN}...//some code here\n\
                ${DARK_LIGHT_BLUE}int ${LIGHT_BLUE}a1;\n\
                ${DARK_LIGHT_BLUE}boolean ${LIGHT_BLUE}d1;\n\
                ${LIGHT_BLUE}a1 ${FADEDCYAN}= ${LIGHT_BLUE}d1 ${FADEDCYAN}&& ${LIGHT_BLUE}d1;${GREEN}//fail d1: is of wrong type //fail a1 and expression d1 && d1  are of different types\n\
                ${GREEN}...//some code here${NO_COL}\n\
            Note that if a line have multiple errors then either no '//fail' comment can \n\
            be used or all errors on that line must be declared in the '//fail comment'.\n\
            Note that if you omit all '//fail' comment the test will always result \n\
            in a SUCCEED as long as atleast one semantic error exists. \n\
            \n\
        ${DARKGREEN}The interactive script CLI:${NO_COL}\n\
            with the interactive CLI you can get more information of the tests, \n\
            this includes the whole (your) compiler output of any given test-file.\n\
            Given that you configured your compiler accordingly you should \n\
            also be able to view more details about semantic/syntax errors\n\
            and even where in the test-file the error occoured. \n\n\
        ${DARKGREEN}How to get Semantic Errors listed by the script:${NO_COL}\n\
            The only thing you have to do is to make sure your compiler outputs\n\
            all the semantic errors (seperated, one per line) and to add a \n\
            *specific string* of letters before and after the list of semantic \n\
            errors is printed. Infront of the outputed list there must the following\n\
            'StartOfErrors:' followed by a new line. At the end of the list there\n\
            must be the following 'EndOfErrors'.\n\
            Here is an example of what the output from your compiler should contain:\n\
                StartOfErrors:\n\
                Error[32]: some semantic error you printed that occoured on line 32\n\
                Error[35]: some other semantic error that was triggered on line 35\n\
                EndOfErrors\n\
            In order for the script to show whats on that line in the .java test file\n\
            it is important that the error is given with this specific syntax.\n\
            Specifically that we have the keyword 'Error' followed by brackets  \n\
            containing the linenumber wehre the error occoured, followed by the \n\
            semantic error message. in case you are curious or just know your \n\
            regex, here is the one used to fetch the linenumber (capture group 1)\n\
                .*Error\[\s*([0-9]*)\].*  \n\
            \n\
        ${DARKGREEN}How to get the AST and CFGs trees to be generated by the script.${NO_COL}\n\
            The only thing you need to do is to make sure that your compiler generates\n\
            dot-files for both the AST and CFGs. These files should be named :\n\
                tree.dot    for the AST\n\
                CFGs.dot    for the CFGs\n\
            Note that the CFGs you generate when constructing the intermediate \n\
            representation all needs to be in one single .dot-file for the script\n\
            to generate them. \n\n\
            ----\n\n\
ABOUT THE FLAGS:\n\
            All flags can (mostly) be used in any combination.\n\
[OPTIONS] :\n\
      -h  : ${DESC_FLAG_H}\n\
      -hh : ${DESC_FLAG_H}\
            You are here...\n\n\
  -[0-9]* : ${DESC_FLAG_T_ESTCASE}\
            Sometimes you just want the result of one or a handful of tests,\n\
            you can use this flag any number of times in order to just show  \n\
            the results of those tests. This is useful if you have alot of tests.\n\
                Examples: \n\
                    ./run_tests.sh myCompiler -6 -7 \n\
                    ./run_tests.sh -1 -5 -7 \n\n\
      -l  : ${DESC_FLAG_L_IST}\n\
      -f  : ${DESC_FLAG_FAST}\
            Use this option if you just want to make sure that no test fails, \n\
            it is useful when you dont need the functionality the menu brings\n\
            since it's faster and does not make you quit the interactive CLI \n\
            everytime you run the script...\n\
            For a even shorter list, consider combining this flag with -e flag.\n\n\
      -ss : ${DESC_FLAG_SKIP_SEMANTIC}\
            The semantic error checking is slow since it needs to do alot of file\n\
            parsing in order to check if your error occoured on a given line in \n\
            your java test file. Note that only the heavier part is skipped!\n\
            Read more aout this in the description above. \n\n\
      -e  : ${DESC_FLAG_E_RRORS_ONLY}\
            By omitting all succeeded tests you will get a very concise summary\n\
            for only the test that fails. Useful when you have alot of tests\n\
            and just want to focus on the failing cases.\n\
            Consider combining this flag with -f flag for faster result.\n\n\
      -p  : ${DESC_FLAG_P_ATHS}\
            Should not even be a option... but if you want to you can \n\
            show the whole path to a java test file in the script output. \n\n\
--NOMENU  : ${DESC_FLAG_MENU}\
            It's like the -f flag but slow, not really intended to be used \n\
            by the end user...\n\n\
\n\n"
        exit 0
    fi;
    printf "\nInstructions:  ./run_tests.sh [OPTIONS]\n\
Example: ./run_tests.sh my_compiler -4 -5 -c\n\
[OPTIONS] :\n\
      -h  : ${DESC_FLAG_H}\
      -hh : ${DESC_FLAG_H_H}\
  -[0-9]* : ${DESC_FLAG_T_ESTCASE}\
      -l  : ${DESC_FLAG_L_IST}\
      -f  : ${DESC_FLAG_FAST}\
      -ss : ${DESC_FLAG_SKIP_SEMANTIC}\
      -e  : ${DESC_FLAG_E_RRORS_ONLY}\
      -p  : ${DESC_FLAG_P_ATHS}\
--NOMENU  : ${DESC_FLAG_MENU}\
\n\n"
    if [[ "$flag_help" == "true" ]]; then
        exit 0
    fi;
    

    #Making sure required filestructured is setup
    folders_exists="true"
    if [[ ! -d "$test_suit_root" ]]; then
        folders_exists="false"

        mkdir "${test_suit_root}"        
    fi;
    if [[ ! -d "$test_valid_path" ]]; then
        folders_exists="false"

        mkdir "${test_suit_root}test_files"
        mkdir "$test_valid_path"
        mkdir "$test_syntax_errors_path"
        mkdir "$test_semantic_errors_path"
        
    fi;
    if [[ ! -d "${test_suit_root}trees" ]]; then 
        folders_exists="false"
        mkdir "${test_suit_root}trees"
        mkdir "${test_suit_root}trees/invalid"
        mkdir "${test_suit_root}trees/invalid/semantic"
    fi;
    if [[ ! -d "$temp_dotfiles_dir" ]]; then 
        folders_exists="false"
        mkdir "$temp_dotfiles_dir"
        mkdir "$temp_dotfiles_valid_dir"
        mkdir "$temp_dotfiles_syntax_dir"
        mkdir "$temp_dotfiles_semantic_dir"        
    fi;
    if [[ ! -d "$temp_java_output" ]]; then 
        folders_exists="false"
        mkdir "$temp_java_output"   
    fi;
    if [[ "$folders_exists" == "false" ]]; then  #TODO: dubbelkolla denna igen...
        printf "\n${RED}Created folder structures for tests/trees/dot-files, please add some test files! (.java)${NO_COL}\n\n"
        exit  
    fi;

    if [[ "$flag_RunInterpreter" == "true" ]]; then
        if ! command -v java; then
            printf "\n\n${RED}Java was not found! You must install Java to use this feature.${NO_COL}\n"
            printf "\t${DARK_LIGHT_BLUE}Installation guide: \n "
            printf "\tBased on your OS run one of the following lines in your terminal...\n "
            printf "\t\tUbuntu:   \n "
            printf "\t\t\tsudo apt install default-jdk  \n\n"
            printf "\t\tARCH/Manjaro:  \n"
            printf "\t\t\tsudo pacman -S jre-openjdk \n\n"
            printf "${LIGHT_BLUE}If this does not work, google 'how to install java on X' where X is your distro/OS...${NO_COL}\n "
            exit
        fi; 
    fi;
    
   
    printf "Command Used:\n===========================================================\n"
    printf "$0 $args_string\n"
    printf "nr of args: $nr_of_args\n"
    printf "===========================================================\n\n"

    #Declaring the rest of the global variables     
    syntax_output="extra_syntax"
    semantic_output="extra_semantic"
    semantic_output_wlines="extra_semantic_wlines"
    valid_output="extra_valid"
    valid_output_wlines="extra_valid_wlines"
    tempOutput="";
    record_output="";
    record_output_withExtra_syntax="";
    record_output_withExtra_semantic="";
    record_output_withExtra_semantic_wlines="";
    record_output_withExtra_valid="";
    record_output_withExtra_valid_wlines="";

    err_string="Cannot generate a syntax for this input"
    succ_string="The compiler successfuly generated a syntax tree for the given input!"
    allTestSucceeded="${DARKGREEN}All Test Succeeded!\n${NO_COL}";

    failingTestsString="Extra: \n"

    id_file=1;
    
    if [[ "$flag_compile" == "true"  ]]; then

        if [[ "$flag_skipClean" == "false" ]]; then

            printf "make clean \n===========================================================\n";
            make clean > /dev/null
            printf "===========================================================\n\n";
        else 
            printf "Skipping make clean! \n";
        fi;

        
        if [[ "$flag_specificCompiler" == "true" ]]; then
            printf "make $compiler\n===========================================================\n";
        else 
            printf "make compiler (default case)\n";
            printf "===========================================================\n";            
        fi; 

        make $compiler
        compilerErrorCode=$?

        if [[ "$flag_RunInterpreter" == "true" ]]; then
            make interpreter
        fi;
                
        if [[ $compilerErrorCode != 0 ]];
        then 
            printf "\n${RED}Cancelling script, Compiler exit code was: $compilerErrorCode ${NO_COL}\n"
            
            if [ ! -f "Makefile" ]; then
                printf "${YELLOW}Cause: Makefile is missing\n${NO_COL}"
            else 
            
                missing_make_rules="$(make -qp 2>&1 | awk '/^[a-zA-Z0-9][^$#\/\t=]*:([^=]|$)/ {split($1,A,/ /);for(i in A)print A[i]}' |     sort -u | awk '$1 ~  /compiler:|interpreter:/' | wc -l)"

            
                if [ "${missing_make_rules}" != "2" ]; then
                    printf "${YELLOW}Cause: Makefile needs to define rules for both 'compiler' and 'interpreter'\n${NO_COL}"
                else 
                    printf "${YELLOW}Cause: See make error message above\n${NO_COL}"
                fi; 
            fi;
            printf "\n"
            exit
        fi;
    else 
        printf "Skip running make\n===========================================================\n";
         
    fi; 
    printf "===========================================================\n";

    if [ ! -f "$compiler" ];
    then
        printf "\n${RED}Compier '$compiler' does not exist, did you forget to make it?\n"
        printf "Make sure that the compiler(gcc/clang) uses a '-o' with the value '$compiler', like this '-o$compiler' !\nExiting script.\n\n ${NO_COL}\n\n"
        exit 
    fi;

    #These are used in multiple fucntions of the program, thus globals...
    declare -a outputList
    declare -a outputFileList
    declare -a is_part_of_valid_tests
    declare -a files

    for file in $test_valid_path*;
    do
        is_part_of_valid_tests[$id_file]="$valid_output"
        files[$id_file]="$file"
        ((id_file=id_file+1));
    done
    if [[ "$flag_RunInterpreter" == "false" ]];then
        for file in $test_syntax_errors_path*;
        do
            is_part_of_valid_tests[$id_file]="$syntax_output"
            files[$id_file]="$file"
            ((id_file=id_file+1));
        done

        for file in $test_semantic_errors_path*;
        do
            is_part_of_valid_tests[$id_file]="$semantic_output"
            files[$id_file]="$file"
            ((id_file=id_file+1));
        done
    fi;

    #These are used in multiple fucntions of the program, thus globals...
    nrOfTests=$(($id_file - 1))    

    #Fix the number incase a folder is empty...
    if [[ -z "$(ls -A $test_valid_path)" ]];then
        nrOfTests=$(($nrOfTests - 1))
    fi;
    
    if [[ -z "$(ls -A $test_syntax_errors_path)" ]];then
        nrOfTests=$(($nrOfTests - 1))
    fi;
    if [[ -z "$(ls -A $test_semantic_errors_path)" ]];then
        nrOfTests=$(($nrOfTests - 1))
    fi;
    

    if [[ $runningTestCases != "ALL" ]]; then
        output_recorder "\nRunning following testcase: $runningTestCases\n"
        
        for ((test_case=0; test_case <= test_counter; test_case++  ))
        do 

            id_file=${test_to_run_arr[$test_case]}

            if [[ ${is_part_of_valid_tests[$id_file]} == "$valid_output" ]]; then
                if [[ "$flag_fast" == "true" ]];then
                    output_recorder "\n\nCheck Valid Test:"
                else 
                    output_recorder "\n\nCheck Valid Test (Test should succeed.):"
                fi; 
                run_validTest ${files[$id_file]};
            elif [[ ${is_part_of_valid_tests[$id_file]} == "$syntax_output" ]];
            then
                if [[ "$flag_fast" == "true" ]];then
                    output_recorder "\n\nCheck Syntax Error Test:"
                else                 
                    output_recorder "\n\nCheck Syntax Error Test (Test should succeed... press \"g\" for details):" ;
                fi; 
                runSyntaxErrorTests ${files[$id_file]};
            elif [[ ${is_part_of_valid_tests[$id_file]} == "$semantic_output" ]];                    
            then
                if [[ "$flag_fast" == "true" ]];then
                    output_recorder "\n\nCheck Semantic Error Test:"
                else                 
                    output_recorder "\n\nCheck Semantic Error Test (Test should succeed... press \"s\" for details):" ;
                fi; 
                run_invalidSemanticTest ${files[$id_file]};
            fi;

        done 

        output_recorder "\n\nFinal Status:\n\t$allTestSucceeded\n${NO_COL}";        

    else
        output_recorder "\nRunning following testcases: $runningTestCases\n"
        output_recorder "\nTotal of $nrOfTests valid and invalid tests \n"
        
        id_file=1; #resets id_file

        if [[ ! -z "$(ls -A $test_valid_path)" ]];then
            if [[ "$flag_ForceGenerateJavaOutput" == "false"  && "$flag_RunInterpreter" == "true" ]];then
                output_recorder "\n${YELLOW}OBS: Using cached java output.  ${NO_COL}"
            fi; 
            
            if [[ "$flag_fast" == "true" ]];then
                output_recorder "\n\nCheck Valid Tests:"
            else             
                output_recorder "\n\nCheck Valid Tests: (All test should succeed...):\n" ;
            fi; 
            failed_one_test="false"
            for file in $test_valid_path*;
            do
                run_validTest $file;
                #valid_test_succeeded is a global variable
                if [[ "$valid_test_succeeded" == "false" ]]; then
                    failed_one_test="true"
                fi; 
            done
            if [[ "$failed_one_test" == "false" ]]; then
                output_recorder "\n${DARKGREEN}All Valid Test succeeded!!${NO_COL}"
            fi;

        else 
            output_recorder "\n\nNo Valid tests in the $test_valid_path path, add some valid .java files to test them. " ;
        fi; 

        if [[ "$flag_RunInterpreter" == "false" ]];then
            if [[ ! -z "$(ls -A $test_syntax_errors_path)" ]];then
                if [[ "$flag_fast" == "true" ]];then
                    output_recorder "\n\nCheck syntax error Tests:"
                else             
                    output_recorder "\n\nCheck syntax error Tests: (All test should succeed...):\n${FADEDCYAN}press \"g\" for details${NO_COL}" ;
                fi; 
                failed_one_test="false"
                for file in $test_syntax_errors_path*;
                do
                    runSyntaxErrorTests $file
                    #syntax_test_succeeded is a global variable
                    if [[ "$syntax_test_succeeded" == "false" ]]; then
                        failed_one_test="true"
                    fi; 
                done
                if [[ "$failed_one_test" == "false" ]]; then
                    output_recorder "\n${DARKGREEN}All Syntax-related tests succeeded!!${NO_COL}"
                fi;
            else 
                output_recorder "\n\nNo syntax error tests in the $test_syntax_errors_path path, add some .java files to test them. " ;
            fi; 

            if [[ ! -z "$(ls -A $test_semantic_errors_path)" ]];then
                if [[ "$flag_fast" == "true" ]];then
                    output_recorder "\n\nCheck invalid semantic Tests:"
                else             
                    output_recorder "\n\nCheck invalid Semantic Tests (All test should succeed...): \n${FADEDCYAN}press \"s\" for details${NO_COL}" ;
                fi; 
                failed_one_test="false"
                for file in $test_semantic_errors_path*;
                do
                    run_invalidSemanticTest $file
                    #semantic_test_succeeded is a global variable
                    if [[ "$semantic_test_succeeded" == "false" ]]; then
                        failed_one_test="true"
                    fi; 
                done 
                if [[ "$failed_one_test" == "false" ]]; then
                    output_recorder "\n${DARKGREEN}All Invalid Semantic Test succeeded!!${NO_COL}"
                fi; 
            else 
                output_recorder "\n\nNo Invalid semantic tests in the $test_semantic_errors_path path, add some .java files to test them. " ;
            fi; 
        fi;

        output_recorder "\n\nFinal Status:\n\t$allTestSucceeded\n${NO_COL}";

         if [[ "$flag_ForceGenerateJavaOutput" == "false" && "$flag_RunInterpreter" == "true" ]];then
            output_recorder "\n${YELLOW}Using cached java output. If you make any changes to your java-test files"
            output_recorder "\nyou must update the cache, do this by running the script with the -j flag! \n${NO_COL}"
        fi; 

    fi;

    if [[ ${tree_dotfile_is_created} == "false"   ]];then
        output_recorder "\t${YELLOW}Compiler does not generate a \"tree.dot\" file! \n${NO_COL}";
    fi;

    if [[ "${CFGs_dotfile_is_created}" == "false" ]];then            
        output_recorder "\t${YELLOW}Compiler does not generate a \"CFGs.dot\" file! \n${NO_COL}";
    fi;

    if [[ "${tree_dotfile_is_created}" == "false" || "${CFGs_dotfile_is_created}" == "false" ]];then            
        output_recorder "\t${YELLOW}The dot-files are used to create the graphs. \n${NO_COL}";
    fi;

    if [[ "$flag_noMenu" == "false" ]]; 
    then 
        menu_system
    else
        exit 0
    fi 

    printf "\n";

}

main $@





