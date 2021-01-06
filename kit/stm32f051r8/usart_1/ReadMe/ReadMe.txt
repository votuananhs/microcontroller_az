USART (Universal synchronous asynchronous receiver transmitter)

A. Danh sánh những module liên quan:
- Clock (RCC):
	-> Tính toán giá trị clock chính xác cấp cho USART1
	-> Enable clock gate cho UART module
- GPIO:
	-> khởi tạo mode cho Tx/Rx chân
- USART:
	-> khởi tạo module.
	-> viết hàm truyền/nhận dữ liệu
- NVIC:
	-> khởi tạo và cho phép ngắt của USART1
	-> interrupt handler

B. USART:
1. Khởi tạo:
- Disable USART module -> USART_CR1[UE] = 0;
- Data = 8 bits -> USART_CR1[M1:M0]
- Parity = none -> USART_CR1[PCE]
- Stop = 1 bit  -> USART_CR2[STOP]
- Baudrate = 9600 bps -> thiết lập oversample1 USART_CR1[OVER8] = 16 bits
- Enable USART module -> USART_CR1[UE] = 1;
- Enable Tx -> USART_CR1[TE]
- Enable Rx -> USART_CR1[RE]

2. Quá trình truyền dữ liệu:
- Cần kiểm tra cờ USART_ISR[TXE]
	-> Nếu USART_ISR[TXE] = 1 -> tiến hành ghi dữ liệu vào USART_TDR = <data> (lưu ý là ghi 1 byte dữ liệu)
	-> Nếu USART_ISR[TXE] = 0 -> không ghi dữ liệu vào USART_TDR
- Truyền đc dữ liệu

3. Quá trình nhận dữ liệu:
- Cần kiểm tra cờ USART_ISR[RXNE]
- Nếu USART_ISR[RXNE] = 1 -> tiến hành đọc dữ liệu trên thanh ghi USART_RDR[8:0]
- Xóa cờ ngắt USART_ISR[RXNE] bằng việc đọc dữ liệu tren USART_RDR hoặc ghi 1 tới bít USART_RQR[RXFRQ]

4. Những phần tài liệu cần đọc:
- 27.5.2./ 27.5.3/ 27.5.4/ 27.5.9/ 27.8


C. Phụ lục
1. Driver cho PL2303: làm theo hướng dẫn theo link http://www.totalcardiagnostics.com/support/Knowledgebase/Article/View/92/20/prolific-usb-to-serial-fix-official-solution-to-code-10-error
