"..\..\tool\elf2uf2.exe" .\Objects\template.axf .\template.uf2

@if not exist C:\Keil_v5\Arm\Flash\Raspberry_Pi_Pico.FLM (

    echo ==================================================
    echo Try to install RP2040 flash programming algorithm...
    echo If you see "Access is denied", please manually copy Raspberry_Pi_Pico.FLM to "<KEIL Folder>\Arm\Flash", e.g. "C:\Keil_v5\Arm\Flash\"
    echo ==================================================
    copy /B .\Raspberry_Pi_Pico.FLM C:\Keil_v5\Arm\Flash\Raspberry_Pi_Pico.FLM

)
