
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int player, computer, c_c, c_p;
	c_c = 0, c_p = 0;
	computer = 1 + rand() % 101;
	cout << "Компьютер загадал число в диапазоне от 1 до 100" << endl;
	for (int count = 0; ; ++count) {
		cin >> player;
		if (player < computer) {
			cout << "Загаданное число больше вашего." << endl;
		}
		else if (player > computer) {
			cout << "Загаданное число меньше вашего." << endl;
		}
		else if (player == computer) {
			cout << "Вы угадали число! Очко игроку." << endl;
			c_p++;
			computer = 1 + rand() % 101;
			count = 0;
			continue;
		}
		if (count >= 5) {
			cout << "Вы не отгадали за 5 попыток. Очко компу." << endl;
			c_c++;
			computer = 1 + rand() % 101;
			count = 0;
			continue;
		}
		if (c_p == 3 || c_c == 3) {
			cout << "Игра окончена!" << endl << "Итоговый счет: " << c_p << " игрок/компьютер " << c_c;
			break;
		}
	}
}