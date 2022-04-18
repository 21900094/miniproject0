ll = gcc
CFLAGS = -W -Wall
TARGET = shop
DTARGET = shop_debug
OBJECTS = main.c product.o manager.o
ALL:$(TARGET)
$(TARGET):$(OBJECTS)
	$(ll) $(CFLAGS) -o $@ $^
$(DTARGET):$(OBJECTS)
	$(ll) $(CFLAGS) -DDEBUG -o $@ $^
clean:
	rm *.o
