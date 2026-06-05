all: spoof_lock

spoof_lock: spoof_lock.c
    gcc spoof_lock.c -o spoof_lock -Wall

clean:
    rm -f spoof_lock

install: spoof_lock
    sudo cp spoof_lock /usr/local/bin/
