
Từ khóa "register" trong ngôn ngữ C

- A declaration of an identifier for an object with storage-class specifier register suggests that access to the object be as fast as possible. The extent to which such suggestions are effective is implementation-defined.


1. Quá trình cấp phát một biến sử dụng thanh ghi nào sẽ được thực thi tự động và do compiler quyết định. Nhưng bạn cũng có thể chỉ định một thanh ghi cụ thể. Nếu có sự kết hợp và nhúng code assembly.

2. Không thể sử dụng & operator để lấy địa chỉa của một biến được khai báo với từ khóa "register". Bởi với những biến này không đc cấp địa chỉ trong vùng nhờ mà được gắn với một thanh ghi (general purpose registers - Rx). Việc truy cập địa chỉ của một thanh ghi Rx là không hợp lệ.

3. Từ khóa "register" có thể được sử dụng với một biến con trỏ

4. register là một "Storage-class specifiers" xem thêm tài liệu tham khảo (1) chương 6.7.1. Cần lưu ý là tránh sử dụng nhiều từ khóa "storage-class" cho một biến.

5. Không giới hạn số lượng biến khai báo với từ khóa register. Quá trình build chương trình compiler sẽ quyết định cấp phát hay ko một biến tới một thanh ghi.


Tham khảo thêm thông tin theo link:
(1) http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1124.pdf
(2) https://www.geeksforgeeks.org/understanding-register-keyword/


