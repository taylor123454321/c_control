################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Adafruit_GPS/Adafruit-GPS-Library-master/examples/flora_dumplog/flora_dumplog.obj: ../Adafruit_GPS/Adafruit-GPS-Library-master/examples/flora_dumplog/flora_dumplog.ino $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/ti/StellarisWare/driverlib/ccs-cm3/Debug" --include_path="C:/ti/StellarisWare/boards/ek-lm3s1968" --include_path="C:/ti/StellarisWare" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="Adafruit_GPS/Adafruit-GPS-Library-master/examples/flora_dumplog/flora_dumplog.d" --obj_directory="Adafruit_GPS/Adafruit-GPS-Library-master/examples/flora_dumplog" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


