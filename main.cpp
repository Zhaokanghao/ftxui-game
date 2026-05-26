#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>
#include <random>
#include <string>

using namespace ftxui;

int main() {
	// 1. 生成1-100的随机数
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 100);
	int target = dis(gen);
	int guess = 0;
	int attempts = 0;
	std::string message = "请输入1-100之间的数字开始游戏！";
	
	// 2. 主循环：游戏逻辑
	while (true) {
		std::string input;
		auto document = vbox({
			text("数字猜谜游戏") | bold | center | color(Color::Blue),
			separator(),
			text("提示：" + message) | color(Color::Yellow),
			text("已猜次数：" + std::to_string(attempts)) | color(Color::GrayDark),
			separator(),
			text("请输入数字：") | bold,
		});
		
		// 渲染界面
		auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
		Render(screen.get(), document);
		screen->Print();
		
		// 读取用户输入
		std::cin >> input;
		try {
			guess = std::stoi(input);
		} catch (...) {
			message = "输入无效，请输入数字！";
			continue;
		}
		
		attempts++;
		
		// 判断结果
		if (guess < 1 || guess > 100) {
			message = "数字必须在1-100之间！";
		} else if (guess < target) {
			message = "太小了，再猜大一点！";
		} else if (guess > target) {
			message = "太大了，再猜小一点！";
		} else {
			message = "🎉 恭喜你猜对了！答案就是" + std::to_string(target) +
			"，你用了" + std::to_string(attempts) + "次！";
			break;
		}
	}
	
	// 游戏结束界面
	auto end_screen = vbox({
		text("数字猜谜游戏") | bold | center | color(Color::Blue),
		separator(),
		text(message) | bold | color(Color::Green) | center,
		separator(),
		text("按回车键退出...") | color(Color::GrayDark) | center,
	});
	
	auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(end_screen));
	Render(screen.get(), end_screen);
	screen->Print();
	std::cin.ignore();
	std::cin.get();
	
	return 0;
}
