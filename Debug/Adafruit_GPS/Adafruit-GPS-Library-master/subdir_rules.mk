################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Adafruit_GPS/Adafruit-GPS-Library-master/Adafruit_GPS.obj: ../Adafruit_GPS/Adafruit-GPS-Library-master/Adafruit_GPS.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.1.1/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me --include_path="C:/ti/ccsv5/tools/compiler/arm_5.1.1/include" --include_path="C:/ti/StellarisWare/boards/ek-lm3s1968/Adafruit_GPS/Adafruit-GPS-Library-master" --include_path="C:/ti/StellarisWare/boards/ek-lm3s1968" --include_path="C:/ti/StellarisWare" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="Adafruit_GPS/Adafruit-GPS-Library-master/Adafruit_GPS.pp" --obj_directory="Adafruit_GPS/Adafruit-GPS-Library-master" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


