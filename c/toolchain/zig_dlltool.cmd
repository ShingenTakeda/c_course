@echo off

REM Find zig executable
set "ZIG_EXE="
for %%p in (zig.exe "C:\zig\zig.exe" "%PROGRAMFILES%\zig\zig.exe" "%USERPROFILE%\zig\zig.exe" "%USERPROFILE%\.cargo\bin\zig.exe") do (
    if exist "%%p" (
        set "ZIG_EXE=%%p"
        goto :found
    )
)

REM Try to find zig in PATH
where zig >nul 2>&1
if %ERRORLEVEL% EQU 0 (
    set "ZIG_EXE=zig"
    goto :found
)

echo Error: Could not find zig executable >&2
exit /b 1

:found
"%ZIG_EXE%" dlltool %*
