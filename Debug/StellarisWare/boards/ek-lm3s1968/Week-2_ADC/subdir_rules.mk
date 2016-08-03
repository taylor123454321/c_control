################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
StellarisWare/boards/ek-lm3s1968/Week-2_ADC/my_adc.obj: ../StellarisWare/boards/ek-lm3s1968/Week-2_ADC/my_adc.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/ti/StellarisWare/driverlib/ccs-cm3/Debug" --include_path="C:/ti/StellarisWare/boards/ek-lm3s1968" --include_path="C:/ti/StellarisWare" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="StellarisWare/boards/ek-lm3s1968/Week-2_ADC/my_adc.d" --obj_directory="StellarisWare/boards/ek-lm3s1968/Week-2_ADC" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

StellarisWare/boards/ek-lm3s1968/Week-2_ADC/startup_ccs.obj: ../StellarisWare/boards/ek-lm3s1968/Week-2_ADC/startup_ccs.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/ti/StellarisWare/driverlib/ccs-cm3/Debug" --include_path="C:/ti/StellarisWare/boards/ek-lm3s1968" --include_path="C:/ti/StellarisWare" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="StellarisWare/boards/ek-lm3s1968/Week-2_ADC/startup_ccs.d" --obj_directory="StellarisWare/boards/ek-lm3s1968/Week-2_ADC" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


