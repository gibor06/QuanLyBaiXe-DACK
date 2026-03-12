# 🚗 Parking Management System (C/C++)

Hệ thống **quản lý bãi giữ xe** được xây dựng bằng **C/C++ Console Application**.
Chương trình hỗ trợ quản lý xe vào bãi, xe ra bãi, danh sách xe và lịch sử xe.

Project được thực hiện nhằm mục đích **học tập cấu trúc dữ liệu và giải thuật**, áp dụng:

- Linked List
- Stack
- Struct trong C/C++
- File I/O
- Console Menu

---

# 📌 Chức năng chính

## 1. Quản lý xe vào bãi

- Nhập thông tin xe
- Lưu thời gian xe vào
- Thêm xe vào danh sách xe trong bãi

## 2. Quản lý xe ra bãi

- Cập nhật thời gian xe ra
- Tính tiền gửi xe
- Lưu vào lịch sử xe

## 3. Hiển thị danh sách

- Danh sách xe đang trong bãi
- Danh sách xe đã rời bãi
- Lịch sử xe gần nhất

## 4. Quản lý nhân viên

- Thông tin nhân viên
- Phân quyền truy cập hệ thống

## 5. Thống kê

- Số xe hiện tại trong bãi
- Số chỗ còn trống

---

# 🧠 Cấu trúc dữ liệu sử dụng

## Linked List

Dùng để lưu danh sách:

- Xe đang trong bãi
- Xe đã rời bãi
- Nhân viên

```cpp
struct Node{
    Itemtype info;
    Node* next;
};
```

## Stack

Dùng để lưu lịch sử:

- Xe vào gần nhất
- Xe ra gần nhất

```cpp
struct StackNode{
    Itemtype info;
    StackNode* next;
};
```

---

# 📂 Cấu trúc project

```
ParkingManagement
│
├── main.cpp
├── tranGiaBao.cpp
├── tranDuongGiaBao.cpp
├── tranBao.h
├── DuongBao.h
```

| File                | Mô tả                        |
| ------------------- | ---------------------------- |
| main.cpp            | Chương trình chính và menu   |
| tranGiaBao.cpp      | Xử lý chức năng quản lý xe   |
| tranDuongGiaBao.cpp | Cài đặt Linked List và Stack |
| tranBao.h           | Khai báo hàm                 |
| DuongBao.h          | Khai báo struct              |

---

# 🔑 Tài khoản đăng nhập thử

Sử dụng tài khoản sau để chạy thử chương trình:

```
Username: admin
Password: 1
```

---

# ▶️ Hướng dẫn chạy chương trình

## 1. Clone project từ GitHub

```bash
git clone https://github.com/your-username/parking-management-system.git
```

Sau đó vào thư mục project:

```bash
cd parking-management-system
```

---

## 2. Compile chương trình

Sử dụng **g++**:

```bash
g++ main.cpp tranGiaBao.cpp tranDuongGiaBao.cpp -o parking
```

---

## 3. Chạy chương trình

Trên Windows:

```bash
parking.exe
```

Trên Linux / Mac:

```bash
./parking
```

---

# 📷 Demo chương trình

```
=========== QUAN LY BAI GIU XE ===========

1. Xe vao bai
2. Xe ra bai
3. Danh sach xe trong bai
4. Lich su xe
5. Thong ke
0. Thoat

Nhap lua chon:
```

---

# 📚 Kiến thức áp dụng

Project áp dụng các kiến thức:

- C/C++ Programming
- Struct
- Linked List
- Stack
- File Handling
- Console Menu System

---

# 📜 License

Project được sử dụng cho mục đích **học tập và nghiên cứu**.
