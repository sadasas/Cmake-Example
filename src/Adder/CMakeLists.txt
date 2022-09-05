add_library(adder adder.cpp)

INSTALL(TARGETS adder DESTINATION lib)
INSTALL(FILES adder.h DESTINATION include)