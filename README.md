# Linux Syslog Management with Doubly Linked List

Bu proje, Linux işletim sistemindeki **Syslog (Sistem Günlükleri)** mekanizmasını simüle etmek ve bu verileri **Çift Yönlü Bağlı Liste (Doubly Linked List)** veri yapısı kullanarak yönetmek amacıyla geliştirilmiştir.



## 📝 Proje Hakkında

Linux sistemlerde log kayıtları sürekli ve hacmi belirsiz bir akışa sahiptir. Bu çalışma, gelen log verilerini çalışma zamanında (runtime) işleyerek dinamik bir veri yapısında depolar.

### Teknik Sorular ve Cevaplar

* **Syslog Mekanizması Nedir?**
    Syslog, Linux sistemlerde çekirdek, servisler ve uygulamalar tarafından üretilen olay mesajlarını (hata, uyarı, bilgi) toplamak ve depolamak için kullanılan standart bir protokoldür. Sistem denetimi ve hata ayıklama için kritik öneme sahiptir.
    
* **Hangi Bağlı Liste Türü Kullanıldı?**
    Bu projede **Çift Yönlü Bağlı Liste (Doubly Linked List)** kullanılmıştır.
    
* **Neden Bu Bağlı Liste Türü Tercih Edildi?**
    Syslog analizinde bir hata (Error) oluştuğunda, bu hatadan hemen önceki tetikleyici olayları (Warning/Info) incelemek gerekir. Çift yönlü liste, sahip olduğu `prev` (önceki) işaretçisi sayesinde geçmişe dönük hızlı tarama yapılmasına imkan tanır. Ayrıca dinamik yapısı sayesinde bellek israfını önler.

---

## 🛠️ Kullanılan Bileşenler ve Fonksiyonlar

Kod içerisinde yer alan temel yapılar ve amaçları şöyledir:

| Bileşen | Amacı |
| :--- | :--- |
| **struct SysLogNode** | LogID, Timestamp, Level ve Message alanlarını içeren, verinin hafızadaki şablonudur. |
| **appendLog()** | Yeni bir log düğümü oluşturur, `time.h` ile zaman damgası ekler ve listenin sonuna bağlar. |
| **displayLogs()** | Listenin başından başlayarak tüm kayıtları formatlı bir şekilde terminale yazdırır. |
| **Dinamik Bellek** | `malloc` fonksiyonu kullanılarak loglar için sadece ihtiyaç duyulduğu kadar yer ayrılır. |

---

## 🚀 Kurulum ve Çalıştırma

1.  **Derleme:**
    ```bash
    gcc main.c -o syslog_app
    ```

2.  **Çalıştırma:**
    ```bash
    ./syslog_app
    ```

---

## 📂 Dosya Yapısı

* `main.c`: Uygulamanın kaynak kodu (Detaylı yorum satırları ve fonksiyon açıklamalarını içerir).
* `README.md`: Proje dokümantasyonu ve teknik açıklamalar.

---

**Geliştirici:** HÜDA NUR SEL
**Konu:** Linux Syslog Bilgilerinin Bağlı Liste ile Gösterilmesi
