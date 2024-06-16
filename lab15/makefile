CC = g++
LIBPATH = ./
LIB_SRC = $(LIBPATH)
LIB_OBJ = $(subst /,\,$)
INCLUDEPATH = -I$(LIBPATH)
EXE1 = DS091
EXE2 = DS092
EXE3 = DS093
EXEALL = $(EXE1) $(EXE2) $(EXE3)

all: $(EXEALL)

$(LIB_OBJ): $(LIB_SRC)
	$(CC) -c $< -o $@ $(INCLUDEPATH)

$(EXE1): $(EXE1).cpp $(LIB_OBJ)
	$(CC) -o $@ $^ $(INCLUDEPATH)

$(EXE2): $(EXE2).cpp $(LIB_OBJ)
	$(CC) -o $@ $^ $(INCLUDEPATH)
   
$(EXE3): $(EXE3).cpp $(LIB_OBJ)
	$(CC) -o $@ $^ $(INCLUDEPATH)

clean:
	del $(EXE1).exe
	del $(EXE2).exe
	del $(EXE3).exe
	del $(LIB_OBJ)