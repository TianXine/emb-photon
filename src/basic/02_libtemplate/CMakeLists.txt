# ==================================================
#        File : CMakeLists.txt
# Description : cmake template script for stm324xx project
#      Author : xine
#     Created : 2022-02-25 19:16:43
#   Copyright : (c) 2022 xinedev.org
#    Modified : 2022-02-25 19:16:43
# ==================================================

cmake_minimum_required(VERSION 3.15)

project(stmtemplate)

set(CMAKE_C_COMPILER /usr/bin/arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER /usr/bin/arm-none-eabi-gcc)
set(OBJCOPY /usr/bin/arm-none-eabi-objcopy)

## Options for compiler and linker
set(CPUFLAGS "-mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs")
set(CMAKE_C_FLAGS "-Os -s -Wall -Werror ${CPUFLAGS}")
set(CMAKE_CXX_FLAGS "-Wall -Werror ${CPUFLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "-T ${CMAKE_CURRENT_SOURCE_DIR}/stm32f4_flash.ld")

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
	${STM32F4XX_STDPERPH_DRIVER_SRCDIR}/stm32f4xx_gpio.c
	${STM32F4XX_STDPERPH_DRIVER_SRCDIR}/stm32f4xx_rcc.c
	${STM32F4XX_STDPERPH_DRIVER_SRCDIR}/stm32f4xx_syscfg.c
	${CMSIS_DEVICE_SRC_DIR}/system_stm32f4xx.c
	main.c
	stm32f4xx_it.c
)

set(HDR
	stm32f4xx_conf.h
	stm32f4xx_it.h
)

set(ASM
	${CMSIS_DEVICE_STARTUP_DIR}/startup_stm32f40_41xxx.s
)

add_executable(template ${SRC} ${HDR} ${ASM})
target_compile_definitions(template PUBLIC -DSTM32F40_41xxx -DUSE_STDPERIPH_DRIVER)

