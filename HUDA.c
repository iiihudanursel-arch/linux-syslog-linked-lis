#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * @struct SysLogNode
 * @brief Her bir sistem günlüðünü (syslog) temsil eden çift yönlü baðlý liste düðümü.
 * * Neden struct? Verileri bir arada tutmak için.
 * Neden Çift Yönlü? Hem ileri (yeni loglar) hem geri (geçmiþ analiz) hýzlý gezinme için.
 */
typedef struct SysLogNode {
    int logID;                  // Benzersiz kayýt numarasý
    char timestamp[32];         // Olayýn gerçekleþtiði zaman (Örn: 2026-03-13 20:00)
    char level[15];             // Log seviyesi: INFO, WARNING, ERROR, CRITICAL
    char message[512];          // Olayýn detaylý açýklamasý
    struct SysLogNode *next;    // Bir sonraki log kaydýna iþaretçi
    struct SysLogNode *prev;    // Bir önceki log kaydýna iþaretçi
} SysLogNode;

// Yeni bir log oluþturup listenin sonuna ekleyen fonksiyon
void appendLog(SysLogNode **head, int id, const char *lvl, const char *msg) {
    SysLogNode *newNode = (SysLogNode *)malloc(sizeof(SysLogNode));
    
    // Zaman damgasýný otomatik oluþturma
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(newNode->timestamp, 32, "%Y-%m-%d %H:%M:%S", timeinfo);

    newNode->logID = id;
    strncpy(newNode->level, lvl, 15);
    strncpy(newNode->message, msg, 512);
    newNode->next = NULL;

    // Eðer liste boþsa ilk elemaný ata
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    // Son elemana kadar git (O(n) karmaþýklýðý)
    SysLogNode *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

// Tüm loglarý ekrana yazdýran fonksiyon
void displayAllLogs(SysLogNode *node) {
    printf("\n--- LINUX SYSLOG GÖRÜNTÜLEYÝCÝ ---\n");
    while (node != NULL) {
        printf("[%s] ID: %d | SEVÝYE: %-8s | MESAJ: %s\n", 
               node->timestamp, node->logID, node->level, node->message);
        node = node->next;
    }
}

int main() {
    SysLogNode *logList = NULL;

    // Örnek Log Kayýtlarý Ekleme
    appendLog(&logList, 101, "INFO", "Sistem baslatildi.");
    appendLog(&logList, 102, "WARNING", "Disk doluluk orani %85 uzerinde.");
    appendLog(&logList, 103, "ERROR", "Veritabani baglantisi koptu.");

    displayAllLogs(logList);

    return 0;
}
