runSyntaxErrorTests() {
    result=$(./$compiler  $1);
    # echo "" 
    # echo "result" $result
    runtimeErrorCode=$?
    filename=$(printf $1 | sed -En 's#.*\/([^/]+)$#\1#p')   
    
    test_succeeded="false" 
    #Enable fast mode, do not generate trees, compiler output only if test succeededd
    if [[ "$flag_fast" == "true" ]]; then
        if [[  $runtimeErrorCode == $SYNTAX_ERROR ]]; then

            test_succeeded="false" 
            test_succeeded="true"
            if [[ "$flag_onlyErrors" == "false" ]];then
                output_recorder "\n${GREEN}[$id_file]SUCCESS: \t${NO_COL}";  
                if [[ "$flag_fullPath" == "true" ]];
                then 
                    output_recorder "\t[$id_file]  $1";
                else 
                    output_recorder "\t[$id_file]  $filename";
                fi;       
            fi;

        else

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
        if [[ "$flag_onlyErrors" == "false" ]];then #NOTE: this should never happen, could be removed...
            if [[ $runtimeErrorCode == $SYNTAX_ERROR ]]; then
                linenumber=$(printf "$result" | tail -n 2 | head -n 1)
                output_recorder "\n${GREEN}  ↳SYNTAX ERROR($runtimeErrorCode)\n${NO_COL}" "$syntax_output";

            fi;
        fi;

        if [[ $runtimeErrorCode == $SEMANTIC_ERROR ]]; then    
            output_recorder "\n${YELLOW}  ↳SEMANTIC ERROR($runtimeErrorCode)\n${NO_COL}" "$syntax_output"
        fi;
        syntax_test_succeeded="$test_succeeded"
        return
    fi;

    # echo ""
    # echo "result " $result
    # Full run, with all information
    syntax_errors=$(printf "$result" | grep -Pzo 'Syntax errors found! See the logs below:(.*\n)*End of syntax errors!' | head -n 2 | tail -n +2 | sed -En 's#^(.*)#\t\1#p')

    outputList[$id_file]="$result"
    outputFileList[$id_file]="$1"
    last_line=$(printf "$result" | tail -n 1 );
    first_chars=${last_line:0:44}
    if [[  $runtimeErrorCode == $SYNTAX_ERROR ]]; then
        test_succeeded="true"
        if [[ "$flag_onlyErrors" == "false" ]];then
            output_recorder "\n${GREEN}[$id_file]SUCCESS: \t${NO_COL}";  
            if [[ "$flag_fullPath" == "true" ]];
            then 
                output_recorder "\t[$id_file]  $1";
            else 
                output_recorder "\t[$id_file]  $filename";
            fi;   
        fi;

    else

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
        fi;
    fi;
    
    ((id_file=id_file+1));

    if [[ $runtimeErrorCode == $SYNTAX_ERROR ]]; then
        
         if [[ "$flag_onlyErrors" == "false" ]];then
            # linenumber=$(printf "$result" | tail -n 2 | head -n 1)
            last_line_results=$(printf "$result" | tail -n 2 | head -n 1)
            output_recorder "\n${GREEN}  ↳SYNTAX ERROR($runtimeErrorCode): ${last_line_results} \n${NO_COL}" "$syntax_output";
        #output_recorder "\n${GREEN}  ↳SYNTAX ERROR($runtimeErrorCode): Line${linenumber:9}: ${last_line:45} \n${NO_COL}" "$syntax_output";
        fi;

    fi;

    if [[ $runtimeErrorCode == $SEMANTIC_ERROR ]]; then
  
        output_recorder "\n${YELLOW}  ↳SEMANTIC ERROR($runtimeErrorCode): \n$syntax_errors\n${NO_COL}" "$syntax_output"
    fi;
    syntax_test_succeeded="$test_succeeded"
}