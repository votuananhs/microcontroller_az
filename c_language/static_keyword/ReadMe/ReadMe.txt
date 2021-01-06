
Từ khóa "static" trong ngôn ngữ C

1. Một biến được khai báo với từ khóa static sẽ vẫn được duy trì trong khi chương trình đang chạy (về điểm này giống với global variable).

2. Vùng nhớ của một biến được khai báo static sẽ được cấp vùng nhớ trong data/bss segment (vùng nhớ biến toàn cục), không phải trong stack (trường hợp này khi nó là một local variable).

3. Với một biến được khai báo static và không khởi tạo giá trị thì nó được khởi tạo giá trị bằng 0 (điểm này giống với global variable)

4. Việc khởi tạo một biến tĩnh (static variable) sẽ chỉ được thực hiện bằng việc sử dụng một hằng số.

5. Với việc sử dụng từ khóa "static" cho một biến hoặc hàm. Việc làm này nhằm xác định phạm vi truy xuất của một biến/hàm:
- local variable: xác định phạm vi của nó chỉ nằm ở trong hàm đó, nhưng khi thoát khỏi hàm, nó không bị thu hồi vùng nhớ đã được cấp
- global variable: xác định phạm vi của nó chỉ nằm trong giới hạn của file nó đc khai báo.
- function: xác định giới hạn phạm vi hàm đó chỉ được sử dụng trong file được khai báo.


Tham khảo thêm thông tin theo link:
https://www.geeksforgeeks.org/static-variables-in-c/
https://www.geeksforgeeks.org/what-are-static-functions-in-c/

