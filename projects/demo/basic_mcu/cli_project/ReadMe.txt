Command Line Interface (CLI)

1. Giới thiệu:
Việc phát triển một thư viện CLI nó cung cấp giải pháp để một MCU có thể giao tiếp ra bên ngoài như thế nào. Từ đó, con người có thể có cách thức để quan sát và điều khiển chương trình như mong muốn. Nếu nhìn rộng ra thì có thể sử dụng CLI để thực hiện giao tiếp giữa hai hoặc nhiều MCUs với nhau. Vậy nên, việc tìm hiểu và làm được nó sẽ rất có ý nghĩa cho người sử dụng MCU.

2. Chi tiết:
2.1. API:
- void help(u8_t argc, u8_t **argv)
    Đây là lệnh mặc định của thư viện CLI. Nhằm mục đích khi người dùng gõ lệnh "help" thì nó sẽ hiển thị ra thông tin những lệnh được hỗ trợ. Thông qua lệnh "help" thì cũng chỉ ra được nguyên mẫu (prototype) của một hàm thực thi của lệnh sẽ giống như thế này.


- void init_cli(void)
    Khởi tạo quá trính bắt đầu sử dụng thư viện CLI trong chương trình. Đây là yêu cầu bắt buộc đối với người phát triển sử dụng CLI. Trước bất kỳ việc sử dụng API của CLI nào thì cần gọi hàm này trước tiên. Và hàm này chỉ gọi một lần duy nhất.


- s8_t add_cli(cli_t *new_command, u8_t num_command)
    Thêm danh sách lệnh để CLI quản lý

    [INPUT] new_command : con trỏ của danh sách lệnh
    [INPUT] num_command : số lượng lệnh tương ứng trong danh sách lệnh


- void parse_cli(const u8_t *str_command, const u8_t len_command)
    Tìm kiếm và thực thi lệnh nếu lệnh tồn tại

    [INPUT] str_command : con trỏ của chuối ký tự nhập vào từ terminal
    [INPUT] len_command : độ dài chuối ký tự


- u8_t prepare_command_cli(const u8_t character)
    Tổ hợp lại những ký tự do người dùng nhập vào tạo thành một câu lệnh

    [INPUT] character : ký tự được nhập vào


- void clear_buffer_cli(void)
    Xóa bộ nhớ buffer cho chuối ký tự nhập vào

2.2. Sequence để gọi thực thi lệnh:

                  |-> add_cli() -| -> parse_cli()
    init_cli() -> |-> add_cli() -|
                  |-> add_cli() -| -> prepare_command_cli()


3. Yêu cầu công cụ và thiết lập thông số:
- Cần cài đặt một terminal trên máy tính. Ở đây có thể chọn RealTerm https://sourceforge.net/projects/realterm/
- Thiết lập thông số trên RealTerm <Port> tab:
    -> Baudrate: 115200
    -> Parity: None
    -> Data Bits: 8
    -> Stop Bits: 1
    -> Hardware Flow Control: None


