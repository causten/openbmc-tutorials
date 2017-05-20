# Test your change with the Robot Framework

This tutorial will show you how to use the OpenBMC Project's Functional
Testing Framework to valid your code.  This lesson relies on the 
[Get in the flash](lessonaddtoflash.md) `hellomethod` file for what to test.

## What is the Robot Framework
The OpenBMC Project was created by developers who knew the importance of
automated testing.  It's not as if code ever changes maintainers or is effected
by anything else _right?_.  So from the beginning, automation of the user
interfaces has happened.  The [Robot Framework](http://robotframework.org)
fit our needs perfectly.


## Getting Started
The test automation is in its own [repository](https://github.com/openbmc/openbmc-test-automation).
Follow the [quick start](https://github.com/openbmc/openbmc-test-automation#quickstart)
section to install any dependencies.

In the previous [Get in the flash](lessonaddtoflash.md) tutorial I had
you running the `hellomethod` in qemu.  Make sure you still have it running.

Time to create your first Robot test.  This is the same file as [here](openbmc-test-automation/tests/test_hellomethod.robot)
This is what your first Robot test will look like.  A few things to note about
syntax
1. Robot requires 2 spaces between words that should be seperated.  
2.  Best practice for OpenBMC testing is to add a Tag with the test case name
to the test case.  That allows tests to be skipped for various reasons
3. Robot is designed to be very readable.  Assigning variables in the test 
case can make it ugly or code like.  Try to avoid it when you can.  Use a 
python file when you need to code


```
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
```

Put that file in to the tests dir

```
$ git clone https://github.com/openbmc/openbmc-test-automation
$ cd openbmc-test-automation
$ cp <openbmc-tutorials>/openbmc-test-automation/tests/test_hellomethod.robot tests
$ export OPENBMC_HOST=localhost
$ export SSH_PORT=2222
$ export HTTPS_PORT=2443
$ tox -e qemu -- tests/test_hellomethod.robot
```

If your test is successful you should see something like this...

```
==============================================================================
Test Telemetry                                                                
==============================================================================
Check if hellomethod exists :: Test REST session log-in.              | PASS |
------------------------------------------------------------------------------
Post a message to commit                                              ..URI:https://localhost:2443/xyz/openbmc_project/tutorial/hellomethod/action/commit, method:Post, args:{u'data': {u'data': [2, u'Hi there from robot']}, u'headers': {u'Content-Type': u'application/json'}}
Response code:200, Content:{
  "data": null, 
  "message": "200 OK", 
  "status": "ok"
}
Post a message to commit                                              | PASS |
------------------------------------------------------------------------------
Test Telemetry                                                        | PASS |
2 critical tests, 2 passed, 0 failed
2 tests total, 2 passed, 0 failed
==============================================================================
Output:  /home/causten/gitrepo/openbmc-test-automation/output.xml
Log:     /home/causten/gitrepo/openbmc-test-automation/log.html
Report:  /home/causten/gitrepo/openbmc-test-automation/report.html
________________________________________________ summary _________________________________________________
  qemu: commands succeeded
  congratulations :)
```

Look at the report.html that comes out.  Nice!


## Extra Information
Writing test cases that can survive rewrites of programs and multiple systems is
a challenge.  Too often I've seen tests cause CI failures instead of finding
CI failures.  There is a good [tutorial](https://github.com/robotframework/HowToWriteGoodTestCases/blob/master/HowToWriteGoodTestCases.rst)
on best practices.

## Extra Credit
Add some bad paths and verify the HTTP responses are correct.  Add a call to
collect FFDC when a test case fails.  Skip a test using the 
[skip_test](https://github.com/openbmc/openbmc-test-automation/blob/master/test_lists/skip_test_palmetto)
concept.