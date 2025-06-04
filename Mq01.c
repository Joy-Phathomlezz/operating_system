#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

int main() {
    key_t key = ftok("somefile.txt", 65);      // generate a unique key
    int msgid = msgget(key, IPC_CREAT | 0666); // create the queue with permissions

    if (msgid == -1) {
        perror("msgget failed");
        return 1;
    }

    printf("Message queue created with ID: %d\n", msgid);
    return 0;
}
