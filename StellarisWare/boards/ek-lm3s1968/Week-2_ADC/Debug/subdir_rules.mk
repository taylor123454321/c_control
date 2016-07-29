################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
my_adc.obj: ../my_adc.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/courses/ENCE361/StellarisWare/utils" --include_path="J:/courses/ENCE361/StellarisWare/boards/ek-lm3s1968" --include_path="J:/courses/ENCE361/StellarisWare" --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="my_adc.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

rit128x96x4.obj: J:/courses/ENCE361/StellarisWare/boards/ek-lm3s1968/drivers/rit128x96x4.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/courses/ENCE361/StellarisWare/utils" --include_path="J:/courses/ENCE361/StellarisWare/boards/ek-lm3s1968" --include_path="J:/courses/ENCE361/StellarisWare" --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="rit128x96x4.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

startup_ccs.obj: ../startup_ccs.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/courses/ENCE361/StellarisWare/utils" --include_path="J:/courses/ENCE361/StellarisWare/boards/ek-lm3s1968" --include_path="J:/courses/ENCE361/StellarisWare" --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="startup_ccs.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ustdlib.obj: J:/courses/ENCE361/StellarisWare/utils/ustdlib.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/courses/ENCE361/StellarisWare/utils" --include_path="J:/courses/ENCE361/StellarisWare/boards/ek-lm3s1968" --include_path="J:/courses/ENCE361/StellarisWare" --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="ustdlib.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


