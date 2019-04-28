
SRC = *.cpp
OUT = a.out


all: build
	./$(OUT)



build:
	g++ -o $(OUT) $(SRC)

clean:
	rm -f *.o $(OUT)