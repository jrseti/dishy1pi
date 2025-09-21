@echo off
:: Usage: build_lib.bat <lib_name> <parts_list>
:: Example: build_lib.bat mylib "C12345 C67890 C24680"

set lib_name="power_parts"
set parts_list=C71687 C599585 C5677734 C14663 C5440143 C307488 C2041331 C71617 C23198 C3032935 C2876010 

:: Loop through each part number
for %%p in (%parts_list%) do (
    echo Processing LCSC part: %%p
    easyeda2kicad --full --lcsc_id=%%p --output ./%lib_name%
)

echo Done. Library created in folder "%lib_name%"
