
A. NVIC (Nested Vectored Interrupt Controller):

1. Chi tiết
	- Xác định ID ngắt cần sử dụng: EXTI0 -> ID interrupt = 5 -> PA0
	- Cập nhận handler interrupt tương ứng trong bảng software vector
	- Thiết lập cho phép ngắt ở mức ngoại vi
		-> GPIO: Input
		-> EXTI:
			--> EXTI_IMR
			--> thiết lập sường ngắt
		-> SYSCFG : SYSCFG_EXTICR1[EXTI0[3:0]]

	- Thiết lập mức priority
		-> NVIC_IPR
	- Xoá cờ ngắt
	- Enable interrupt từ NVIC
	- Bật ngắt toàn cục (enable global interrupt) bằng việc sử dụng lệnh ASM: cpsie i

	- Khi ra khỏi ngắt cần phải xóa cờ ngắt trong NVIC và trong ngoại vi
