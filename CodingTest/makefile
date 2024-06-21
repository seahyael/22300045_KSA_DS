CC = g++
LIBPATH = ./
LIB_SRC = $(LIBPATH)
LIB_OBJ = $(subst /,\,$)
INCLUDEPATH = -I$(LIBPATH)
EXE1 = DS101
EXE2 = DS102
EXE3 = DS103
EXE4 = DS104
EXE5 = DS105
EXE6 = DS106
EXE7 = DS107
EXE8 = DS108
EXE9 = DS109
EXE10 = DS110
EXEALL = $(EXE1) $(EXE2) $(EXE3) $(EXE4) $(EXE5) $(EXE6) $(EXE7) $(EXE8) $(EXE9) $(EXE10)

all: $(EXEALL)

$(LIB_OBJ): $(LIB_SRC)
	$(CC) -c $< -o $@ $(INCLUDEPATH)

$(EXE1): $(EXE1).cpp $(LIB_OBJ)
	$(CC) -o $@ $^ $(INCLUDEPATH)

$(EXE2): $(EXE2).cpp $(LIB_OBJ)
	$(CC) -o $@ $^ $(INCLUDEPATH)
   
$(EXE3): $(EXE3).cpp $(LIB_OBJ)
	$(CC) -o $@ $^ $(INCLUDEPATH)

$(EXE4): $(EXE4).cpp $(LIB_OBJ)
	$(CC) -o $@ $^ $(INCLUDEPATH)

$(EXE5): $(EXE5).cpp $(LIB_OBJ)
	$(CC) -o $@ $^ $(INCLUDEPATH)
   
$(EXE6): $(EXE6).cpp $(LIB_OBJ)
	$(CC) -o $@ $^ $(INCLUDEPATH)

$(EXE7): $(EXE7).cpp $(LIB_OBJ)
	$(CC) -o $@ $^ $(INCLUDEPATH)

$(EXE8): $(EXE8).cpp $(LIB_OBJ)
	$(CC) -o $@ $^ $(INCLUDEPATH)
   
$(EXE9): $(EXE9).cpp $(LIB_OBJ)
	$(CC) -o $@ $^ $(INCLUDEPATH)

$(EXE10): $(EXE10).cpp $(LIB_OBJ)
	$(CC) -o $@ $^ $(INCLUDEPATH)

clean:
	del $(EXE1).exe
	del $(EXE2).exe
	del $(EXE3).exe
	del $(EXE4).exe
	del $(EXE5).exe
	del $(EXE6).exe
	del $(EXE7).exe
	del $(EXE8).exe
	del $(EXE9).exe
	del $(EXE10).exe
	del $(LIB_OBJ)