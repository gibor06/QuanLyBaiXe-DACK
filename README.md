# 🚗 Parking Management System — Hệ thống quản lý bãi giữ xe bằng C/C++

**Parking Management System** là project mô phỏng **hệ thống quản lý bãi giữ xe** được xây dựng dưới dạng **C/C++ Console Application**, nhằm hỗ trợ quản lý xe vào bãi, xe ra bãi, danh sách xe hiện có, lịch sử hoạt động và một số thông tin quản trị cơ bản.

Project được thực hiện với mục tiêu **học tập, thực hành và củng cố kiến thức về cấu trúc dữ liệu và giải thuật**, đồng thời áp dụng các kỹ thuật lập trình nền tảng trong C/C++ như:

* **Linked List**
* **Stack**
* **Struct**
* **File I/O**
* **Console Menu**
* **Quản lý dữ liệu dạng tuyến tính**

Dự án phù hợp với sinh viên đang học các môn như:

* Cấu trúc dữ liệu và giải thuật
* Lập trình C/C++
* Nhập môn phát triển phần mềm
* Phân tích và tổ chức chương trình console

Repository được tổ chức theo hướng **rõ ràng, dễ đọc, dễ chạy và dễ mở rộng**, giúp người học dễ dàng tham khảo logic xử lý, cách tổ chức file nguồn và phương pháp xây dựng một chương trình quản lý thực tế bằng C/C++.

---

# 👨‍💻 Tác giả

**Trần Gia Bảo** - **gibor06**

Sinh viên ngành **Công Nghệ Thông Tin** - **Trường Đại học Công Thương TP.HCM (HUIT)**

📍 TP.HCM, Việt Nam

---

# 🌐 Giới thiệu project

Hệ thống **quản lý bãi giữ xe** là một bài toán quen thuộc trong thực tế, thường yêu cầu xử lý đồng thời nhiều thao tác như:

* tiếp nhận xe vào bãi,
* ghi nhận thời gian gửi xe,
* xử lý xe ra bãi,
* tính toán chi phí gửi xe,
* lưu lại lịch sử phương tiện,
* và thống kê tình trạng bãi xe hiện tại.

Trong project này, các chức năng trên được mô phỏng bằng chương trình console, qua đó giúp người học hiểu rõ hơn cách áp dụng **cấu trúc dữ liệu tuyến tính** vào một bài toán quản lý thực tế.

Đây là một project có giá trị học tập cao vì không chỉ dừng ở mức lý thuyết mà còn gắn trực tiếp với:

* cách tổ chức dữ liệu,
* cách chia module chương trình,
* cách xử lý menu,
* cách thao tác với file,
* và cách quản lý luồng xử lý trong ứng dụng console.

---

# 📌 Chức năng chính

## 1️⃣ Quản lý xe vào bãi

Chức năng này cho phép tiếp nhận xe mới vào hệ thống.

Bao gồm:

* Nhập thông tin xe
* Lưu thời gian xe vào bãi
* Thêm xe vào danh sách xe đang gửi
* Cập nhật trạng thái bãi xe sau khi tiếp nhận

Đây là thao tác cơ bản và quan trọng nhất của hệ thống, vì nó quyết định dữ liệu đầu vào cho toàn bộ quá trình quản lý xe.

---

## 2️⃣ Quản lý xe ra bãi

Chức năng này xử lý quá trình một xe rời khỏi bãi giữ xe.

Bao gồm:

* Cập nhật thời gian xe ra
* Tính tiền gửi xe
* Xóa hoặc chuyển xe khỏi danh sách xe đang trong bãi
* Lưu thông tin xe vào lịch sử xe đã rời bãi

Thông qua chức năng này, chương trình mô phỏng một quy trình tương đối đầy đủ trong quản lý gửi xe thực tế.

---

## 3️⃣ Hiển thị danh sách

Chương trình hỗ trợ hiển thị dữ liệu để người dùng dễ theo dõi tình trạng hoạt động của bãi giữ xe.

Bao gồm:

* Danh sách xe đang trong bãi
* Danh sách xe đã rời bãi
* Lịch sử xe gần nhất
* Thông tin cơ bản của các đối tượng được quản lý

Chức năng này giúp tăng tính trực quan và hỗ trợ kiểm tra dữ liệu trong quá trình vận hành.

