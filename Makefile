SOURCE_PATH=src
OBJECT_PATH=out

FILE=_main output search delete update
FILE_O=$(addprefix $(OBJECT_PATH)/,$(addsuffix .o,$(FILE)))

$(OBJECT_PATH)/%.o: $(SOURCE_PATH)/%.c
	gcc -c -o $@ $<

link: $(FILE_O)
	gcc -o program $(FILE_O)

run: link
	./program

compile:
	arduino-cli compile -b arduino:avr:uno src

upload: compile
	arduino-cli upload -p /dev/ttyACM0 -b arduino:avr:uno src
