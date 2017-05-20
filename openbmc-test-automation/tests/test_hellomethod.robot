*** Settings ***
Resource          ../lib/rest_client.robot
Resource          ../lib/resource.txt
Library           Collections

*** Variables ***
${URI}=    /xyz/openbmc_project/tutorial/hellomethod


*** Test Cases ***

Check if hellomethod exists
    [Documentation]  Test REST session log-in.
    [Tags]  check_if_hellomethod_exists

    Initialize OpenBMC
    ${resp}=  Get Request  openbmc  ${URI}
    Should Be Equal As Strings  ${resp.status_code}  ${HTTP_OK}


Post a message to commit
    [Tags]  Post_a_message_to_commit

    @{count_list}=   Create List     ${2}   Hi there from robot
    ${data}=   create dictionary   data=@{count_list}
    
    ${resp}=   openbmc post request    ${URI}/action/commit      data=${data}
    should be equal as strings      ${resp.status_code}     ${HTTP_OK}

