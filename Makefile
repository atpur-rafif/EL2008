SOURCE_PATH=src
OBJECT_PATH=out

FILE=_main output
FILE_O=$(addprefix $(OBJECT_PATH)/,$(addsuffix .o,$(FILE)))

$(OBJECT_PATH)/%.o: $(SOURCE_PATH)/%.c
	gcc -c -o $@ $<

link: $(FILE_O)
	gcc -o program $(FILE_O)

run: link
	./program
