# ==================================================
#        File : CMakeLists.txt
# Description : cmake template script for stm324xx project
#      Author : xine
#     Created : 2022-02-25 19:16:43
#   Copyright : (c) 2022 xinedev.org
#    Modified : 2022-02-25 19:16:43
# ==================================================

cmake_minimum_required(VERSION 3.15)

project(stmtemplate C ASM CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

## Tool chain
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_SYSTEM_PROCESSOR Arm)

set(CROSS_COMPILER_PREFIX "/usr/bin/arm-none-eabi-")
set(CMAKE_C_COMPILER ${CROSS_COMPILER_PREFIX}gcc)
set(CMAKE_CXX_COMPILER ${CROSS_COMPILER_PREFIX}g++)
set(CMAKE_ASM_COMPILER ${CROSS_COMPILER_PREFIX}gcc)
set(OBJCOPY ${CROSS_COMPILER_PREFIX}objcopy)
#set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

## Options for compiler and linker 
set(MPUFLAGS "-mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16")
set(CMAKE_C_FLAGS "-Os -s -Wall -Werror ${MPUFLAGS}")
set(CMAKE_CXX_FLAGS "-Wall -Werror ${MPUFLAGS}")
set(LINKER_FLAGS "-T${CMAKE_CURRENT_SOURCE_DIR}/stm32f4_flash.ld -u Reset_Handler -Wl,-Map=${CMAKE_PROJECT_NAME}.map,--cref -Wl,--gc-sections --specs=nano.specs --specs=nosys.specs")

## StdPeriph Driver
set(STM32F4XX_STDPERPH_DRIVER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../library/STM32F4xx_StdPeriph_Driver")
# Directory of StdPeriph Driver source
set(STM32F4XX_STDPERPH_DRIVER_SRCDIR "${STM32F4XX_STDPERPH_DRIVER_DIR}/src")

## CMSIS
set(CMSIS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../library/CMSIS")
set(CMSIS_INC_DIR "${CMSIS_DIR}/Include")
set(CMSIS_DEVICE_SRC_DIR "${CMSIS_DIR}/Device/ST/STM32F4xx/Source/Templates/")
set(CMSIS_DEVICE_INC_DIR "${CMSIS_DIR}/Device/ST/STM32F4xx/Include")
set(CMSIS_DEVICE_STARTUP_DIR "${CMSIS_DIR}/Device/ST/STM32F4xx/Source/Templates/TrueSTUDIO") # Use truestudio for gcc

include_directories(
	"${STM32F4XX_STDPERPH_DRIVER_DIR}/inc"
	"${CMSIS_INC_DIR}"
	"${CMAKE_CURRENT_SOURCE_DIR}" # invoke stm324xx_conf.h search path
	"${CMSIS_DEVICE_INC_DIR}")

set(SRC
	main.c
	${STM32F4XX_STDPERPH_DRIVER_SRCDIR}/stm32f4xx_gpio.c
	${STM32F4XX_STDPERPH_DRIVER_SRCDIR}/stm32f4xx_rcc.c
	${STM32F4XX_STDPERPH_DRIVER_SRCDIR}/stm32f4xx_syscfg.c
	system_stm32f4xx.c
	stm32f4xx_it.c
	led.c
)

set(HDR
	stm32f4xx_conf.h
	stm32f4xx_it.h
	led.h
)

set(ASM_SRC
	#${CMSIS_DEVICE_STARTUP_DIR}/
	startup_stm32f40_41xxx.s
)

add_executable(${CMAKE_PROJECT_NAME} ${ASM_SRC} ${SRC} ${HDR})
target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC -DSTM32F40_41xxx -DUSE_STDPERIPH_DRIVER)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${LINKER_FLAGS})

add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
	COMMAND ${OBJCOPY} -Oihex $<TARGET_FILE:${CMAKE_PROJECT_NAME}> ${CMAKE_PROJECT_NAME}.hex
	COMMAND ${OBJCOPY} -Obinary $<TARGET_FILE:${CMAKE_PROJECT_NAME}> ${CMAKE_PROJECT_NAME}.bin
	COMMENT "Generating hex and binary format target."
	)
