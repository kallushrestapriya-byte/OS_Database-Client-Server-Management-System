CC = gcc
CFLAGS = -Wall

TARGET = database_app

SOURCES = app.c client_server.c student_records.c

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm -f $(TARGET) students.txt temp.txt
