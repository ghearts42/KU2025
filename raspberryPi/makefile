TARGET = helloRaspberry switchLed
all : ${TARGET}

helloRaspberry :
	cc -o helloRaspberry helloRaspberry.c -lwiringPi

switchLed :
	cc -o switchLed switchLed.c -lwiringPi

clean :
	rm ${TARGET}