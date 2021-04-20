#include<iostream>

int main()
{
	std::string first_name;
	std::string friend_name;
	char friend_sex = 0;
	int age = 0;

	std::cout << "Enter the name of the person you want to write to (followed by 'enter'):\n";
	std::cin >> first_name;
	std::cout << "Enter her/his age (followed by 'enter'):\n";
	std::cin >> age;
	std::cout << "Enter the name of another friend (followed by 'enter'):\n";
	std::cin >> friend_name;
	std::cout << "Is this friend male or female? (type m/f followed by 'enter'):\n";
        std::cin >> friend_sex;

	std::cout << "Dear " << first_name << ",\n\tHow are you? Here everything is ok, I miss you so much.\n";
	std::cout << "\tI hear you just had a birthday and you are " << age << " years old.\n";
		if (age <= 0 || age >= 110) {
			std::cerr << "Your are kidding!\n";
			exit(1);
		}
		else if (age < 12) {
			std::cout << "\tNext year you will be " << ++age << '\n';
		}
		else if (age == 17) {
			std::cout << "\tNext year you will be able to vote.\n";
		}
		else if (age > 70) {
			std::cout << "\tI hope you are enjoying retirement.\n";
		}
	std::cout << "\tHave you seen " << friend_name << " lately?\n";
		if (friend_sex == 'f') {
			std::cout << "\tIf you see " << friend_name << " please ask her to call me.\n";
		}
		else if (friend_sex == 'm') {
			std::cout << "\tIf you see " << friend_name << " please ask him to call me.\n";
		}
		else {
			std::cout << "\tIf you see " << friend_name << " please ask it to call me.\n";
		}

	std::cout << "\n\nYours sincerely,\n\nAndrea\n\n";
}