---

## 4️⃣ Quản lý nhân viên

Ngoài quản lý xe, hệ thống còn có chức năng quản lý nhân viên để phục vụ cho việc vận hành hệ thống.

Bao gồm:

* Thông tin nhân viên
* Phân quyền truy cập hệ thống
* Xác thực đăng nhập cơ bản

Đây là phần mở rộng có ý nghĩa thực tế, giúp project không chỉ dừng lại ở mức quản lý phương tiện mà còn chạm đến yếu tố quản trị người dùng.

---

## 5️⃣ Thống kê

Hệ thống hỗ trợ thống kê tình trạng hiện tại của bãi xe.

Bao gồm:

* Số xe hiện tại trong bãi
* Số chỗ còn trống
* Thông tin tổng quan phục vụ kiểm tra nhanh

Chức năng này giúp người dùng đánh giá nhanh năng lực chứa xe và tình trạng hoạt động của bãi.

---

# 🧠 Cấu trúc dữ liệu sử dụng

Project áp dụng các cấu trúc dữ liệu cơ bản nhưng rất quan trọng trong lập trình C/C++.

## 1️⃣ Linked List

**Linked List** được sử dụng để lưu trữ các danh sách động trong hệ thống như:

* Xe đang trong bãi
* Xe đã rời bãi
* Nhân viên

Việc sử dụng danh sách liên kết giúp chương trình có thể:

* thêm phần tử linh hoạt,
* xóa phần tử thuận tiện,
* quản lý dữ liệu động mà không cần biết trước kích thước.

Ví dụ cấu trúc node:

```cpp
struct Node{
    Itemtype info;
    Node* next;
};
```

---

## 2️⃣ Stack

**Stack** được sử dụng để lưu lịch sử thao tác gần nhất, chẳng hạn như:

* Xe vào gần nhất
* Xe ra gần nhất

Cấu trúc stack phù hợp với nguyên tắc **LIFO (Last In, First Out)**, giúp mô phỏng việc truy xuất nhanh các thao tác mới nhất.

Ví dụ cấu trúc stack node:

```cpp
struct StackNode{
    Itemtype info;
    StackNode* next;
};
```

---

# 🧩 Ý nghĩa học thuật của project

Project không chỉ là một chương trình quản lý đơn thuần mà còn là bài thực hành tiêu biểu cho việc áp dụng các kiến thức về:

* tổ chức dữ liệu,
* thiết kế thuật toán,
* chia module chương trình,
* quản lý file,
* và xử lý logic nghiệp vụ trong môi trường console.

Thông qua project này, người học có thể hiểu rõ hơn cách chuyển từ một bài toán thực tế sang một mô hình lập trình cụ thể bằng C/C++.

Đây là dạng project rất phù hợp cho sinh viên trong giai đoạn luyện tập:

* tư duy lập trình,
* tư duy dữ liệu,
* tư duy tổ chức source code,
* và kỹ năng xây dựng chương trình có nhiều chức năng liên kết với nhau.

---

# 📂 Cấu trúc project

```text
ParkingManagement
│
├── main.cpp
├── tranGiaBao.cpp
├── tranDuongGiaBao.cpp
├── tranBao.h
└── DuongBao.h
```

| File | Mô tả |
| --- | --- |
| `main.cpp` | Chương trình chính, xử lý menu và điều hướng chức năng |
| `tranGiaBao.cpp` | Xử lý các chức năng liên quan đến quản lý xe |
| `tranDuongGiaBao.cpp` | Cài đặt các cấu trúc dữ liệu như Linked List và Stack |
| `tranBao.h` | Khai báo hàm cho các chức năng trong chương trình |
| `DuongBao.h` | Khai báo struct và các thành phần dữ liệu chính |

---

# 🔑 Tài khoản đăng nhập thử

Bạn có thể sử dụng tài khoản mặc định sau để chạy thử chương trình:

```text
Username: admin
Password: 1
```

Tài khoản này phục vụ cho mục đích kiểm thử chức năng đăng nhập và truy cập hệ thống trong môi trường học tập.

---

# ▶️ Hướng dẫn chạy chương trình

## 1️⃣ Clone project từ GitHub

