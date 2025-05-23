@echo off
set /p n= Enter max index of file to delete:
set /a m=%n%-1
for /l %%a in (0 2 %m%) do (
   IF EXIST F%%a.dat (
      del F%%a.dat
   ) ELSE (
      echo F%%a.dat missing.
   )
   
)
pause