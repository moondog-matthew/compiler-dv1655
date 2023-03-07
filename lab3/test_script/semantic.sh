run_invalidSemanticTest() {
    result=$(./$compiler $1);
    runtimeErrorCode=$?
    filename=$(printf $1 | sed -En 's#.*\/([^/]+)$#\1#p')     
    test_succeeded="true"  
    #Enable fast mode, do not generate trees, compiler output only if test succeededd
    if [[ "$flag_fast" == "true" ]]; then
        if [[  $runtimeErrorCode == $SEMANTIC_ERROR ]]; then
            
            strBuffer=""
            if [[ "$flag_onlyErrors" == "false" ]];then   
                #output_recorder "\n${GREEN}[$id_file]SUCCESS: \t${NO_COL}";     
                if [[ "$flag_fullPath" == "true" ]];
                then 
                    strBuffer+="\t[$id_file]  $1";
                else 
                    strBuffer+="\t[$id_file]  $filename";
                    
                fi;     
                
            fi;
            # LOC=$(printf "$result" | grep -Pzo 'Semantic errors found! See the logs below:(.*\n)*End of semantic errors!' | sed -En 's#^(.*)#\t\1#p' | wc -l)
            # if [[ $LOC < 1 ]]; then 
            #     LOC=1 
            # fi;
            semantic_errors=$(printf "$result" | grep -Pzo 'Semantic errors found! See the logs below:(.*\n)*End of semantic errors!' | tr '\0' '\n' | sed -En 's#^(.*)#\t\1#p' )

            userDefinedErrorLines=$(getLOCOfErrorsFromFile "$1")
            compilerErrorLines=$(getLOCOfErrorsFromCompiler "$semantic_errors")

            verifySemantic "$1" "$userDefinedErrorLines" "$compilerErrorLines" "$id_file"
            # print_semantic_error_lines "$1" \
            #                         "$semantic_errors"  \
            #                         "$semantic_output"  \
            #                         "$semantic_output_wlines"   \
            #                         "GREEN"\
            #                         "\n  ↳SEMANTIC ERROR($runtimeErrorCode):"\
            #                         "$semantic_output"\
            #                         "\n${RED}[$id_file]FAILED: \t${NO_COL}${strBuffer}" \
            #                         "\n${GREEN}[$id_file]SUCCESS: \t${NO_COL}${strBuffer}"
            #Global variable set in print_semantic_error_lines function: semantic_test_did_not_fail                
            test_succeeded="$semantic_test_did_not_fail"

        else
            test_succeeded="false"
            output_recorder "\n${RED}[$id_file]FAILED:\t${NO_COL}";
            if [[ "$flag_fullPath" == "true" ]];
            then 
                output_recorder "\t[$id_file]  $1";
            else 
                output_recorder "\t[$id_file]  $filename";
            fi;
            allTestSucceeded="${RED}Some Test Failed! FAIL\n${NO_COL}"
            if [[ $runtimeErrorCode == $SEGMENTATION_FAULT ]]; then

                output_recorder "\n  ${RED}↳Segmentation Fault($runtimeErrorCode): (Not a valid fail) ${NO_COL}\n";
            fi;    
        fi;
        
        ((id_file=id_file+1));

        if [[ $runtimeErrorCode == $SYNTAX_ERROR ]]; then

            linenumber=$(printf "$result" | tail -n 2 | head -n 1 )
            output_recorder "\n${RED}  ↳SYNTAX ERROR($runtimeErrorCode)\n${NO_COL}" "$semantic_output";
            
        fi;

        if [[ $runtimeErrorCode == $SEMANTIC_ERROR ]]; then

            if [[ "$flag_onlyTrees" == "true" ]]; then

                if [[ -f "tree.dot"  ]];then
                    cp tree.dot $temp_dotfiles_semantic_dir$filename.dot
                    dot -Tpdf $temp_dotfiles_semantic_dir$filename.dot -o${test_suit_root}trees/invalid/semantic/$filename.pdf &
                else
                    tree_dotfile_is_created="false"
                fi;

                if [[ -f "CFGs.dot" ]];then
                    cp CFGs.dot $temp_dotfiles_semantic_dir$filename"(_CFGs)".dot    
                    dot -Tpdf $temp_dotfiles_semantic_dir$filename"(_CFGs)".dot -o${test_suit_root}trees/invalid/semantic/$filename"(_CFGs)".pdf &
                else
                    CFGs_dotfile_is_created="false"
                fi;
                
            fi;

            #output_recorder "\n${GREEN}  ↳SEMANTIC ERROR($runtimeErrorCode)${NO_COL}" "$semantic_output"

            #output_recorder "\n${GREEN}  ↳SEMANTIC ERROR($runtimeErrorCode): \n$semantic_errors\n${NO_COL}" "$semantic_output"
            # test_succeeded="false"    
        fi;
        # semantic_test_succeeded="$test_succeeded"
        return
    fi;

    #Full run, with all information
      
    semantic_errors=$(printf "$result" | grep -Pzo 'Semantic errors found! See the logs below:(.*\n)*End of semantic errors!' | tr '\0' '\n' | sed -En 's#^(.*)#\t\1#p' )

    outputList[$id_file]="$result"
    outputFileList[$id_file]="$1"
    last_line=$(printf "$result" | tail -n 1 );
    first_chars=${last_line:0:44}
    if [[  $runtimeErrorCode == $SEMANTIC_ERROR ]]; then
        test_succeeded="true"
        strBuffer=""
        if [[ "$flag_onlyErrors" == "false" ]];then
            #output_recorder "\n${GREEN}[$id_file]SUCCESS: \t${NO_COL}";     
            if [[ "$flag_fullPath" == "true" ]];
            then 
                strBuffer+="\t[$id_file]  $1";
            else 
                strBuffer+="\t[$id_file]  $filename";
            fi;        
      
            filename=$(printf $1 | sed -En 's#.*\/([^/]+)$#\1#p')         

            if [[ -f "tree.dot"  ]];then
                cp tree.dot $temp_dotfiles_semantic_dir$filename.dot
                dot -Tpdf $temp_dotfiles_semantic_dir$filename.dot -o${test_suit_root}trees/invalid/semantic/$filename.pdf &
            else
                tree_dotfile_is_created="false"
            fi;

            if [[ -f "CFGs.dot" ]];then
                cp CFGs.dot $temp_dotfiles_semantic_dir$filename"(_CFGs)".dot    
                dot -Tpdf $temp_dotfiles_semantic_dir$filename"(_CFGs)".dot -o${test_suit_root}trees/invalid/semantic/$filename"(_CFGs)".pdf &
            else
                CFGs_dotfile_is_created="false"
            fi;
    
        fi;

        userDefinedErrorLines=$(getLOCOfErrorsFromFile "$1")

        compilerErrorLines=$(getLOCOfErrorsFromCompiler "$semantic_errors")

        verifySemantic "$1" "$userDefinedErrorLines" "$compilerErrorLines" "$id_file"
        # echo "semanticErrors: $semantic_errors"
        # print_semantic_error_lines "$1" \
        #                             "$semantic_errors"  \
        #                             "$semantic_output"  \
        #                             "$semantic_output_wlines"   \
        #                             "GREEN"\
        #                             "\n  ↳SEMANTIC ERROR($runtimeErrorCode):"\
        #                             "$semantic_output"\
        #                             "\n${RED}[$id_file]FAILED: \t${NO_COL}${strBuffer}" \
        #                             "\n${GREEN}[$id_file]SUCCESS: \t${NO_COL}${strBuffer}"
        #Global variable set in print_semantic_error_lines function: semantic_test_did_not_fail                
        test_succeeded="$semantic_test_did_not_fail"
        
        output_recorder "${NO_COL}" "$semantic_output"
        output_recorder "${NO_COL}" "$semantic_output_wlines"
    else
        # test_succeeded="false"
        output_recorder "\n${RED}[$id_file]FAILED:\t${NO_COL}";
        if [[ "$flag_fullPath" == "true" ]];
        then 
            output_recorder "\t[$id_file]  $1";
        else 
            output_recorder "\t[$id_file]  $filename";
        fi;

        allTestSucceeded="${RED}Some Test Failed! FAIL\n${NO_COL}"
        if [[ $runtimeErrorCode == $SEGMENTATION_FAULT ]]; then
            output_recorder "\n  ${RED}↳Segmentation Fault($runtimeErrorCode): (Not a valid fail) ${last_line:45} ${NO_COL}\n";
        else
            if [[ "$flag_fast" == "false" ]]; then 
                output_recorder "\n  ${RED}↳Unexpected error code($runtimeErrorCode): No semantic errors reported!" "$semantic_output"
            fi;
        fi;    
    fi;
    
    ((id_file=id_file+1));

    if [[ $runtimeErrorCode == $SYNTAX_ERROR ]]; then

        linenumber=$(printf "$result" | tail -n 2 | head -n 1 )
        output_recorder "\n${RED}  ↳SYNTAX ERROR($runtimeErrorCode): Line${linenumber:9}: ${last_line:45} \n${NO_COL}" "$semantic_output";
        
    fi;

    # semantic_test_succeeded="$test_succeeded"
}

