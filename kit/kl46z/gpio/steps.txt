1. Kiểm tra nguồn clock của ngoại vi làm việc (PIT -> bus clock -> MCGOUTCLK )

2. Kiểm tra Clock Gate (enable/disable) kiểm tra trong SIM:
- OUTDIV4 -> SIM_CLKDIV1[OUTDIV4] -> OUTDIV4 = [18..16]
- Clock Gate -> SIM_SCGC6[PIT]  -> PIT = [23]

3. Xác phương sử dụng PIT
- Polling: tự check cờ PIT_TFLGn[TIF]
- Interrupt: Phải setting NVIC

3.1. Setting NVIC (chỉ sử dụng khi chạy ngắt timer)
- Xác định interrupt ID của PIT: 38 (irq = 22)
- thành ghi priority cho interrupt id 38: IPR = 5, PRI_5[23..16]

4. Setting PIT
- Enable PIT module -> PIT_MCR[MDIS] = 0
- Khởi tạo giá trị của "Timer load value register - PIT_LDVAL0 = 0x???? "
- Xoá cờ ngắt: PIT_TFLG0[TIF] = 1; TIF = [0]
- Enable/Disable ngắt - PIT_TCTRL0[TIE] - TIE = [1] -> Cần lưu ý là việc thiết lập này chỉ thực hiện khi sử dụng ngắt như trong mục (3)
- Start PIT channel timer: PIT_TCTRL0[TEN] = 1

Câu hỏi cần tìm hiểu:
1. Tại sao chương trình lại chạy vào HardFault_Handler(). Nhưng khi đặt breakpoint trong interrupt của PIT thì ko nhảy vào nữa ?

2. Tại sao line 87 trong main.c lại đang không thực hiện đúng khi xoá bit TIE
