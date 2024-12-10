#include <stdio.h>

// 定义枚举类型 Weekday
enum Weekday {
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY
};

// 打印星期的函数
void printWeekday(enum Weekday day) {
	switch (day) {
	case MONDAY:
		printf("星期一\n");
		break;
	case TUESDAY:
		printf("星期二\n");
		break;
	case WEDNESDAY:
		printf("星期三\n");
		break;
	case THURSDAY:
		printf("星期四\n");
		break;
	case FRIDAY:
		printf("星期五\n");
		break;
	case SATURDAY:
		printf("星期六\n");
		break;
	case SUNDAY:
		printf("星期日\n");
		break;
	default:
		printf("未知的星期\n");
	}
}

int main() {
	// 声明枚举变量 today 并赋值为 MONDAY
	enum Weekday today = MONDAY;
	
	// 打印今天是星期几
	printWeekday(today);
	
	// 获取明天是星期几并打印
	enum Weekday tomorrow = (today == SUNDAY)? MONDAY : (enum Weekday)(today + 1);
	printWeekday(tomorrow);
	
	return 0;
}
