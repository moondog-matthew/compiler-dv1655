run_validTest() {
    result=""
    if [[ "$flag_RunInterpreter" == "false" ]];then
        result=$(./$compiler < $1 2>&1);    
    else 
        result=$(./$compiler "$1" -b    2>&1);  
    fi;

    runtimeErrorCode=$?

    test_succeeded="false" 

    filename=$(printf $1 | sed -En 's#.*\/([^/]+)$#\1#p')
    test_succeeded="false"
    #Enable fast mode, do not generate trees, compiler output only if test succeededd
    if [[ "$flag_fast" == "true" ]]; then
        if [[  $runtimeErrorCode == $SUCCESS ]]; then
            test_succeeded="true"
            if [[ "$flag_onlyTrees" == "true" ]]; then
            
                if [[ -f "tree.dot"  ]];then
                    cp tree.dot $temp_dotfiles_valid_dir$filename.dot
                    dot -Tpdf $temp_dotfiles_valid_dir$filename.dot -o${test_suit_root}trees/$filename.pdf &
                else
                    tree_dotfile_is_created="false"
                fi;

                if [[ -f "CFGs.dot" ]];then
                    cp CFGs.dot $temp_dotfiles_valid_dir$filename"(_CFGs)".dot     
                    dot -Tpdf $temp_dotfiles_valid_dir$filename"(_CFGs)".dot -o${test_suit_root}trees/$filename"(_CFGs)".pdf &
                else
                    CFGs_dotfile_is_created="false"
                fi;
   
            fi;
            
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
            allTestSucceeded="${RED}Some Test Failed! FAIL\n${NO_COL}"
        fi;

        if [[ $runtimeErrorCode == $SYNTAX_ERROR ]]; then

            linenumber=$(printf "$result" | tail -n 2 | head -n 1)
            output_recorder "${RED}\n[$id_file]FAILED:\t${NO_COL}";
            if [[ "$flag_fullPath" == "true" ]];
            then 
                output_recorder "\t[$id_file]  $1";
            else 
                output_recorder "\t[$id_file]  $filename";
            fi;
            output_recorder "\n${RED}  ↳SYNTAX ERROR($runtimeErrorCode)\n${NO_COL}";
        fi;

        
        if [[ $runtimeErrorCode == $SEMANTIC_ERROR ]]; then

            filename=$(printf $1 | sed -En 's#.*\/([^/]+)$#\1#p')      

            if [[ -f "tree.dot"  ]];then
                cp tree.dot $temp_dotfiles_valid_dir$filename.dot
                dot -Tpdf $temp_dotfiles_valid_dir$filename.dot -o${test_suit_root}trees/$filename.pdf &
            else
                tree_dotfile_is_created="false"
            fi;

            if [[ -f "CFGs.dot" ]];then
                cp CFGs.dot $temp_dotfiles_valid_dir$filename"(_CFGs)".dot     
                dot -Tpdf $temp_dotfiles_valid_dir$filename"(_CFGs)".dot -o${test_suit_root}trees/$filename"(_CFGs)".pdf &
            else
                CFGs_dotfile_is_created="false"
            fi;                      

            output_recorder "${YELLOW}\n[$id_file]FAILED:\t${NO_COL}";
            if [[ "$flag_fullPath" == "true" ]];
            then 
                output_recorder "\t[$id_file]  $1";
            else 
                output_recorder "\t[$id_file]  $filename";
            fi;        

            output_recorder "\n${YELLOW}  ↳SEMANTIC ERROR($runtimeErrorCode)${NO_COL}"       
            
        fi;

        if [[ $runtimeErrorCode == $SEGMENTATION_FAULT ]]; then #Segmentationfault

            output_recorder "${RED}\n[$id_file]FAILED:\t${NO_COL}";
            if [[ "$flag_fullPath" == "true" ]];
            then 
                output_recorder "\t[$id_file]  $1";
            else 
                output_recorder "\t[$id_file]  $filename";
            fi;        

            output_recorder "\n  ${RED}↳Segmentation Fault($runtimeErrorCode) ${NO_COL}\n";        

        fi;

        if [[ $runtimeErrorCode == $ASSERT ]]; then #Assert

            output_recorder "${LIGHT_RED}\n[$id_file]FAILED:\t${NO_COL}";
            if [[ "$flag_fullPath" == "true" ]];
            then 
                output_recorder "\t[$id_file]  $1";
            else 
                output_recorder "\t[$id_file]  $filename";
            fi;        

            output_recorder "\n  ${LIGHT_RED}↳Assert Happened($runtimeErrorCode) ${NO_COL}\n";        

        fi;

        ((id_file=id_file+1));
        valid_test_succeeded="$test_succeeded"
        return
    fi;

    #Full run, with all information
    
    semantic_errors=$(printf "$result" | grep -Pzo 'Semantic errors found! See the logs below:(.*\n)*End of semantic errors!' | tr '\0' '\n' | sed -En 's#^(.*)#\t\1#p' )
    outputList[$id_file]="$result"
    outputFileList[$id_file]="$1"
    last_line=$(printf "$result" | tail -n 1 )
    first_chars=${last_line:0:44}    
    

    if [[  $runtimeErrorCode == $SUCCESS ]]; then
        test_succeeded="true"
        
        if [[ "$flag_onlyErrors" == "false" ]];then
            filename=$(printf $1 | sed -En 's#.*\/([^/]+)$#\1#p')           

            if [[ -f "tree.dot"  ]];then
                cp tree.dot $temp_dotfiles_valid_dir$filename.dot
                dot -Tpdf $temp_dotfiles_valid_dir$filename.dot -o${test_suit_root}trees/$filename.pdf &
            else
                tree_dotfile_is_created="false"
            fi;

            if [[ -f "CFGs.dot" ]];then
                cp CFGs.dot $temp_dotfiles_valid_dir$filename"(_CFGs)".dot     
                dot -Tpdf $temp_dotfiles_valid_dir$filename"(_CFGs)".dot -o${test_suit_root}trees/$filename"(_CFGs)".pdf &
            else
                CFGs_dotfile_is_created="false"
            fi;
       
            output_recorder "\n${GREEN}[$id_file]SUCCESS: \t${NO_COL}";

            if [[ "$flag_fullPath" == "true" ]];
            then 
                output_recorder "\t[$id_file]  $1";
            else 
                output_recorder "\t[$id_file]  $filename";
            fi;
            
            if [[ "$flag_RunInterpreter" == "true" ]];then
                #output_recorder "\n\tRunning Interpretor on compiled bytecode"
                interpreter_output="$(./interpreter )" #TODO: Let user pick what interpreter to use... no hardcoding!
                interpreter_runtimeErrorCode=$?
                
                #real_java_output="$(java $1 2>&1)"
                real_java_output=""
                
                if [[ ! -f "${temp_java_output}${filename}_jvm_out" ]]; then
                    real_java_output="$(java $1 2>&1)"
                    printf "$real_java_output" > "${temp_java_output}${filename}_jvm_out" 
                else
                    if [[ "$flag_ForceGenerateJavaOutput" == "true" ]];then
                        real_java_output="$(java $1 2>&1)"
                        printf "$real_java_output" > "${temp_java_output}${filename}_jvm_out"                     
                        
                    fi;
                    real_java_output="$(cat ${temp_java_output}${filename}_jvm_out )"
                fi;

                

                outputList[$id_file]+="${FADEDCYAN}\n\n#################################################\n"
                outputList[$id_file]+="             Output from JVM Interpreter\n"
                outputList[$id_file]+="nvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n${NO_COL}"
                outputList[$id_file]+="$real_java_output"

                outputList[$id_file]+="${DARKGREEN}\n\n#################################################\n"
                outputList[$id_file]+="             Output from Interpreter\n"
                outputList[$id_file]+="nvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n${NO_COL}"
                #outputList[$id_file]+="$interpreter_output"
                if [[ $interpreter_runtimeErrorCode != SUCCESS ]];then
                    output_recorder "${RED}"
                else 
                    output_recorder "${FADEDCYAN}"
                fi;
                output_recorder "\n\tFinished Interpretor execution, return code: $interpreter_runtimeErrorCode ${NO_COL}"


                

                outputList[$id_file]+="$interpreter_output"
                if [[ "$real_java_output" == "$interpreter_output" ]];then
                    output_recorder "${FADEDCYAN}"
                    output_recorder "\n\tInterpreter output matches output from real java compiler! ${NO_COL}"
                else 
                    output_recorder "${RED}"
                    output_recorder "\n\tInterpreter output does NOT match output from real java compiler! ${NO_COL}"
                fi;                                 
            fi;
        fi;
    else                
        
        allTestSucceeded="${RED}Some Test Failed! FAIL\n${NO_COL}"
    fi;

    
    if [[ $runtimeErrorCode == $SYNTAX_ERROR ]]; then

        linenumber=$(printf "$result" | tail -n 2 | head -n 1)
        output_recorder "${RED}\n[$id_file]FAILED:\t${NO_COL}";
        if [[ "$flag_fullPath" == "true" ]];
        then 
            output_recorder "\t[$id_file]  $1";
        else 
            output_recorder "\t[$id_file]  $filename";
        fi; 
        output_recorder "\n${RED}  ↳SYNTAX ERROR($runtimeErrorCode): Line${linenumber:9}: ${last_line:46} \n${NO_COL}";
        
        junk=$(rm "${test_suit_root}trees/${1:12}.pdf" > /dev/null  2>&1)
    fi;

    if [[ $runtimeErrorCode == $SEMANTIC_ERROR ]]; then

        filename=$(printf $1 | sed -En 's#.*\/([^/]+)$#\1#p')   
        if [[ -f "tree.dot"  ]];then
            cp tree.dot $temp_dotfiles_valid_dir$filename.dot
            dot -Tpdf $temp_dotfiles_valid_dir$filename.dot -o${test_suit_root}trees/$filename.pdf &
        else
            tree_dotfile_is_created="false"
        fi;

        if [[ -f "CFGs.dot" ]];then
            cp CFGs.dot $temp_dotfiles_valid_dir$filename"(_CFGs)".dot     
            dot -Tpdf $temp_dotfiles_valid_dir$filename"(_CFGs)".dot -o${test_suit_root}trees/$filename"(_CFGs)".pdf &
        else
            CFGs_dotfile_is_created="false"
        fi;

        output_recorder "${YELLOW}\n[$id_file]FAILED:\t${NO_COL}";
        if [[ "$flag_fullPath" == "true" ]];
        then 
            output_recorder "\t[$id_file]  $1";
        else 
            output_recorder "\t[$id_file]  $filename";
        fi;       
        
        #output_recorder "\n${YELLOW}  ↳SEMANTIC ERROR($runtimeErrorCode):" "$valid_output"        

        userDefinedErrorLines=$(getLOCOfErrorsFromFile "$1")
        compilerErrorLines=$(getLOCOfErrorsFromCompiler "$semantic_errors")

        verifySemantic "$1" "$userDefinedErrorLines" "$compilerErrorLines" "$id_file"

        # print_semantic_error_lines "$1" \
        #                                 "$semantic_errors"  \
        #                                 "$valid_output"  \
        #                                 "$valid_output_wlines"   \
        #                                 "YELLOW"\
        #                                 "\n  ↳SEMANTIC ERROR($runtimeErrorCode):"\
        #                                 "$valid_output"

        output_recorder "${NO_COL}" "$valid_output"        

    fi;

    if [[ $runtimeErrorCode == $SEGMENTATION_FAULT ]]; then

        output_recorder "${RED}\n[$id_file]FAILED:\t${NO_COL}";
        if [[ "$flag_fullPath" == "true" ]];
        then 
            output_recorder "\t[$id_file]  $1";
        else 
            output_recorder "\t[$id_file]  $filename";
        fi;         

        output_recorder "\n  ${RED}↳Segmentation Fault($runtimeErrorCode): ${last_line:45} ${NO_COL}\n";
        junk=$(rm "${test_suit_root}trees/${1:12}.pdf" > /dev/null  2>&1)

    fi;

     if [[ $runtimeErrorCode == $SEGMENTATION_FAULT ]]; then #Assert

            output_recorder "${LIGHT_RED}\n[$id_file]FAILED:\t${NO_COL}";
            if [[ "$flag_fullPath" == "true" ]];
            then 
                output_recorder "\t[$id_file]  $1";
            else 
                output_recorder "\t[$id_file]  $filename";
            fi;        

            output_recorder "\n  ${LIGHT_RED}↳Assert Happened($runtimeErrorCode) ${NO_COL}\n";        
            treated_assert_str=$(printf "$last_line" | tail -n 1 | awk -F': ' '{s=0;space=" "; for (i=1; i<=NF; i++) {for (j=1;j<i;j++) printf " " ; print "   "space"↳"$i}; }')
            output_recorder "${LIGHT_RED}$treated_assert_str${NO_COL}\n" "$valid_output";        

        fi;

    ((id_file=id_file+1));
    valid_test_succeeded="$test_succeeded"
}