# 🧩 Useful-Library-by-C++-Language

A concise and efficient collection of reusable C (and some C++) data structures and utility headers, ready to be incorporated into your projects.

---

## 🚀 Features

- ✅ Double-linked list (`clsDblLinkedList.h`)  
- ✅ Dynamic array (`clsDynamicArray.h`)  
- ✅ Stack (array & linked list variants: `clsMyStack.h`, `clsMyStackArr.h`)  
- ✅ Queue (array & linked list variants: `clsMyQueueArr.h`, `clsMyQueueLine.h`)  
- ✅ String utilities (`clsMyString.h`, `clsString.h`)  
- ✅ Input validation (`clsInputValidate.h`)  
- ✅ Date utilities (`clsDate.h`)  
- ✅ General utilities (`clsUtil.h`)  

*(Each header is self-contained, documented and ready to use.)*

---

## 📦 Getting Started

### 1️⃣ Clone the repository  
```bash
git clone https://github.com/Moaaz-git/Useful-Library-by----C-Language.git
cd Useful-Library-by----C-Language
```

### 2️⃣ Include the library in your project  
Copy the desired header(s) into your project’s `include/` folder and include them in your source file:
```c
#include "clsDblLinkedList.h"
#include "clsUtil.h"
```

### 3️⃣ Compile your code  
```bash
gcc -o myapp main.c
```
If you’re using C++ or a makefile, simply treat `.h` files as C-compatible headers.

---

## 🧑‍💻 Usage Examples

**Example: Double Linked List**
```c
#include "clsDblLinkedList.h"

int main(void) {
    DblLinkedList list = DLL_create();
    DLL_pushBack(&list, 10);
    DLL_pushBack(&list, 20);
    DLL_pushFront(&list, 5);

    printf("List size = %d\n", DLL_size(&list));

    DLL_destroy(&list);
    return 0;
}
```

**Example: Dynamic Array**
```c
#include "clsDynamicArray.h"

int main(void) {
    DynamicArray arr = DA_init(sizeof(int));
    int value = 42;
    DA_pushBack(&arr, &value);
    printf("First element = %d\n", *(int*)DA_get(&arr, 0));
    DA_free(&arr);
    return 0;
}
```

> 📘 More examples will be added in an `examples/` folder soon.

---

## 🎯 Why Use This Library?

- 📂 **Organized:** Clear separation of data structures and utilities  
- ⚡ **Lightweight:** Pure header-only design with minimal dependencies  
- 🔧 **Flexible:** Integrate only the parts you need  
- 🎓 **Educational:** Great for students and professionals learning data structures  
- 🚀 **Extensible:** Add your own utilities or improve existing ones easily  

---

## 🧩 Directory Structure

```
/
├── clsDate.h
├── clsDblLinkedList.h
├── clsDynamicArray.h
├── clsInputValidate.h
├── clsMyQueue.h
├── clsMyQueueArr.h
├── clsMyQueueLine.h
├── clsMyStack.h
├── clsMyStackArr.h
├── clsMyString.h
├── clsString.h
├── clsUtil.h
└── README.md
```

---

## 📖 Contributing

Contributions are always welcome! 💡  

To contribute:
1. Fork this repository  
2. Create a new branch: `feature/YourFeatureName`  
3. Commit your changes with clear messages  
4. Submit a Pull Request  

Please include comments and examples for any new code you add.

---

## 📝 License

This project is licensed under the **MIT License** — see the [LICENSE](LICENSE) file for details.

---

## 📬 Contact

Created and maintained by **[Moaaz-git](https://github.com/Moaaz-git)**  
💬 Feel free to open an issue or reach out via GitHub for feedback or suggestions!

---

## 💖 Special Thanks

A special thanks to **Dr-Mohammed Abo Hadhoud**, the founder of the **[Programming Advices Platform](https://programmingadvices.com/)**,  
for his exceptional teaching, mentorship, and continuous contributions to the programming community. 🙏  

---

⭐ **If you find this project helpful, consider giving it a star!**  
Thank you for using **Useful-Library-by-C++-Language** — Happy Coding! 🎉
