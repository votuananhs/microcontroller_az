System timer (Systick)

A. Danh sánh những module liên quan:
- Clock (RCC):
	-> Tính toán giá trị clock chính xác cấp cho System Timer (Systick)
- System Timer:
	-> khởi tạo module.
	-> viết hàm start/get_state
- NVIC:
	-> khởi tạo và cho phép ngắt của Systick
	-> interrupt handler

B. System Timer:
1. Khởi tạo:
- Disable systick
- Lựa chọn source clock cho Systick
- Set giá trị bằng 0 cho SYST_SCR register

2. Start timer:
- Ghi giá trị cho thanh ghi reload
- Ghi giá trị bằng 0 cho current value register
- Ghi 1 tới bit enable Systick

3. Kiểm tra trạng thái của cờ tràn
- đọc giá trị bit COUNTFLAG trong thanh ghi SYST_CSR
