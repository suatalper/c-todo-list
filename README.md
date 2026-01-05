# C To-Do List Application

A simple console-based To-Do List application written in C.
C dilinde yazılmış basit bir konsol tabanlı Yapılacaklar Listesi uygulaması.

## Features / Özellikler

- **Add Task**: Create new tasks with a priority level (1-10). Tasks are automatically assigned a unique ID.
- **View Tasks**: List all current tasks saved in the system.
- **Mark as Complete**: distinct tasks as completed (Note: Logic currently displays available tasks).
- **Persistence**: functionality to save and retrieve tasks from a text file (`tasks.txt`).

- **Görev Ekle**: Öncelik seviyesi (1-10) ile yeni görevler oluşturun. Görevlere otomatik olarak benzersiz bir kimlik atanır.
- **Görevleri Görüntüle**: Sistemde kayıtlı tüm mevcut görevleri listeleyin.
- **Tamamlandı Olarak İşaretle**: Görevleri tamamlandı olarak işaretleyin.
- **Kalıcılık**: Görevleri bir metin dosyasından (`tasks.txt`) kaydetme ve alma işlevi.

## Compilation / Derleme

### Windows (GCC)

```bash
gcc main.c -o todo.exe
./todo.exe
```

## Usage / Kullanım

Run the executable to see the menu:
Yürütülebilir dosyayı çalıştırarak menüyü görebilirsiniz:

1. **Add Task**: Follow the prompts to enter a task description and priority.
2. **View Tasks**: Displays the list of tasks.
3. **Mark Task as Complete**: (Work in Progress) Select a task to mark as done.
4. **Exit**: Close the application.
