################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Adresse.cpp \
../Date.cpp \
../Personne.cpp \
../principal.cpp \
../validationFormat.cpp 

OBJS += \
./Adresse.o \
./Date.o \
./Personne.o \
./principal.o \
./validationFormat.o 

CPP_DEPS += \
./Adresse.d \
./Date.d \
./Personne.d \
./principal.d \
./validationFormat.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


