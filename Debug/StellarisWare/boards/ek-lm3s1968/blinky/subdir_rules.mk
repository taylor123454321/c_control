################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
StellarisWare/boards/ek-lm3s1968/blinky/blinky.obj: ../StellarisWare/boards/ek-lm3s1968/blinky/blinky.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/ti/StellarisWare/driverlib/ccs-cm3/Debug" --include_path="C:/ti/StellarisWare/boards/ek-lm3s1968" --include_path="C:/ti/StellarisWare" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="StellarisWare/boards/ek-lm3s1968/blinky/blinky.d" --obj_directory="StellarisWare/boards/ek-lm3s1968/blinky" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

StellarisWare/boards/ek-lm3s1968/blinky/startup_ccs.obj: ../StellarisWare/boards/ek-lm3s1968/blinky/startup_ccs.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/ti/StellarisWare/driverlib/ccs-cm3/Debug" --include_path="C:/ti/StellarisWare/boards/ek-lm3s1968" --include_path="C:/ti/StellarisWare" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="StellarisWare/boards/ek-lm3s1968/blinky/startup_ccs.d" --obj_directory="StellarisWare/boards/ek-lm3s1968/blinky" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

StellarisWare/boards/ek-lm3s1968/blinky/startup_ewarm.obj: ../StellarisWare/boards/ek-lm3s1968/blinky/startup_ewarm.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/ti/StellarisWare/driverlib/ccs-cm3/Debug" --include_path="C:/ti/StellarisWare/boards/ek-lm3s1968" --include_path="C:/ti/StellarisWare" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="StellarisWare/boards/ek-lm3s1968/blinky/startup_ewarm.d" --obj_directory="StellarisWare/boards/ek-lm3s1968/blinky" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

StellarisWare/boards/ek-lm3s1968/blinky/startup_gcc.obj: ../StellarisWare/boards/ek-lm3s1968/blinky/startup_gcc.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/ti/StellarisWare/driverlib/ccs-cm3/Debug" --include_path="C:/ti/StellarisWare/boards/ek-lm3s1968" --include_path="C:/ti/StellarisWare" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="StellarisWare/boards/ek-lm3s1968/blinky/startup_gcc.d" --obj_directory="StellarisWare/boards/ek-lm3s1968/blinky" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

StellarisWare/boards/ek-lm3s1968/blinky/startup_rvmdk.obj: ../StellarisWare/boards/ek-lm3s1968/blinky/startup_rvmdk.S $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/ti/StellarisWare/driverlib/ccs-cm3/Debug" --include_path="C:/ti/StellarisWare/boards/ek-lm3s1968" --include_path="C:/ti/StellarisWare" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="StellarisWare/boards/ek-lm3s1968/blinky/startup_rvmdk.d" --obj_directory="StellarisWare/boards/ek-lm3s1968/blinky" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


