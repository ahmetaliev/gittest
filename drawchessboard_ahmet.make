#
# SDL application Makefile
# type without args to build
# type run to execute
# type clean to clean sources
# type log to check application log
#

TARGET = drawchessboard_ahmet

all: $(TARGET)

CFLAGS =-fmax-errors=1 -I/sdcard/cpl/libs_348 -Os -Wall -DANDROID -I${EXTERNAL_STORAGE}/CCTools/SDL/include
CPPFLAGS=$(CFLAGS) -I D:\msys32\mingw32\include\SDL2\ 

LDFLAGS = -shared ${EXTERNAL_STORAGE}/CCTools/SDL/lib/SDL_android_main.o -L${EXTERNAL_STORAGE}/CCTools/SDL/lib -lSDL2 -lSDL2_ttf -lGLESv1_CM -llog -lm

SDLRUN = am start $(shell am 2>&1| grep -q '\-\-user' && echo '--user 0') -n com.pdaxrom.cctools.sdlplugin/.sdlpluginActivity -e sdlmain

OBJS = $(TARGET).o

$(TARGET): $(OBJS)
	$(CC) -o lib$@.so $^ $(LDFLAGS)

clean:
		rm -f $(OBJS) lib$(TARGET).so

run: $(TARGET)
		$(SDLRUN) $(PWD)/lib$(TARGET).so

log:
		logcat -d | grep SDL

l2:
	logcat -d | grep SDL


 
exe : 
	g++      -fmax-errors=1 -I D:\msys32\mingw32\include\SDL2\ drawchessboard_ahmet.cpp    -lmingw32 -lSDL2main -lSDL2 -mwindows   -lsdl2_ttf    -o drawchessboard_ahmet.exe -w
	
#$(TARGET): $(TARGET).o
#		ls $(TARGET).exe
#		g++  -w -fmax-errors=1 $(TARGET).cpp -I d:\msys32\mingw32\include\sdl2\ -I D:\msys32\mingw32\include\SDL2\ -w -lmingw32 -lSDL2main -lSDL2 -mwindows   -lsdl2_ttf  -o $(TARGET).exe
#		echo %date% %time%
#		drawchessboard_ahmet.exe
#$(TARGET).exe:
#	g++  -w -fmax-errors=1 drawchessboard_ahmet.cpp -I d:\msys32\mingw32\include\sdl2\ -w -lmingw32 -lSDL2main -lSDL2 -mwindows   -lsdl2_ttf  -o drawchessboard_ahmet.exe
	
