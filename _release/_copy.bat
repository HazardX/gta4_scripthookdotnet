@ECHO OFF

REM **                                                                              **
REM ** Collects all files required for a release package in the "archive" subfolder **
REM **                                                                              **

mkdir .\archive
mkdir ".\archive\scripts\for Developers\bin"

copy ..\ScriptHookDotNet.readme.txt .\archive\
copy ..\bin\ScriptHookDotNet.dll .\archive\ScriptHookDotNet.asi
copy ..\bin\ScriptHookDotNet.dll ".\archive\scripts\for Developers\bin\ScriptHookDotNet.dll"
copy ..\bin\ScriptHookDotNet.xml ".\archive\scripts\for Developers\bin\ScriptHookDotNet.xml"
copy ..\bin\ScriptHook.dll .\archive\ScriptHook.dll
copy .\scriptsMessage.txt ".\archive\scripts\_PUT .NET SCRIPTS HERE"

xcopy /S /Y .\PlainScripts\*.* ".\archive\scripts\for Developers\PlainScripts\"

xcopy /S /Y ..\TestScriptVB\*.* ".\archive\scripts\for Developers\TestScriptVB\"
del /AH ".\archive\scripts\for Developers\TestScriptVB\TestScriptVB.suo"
del ".\archive\scripts\for Developers\TestScriptVB\TestScriptVB.vbproj.user"
del /Q ".\archive\scripts\for Developers\TestScriptVB\bin"
rmdir /S /Q ".\archive\scripts\for Developers\TestScriptVB\obj"
copy .\postbuildVB.bat ".\archive\scripts\for Developers\TestScriptVB\bin\_postbuild.bat"

xcopy /S /Y ..\TestScriptCS\*.* ".\archive\scripts\for Developers\TestScriptCS\"
del ".\archive\scripts\for Developers\TestScriptCS\TestScriptCS.suo"
del ".\archive\scripts\for Developers\TestScriptCS\TestScriptCS.csproj.user"
del /Q ".\archive\scripts\for Developers\TestScriptCS\bin"
rmdir /S /Q ".\archive\scripts\for Developers\TestScriptCS\obj"
copy .\postbuildCS.bat ".\archive\scripts\for Developers\TestScriptCS\bin\_postbuild.bat"

pause