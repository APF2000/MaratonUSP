// obs: run: "C:\Program Files\Google\Chrome\Application\chrome.exe" --remote-debugging-port=9988

*** Settings ***
Documentation    Get data from REIT ranking site
Library          SeleniumLibrary
Library          Process
Library          Collections

*** Variables ***
${SITE_URL}  https://leetcode.com/list/xi4ci4ig/
${TABLE_LOCATOR}  css=table#table-ranking
${SIGN_IN LOCATOR}  css=#navbar-right-container > div.auth-links__3huC > a:nth-child(3)
${GITHUB_SIGN_IN LOCATOR}  css=#app > div > div.sign-in-wrapper__2SAX > div > div.placeholder-bottom__2SYS > div > div > div > div.container__1lsb > div > a:nth-child(2)
${FIRST_ACCOUNT LOCATOR}  css=html body div div div.ant-modal-wrap.lc-modal__3L7G.empty-title__2_Zc div.ant-modal div.ant-modal-content div.ant-modal-body div.lc-modal-body__jO0c div.sign-in-container__3IFW div.container__1Q_2 div.container__1lsb div a.link__Mcl7

&{CHROME_OPTIONS}  debugger_address=localhost:9988

# _ignore_local_proxy=${EMPTY}  --proxy-server=${EMPTY}  default_capabilities=${EMPTY}  to_capabilities=${EMPTY}

*** Test Cases ***
# Create debug browser
#     ${cmd}=  Set Variable  "C:\Program Files\Google\Chrome\Application\chrome.exe" --remote-debugging-port=9988
#     Run Process  command=${cmd}

Should open browser
    ${ChromeOptions}=     Evaluate      sys.modules['selenium.webdriver'].ChromeOptions()  sys,selenium.webdriver 

    # Method debugger_address is not callable so convert to Capabilities Dictionary and set it manually
    ${ChromeCapabilities}=     Call Method     ${ChromeOptions}    to_capabilities
    Set To Dictionary    ${ChromeCapabilities["goog:chromeOptions"]}    debuggerAddress    localhost:9988

    # Instead of using the Chrome Options use Capabilities.
    Create WebDriver    Chrome   desired_capabilities=${ChromeCapabilities}
   
    # Open Browser  url=${SITE_URL}  browser=chrome  options=${CHROME_OPTIONS}

Login in leetcode
    Wait Until Element Is Visible    ${SIGN_IN LOCATOR}
	Click Element    ${SIGN_IN LOCATOR}

    Wait Until Element Is Visible    ${GITHUB_SIGN_IN LOCATOR}
	Click Element    ${GITHUB_SIGN_IN LOCATOR}

    #Wait Until Element Is Visible    ${FIRST_ACCOUNT LOCATOR}
	#Click Element    ${FIRST_ACCOUNT LOCATOR}