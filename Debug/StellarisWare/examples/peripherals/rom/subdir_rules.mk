################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
StellarisWare/examples/peripherals/rom/rom_direct.obj: ../StellarisWare/examples/peripherals/rom/rom_direct.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/ti/StellarisWare/driverlib/ccs-cm3/Debug" --include_path="C:/ti/StellarisWare/boards/ek-lm3s1968" --include_path="C:/ti/StellarisWare" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="StellarisWare/examples/peripherals/rom/rom_direct.d" --obj_directory="StellarisWare/examples/peripherals/rom" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

StellarisWare/examples/peripherals/rom/rom_mapped.obj: ../StellarisWare/examples/peripherals/rom/rom_mapped.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/ti/StellarisWare/driverlib/ccs-cm3/Debug" --include_path="C:/ti/StellarisWare/boards/ek-lm3s1968" --include_path="C:/ti/StellarisWare" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="StellarisWare/examples/peripherals/rom/rom_mapped.d" --obj_directory="StellarisWare/examples/peripherals/rom" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

