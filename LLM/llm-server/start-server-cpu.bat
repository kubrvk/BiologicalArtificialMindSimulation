@echo off
setlocal
cd /d "%~dp0bin"

set MODEL=%~dp0..\llm\Qwen3-4B-Q4_K_M.gguf
set LOGFILE=%~dp0cpu-server.log

echo Starting llama-server (CPU-only build) on http://127.0.0.1:8080 ...
echo Model: %MODEL%
echo Log:   %LOGFILE%
echo.

llama-server.exe -m "%MODEL%" --port 8080 --host 127.0.0.1 -t 8 -c 4096 --parallel 1 --reasoning off --log-file "%LOGFILE%"

echo.
echo Server process exited. Press any key to close this window.
pause >nul
