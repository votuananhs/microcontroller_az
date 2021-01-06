
A. Lập trình I/O:
1. Mục đích:
	- hiểu về lập trình Input/Output digital trên một chân của MCU
	- hướng dẫn những bước căn bản để phân tích thông tin HW/SW cần xây dựng một chương trình điều khiển I/O

2. Yêu cầu cần có để bắt đầu bài học này:
	- cần có 1 board vi điều khiển "STM32F0 Discovery". Nếu không có thì có thể sử dụng một loại board khác
	- tài liệu reference manual của con chíp (stm32f051r8)
	- makefile project mẫu
	- Ozone Segger và biết cách sử dụng phần mềm Ozone
	- Jlink debugger

3. Nội dung:
	- những bước để bắt đầu làm quen với ngoại vi
	- hướng dân cách viết chương trình đọc/ghi dữ liệu I/O trên một chân của MCU bẳng sử dụng ngôn ngữ C

4. Chi tiết
	- hướng dẫn cách đọc một block diagram
	- Liệt kê những ngoại vi sẽ được sử dụng cho lập trình I/O
		-> GPIO (chính)
		-> RCC (khối ngoại vi clock)
	- Cách thức điều khiển ngoại vi
		-> Thanh ghi:
			--> xác định address của những thanh ghi sẽ sử dụng
			--> xác định/tìm hiểu những trường bít trong thanh ghi có ý nghĩa/điều khiển gì ?
			--> xác định giá trị của trường bit sẽ phản ánh điều gì ?
			--> giá trị mặc định (phụ)
	- Viết chương trình bằng sử dụng ngôn ngữ C
		-> Liệt kê những thanh ghi sẽ tương tác/làm việc, địa chỉ cụ thể của những thanh ghi đó ?
			--> mode
			--> thiết lập chức năng GPIO cho chân sử dụng
			--> chiều dữ liệu (input/output)
			--> ghi dữ liệu ra trên thanh ghi nào ?
				==> ghi dữ liệu theo pin
				==> ghi dữ liệu theo port
			--> đọc dữ liệu về trên thanh ghi nào ?
			--> một số option thiết lập cho pin (pull-up/down)
		-> Trình tự điều khiển ngoại vi (trình tự ghi giá trị tới thanh ghi)
		-> Triển khai phương pháp/thuật toán để ứng dụng viết chương trình