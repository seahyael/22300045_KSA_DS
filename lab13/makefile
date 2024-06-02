CC = g++
LIBPATH = ./
LIB_SRC = $(LIBPATH)DS076.h
LIB_OBJ = $(subst /,\,$(LIBPATH)DS076.h)
INCLUDEPATH = -I$(LIBPATH)
EXE1 = DS071
EXE2 = DS072
EXE3 = DS073
EXE4 = DS074
EXE5 = DS075
EXE6 = DS076
EXEALL = $(EXE1) $(EXE2) $(EXE3) $(EXE4) $(EXE5) $(EXE6)

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
	del $(EXE4).exe
	del $(EXE5).exe
	del $(EXE6).exe
	del $(LIB_OBJ)