getLOCOfErrorsFromFile(){
    filename=$1

    userDefinedErrorLinesRaw="$(grep -n '@fail' $1 | cut -d : -f 1)"  
    echo  "$userDefinedErrorLinesRaw"
}

getLOCOfErrorsFromCompiler(){
    input=$1
    
    semanticErrorRaw=$(printf "$input" | grep -oP '(?<=@error at line ).*?(?=\.)' )
    echo  "$semanticErrorRaw"
}

verifySemantic(){
    file=$1
    userDefinedErrorLines=$2
    compilerErrorLines=$3
    # echo "userDefinedErrorLines: $userDefinedErrorLines"
    # echo "compilerErrorLines $compilerErrorLines"

    filename=$(printf "$1" | sed -En 's#.*\/([^/]+)$#\1#p')   

    SAVEIFS=$IFS
    IFS=$'\n'
    userDefinedErrorLinesO=($userDefinedErrorLines)
    IFS=$SAVEIFS

    SAVEIFS=$IFS
    IFS=$'\n'
    compilerErrorLinesO=($compilerErrorLines)
    IFS=$SAVEIFS

    # check if all of the expected errors are found
    expected_output_errors=''
    unexpected_output_errors=''

    for i in ${!userDefinedErrorLinesO[*]}; do
        if [[ ! " ${compilerErrorLinesO[*]} " =~ " ${userDefinedErrorLinesO[$i]} " ]]; then 
            if [[ ! -z "$unexpected_output_errors" ]]; then
                unexpected_output_errors+=", ";
            fi;
            unexpected_output_errors+="${userDefinedErrorLinesO[$i]}";
        else
            if [[ ! -z "$expected_output_errors" ]]; then
                expected_output_errors+=", ";
            fi;
            expected_output_errors+="${userDefinedErrorLinesO[$i]}";
        fi;
    done


    if [[ -z "$unexpected_output_errors" ]]; then
        if [[ "$flag_onlyErrors" == "false" ]];then    
            output_recorder "\n${GREEN}[$4]SUCCESS: \t${NO_COL}"
        fi;
    else
        output_recorder "\n${RED}[$4]FAILED:\t${NO_COL}";
        semantic_test_succeeded="false";
        allTestSucceeded="${RED}FAIL! (Some of the semantic tests Failed) \n${NO_COL}"
    fi;

    if [[ "$flag_onlyErrors" == "false" || ! -z "$unexpected_output_errors" ]];  then
        if [[ "$flag_fullPath" == "true" ]]; then 
            output_recorder "\t[$4]  $1";
        else 
            output_recorder "\t[$4]  $filename";
        fi;       
    fi;

    if [[ "$flag_fast" == "false" ]]; then
        if [[ ! -z "$expected_output_errors" && "$flag_onlyErrors" == "false" ]]; then    
            output_recorder "\n${GREEN}↳SEMANTIC ERROR \tThe compiler succesfully handled the errors at the following lines: $expected_output_errors${NO_COL}" "$semantic_output"
        fi;
        if [[ ! -z "$unexpected_output_errors" ]]; then    
            output_recorder "\n${RED}↳SEMANTIC ERROR \tThe compiler failed to handle the errors at the following lines: $unexpected_output_errors${NO_COL}" "$semantic_output"
        fi;
    fi;

}