```bash
git clone https://github.com/gibor06/parking-management-system.git
```

Sau đó di chuyển vào thư mục project:

```bash
cd parking-management-system
```

---

## 2️⃣ Compile chương trình

Sử dụng trình biên dịch **g++** để biên dịch toàn bộ mã nguồn:

```bash
g++ main.cpp tranGiaBao.cpp tranDuongGiaBao.cpp -o parking
```

Lệnh trên sẽ tạo file thực thi có tên là `parking`.

---

## 3️⃣ Chạy chương trình

### Trên Windows

```bash
parking.exe
```

### Trên Linux / macOS

```bash
./parking
```

Sau khi chạy, chương trình sẽ hiển thị menu console để người dùng thao tác với hệ thống.

---

# 📷 Demo chương trình

Giao diện chương trình ở dạng console menu, ví dụ:

```text
=========== QUAN LY BAI GIU XE ===========

1. Xe vao bai
2. Xe ra bai
3. Danh sach xe trong bai
4. Lich su xe
5. Thong ke
0. Thoat

Nhap lua chon:
```

Thiết kế dạng menu console giúp người học tập trung vào:

* logic xử lý chương trình,
* cách tổ chức chức năng,
* và cấu trúc dữ liệu được sử dụng phía sau.

---

# 📚 Kiến thức áp dụng

Project áp dụng các kiến thức và kỹ thuật sau:

* **C/C++ Programming**
* **Struct**
* **Linked List**
* **Stack**
* **File Handling**
* **Console Menu System**
* **Modular Programming**
* **Data Management in Console Application**

Đây đều là các kiến thức nền tảng rất quan trọng đối với sinh viên học lập trình hệ thống, cấu trúc dữ liệu và phát triển phần mềm cơ bản.

---

# 🎯 Mục tiêu project

* Xây dựng chương trình **quản lý bãi giữ xe** bằng **C/C++**
* Rèn luyện kỹ năng áp dụng **cấu trúc dữ liệu và giải thuật** vào bài toán thực tế
* Thực hành sử dụng **Linked List**, **Stack**, **Struct** và **File I/O**
* Tăng khả năng tổ chức chương trình theo nhiều file nguồn và file header
* Hỗ trợ học tập, ôn luyện và tham khảo cho sinh viên ngành **Công Nghệ Thông Tin**
* Xây dựng một repository học thuật rõ ràng, dễ đọc và dễ sử dụng trên GitHub

---

# 👥 Đối tượng phù hợp

Project này phù hợp với:

* Sinh viên đang học **C/C++**
* Sinh viên học môn **Cấu trúc dữ liệu và giải thuật**
* Người mới luyện tập xây dựng **console application**
* Người muốn tham khảo cách tổ chức project nhiều file trong C/C++
* Người cần một bài toán thực tế để luyện tập quản lý dữ liệu động

---

# 🚀 Hướng phát triển trong tương lai

Project có thể tiếp tục được mở rộng theo nhiều hướng như:

* Thêm giao diện trực quan thay cho console
* Bổ sung quản lý nhiều loại xe khác nhau
* Lưu dữ liệu bằng cơ sở dữ liệu thay vì file
* Cải thiện cơ chế phân quyền người dùng
* Thêm thống kê doanh thu gửi xe
* Tích hợp thời gian thực và xử lý ngày giờ chi tiết hơn

Những hướng mở rộng này sẽ giúp project tiến gần hơn tới một hệ thống quản lý thực tế và hoàn chỉnh hơn.

---

# 📫 Contact

<p align="center">
  <a href="mailto:gibor06.dev@gmail.com">
    <img src="https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white" alt="Email Badge"/>
  </a>

  <a href="https://www.facebook.com/gibor06">
    <img src="https://img.shields.io/badge/Facebook-1877F2?style=for-the-badge&logo=facebook&logoColor=white" alt="Facebook Badge"/>
  </a>

  <a href="https://www.instagram.com/gibor06/">
    <img src="https://img.shields.io/badge/Instagram-%23E4405F.svg?style=for-the-badge&logo=instagram&logoColor=white" alt="Instagram Badge"/>
  </a>
</p>

---

# 📜 License

Project được sử dụng cho mục đích **học tập**, **nghiên cứu** và **tham khảo**.
