CC=gcc
CFLAGS=-I.

# 목표: 의존성이 변경될 때마다 main 실행 파일을 재생성합니다.
SepTest: main.o myutil.o
	$(CC) -o SepTest main.o myutil.o

# main.c의 의존성과 컴파일 규칙
main.o: main.c myutil.h
	$(CC) -c main.c

# myutil.c의 의존성과 컴파일 규칙
myutil.o: myutil.c myutil.h
	$(CC) -c myutil.c

clean:
	rm -f *.o SepTest
